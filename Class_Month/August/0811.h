#pragma once
/*
	1. SetupAttacment에 소켓 이름을 받을 수 없는 것이 아님
	- 생성자에서 처리하기엔 블프에서 설정할 변수에 대해 모르는 것 뿐임
	
	2. 애니메이션 대량 편집 가능
	- 다수 클릭하고 우클릭 - 에셋 액션 - 프로퍼티 매트릭스를 통한 대량 편집

	3. cpp에서 타임라인 쓰기
	- UTimelineComponent, UCurveFloat, FOnTimelineFloat
	- float용 curve 에셋을 만들어서 UCurveFloat에 물려준 걸 기반으로 작업 -> t : 0일 때 0, t : 1일 때 1인데
	이 값을 PlayRate이나 Curve의 y축 값에 대해 변형을 주어 활용 가능
	- FOnTimelineFloat에 float을 인자로 받는 함수를 바인드 해주고 UCurveFloat과 FOnTimeineFloat을 사용한 타임라인을 쓰겠다는 의미로 AddInterpFloat()으로 추가
*/