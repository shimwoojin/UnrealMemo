#pragma once
/*
	1. FireBall 스킬이 우클릭 시 줌하는 ActionB를 갖기 위해 BP_Player쪽에서 ZoomIn, ZoomOut을 적절한 시야로 구현하는게 과제였는데 
	- 핵심 키워드는 TimeLine, Camera::FieldOfView, SpringArm::TargetArmLength, SpringArm::SocketOffSet
	- 과제를 하면서 SpringArm::SocketOffset이 아닌 SpringArm::TargetOffset을 건드렸었는데 TargetOffset은 월드 좌표 기준으로 얼마나 떨어져있을지를 정하는 값임
	- 아마 TargetOffset의 z를 기본 75~100정도로 설정해줬던 이유가 수영할 때 플레이어의 축이 바뀌어도 카메라는 위에서 쳐다보는 시점으로 만들려고 했던 것 같음

	- 일단 과제에서 쓴 값들을 적으면 0~0.25초 동안
	FieldOfView : 80 -> 70
	TargetArmLenth : 300 -> 250
	SocketOffset.y : 0 -> 100
	SocketOffset.z : 0 -> -30

	- SocketOffset.z를 -30하는 이유가 의아할 수 있는데 TargetOffset.z가 100인 상황이였기 때문에 이렇게 했을 때 시야가 더 자연스러웠음

	2. 이벤트 그래프에 생성한 TimeLine은 변수 탭에 컴포넌트로서 존재하는데 component라는 것이 결국 주소를 알고 있는 포인터 변수이기 때문에 주소만 바꿔주면 다른 걸로도 set이 가능하다고 함
	- C++에서는 변수 탭이 아닌 컴포넌트 탭에 Timeline을 달고 있을 수 있는데 블프에서는 불가능했음(이유는 잘 모름)
	- ConstructionScript에서 AddComponentByClass를 해서 월드에 배치해서 인스턴스 생성 후 컴포넌트 탭에 있는 걸 보여주시려 한거 같은데
	ConstructionScript에서 AddComponentByClass는 불가능함
	- 이벤트 그래프에서 AddComponentByClass를 하면 TimelineComponent로서 존재하는 것을 확인할 수 있긴 함

	- 결론은 Timeline이라는 것은 component가 맞고 블프에서는 단지 변수로서 존재한다는 것

	3. Timeline에서 그래프의 형태는 linear뿐만 아니라 다양한 형태로 만들 수 있음
	- key 만들어 놓은 점에서 우클릭 후 설정 가능
	- TimeLine의 키를 편집할 때 vector같은 그래프는 x,y,z따로 볼 수도 있고 값을 잠궈놓고 편집할 수도 있음, 그래프에 눈이랑 자물쇠 모양 있음

	4. zoom이 가능하냐 불가능하냐라는 변수를 갖고 있어야 한다는 의견이 있었는데 이것이 아닌 이유는
	- BP_FireBall이라는 스킬이 두 번째 기능인 ActionB가 단지 ZoomIn, ZoomOut이였을 뿐
	- 설계 의도는 우클릭을 누르면 CurrentSkill의 ActionB가 실행되는 것인데 구현한 스킬마다 ActionB가 다른 스킬을 취하길 원한 것이고
	- 단지 FireBall의 ActionB가 ZoomIn, ZoomOut이였던 것
	- ActionB를 오버라이딩 하지 않는 BP_Skill의 자손 클래스들은 우클릭을 누르면 빈 ActionB를 실행하려다가 아무일도 일어나지 않는 형태로 구현된 것

	- FireBall이 ZoomIn, ZoomOut을 구현하기 위해선 player가 가지는 속성을 훔쳐와서 값을 바꾸는 작업을 해야하는 건데(여기선 camera, springarm 등)
	GetOwner - CastToBP_Player - Camera 이런 식으로 값을 가져와서 직접 수정할 수 있긴 하겠지만 이런 코딩이 많아지면 나중에 디버깅이 힘들어진다고 함
	- 그렇기 때문에 player에서 자신의 camera, springarm의 값을 바꾸는 ZoomIn, ZoomOut을 하는 함수를 구현해서 fireball쪽에선 player의 그 함수를 호출해야 하는 건데
	ZoonIn, ZoomOut이 인터페이스가 아니였다면 GetOwner - CastToBP_Player - ZoomIn을 하는 형태였을 거고 확장성이 낮아지는 요인으로 작용할 수 있음

	- 아무튼 ActionB의 발동 매커니즘은 Controller에서 우클릭을 하면 Player가 상속한 인터페이스인 ActionB를 호출하고 플레이어의 ActionB는 CurrnetSkill의 BeginActionB, EndActionB를 호출하고
	CurrentSkill에서 BP_Skill을 상속한 자손 스킬들이 오버라이딩한 BeginActionB, EndActionB가 실제로 실행되는 것임 단지 fireball이 구현하려는 내용이 player의 값을 건드리는 내용이여서
	player에서 이 내용을 바꿔주는 함수를 만들어서 넘겨준 것 뿐임

	5. 4번같은 로직이 아니라 A스킬이 B스킬을 알고 있으며 A스킬의 ActionB에서 B스킬의 ActionB를 호출하는 방식으로도 구현할 수 있는데 이런 구현은 B스킬을 가져다 쓴 곳에서 B스킬이 바꼈을 때
	직접적으로 영향을 받음
	- 게임 컨셉에 따라 이런 방법도 적용해봄직 함

	6. ZoomIn이 된 시점에 CameraLag이 있으면 움직임이 보기 불편한데 Zoom이 된 시점엔 SpringArm::EnableCameraLag을 껐다 켰다 하는 방식은 뚝뚝 끊겨보여서 더 부자연스러웠음
	- 위 내용 구현할 때 timeline에서 Finished, Direction, Switch 활용해서 구현함 -> play랑 reverse의 끝난 시점을 direction의 switch로 각각 처리하는 방식
	- CameraLagSpeed를 timeline에 추가해서 그 값을 뽑아다가 다시 set해주는 것이 보기에 더 자연스러울 것

	7. TimeLine내부에 외부커브를 들여올 수 있는데
	- 커브 클래스를 콘텐츠 브라우저에서 만들 수 있음, 편집 방식은 크게 다르지 않음
	- 외부커브를 적용하는 경우는 같은 커브를 여러군데에서 써야할 경우 고려해 볼만함, 아닌 경우 TimeLine에서 직접 편집하는 것이 더 편할 듯

	8. 에셋을 다중적용해야 할 경우가 있는데(보통은 머티리얼, 이번 경우는 외부커브) 콘텐츠 브라우저에서 ctrl 혹은 shift로 다중 선택해서 에셋 선택 창의 돋보기 모양 클릭하면 다중 적용 가능

	9. 외부커브의 응용이 가능한데
	- t : 0 -> 1, value : 0 -> 1 선형 증가하는 그래프 혹은 t : 0 -> 1, value : 1 ->0 선형 감소하는 그래프 등 자주 쓸 법한 외부커브는 만들어두고
	- timeline에서 만들어 둔 외부커브를 적용 후 나오는 값에 더하거나 곱하거나 해서 내가 원하는 값으로 사용 가능(더하거나 곱하는 것 보단 Lerp가 더 편함, LinerInterpolation 선형보간)
	- timeline에서 나오는 값을 Lerp의 alpha로서 사용
	
	10. Lerp의 상위호환 급으로 MapRangeClamped 라는 노드도 있었는데
	- Value : 20
	- InRangeA : 10
	- InRangeB : 30
	- OutRangeA : 100
	- OutRangeB : 2000일 때 

	- return되는 값은 1050인 식의 방식
	- 20이 10과 30의 중간 값이니깐 100과 2000의 중간 값인 1050이 return되는 것

	11. TimeLine에서 더 써봄직한 노드들이 있는데
	- SetPlayRate : TimeLine의 시간 축을 늘이거나 줄일 수 있음
	- SetTimeLineLength : TimeLine의 어느 시간까지 적용시킬 지

	12. 이벤트 그래프에 우클릭 후 어떤 관련 내용들만 볼 지를 정하는 게 <컨텍스트에 따라>를 toggle하는 방식으로 정할 수 있는데 
	- 추가적으로 <컨텍스트에 따라> 오른쪽에 화살표 클릭해서 어떤 내용 켤지 끌지 정할 수도 있음

	13. 추가적으로 줌을 했을 때 crosshair를 만들어 주기 위해 <콘텐츠 브라우저 우클릭 - 유저 인터페이스 - 위젯 블루 프린트>으로 WBP_CrossHair 만들고
	- 엔진 컨텐츠에서 대충 쓸만한 texture찾아서 우리 프로젝트로 <복사>해줌
	- <이동>하면 내 엔진은 그 texture 다른 프로젝트에서 사용 불가

	14. WBP_CrossHair에서 CanvasPannel 밑에 Image 달아주고 내용을 편집해주어야 하는데
	- 우측 상단에 FillScreen, Desired 등 화면을 어떻게 볼지 정하는 탭이 있는데
	FillScreen : CanvasPannel로서 적용된 점선 내(내 모니터의 해상도 혹은 default 값)에서 Image가 어떤 크기일 지 상대적으로 보여줬고
	Desired : Image가 실제로 100 * 30의 픽셀을 차지하는데 내 모니터상의 100 * 30만큼 차지한 것을 보여준 것 같음

	- Appreance - Image에서 사용할 이미지 파일 적용할 수 있고, ImageSize X, Y를 설정 가능
	- ImageSizeX,Y를 적용해도 모양이 이상한데 CanvasPanelSlot의 SizeToContent를 True로 줘야 제대로 적용되는데
	- CanvasPanel의 SizeX,Y가 또 따로 있는데 이게 아마 canvas에 추가한 Image로서 쓰기로 정한 도구의 크기가 100, 30이라는 뜻이고
	100, 30의 공간에서 내가 적용한 Image는 32 ,32 였는데 32, 32로 적용한 image가 100, 30의 공간에 맞춰 늘어났던 것으로 보임, SizeToContent를 true로 줌으로서
	내가 적용한 image파일의 크기 32, 32로 적용된 것 같음(100, 30이라는 값을 오버라이딩 적용한 듯)

	15. 에임을 화면의 정중앙을 주기 위해 1920 / 2, 1080 /2 한 값을 각각 X위치, Y위치에 주었는데 이것이 정확한 위치가 아닌 이유는
	- 앵커가 좌측상단을 기준으로 되어 있었기 때문이고
	- 좌측 상단부터 출력되는 이미지를 화면의 x절반, y절반만큼씩 이동시킨 것이고
	- Alignment가 0, 0이였는데 내 image의 좌측상단을 앵커에 맞춘다는 뜻이고 1,1은 우측 하단을 앵커에 맞춘다는 뜻임
	- 앵커를 좌측상단에 주고 1920 / 2, 1080 / 2, Alignment는 0.5, 0.5로 원하는 세팅을 할 수 있었지만

	- 조금 더 추가해서 앵커를 좌측 상단이 아닌 중앙으로 주고 X위치, Y위치를 0, 0 으로 줘도 같은 세팅을 줄 수 있었음
	
	16. 수업 끝나기 직전에 review로 먼저 보여주셨는데
	- 우리가 볼 수 없는 이유는 아직 WBP가 있긴 하지만 이 WBP를 적용해주겠다 라는 코드가 없기 때문임
*/