#pragma once
/*
	1. Interface의 Naming은 좀 더 포괄적으로
	- ex. SkillQ 같은 네이밍은 키 바인딩이 바뀌게 되면 Q가 아니게 될 수 있음
	- ex. DrinkPotion() -> UseItem()
	- DrinkPotion의 경우는 구체화하는 클래스 쪽에 가서 DrinkPotion() 함수를 만들고 UseItem() 인터페이스에 물려주는 식으로 해야 좋은 설계일 듯

	2. BT의 데코레이터 중에 IsAtLocation을 사용하여 Target과 조종당하는 enemy 간에 거리 검사가 가능한데
	- 이 때 인심좋은 AI를 만들기 위해서 Aceptable Radius를 150을 줌
	- 이 값을 너무 적게 줘버리면 공격을 하다가도 조금만 멀어져도 다시 따라붙음

	3. AI의 정찰을 위해 AI가 목표로 삼을 location을 선과 점의 형태로 가진 SplineComponent가 있음
	- BP_PatrolRoute : 새 Actor는 Splinecomponent만 가지고
	- BP_PatrolComponent : ActorComponent이고 위에서 만든 Actor의 오브젝트 래퍼런스를 가지고 <인스턴스 편집>을 주어서 월드상에 배치를 하게 될 위 Actor에 대해 변수로 알고 있음(월드에서 배치 이후 지정해주어야 함)

	4. BP_PatorlRoute를 월드 상에 배치하고 나면 Point 2개로 시작해서 여러 개를 찍을 수 있는데
	- 포인트에 마우스 우클릭 하고 <복제> 후 복제로 생겨난 point를 적절한 위치로 옮겨주면 됨
	- 실제 AI의 이동은 point를 기준으로 움직이기 때문에 배치 시 생겨난 곡선의 형태가 아닌 Point를 향해서 움직임

	5. 배치한 BP_PatrolRoute를 편리하게 다루는 방법 중에
	- 배치한 actor의 component에 직접 값을 바꿔주는데
	- 0번 point -> 1번 point의 유형을 Curve -> Constant로 바꿔 실제 어떻게 움직일지 직관성을 높일 수 있고
	- CloseLoop를 True 주게 되면 Point의 끝 지점에서 다시 0번 지점으로 이동하게 됨 ( 아니라면 끝 지점에 도달하고 끝 -1 , 끝 -2 이렇게 움직일 예정)

	6. BP_PatrolRoute의 기즈모가 처음과 달라질 수가 있는데
	- 0번 point에 대해 위치를 옮기게 되면 그럴 수 있음(Actor 자체를 옮긴게 아니라)

	7. 위에서 만든 BP_PatrolComponent를 Enemy 혹은 Enemy_Melee에 달아주고 (용도에 따라 위치는 선택) 실제 월드에 배치한 Enemy에 대해 BP_PatrolComponent가 가진 실제 월드에 배치한 BP_PatrolRoute를 변수에 설정해주어야 함
	
	8. Enemy에 물려준 PatrolComponent가 하는 일은 월드에 배치된 SplineComponent를 들고 있는 Actor를 알고 그 Actor의 SplineComponent에 접근해서 위치를 얻어오는 처리를 하는 것 같음
	- 우리가 만들어 둔 point를 0부터 n까지를 정할 Index가 필요하고
	- 1) 0부터 n까지 일지 2) n부터 0까지 일지 3) 0부터 n까지 그냥 쭉 loop를 돌지를 정할 bReverse로 필요하고

	9. 결국 Enemy입장에서 알아야 하는건 결국 월드에 배치한 Actor의 SplineComponent에 접근해서 GetLocationAtSplinePoint(Index로 각 point위치를 얻을 수 있음)
	- 그 처리를 대신해 줄 BP_PatrolComponent를 만든 것임

	10. GetDestination이 Boolean 반환 값이 있는 이유는 공교롭게 patrol point가 원점(0,0,0)일 때 길이 있는데도 원점인건지 길이 없어서 원점인건지를 알게 해줌


	
*/