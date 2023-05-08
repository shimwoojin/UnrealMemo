#pragma once
/*
	1. ApplyRadialDamage는 근원지로부터 멀어질수록 데미지가 덜 들어가는게 기본값
	- 균등하게 주려면 bool값 체크해줘야 함

	2. fireball을 어느 위치에서 어떤 방향으로 던져야 하는지가 문제인데
	- 손에서 던져야 하고
	- 정해놓은 끝 지점으로 던져야 함

	- 손에서 던지는건 GetInstigator - GetComponentByClass를 하여 SkeletalMeshComponent에서 정보를 훔쳐옴
	- SkeletalMesh로부터 Socket위치를 받아오는 GetSocketLocation으로 hand_r의 위치를 받아옴

	3. 2번 방법은 굉장히 위험한 방법임(강사님이 GetComponentByClass를 소개하기 위해 사용한 방법인 듯
	- 위 방법을 정말 사용해야 한다면 적어도
	- GetInstigator - CastToCharacter - GetComponentByClass - IsValid - GetSocketLocation 순으로 가거나
	- Interface로 Character가 상속받아서 GetSkeletalMeshSocketLocation 같은 이름으로 건내주는 방법이 그나마 안전할 듯

	- FireBall에서 받아온 SkeletalMesh에 SetSkeletalMesh 같은 함수로 캐릭터의 메시를 바꿔버리면 디버깅할 때 추적이 정말 어려워짐

	4. GetComponentByClass는 그 class가 가지고 있는 특정 component를 처음 만났을 때 그놈 딱 하나를 들고 오고 (계층 구조상 상위 컴포넌트가 걸릴 확률 높음)
	- GetComponentsByClass는 그 class가 가지고 있는 특정 component를 전부다 가지고와 배열로 리턴해줌

	5. FindLookAtRotation으로 시작지점을 손으로 주고 끝 지점을 Destination을 주어서 Projectile_FireBall의 Rotation으로 넘겨줌
	- 던질 fireball의 rotation을 정해준 것

	6. 던진 fireball이 overlap이 안되면 소멸이 안되는데
	- 시간이 지나면 액터를 사라지게 하기 위해 lifespan을 설정해주어야 하는데
	- actor의 기본 값에 있음

	7. 시간이 다 되서 사라질 때 폭발해서 스플뎀 입히도록
	- 기존 로직에서 액터와 맞았을 때 데미지를 주는 방식은 beginoverlap에서 처리하고
	- DestroyedActor이벤트에선 스플뎀을 처리해 줌(이 이벤트는 소멸 직전에 수행하는 것, 아직 Actor가 None이 아님)
	
	8. 충돌에 따라서 어디 맞았는지를 처리하는 게 질문이 들어왔는데
	- component의 overlap에서 어떤 component랑 부딪혔는지에서 GetObjectType을 가져와서 스위치로 처리할 수 있음
	
	- overlap(component버전) 이거 실험 좀 해봤는데 overlappedcomponent로 나오는 핀은 자기 자신이고
	- othercomponent로 나오는 핀은 overlap된 상대인데
	- 이 때 캐릭터는 mesh에도 collision이 있고 capsule에도 collision이 있어서 뭐가 나오나 실험을 해봤는데
	- overlapevent가 둘 다 켜져있다고 가정했을 때 mesh가 충돌되었고
	- 원래 세팅은 mesh의 overlap 이벤트는 꺼져있었기 때문에 capsule과 collision이 일어났음

	- enemy에서 capsule이랑 mesh에서 둘다 overlap만들어서 해봤는데 랜덤하게 맞음

	9. fireball을 든 상태에서 우클릭을 누르면 zoomin 떼면 zoomout을 만들기 위해
	- BP_skill에 빈 커스텀 이벤트 BeginActionB, EndActionB를 만들고
	- BP_Fireball에서 구현을 할 때 GetInstigator에서 Zoonin, Zoomout을 각각 오버라이딩 한 BeginActionB, EndActionB에 연결
	- 실제 ZoomIn과 ZoomOut은 player에서 구현

	- 결국 zoomin, zoomout을 하기 위해 값을 건드려야 하는 부분은 player가 가지고 있는 camera, springarm이기 때문에 그 값을 건드는 함수(인터페이스)는
	player에서 처리하고
	- 그 함수를 fireball의 특수 행동에서 콜을 해서 동작하게 하고
	- 실제 액션 바인딩의 내용 추가에선 current_skill의 특수행동을 콜하는 방식

	- 구조가 굉장히 기괴하나 유연함
	- 다른 스킬들의 다른 특수행동에 대해 짤 때 유연해짐

	10. Zoomin을 구현하기 위해 건드려야 할 값들은 camera::FieldOfView, springarm::targetarmlength, springarm::socketoffset

	11. 축 입력과 액션 입력에 대해 차이를 알아보면
	- 축 입력은 매 프레임 실행되는 tick 같은 함수
	- 단지 입력이 들어왔을 때 어떤 값을 뱉어내는지를 정해서 그 값으로 처리함

	- 액션 매핑은 입력이 들어온 그 한 순간 실행핀 처리함

	12. ZoomIn, ZoomOut에서 TimeLine을 이용한 처리를 하는데
	- float, vector, color, event에 대해 처리할 수 있고
	- event를 제외한 3개는 float이 몇개인지만 다름
	- 몇 초에 어떤 값을 가지고 또 몇 초에는 어떤 값을 가질지를 선형적으로 증가할 수 있는데
	그 값을 플레이어의 특정 값에 set해주면 시간에 따른 값의 증가 혹은 감소를 볼 수 있음
	- 시작에선 play로 핀이 들어가고 원래 상태로 돌아가기 위해 reverse핀에 넣어주는데

	- 이때 timeline내부에서 길이를 내가 원하는 값으로 설정해주어야 함
	안 했다면 reverse시 반응이 늦는 결과가 나옴(maxwalkspeed바꿔보다가 알게됨)


	
*/