#pragma once
/*
	1. UWorld와 Level의 관계는 SceneManager와 Scene의 관계 정도
	
	2. GetPlayer계열 함수는 PlayerController가 기반이 되어서 나머지를 처리함
	- 멀티 플레이 게임에서 부여받은 인덱스를 통해 접근(이 인덱스는 ID와는 또 별개)

	3. BT에서 <데코레이터>의 관찰자 중단은 실행 흐름에 관계 없이 취소시키고자 등록한 내용(Self 혹은 LowerPriority 혹은 둘다)을 취소시킴

	4. Fireball은 그냥 Enemy가 던질 땐 Enemy의 정면벡터 방향으로 던짐
	- Enemy로 판단되는 기준은 fireball의 destination 지정이 안된 것으로 알 수 있음(카메라가 없기 때문)
	- BT에서 Rotate를 한다는 보장이 돼있기 때문에 어디로 던져야 한다는 로직이 필요없음
	- Z축 차이가 있으면 못 때리게 되는 로직이긴 함

	5. EQS의 SimpleGird를 만들어봄
	- EQS는 BT에서 Run EQS Query로 Task로 처리됨
	- 우리가 만든 EQS를 이 Run EQS Query노드에 물려줘야 하는데 디테일 탭에 Deprecated된 내용이 있기에 주의
	- 실제 등록은 EQS - EQS Request에서 해야 함(Query Template)
	- EQS에서 득점을 많이 한 위치에 대해서 BB의 어떤 값에 물려줄지도 디테일 탭에서 설정
	- 상위 몇%에서 Random한 값을 줄지 정하는 옵션도 있음 -> 기본 값은 SingleBestItem

	6. EQS 디버그 방법은 ' 누른 후 키패드 3

	7. EQS SimpleGrid의 디테일 탭
	- GridHalfSize : Querier 혹은 Item의 위치를 기준으로 정사각형 모양만큼 ( 500이라면 1000 * 1000의 정사각형 만큼 위치 만듬 )
	- SpaceBetween : GridHalfSize로 만들어진 영역안에 각 위치를 얼마만큼의 간격으로 생성할지
	- GenerateAround : Querier일지 Item일지 인데 Item은 어떤 걸 의미하는 건지 ?

	8. SimpleGrid에 테스트 추가해봄 (Distance)
	- Test Purpose : Filter 혹은 Score 혹은 Filter와 Score 둘 다 적용(Filter는 안 쓸 애들 걸러내는 것)
	- TestMode : Distance2D, Distance3D, Z에 대해, Z 절대값에 대해 정도(2D와 3D의 차이는 3D는 실제 Actor의 Location을 기준으로 함, 2D는 Actor의 Location중 X,Y만 활용)
	- DistanceTo : Querier가 있고 다른 건 뭐가 있지 ?
	- 필터 : Minimum이면서 500을 주면 500보다 가까이 있는 애들은 전부 필터링 된다는 뜻
	- Score : 최종 선발 -> 결국 점수가 높은 위치가 선발되는 것
	- Score Equation : InverseLinear는 거리가 멀수록 점수가 떨어짐
	- Scoring Factor : 점수에 그냥 곱하기 해주는 값(왜 만듬 ?ㅋㅋ)
	- NormalizationType : Absolute VS RelativeToScores는 Absolute는 관찰자 기준으로 점수 메기고 후자는 관찰자에서 제일 가까이 점수 메긴거를 기준으로 점수를 메김
	- Reference Value : 준 값에 대해 관찰자 기준으로 월을 만들어서 거기가 그 원에 가까울수록 점수가 낮음(원래는 점수가 높아야 하는데 반대인 상황, Linear, InverseLinear로 바꿀 수 있으니 쓰는덴 지장없음)
	- Clamp : 특정 범위에 대해 낮으면 0점, 높으면 만점 -> InverseLinear이면 반대일 듯 ?

	- Test는 여러 Test를 붙여서 가능하고 붙여놓고 On/Off도 가능
*/