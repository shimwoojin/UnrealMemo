#pragma once
/*
	1. BehaviorTree는 AIController를 대상으로 하는 RunBehaviorTree를 통해 실행시킬 수 있음
	- BP_EnemyController에서 BeginPlay에서 사용할 BT를 지정해줬음

	2. BT의 루트는 한 종류의 노드만 가질 수 있음
	- BT는 기본적으로 전위 순회를 함(어떤 순서로 실행될지 노드의 우측 상단에 적혀있음, -1은 실행하지 않을 노드라는 뜻(Invalid))
	전위 순회는 노드 좌측에 선 하나 긋고 루트에서부터 좌측으로 내려오는 식으로 야메로 순서를 알아볼 수 있음(중위는 중앙 아래, 후위는 오른쪽에)

	3. BT의 Composites는 3종류가 있음
	- Selector : 자식 노드가 하나라도 성공하면 성공임 -> 태스크를 끝냄(if, else if, else의 느낌, 성공은 or 연산 취급)
	- Sequence : 자식 노드가 전부 성공해야 성공임
	- SimpleParallel : 보라색에서 뻗어나가는 task가 main(좌측 노드), 검은색(오른쪽)에서 뻗어나가는 task가 main과 같이 실행 될 sub task임
	노드 디테일에 FinishMode가 있어서 Main이 끝나면 sub를 같이 끌낼 지 Sub도 기다려줄지 정하는 옵션이 있음(자주 쓰는 노드는 아님)

	- Selector 밑에 Sequence, Sequence 밑에 Move To, Wait가 있다면
	Sequence가 MoveTo, Wait를 둘다 성공 시켜야 Sequence가 성공이고 Sequence가 성공이기 때문에 Selector도 성공이고 태스크를 종료함

	4. MoveTo 노드를 봤을 때 대상을 정해줘야 하는데 위치 벡터 혹은 Actor를 지정해주어야 하고 결국 변수를 가져야 한다는 것이고
	BT의 변수는 BlackBoard(BB)를 설정해 줄 수 있음
	- Root 노드의 디테일에서 BB를 장착해 줄 수 있음

	5. BB를 만드는 방법은 1) 콘텐츠 브라우저 우클릭 2) BT내에서 상단 탭에 새 블랙보드 3) 루드 노드에서 생성 가능
	- 사실 BT에 필요한 대부분의 노드가 BT 상단 탭에서 가능

	6. BB에서 특이 사항 3가지 정도가 있는데
	- 디테일에 Instance Synced는 블랙보드끼리 같은 값을 갖게 됨(정적 멤버 변수의 느낌)
	- UObject의 자식 클래스들은 Object 타입을 주고 밑에서 다시 세부 설정하게 만들어져 있음
	- Parent BT도 줄 수 있는데 Parent에서 작성한 키에 추가로 더 만들어서 쓸 수 있음(상속 가능)

	7. MoveTo에 어디로 이동할지 정해주는 방법은 여러가지가 있는데 그 중 Service로 처리해 봄(상단 탭 -> 새 서비스 혹은 콘텐츠 브라우저에서 생성 가능)
	- 새 클래스를 만들면 오버라이드를 뭐 할 수 있나 확인하자
	- Service의 오버라이더블은 8가지지만 크게 4가지로 봤을 때 Activation, Deactivation, Search, Tick 정도로 볼 수 있음
	- ReceiveActivationAI는 service를 달아준 노드가 활성화 되면 실행된다고 보면 됨
	- Service에서 변수로 <Black Board Key Selector 구조체>를 만들어서 <인스턴스 편집 가능>을 주면 MoveTo 노드 혹은 다른 task 노드에서 어떤 BB에 그 변수를 할당해 줄지 설정 가능함

	8. Service의 클래스 디폴트에서 Tick에 대해 Interval, RandomDeviation을 설정하여서 tick을 랜덤한 주기로 할 수 있게 해줄 수 있음
	
	9. 항상 AIController쪽에선 RunBehaviorTree 후 어떤 BT 쓸지 정하고 Enemy에선 어떤 AIController쓸지 까먹지 않기
	+ Nav Mesh Bound Volume가 월드에 배치되어 있어야 <길찾기> 가능 -> P를 누르면 갈 수 있는 길이 보이고 Volume의 Z Scale도 중요함
	- Nav Mesh Bound Volume의 Z가 충분히 크지 않다면 계단 같은 지형에선 AI들이 바보가 될 수 있음
	- 도착지에 대해서만 volume이 감싸는 게 아니라 출발점에서부터 도착점까지 전부 volume이 커버해야 길 찾을 수 있는 듯

	10. RunTime에 어떤 노드로 들어가고 있는지 확인해 볼 수 있음
	- 게임 실행 중에 BT내부에서 AIController마다 어떤 내용으로 진행되는지 확인 가능

	11. MoveTo의 디테일에 Acceptable Radius는 오차 허용 범위(그 위치 +- 오차 허용 범위 안에 들면 도착했다고 취급)

	12. RunTime에 AI가 잘 작동하는지 확인하는 방법도 있는데
	- '(작은따옴표)를 누르면 AI Debugging Mode로 들어가는데 우측 숫자 패드의 0,1,2,3,4에서 디테일 옵션 더 볼 수 있음(키 자판 없으면 불가능한 듯)
	- Active Task 확인 가능(배열 인덱스처럼 나오는 건 노드의 우측 상단에 적힌 숫자)

	13. BahaviorTreeTask도 우리가 정의할 수 있는데 (BTT)
	- 오버라이더블에 보면 Abort, Execute, Tick 정도로 볼 수 있음
	- Abort는 후에 알게 되겠지만 Task 노드가 외부요인으로 중단될 때 callback할 내용 적어줄 수 있는 듯
	- BTT는 Excute이벤트가 끝나면 끝나는 게 아니라 <FinishExecute를 실행>해서 성공이든 실패든 알려주어야 task 노드 탈출 가능함
	- 노드 자체가 실행 시간을 길게 가져야 한다면 Tick 같은 이벤트에서 시간을 끌다가 FinishExecute로 끝내는 방식도 가능하단 것(굳이 tick은 아니여도 됨)
*/