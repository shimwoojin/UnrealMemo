#pragma once
/*
	1. BT의 Composite들 중에 Selector는 자식 중에 하나라도 성공하면 흐름 멈추고 Sequence는 자식 중에 하나라도 실패하면 흐름 멈춤
	- 단락 회로 평가(Short Circuit Evaluation)랑 같다고 보면 됨

	- Or 연산에선 하나만 참이면 참이기 때문에 A or B에서 A가 참이라면 B는 참인지 거짓인지 확인조차 안 함
	ex) A or (B+=3) 이라면 A가 참일 때 B는 값이 변하지 않음, A가 false라면 B의 값이 변하겠지
	- 마찬가지로 And 연산에서 A and B에서 A가 거짓이라면 B는 확인하지 않음

	- 대입연산잔의 반환값은 자기 자신임 -> x = y = z = 0; 이 성립하는 이유

	- A or TestFunction()에서 함수가 실행될지 안 될지를 구분하려면 위의 내용을 알아야 함

	2. Task를 하나 구성해보던 중에 Execute AI 이벤트에서 조종하는 pawn에 Dodge를 인터페이스로 불러서 실행시켜주고 바로 FinishExecute를 성공처리하면
	문제가 있는데
	- 구르는 중에 다음 task로 넘어가버리기 때문에 문제가 생길 수 있음
	- 구르는 동작이 확실히 끝날 때 놓아주어야 함 -> 어떻게 ? -> state
	- state가 dodging이 아닐 때를 tick에서 검사해서 finishexecute해주면 됨

	3. Task에 <데코레이터>를 달아줄 수 있는데
	- Task가 실행하기 전에 <데코레이터>에 대한 평가를 먼저 진행하고 <데코레이터>가 거짓으로 평가되면 task는 실행하지 않음
	- CoolDown이라는 만들어진 <데코레이터>를 사용했는데 시간을 정해놓고 한 번 실행한 task가 다음 유효시간 전에 노드에 들어오면 false를 반환

	4. <데코레이터> 중 자주 BlackBoard의 값으로 평가를 할 수도 있는데
	- IsSet, IsNotSet으로 값이 설정된 지 안 된지로 평가할 수 있음 -> Actor나 Vector는 이런 식으로 설정하고
	- Enum값을 평가로 사용하게 되면 어떤 타입일 때 true로 평가할지 등 자료형에 따라 평가 내용이 달라짐

	5. service, task, decorator등의 key 설정은 각 클래스에서 <인스턴스 편집 가능>을 주고 BT에서 노드의 디테일에서 개별 설정해야 함

	6. <데코레이터>는 service보다 우선함
	- Root 바로 밑 노드에는 <데코레이터>가 붙을 수는 있으나 <데코레이터>가 무시 됨 -> 색이 거무죽죽해지며 무시 된다고 경고문구 나옴
	- <데코>의 값을 바꾸는 로직이 <서비스>에 있는데 <데코>가 항상 먼저 실행되어 <데코>의 값을 바꿔줄 <서비스>에 도착할 수 없어 BT가 실행할 수 없는 상황을 방지하기 위해

	- <데코레이터>, <Task>, <Service>가 같은 노드에 같이 붙으면 1)데코 2) Service 3) Task 정도의 순인 듯, task가 마지막

	7. EnemyMelee, EnemyRanged로 나누기 위해 BP_Enemy는 abstract로 만들고 새로운 BT 만들어주고 플레이어를 target으로 지정할 object - character를 변수로 지정

	8. 적이 플레이어를 발견하면 칼을 뽑게 하기 위해 BTT_Arm 작성
	- IsArmed가 false라면 WeaponA 인터페이스 함수를 실행하여 칼을 뽑도록
	- task가 끝나는 시점을 정확히 지정해주기 위해 tick에서 arming이 false일 때 task가 끝나도록 finishexecute - true로

	- 이런 작업할 때 주의할 점이 이 노드를 탈출하지 못하는 상황을 방지해야하는데 Arming이 false일 때가 탈출 조건인 지금은 문제가 없었음
	- 아마 AI 작업하다 보면 이 부분이 굉장히 문제가 많이 생길 듯

	9. 언리얼이 AIPerception Component를 지원해주는데
	- Enemy에 추가하고 BP에선 Hearing이나 Sight정도 사용 가능 ( Damage는 못 쓴다고 하심)
	- AIPerception 블프도 사용자 정의가 가능 -> AIPerception 내의 sense config도 새로 정의해서 AIPerception에 장착해주어야 함(언젠간 시도해보는 걸로)
	SenseConfig의 이벤트 중에 Listener는 AIPerception의 수용자 정도로 생각해야 함(AIPerception의 주인)

	10. SenseConfig 중에 SightConfig를 상세히 알아보면
	- Sight Radius : 시야 범위
	- Lose Sight Radius : 시야 범위에 잡힌 target을 잃어버리기까지의 범위

	ex) Sight Radius는 1000인데 Lose Sight Radius는 10000이라면 한 번 발견되면 텔레포트하지 않는 이상 계속 시야에 잡힌다는 뜻

	- PeripheralVisionHalfAngleDegree : 정면을 중심으로 좌우의 시야각 -> 75라면 정면을 기준으로 좌우 각 75, 총 150도
	- DetectionByAffiliation : 적, 중립, 친구 설정 -> 블프는 다 체크하자, 어차피 의미없음(cpp에서나 가능)
	- AutoSuccessRangeFromLastSeenLocation : 마지막 위치에서부터 원형 반경으로 이 범위까지는 시야에 잡힘
	- PointOfViewBackwardOffset : 적의 시야를 뒤통수부터 시작할 수 있게 해줌 -> springarm 생겨 먹은거 생각하면 될 듯
	- NearClippingRadius : 뒤통수 시야각 조금 깎아내 줌
	- 최대 수명 : 감각을 잊기까지 걸리는 시간(0초라면 안 까먹음)

	- AIDebugging모드 (')로 들어가서 우측 키패드 4를 누르게 되면 perception이 어떻게 이루어 지고 있는지 확인 가능함
	초록 반경 : SightRadius, 빨간 반경 : LoseSightRadius
*/