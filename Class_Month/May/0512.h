#pragma once
/*
	1. Fireball이 Damage를 ApplyDamage로 1번, ApplyRadialDamage로 2번 주는 방식이기 때문에 Destroy 관련 함수에서 문제가 생길 수 있음
	- AI인지를 끄기 위해 Enemy에서 DestroyComponent 했던 부분이 2번 들어오기 때문에 문제가 생김
	- Damage를 받기 전에 AnyDamage에서 IsState가 Died가 아닐 때 흐름에 들어올 수 있도록 처리함
	- 포폴할 때 OverlappingActors로 처리한 부분이 있었는데 그런 함수를 쓸 땐 문제가 생길 수 있었음

	2. 원거리 Enemy에게 일정거리 이상 접근 시 플레이어의 뒤로 Enemy가 Teleport하기 위해
	- EQS_GetDestination을 만들고
	- Point:Circle을 깔고 Dot으로 처리를 하면 됨

	- Point:Circle은 원 둘레에서 몇 개의 point를 깔지 혹은 거리 몇 마다 깔지를 둘 중 선택해서 사용하면 됨
	- Point:Circle 아이템들은 플레이어 주위에 깔 것이기 때문에 추가적인 클래스를 만들어주어야 함(플레이어를 반환해주는)(EQC)

	- Dot은 LineA와 LineB에 대해 Dot을 하는 건데
	- Rotation으로 주게 되면 그 Context의 방향을 Line으로 쓰는 것이고 Point로 쓰면 점 2개에 대해 뺄셈을 한 벡터를 Line으로 쓴다는 뜻
	
	- 플레이어가 보고 있는 방향과 플레이어로부터 아이템이 얼마나 떨어져있는지를 구하기 위해
	- EQC_Target을 만들고
	- ProvideSingleActor를 오버라이드해서 블랙보드에서 target으로 잡혀있을 player를 리턴해줌

	- Dot에서 cos값만 중요함 -> 내적 시 사용한 2 선분의 길이는 1로 처리 됨
	- 플레이어의 뒤통수라는 건 결국 Dot했을 때 -1에 가까운 값들임

	- Filter로 0보다 큰 값들은 걸러주고
	- Linear -> InverseLinear로 바꿔 줌(값이 클 수록 점수가 커지는 것에 대해 0보다는 -1이 점수가 더 커야하므로)
	
	- Dot2D로 바꾸거나 RelativeToScore로 바꾸는 건 센스 껏

	- 위에 대로만 하면 단 하나의 맨 뒤통수가 최고값을 얻는데 다양성을 주기 위해 BT에서 RunEQSQuery에 대해 상위 25중에 랜덤으로 값을 가지게 함

	3. EQSQuery 디버깅 시 매 틱마다 반영이 안 되는 것처럼 보이지만 실제로 EQSQuery가 BT상에서 흐름에 들어올 때마다 최고점의 아이템을 골라내긴 하지만
	원활한 디버깅을 위해 누가 위너인지에 대한 이미지로 보여지는 반영 자체는 늦어짐(실제 반영은 계속 됨)

	4. 거리 조절에 대해 데코레이터로 간단하게 처리할 수 있었는데
	- 500거리보단 밑에 있을 땐 텔포, 2000거리 안에 있을 땐 fireball을 던져야 하는데
	- IsAtLocation 데코레이터로 간단하게 처리 가능하고
	- InverseContition으로 가까울 때일지 멀때 일지에 대한 결과를 반전할 수 있음

	- 데코레이터를 여러개 붙이다보면 복잡해 보일 수 있는데
	- 데코레이터 노드 중 <컴포짓>이라는 노드로 합쳐서 사용할 수 있음

	- 500이상 2000이하 등 이런 로직을 컴포짓으로 한 번에 처리도 가능하지만
	- 다른 노드에 붙이고 처리 순서를 바꾸는 등으로 같은 로직이 처리 가능하므로
	- ai다룰 땐 이런 흐름에 대한 고민을 좀 해봐야 할 듯
	- 사실 컴포짓으로 처리하면 2000거리를 넘어가도 플레이어한테 텔레포트하는 의도치 않은 상황이 생길 수 있으니 이런 부분을 캐치해야 함

	5. 텔레포트 후 fireball로 스왑을 해야 하는데
	- 수업에서 짜놨던 스킬 스왑하는 task는 bool값으로 switch가 가능한지를 BT노드에서 체크해서 사용하기 때문에
	- 기존 fireball 던지던 흐름에선 switch allowed가 false인 노드가 필요함
	- 그렇기 때문에 switch allowed가 true인 task를 teleport하는 흐름에서 실행해줌

	6. fireball과 마찬가지로 teleport도 enemy가 수행할 땐 마우스로 위치를 지정할 수 없기 때문에
	- 마우스로 위치 지정한 것이 실패한 경우에 EQS로 얻어온 블랙보드의 Destination을 텔레포트 위치로 지정해줌
	- EQS의 아이템의 위치로 순간이동 하는 것이기 때문에 사실 캐릭터가 땅 속에 파묻히는 위치이지만 에디터에서 그런 부분은 알아서 처리해줌
	기존 Teleport는 이런 오차에 대해 NormalVector에 일정 값을 곱해서 더한 위치를 Destination으로 삼음
*/