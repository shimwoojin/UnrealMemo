#pragma once
/*
	1. WBP에 <디자이너>탭이 있고 <그래프>탭이 있는데 <디자이너>의 팔레트에 추가한 이미지, 버튼, 텍스트 등에 대해 변수로 만들 수 있었음
	- 변수로 만들게 되면 <그래프>에서 다른 블프 클래스처럼 제어할 수 있는데(변수, 함수, 매크로, 이벤트 디스패처, 인터페이스, 이벤트)
	- 이벤트에 대해선 construct, tick, 마우스 관련 이벤트까지 활용 할 수 있을 듯, overlap이나 hit같은 이벤트는 widget에 없는 듯

	- 변수로 만들게 됐을 때 이 WBP를 소유하고 있을 Controller쪽에서 CrossHair 이미지를 게임 도중에 바꿀 수 있나 테스트를 해봤는데 가능함
	- 이 WBP 클래스를 소유하고 있을 controller쪽에서 <UserWidget 오프젝트 래퍼런스>에 CastToWBP_Crosshair를 통해 변수나 함수에 직접적인 변경이 가능했고
	- Cast하는 방식이 맘에 안 든다면 인터페이스도 상속이 가능한 것으로 확인 됨
	- 런타임 중에 palette에 추가한 image 파일의 변경도 가능한 걸 확인했음(CrossHair - GetWidget - CastToWBP_CrossHair - CrossHair - SetBrushFromTexture)
	- 형변환을 해야 하는 이유는 GetWidget의 return값이 UserWidget 오프젝트 래퍼런스 이기 때문(아마 Widget클래스의 최상위 부모 인듯)

	2. UI도 성격에 따라 어디서 갖고 있을 지 고민을 좀 해봐야하는데
	- 게임의 전체 KDA, 게임 시간, 게임 점수 등 전체적인 내용에 대해선 GameMode
	- CrossHair, HP 게이지바, 궁극기 게이지 등 플레이하는 캐릭터가 바뀌어도 계속 화면에 띄워야 하는 내용은 Controller
	- Player가 플레이하는 캐릭터가 바뀐다면 바뀌어야 할 내용은 Player

	- 우리가 만든 CrossHair는 Controller에서 갖고 있을 예정

	3. BP_PlayerController쪽에서 WidgetComponent를 추가해주고 WidgetComponent의 UserInterface - WidgetClass를 WBP_CrossHair로 줌으로서 우리가 사용할 위젯 클래스를 정함
	- WidgetComponent - GetWidget - AddToViewport를 함으로서 우리가 만든 크로스헤어를 화면에 띄울 수 있었는데
	- UserInterface - Space에서 Screen으로 세팅을 바꿔주었는데 World는 우리 화면이 아니라 월드에 인스턴스로 포함된 것처럼 취급하는 것 같음

	- 의아했던 부분은 GetWidget을 통해 얻어온 점이고 이걸 보고 WidgetComponent라는 것이 WidgetClass를 포함하고 다른 추가적인 기능을 줄 수 있는 거라고 추측함
	- 그래서 실험을 해봤는데
	- 변수에 <UserWidget 클래스 래퍼런스>를 추가해서 BeingPlay에 CreateWidget을 통해 만들게 되면 component에서 GetWidget으로 얻어온 거랑 같은 효과더라
	- 클래스 래퍼런스로 추가하기 전에 <UserWidget 오프젝트 레퍼런스>로 주어 직접 WBP_CrossHair를 물려주려고 했는데 이건 불가능 한 것 같음

	4. 화면에 WBP_CrossHair를 띄울 수 있게 됐는데 ShowCrossHair, HideCrossHair를 통해 ZoomIn이 됐을 때만 이 위젯을 화면에 표시하게 바꿔주려면
	- GetWidget - SetVisibility를 통해 제어가 가능함
	- Controller 전용 인터페이스 하나 만들어서 ZoomIn, ZoomOut 함수 만들고
	- ShowCrossHair은 SetVisibility를 NotHitTestable(Self&AllChildren)을 주고 HideCrossHair은 Collpased 옵션을 줌

	- SetVisibility의 옵션 5가지 중

	1) Visible : 표시o, 상호작용 가능
	2) Collpased : 표시x, 공간 차지x 
	3) Hidden : 표시x, 공간 차지 o -> 공간을 차지 한다는 것이 아마 Zorder가 높아서 화면에 표시될 우선순위가 높은 Widget을 Hidden으로 가려버리면 ZOrder가 상대적으로 낮은 UI를 가려버릴 수 있는 것 같음
	이럴 때 Collpased 써서 다른 UI를 가리지 말아야 할 듯
	4) NotHitTestable(Self&AllChildren) : 표시o, 상호작용 x
	5) NotHitTestable(Self) : 4와 같지만 자식엔 적용x

	5. 4에서 만든 ShowCrossHair, HideCrossHair를 TimeLine의 Start와 Reverse에 추가로 연결해 줌
	- Timeline의 핀에서 Finished와 Direction을 조합해서 처리하거나
	- PlayfromStart, ReverseFromEnd 등의 핀으로 더 세밀한 조정 가능할 것 같긴 함

	6. Fireball이 실제 날아가는 방법을 여러가지 방법이 있는데
	- 투사체 속력이 빠르면 그냥 캠 위치에서 쏴버리는 경우가 있음
	- fps에서도 대부분 캠 위치에서 쏴버리기도 하는데 총 위치에서 카메라가 가는 line을 따라 보간하는 방법도 있음
	- 카메라 line의 중간에서부터 날아가는 경우도 있음
	- linetrace에 걸리면 그냥 이미 맞아있고 파티클만 나가는 방식도 있음(스나이퍼)
	
	- fireball이 손에서 target까지 가는거랑 camera의 line을 따라가는 게 aim이 안 맞는 이유는 딱 한점에서만 맞기 때문임(taret으로 지정된 점에서만 맞음)
*/