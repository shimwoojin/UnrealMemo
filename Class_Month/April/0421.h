#pragma once
/*
	1. 체력 게이지를 적의 머리위에 띄워주기 위해 만들어 둔 WBP_Gauge를 적용시켜주어야 하는데
	- Character 혹은 Enemy에 WidgetComponent를 추가하고
	- 위젯 클래스를 WBP_Gauge를 적용해주고
	- World가 아닌 Screen으로 바꾸고(World일 경우 백페이스 컬링되어 안 나오는 방향이 있음)
	- 원하는 사이즈에서 드로를 해주고(체크 안하면 WBP_Gauge를 우리가 만들어 둔 크기가 아니라 컴포넌트에서 정한 크기로 드로우 됨)
	- AddToViewPort는 하지 않으면 적용 됨(캔버스 패널이 아니라 SizeBox라 그런가 ?)

	2. 체력 게이지는 체력이 변하면 업데이트 되어야 하기 때문에
	- WBP_Gauge의 ProgressBar의 Percent 값을 체력이 변하는 순간 업데이트 해주어야 함
	- 체력 게이지의 소유주에게서 LifeNow / LifeMax 한 값을 Progress의 Percent에 적용해야 함
	- WBP_Gauge에서 함수로 만들어서 형변환해서 AnyDamage에서 처리할 수도 있지만 인터페이스를 사용하여 구성

	- 사실 AnyDamage에서만 처리하긴 하는데 체력을 회복한다던가 최대체력이 변한다던가 하는 곳에선 항상 체력게이지를 업데이트 하는 코드가 있어야 하는데
	이 방법은 조금 맘에 안 들지도

	3. 위젯은 상속은 안 되고 다른 위젯의 부품으로서 들어갈 순 있음
	- 부품으로서 들어가는 건 위젯의 <사용자 생성> 탭

	4. character의 skeletalmesh, collision 등은 바꿀 수 없음
	- cpp에서는 가능하다고 함

	5. 형변환 대신 인터페이스로 SetGaugeRatio, SetGaugeColor를 구성하는 건 너무 많이했으니 패스
	
	6. LinearColor는 0 ~ 1 사이의 비율로 표현한 색
	- RGBA 각각에 대해서 각 채널 당 8비트 씩 주어서 0 ~ 255의 정수로 표현하건 채널 당 10비트 씩 주어서 0 ~ 1023의 정수로 표현하건
	빨강, 파랑, 초록의 최대 농도(?), 진하기(?)는 255에서 1023에서 같아야 하기 때문에 이 비율을 표현한 게 linearcolor

	- BPC : BitPerChanel, R,G,B,A를 각각 한 채널로서. A가 Color가 아니기 때문에 BitPerColor는 정확하게는 맞는 말이 아님
	- BPP : BitPerPixel, R,G,B의 채널을 더한 총 비트 수. Alpha는 포함되지 않음

	7. 위젯을 컴포넌트로 쓰다 보면 항상 GetWidget 혹은 GetUserWidgetObject로 실제 위젯 클래스 불러오는 거 잊지 말기
	- 특히 인터페이스까지 쓰니깐 WidgetComponent에 인터페이스콜을 해도 오류없이 작동을 안 하니 어디서 잘못된지 알 수가 없음

	8. 적은 머리위에 gauge를 머리위에 띄우지만 플레이어는 playergauge를 따로 만들어서 처리할건데
	- 일단 이런 거 처리하기 전에 같은 내용인데 2개 만들어야 하나 생각해보면
	- 이번 케이스는 그래야 할 듯
	- SizeBox로서 인스턴스 위에 존재하는 위젯이 아니라 우리 화면에 꽉 채워서 고정될 UI로 존재할 거기 때문에
	- 캔버스 패널에 다시 적용해주어야 함(만들어 둔 WBP_Gauge는 <사용자 생성> 탭에서 재활용)

	9. 끝날 때 문제가 있는데
	- 화면 좌상단에 플레이어 게이지는 WBP_PlayerGauge로서 뜨는데(Player에서 WBP_PlayerGauge를 쓰고 AddToViewport까지 해줌)
	- 플레이어 머리 위에도 게이지가 뜸(다음 시간에 해결해보기로)
	- WidgetComponent의 HiddenInGame을 키면 해결되긴 함
*/