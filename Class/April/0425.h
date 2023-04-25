#pragma once
/*
	1. 포폴 피드백 중에 데이터를 전달하는 방식에는 2가지가 있다고 하심 1) Get으로 받거나 2) Set으로 세팅하거나
	- 예를 들면 Character와 연관된 값이 Weapon의 i라고 하면 이걸 처리하는 곳이 1) Weapon에서 Character를 getter로 얻어와서 처리하거나 2) Character에서 Weapon에 대해 set을 하거나
	- 누구한테 이 정보가 있는 게 적합한지를 잘 판단하길
	- 이거에 또 적합한 예로 애님 블프에서 IsArmed를 Tick마다 확인하는 게 아니라 Character가 무기 바꿀 때 애님 블프에 알려주는 게 맞는 것

	2. Widget은 Component로 다루게 되면 Ingame내에 Transform을 가져야 하는 경우 사용하고 아닌 경우 변수로서 CreateWidget, AddToViewport로 다루는 게 더 적합
	- CrossHair : 변수로 CreateWidget, AddToViewPort
	- Enemy의 체력바 : Widget Component
	- Player의 체력바 : 변수로 CreateWidget, AddToViewPort

	- 처음에 Component로서 PlayerController에서 Crosshair가 정상 작동한 이유는 controller가 default로 hiddeningame이기 때문에 월드상에서 component로서 작용이 안 된 것 뿐.
	Component로 widget을 사용해도 AddToViewport를 하게 되면 변수로 쓰는 것과 별 차이가 업음
	- 2D상 화면에 표시하기 위해서 Component로 추가해서 HiddenInGame걸어주고 AddToViewport해도 되긴 하나 쓰임새에 맞게 변수로 쓰는 쪽으로,,
	
	3. CreateWidget의 OwningPlayer는 핀을 안 주면 GameMode에서 걸어준 default controller를 갖게 됨

	4. 체력 게이지의 경우 체력이 변하면 게이지도 변하는 코드가 항상 추가되어야 하기 때문에 체력이 변하는 setter 혹은 add, sub를 하는 코드에 게이지를 업데이트 하는 함수로 같이 처리하는 게 효율상 좋음
	- 또한 이런 케이스가 있기 때문에 만들어진 setter혹은 getter가 있다면 그것을 사용하여 처리하는 것이 맞음

	5. Character에서 SetLifeNow라는 함수로 처리하는 부분이 있고
	- SetLifeNow에 대해서 Enemy, Player에서 각각 오버라이딩 했기 때문에
	- Enemy, Player는 각각 자기의 widget에 맞는 처리가 들어가게 됨(굉장히 강력한 듯), Character에선 Beginplay랑 AnyDamage에서 1번씩 SetLifeNow 호출

	6. 블프 setter는 처리하고 나온 값에 대해서 return 해주는 경우가 대부분 인 듯

	7. WBP_Gauge에서 인터페이스 정의한(SetGaugeColor, SetGaugeRatio)는 WBP_PlayerGauge에서 또 인터페이스 상속해주고 새로 정의해야하는데
	- WBP_PlayerGauge 내에서 WBP_Gauge를 <사용자 생성> 탭에서 재활용하고 있기 때문에 
	WBP_PlayerGauge의 변수인 WBP_Gauge의 인터페이스 함수를 콜해서 WBP_PlayerGauge를 재정의하면 유연하게 같은 기능을 가진 인터페이스 함수 구성 가능


*/