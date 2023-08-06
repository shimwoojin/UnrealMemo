#pragma once
/*
	1. 표시 - 개발자 - 본
	- 게임 플레이 중에 본 확인 가능

	2. IK를 다룸에 있어 Effector와 Joint Target을 알아야 하는데
	- Effector : IK를 적용할 본에게 실제 적용할 위치 혹은 회전
	- Joint Target : IK를 적용할 본의 부모가 어디 쯤으로 와야하는지를 정하는 값(이 값을 잘못 설정하면 무릎이 꺾이면 안 될 방향으로 꺾인다거나 할 수 있음)

	- Effector는 미리 계산된 가상 본을 BoneSpace로 넘겨주고
	JointTarget은 적용할 본의 부모의 BoneSpace 정도를 넘겨주면 된다

	- 이 때 우리는 IK가 foot에 적용되지만 무릎에 대해서도 가상 본을 만들었는데 세밀한 조종을 할 경우 무릎의 위치도 조종해야 하는 경우가 있기 때문에
	무릎(부모 본)에 대해서도 가상 본은 만들어 두어 적용하는 것이 확장성 면에서 나아 보임

	3. 우리가 구성한 IK를 만들고 나서의 관점에서 추상적으로 설명하면
	- IK를 적용해서 땅의 경사와 높이에 맞게 발의 위치를 조종하고
	- 이렇게 됐을 때 메쉬가 늘어난다는 설정을 안하게 되면 원하는 결과를 얻을 수 없고(늘어난다고 하는 것도 본 사이 간격에 넓어져서 원하는 결과는 아님)
	- IK 적용하기 위해 왼발, 오른발의 위치 중 낮은 발만큼 골반을 낮춰주고
	- 위치가 조정될 왼발, 오른발에 대해서도 낮아진 골반만큼 빼주어야 함

	- IK 적용 후 실제 캡슐보다 스켈레탈 메쉬 자체는 경사면에서 낮은 위치에 있을 수 있음

	- 내가 이해하기엔 높은 발만 위치가 조정된 것으로 이해가 됨 -> 골반은 낮아지고 낮아진 골반만큼 밑에 발은 다시 빼주니깐 +- 0 이여서 밑에 발은 위치 변화 없음

	4. 라인트레이스로 땅의 위치만큼 조정된 가상본 혹은 IK 본이 있고 적용할 발이 있다면 <레그IK> 노드로 간단하게 처리할 수도 있음
	- 마찬가지로 캡슐이 경사에 걸치면 뒷발이 IK 적용이 안 되어서 골반 높이를 낮추는 로직 자체는 유지해주어야 함

	5. 애니메이션 레이어 전용 인터페이스가 있음
	- Instance Class를 변경하여 다른 애님 블프의 애님 레이어를 실행시킬 수도 있음(디테일 탭 안 보면 어떻게 동작하고 있는지 해석이 안 될듯;)
*/