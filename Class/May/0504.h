#pragma once
/*
	1. AI가 무장하는 동안 인지 밖으로 나가면 바로 target을 잃어버리는 로직 수정중에
	- AIPerception Component가 인지를 얻거나 잃었을 때 호출되는 이벤트가 3개 있고(호출시점은 같음)
	- Stimulus 구조체가 가진 정보중에 AIPerception에서 세팅해놓은 <최대 수명>을 활용하여 로직을 작성하려고 했으나 이벤트에서 나오는 출력 값 말고는 이 값을 끌어 쓸 수 있는 방법이 없음
	- Age : Stimulus를 분해 값 중 <최대 수명>에 대해 인지를 잃은 순간부터 시간을 재는 거고
	- Expiration Age : <최대 수명> 그 자체 -> 내 생각에 그냥 이 값을 SetTimerByEvent로 활용하는 게 좋을 듯

	2. GetKnownPerceivedActors와 GetCurrentlyPerceivedActors의 차이는
	- GetKnownPerceivedActors : <최대 수명>의 시간까지 지난 Actor들
	- GetCurrentlyePerceivedActors : <최대 수명>과 상관없이 인지가 된 Actor들 ( Succesfully Sensed가 false로 나가지 않은 애들 )

	3. BT에 버그(?)가 있는데
	- Root 바로 밑을 끊어도 정상 실행 됨

	4. AIPerception Component를 활용함에 있어서 <이벤트>만을 활용하기엔 부족함이 있음
	- GetKnownPerceivedActors나 GetCurrentlyPerceivedActors 등 AI 관련 함수들 잘 조합해서 로직 짜기로

	5. Enemy의 최상 클래스에서 BTAsset을 관리하고 거기서 RunBehaviorTree를 해주고 자식에선 BTAsset만 다른 값들을 장착해주면 관리가 편함
	- GetAIController는 Self 혹은 누구의 컨트롤러인지 알려줘야 함(valid 체크는 센스)

	6. 캠 쉐이크 부모는 <MatineeCameraShake> 사용
	- 진동을 얼마나 줄지(BlendIn, BlendOut도 있음 -> 피격 시 효과의 경우는 BlendIn, BlendOut은 효과가 별로라서 0)
	- Rotation에 대해 Location에 대해 FOV에 대해서도 Oscillation을 줄 수 있음
	- 각각 x,y,z에 대해 진폭을 얼마나 주기를 얼마나 할지 줄 수 있고
	- sin 파형 혹은 Perlin Noise 파형으로 줄 수도 있음 -> 파형의 어느 지점부터 시작할 지에 대한 offset도 줄 수 있음(random 혹은 0)

*/