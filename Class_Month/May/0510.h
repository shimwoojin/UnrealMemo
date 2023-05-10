#pragma once
/*
	1. EQS의 ScoringFactor는 다중 test에서 어떤 test에 중요도를 더 줄지에 필요할 수 있음

	2. Clamp와 NormalizationType(RelativeToScores)가 같이 사용됐을 때 Clamp의 Min으로 설정한 값부터가 0이 아닐 수가 있음
	- Min이 100이여도 제일 가까운 아이템이 120이라면 120이 0점으로 채점될 수 있다는 뜻

	3. 개인적으로 이 기능을 도망가는데 써야한다면 Linear 계열(Distance가 멀수록 채점 점수가 높아지는 경우) 중에서 골라놓고 Clamp Min으로 사용하면 괜찮을 듯
	- 혹은 반대로 Inverse Linear 계열을 사용하고 Clamp Max만 걸어놓고 쓰면 최적화에 도움될 듯

	4. Querier와 Item 간에 서로 Trace를 쏴서 그 중간에 걸리는 게 있는지 없는지로 점수를 메기는 Test도 있는데
	- Querier : BT가 돌리는 주체
	- Item : EQS에 의해 생겨난 초록 덩어리들(디버깅 시 보이는)

	- Querier -> Item으로 Trace를 쏠지 Item -> Querier로 Trace를 쏠지를 정할 수 있긴한데 (사실 의미가 있나 싶고) 이거 말고 중요한 옵션 중에
	- <Bool 일치>라는 옵션이 있음 -> 이게 Trace가 막히면 점수가 1점일지 0점일지를 정하는 옵션(Bool일치 체크를 풀어야 막힌 Item이 0점 처리 됨) - Hit가 나면 True임(Bool일치가 true면 Hit가 나면 1점)
	
	- Trace가 Hit일때만 되게끔 하는게 있었는데 체크를 풀고나서 overlap으로 설정해놓은 대상과 Trace가 안 됐음(예상과 다름)(OnlyBlockingHit)(뭔가 모르는 게 있는 듯)

	- Trace를 어느 위치에서 쏠지, Item의 Z Offset을 얼마나 줄지도 있음(DataBinding이 가능하고 여기서 Parameter 설정이 되는데 이  EQS에 접근하는 법만 알면 외부에서 세팅 가능할 듯)

	5. Enemy가 죽고 나서 죽는 몽타주를 재생하고 누운 상태로 나를 향해 Rotate하는데
	- 이게 왜 이러냐면 죽는 몽타주가 재생중에도 Target은 나(Player)로 잡혀 있고 BT의 Rotate가 실행되기 때문임
	- Target을 풀어주면 되는건데
	- Component의 Deactivate 함수로는 인지가 안 풀렸음
	- AIPerception의 SetSenseEnabled에서 시각의 Enabled를 false로 하겠다라는 방식은 적용은 됨(하지만 이게 Enemy쪽이기 때문에 상속받을 애들이 다른 감각을 가질 수 있기 때문에 범용적이지 않음)
	- 결국은 Component를 파괴하는 방식으로 작성함(Destroy Component)

	6. 기존에 처리안했던 부분인데 죽으면 Spawn후 몸에 붙여놨던 무기, 스킬들을 다 지워줌
	- AnyDamage에서 Died로 상태가 변해 DestroyActor가 되기 직전에 지워 줌

	7. VisualStudio 프로파일링 방법
	- 디버그 - 성능 프로파일러 - CPU사용량, GPU사용량 체크 -> 게임 플레이 -> wait... -> 결과 분석

		7.1) 확인 가능한 정보들
		- 시간마다 프레임이 얼마나 나오는지
		- 어떤 함수가 전체 게임 시간 중 부하가 많았는지(%로 표시)
		- 특정 함수 안에서 불린 함수들에 대해서도 부하가 얼마나 걸렸는지
		
		7.2) 그래픽 디버깅 ( 디버그 - 그래픽 디버그 시작 )
		- 한 프레임에 대해 어떤 Draw콜이 있었고
		- 각 Draw콜이 pipeline에서 어떻게 그래픽이 만들어졌는지(그림으로 확인 가능)(파이프라인 단계 창을 켜야 함)
		- Constant Buffer, VertexBuffer 등 GPU로 넘어가는 버퍼들도 확인 가능한 듯

	8. 결국 생각을 더 해보니 내 게임의 지연의 원인은 몬스터가 많아졌을 때 돌아가는 Behavior Tree가 Tick으로 돌아가는 것이 원인인 것 같음
	- BT 경량화
	- 혹은 몬스터 마릿수 제한
*/