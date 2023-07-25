#pragma once
/*
	1. 파쿠르를 하기 위해 obstacle의 z가 중요한 경우가 있고 x 혹은 y가 중요한 경우가 있음
	- FVector를 포함한 구조체를 만들어서
	- 그 값이 0이 아닐 경우 obstacle의 성분과 검사를 진행

	2. 파쿠르 진행을 큰 그림으로 보고 가면
	- 1) 키 입력을 통해 Character의 Parkour()를 호출함 -> Parkour()는 ParkourComp의 BeginParkour()를 호출하는 함수
	- 2) BeginParkour()는 파쿠르가 가능한 상황인지를 검사하는데
	- 3) 배꼽, 왼손, 오른손 즈음에서 나오는 LineTrace에 Obstacle이 모두 닿아야 하고
	- 4) 그 모든 LineTrace들이 AcceptableAngle(45도) 보다 작은 각도여야 하고
	- 5) 위 조건을 통과하고 나면 climb을 할지 slide를 할지 일반 높이의 파쿠르를 할지를 정하기 위해 머리, 발 쪽의 LineTrace를 검사하여
	- 6) 머리 쪽 트레이스가 obstacle과 충돌이 있다면 데이터 테이블에서 설정한 파쿠르 모션을 실행하는데
	- 7) 파쿠르 모션이 캐릭터가 Obstacle과 유효한 거리에 있는지 DistMin, DistMax를 검사하고(데이터 테이블의 값과 라인트레이스의 결과를 대조하는 것)
	- 8) 데이터 테이블이 가지고 있는 정보 중 obstacle이 580 +- 10 의 오차 범위 안 쪽에 있어야만 climb하는 파쿠르를 할 수 있음
	- 9) 마찬가지로 slide는 climb은 아니지만 아래 쪽 LineTrace가 충돌이 없고
	- 10) DistMin, DistMax를 충족하며 Obstacle과 바닥과의 거리가 충분한지를 검사하여 slide를 실행함
	- 11) Climb, Slide가 아니면 일반 파쿠르 검사를 진행하고 마찬가지로 DistMin, DistMax, Obstacle의 x,y,z 중 일치하는가를 검사하여 파쿠르 진행

	- 움직임 자체를 만들어진 애니메이션만큼 움직이게 하고자 Root Motion을 사용한 몽타주를 재생하게 되는데

	- Climb의 경우 캐릭터의 z값이 변화하는 것이기 때문에 CharacterMovemonetComponent에서 Mode를 Fly모드로 바꿔주어야 하고(Walk Mode의 경우 Z값이 변하는 RootMotion 애니메이션 사용해봐야 제자리에서 동작함)
	- 일반 파쿠르의 경우 Root 본은 바닥에 붙어 질질 끌려오는 애니메이션이기 때문에 캡슐과 Obstacle간의 충돌이 일어나지 않게끔 하여 진행하게 됨
	- Slide의 경우도 마찬가지로 캐릭터의 Capsule과 장애물의 충돌이 안 일어나는 방식을 사용해야 할 것임

	3. 같은 일반 파쿠르여도 진입 거리에 따라 다른 모션이 나오게끔 만들어놨는데
	- LineTrace 거리가 500이고
	- 진입 거리에 따라 0 - 80 , 80 - 160, 160 - 240, 240 - 320 같은 느낌으로 분할을 하여 파쿠르를 가능하게 끔 해놨음
	- 무슨 뜻이냐면 Obstacle과 캐릭터와의 거리가 500보다 가까우면 파쿠르의 일정 조건을 만족한 것이고
	- 320보다도 가까우면 특정 파쿠르에 몽타주의 조건을 만족하게 된 것

	4. Root Motion이 적용된 애니메이션을 활용하려면 캐릭터의 콜리전을 끄면 안 됨
	- CollisionEnable(false);를 하게 되면 RootMotion이 적용되지 않음
	- 결이 비슷한 예로 위에서도 z 가 있는 RootMotion을 사용하기 위해선 CharacterMovementComponent의 mode를 fly로 바꿨어야 했는데
	- 그렇기 때문에 Root Motion을 적용하려면 캐릭터의 피직스까지 세팅을 잘 해줘야 함

	5. 추가로 처리한 내용은
	- AnimInstance의 MontageEnded 델리게이트에 몽타주 끝났을 때 처리를 위한 함수를 바인드 해줬고
	- 바인드한 이 함수는 콜리전 껐다 켠다거나 MovementMode를 바꾼다거나 ParkourType(BeginParkour()의 진입을 막는, 혹은 지금 진행중인 파쿠르가 뭔지를 알려주는 변수)
	을 비워줌
*/