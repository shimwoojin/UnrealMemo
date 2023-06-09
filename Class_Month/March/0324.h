#pragma once
/*
	
	1. BP_Weapon이 Map으로 상태, 몽타주 정보를 갖고 있었는데 BP_Weapon은 추상클래스이기 때문에 구체화한 클래스인 BP_Sword에서
	실제 정보를 갖고 있게 됨
	
	2. BlendSpace를 칼 든 버전으로 새로 만들었는데 Speed와 Direction을 각각 y,x축을 하여서 Idle에 대해서 8개, 걷기에 대해서 8개,
	뛰기에 대해서 8개를 블렌드 스페이스에 알맞게 올려줌
	- Direction은 언리얼의 yaw rotation이 왼쪽으로 -180, 오른쪽으로 180인 것을 활용
	- snap to grid 옵션을 끄면 자유롭게 배치 가능

	3. 만든 블렌드 스페이스를 ABP_Character에 가서 스테이트 머신에서 연결해주고 트랜지션 룰은 bArmed인 bool변수가 켜지고 꺼지고로 전환
	- bArmed의 값을 매 프레임 업데이트 시켜주는데 ABP_Character의 이벤트 그래프에서 틱마다 업데이트하는 이벤트에서
	TryGetPawnOwner에서 IsArmed로 핀을 뽑아오는데 이게 가능했던 것은 IsArmed가 BP_Character에서 정의한 인터페이스이기 때문

	4. 블렌드 스페이스가 애니메이션을 다르게 출력하는 변수로 Speed와 Direction을 줬는데 Speed는 CharacterMovement에서 쉽게 얻어올 수 있었지만
	Direction은 우리가 계산해서 얻어와야 하는데 일단 ABP_Character의 이벤트 그래프에서 매틱마다 계산해야하는 게 맞음
	- Calculate Direction이라는 함수가 있고
	- BaseRotation에는 캐릭터의 Rotation이 아니라 컨트롤러의 Rotation을 줬음(캐릭터는 컨트롤러의 회전을 따라가기 때문)
	- 회전은 Z회전만 줘야함

	5. 검을 뽑을 때 미끄러지듯이 움직이면서 검 뽑는 모션을 고쳐보고자 함
	- 몽타주 슬롯을 UpperBody, FullBody 2개로 만들어서 애니메이션 용도 별로 슬롯 지정

	6. LayeredBlendPerBone 본마다레이어를블렌딩합니다 노드를 사용해서 UpperBody에 대해 사용해줄건데
	- 어떤 Bone을 기준으로 블렌딩을 해줄건지 정해야하는데 스켈레톤 트리를 보면
	- 골반과 상체로 나뉘고 상체에서 또 여러갈래로 나뉘는데 아무튼 spine_01을 기준으로 했음

	7. Locomotion과 UpperBody슬롯을 Spine_01 Bone을 기준으로 블렌딩을 처리하는데 이 때 문제가 있음
	- UpperBody슬롯에 있는 몽타주는 단발성이기 때문에 기본 동작이 있어야 했고
	- 그래서 Locomotion에 대해 Cache를 만들어주어서 UpperBody의 기본 동작으로 줬음

	8. 이렇게까지 하고 나면 걷거나 뛰면서 칼을 뽑고 집어넣는 것까지 할 수 있었는데
	- 검을 뽑거나 넣는 진행 동작중에 구르거나 백스텝을 해버리면 다시 할 수 없는 버그가 있었는데
	- 이것의 이유는 검을 뽑거나 집어넣는 동작이 일단 Idle -> Arming으로 전환되고나서 진행이 되고
	- Arming의 몽타주가 다 끝나고 나면 다시 Idle로 바뀌고
	- 기본적으로 검을 뽑거나 넣는 건 Idle상태가 전제가 되어있기 때문에 그랬던 것
	- 이에 대한 해결책으로 구르거나 백스텝도 Idle에서 시작할 수 있게 바꿔줘야 함
	- 몽타주 재생 중에 방해받을 때에 대한 처리를 할 수 있는 노드도 있었지만 근본적으로 그게 해결책은 아님
	- 근본적인 해결책이 아닌 이유는 구르기가 장비보다 우선순위가 높다면 그렇게 하는게 맞을 수 있지만 우리의 동작은
	우선순위가 동등하고 독립적이기 때문에 이것은 안 됨

	9. Dodge쪽을 바꿔주는데 Idle일때만 동작할 수 있고 Idle->Dodging->Idle 이런식으로 상태를 변경시키면서 진행되어야 함
	- Dodge자체 로직을 좀 바꾸는데 아무키도 안 눌리면 백스텝, 방향키가 같이 눌리면 그 방향으로 구르기

	10. 노드를 재구성하다보니 Dodging도 Roll과 BackStep에 대해서 데이터에셋을 만들고 이것의 인덱스를 구하는데 있어서
	전에 썼던 것과 같은 로직을 쓰다보니 일단 이 로직에 대해서 공통으로 묶어주고 가야 함
	- 함수 라이브러리를 만들어주었고
	- 이것은 전역함수를 만든 것
	- 매크로와의 차이는 매크로는 범위 지정이 있었지만 얘는 없었음

	11. DataAsset의 GetMontageData에 대해서 함수 라이브러리에 새로 포장해서 새로운 함수 만들어줌

*/