#pragma once
/*
	1. AIPerception Component의 Touch Config는 모바일의 Touch가 아니라 실제 오브젝트 간 닿았는지에 대한 인지임
	- CPP에 가서 더 알아보기로

	2. Hearing Config의 실제 범위는 Hearing Range 1가지임(LOS Hearing Range는 디버깅 시 범위만 표시해줌, 기능이 없음)
	
	3. Sense Config의 EnableStarted를 꺼도 인지 자체는 꺼지더라도 디버깅 시 범위 표시까지 꺼지지는 않음

	4. 몽타주에 PlaySound Notify 배치하여 원하는 타이밍에 음원파일 재생 가능
	- 하지만 우리가 듣는 소리와 별개로 AI가 인지하기 위해선 '소리가 난다'라는 다른 함수를 호출하여야 인지 가능함(함수 이름 : Report Noise Event)
	- Report Noise Event의 Max Range가 0이 라는 것은 범위가 무제한 이라는 뜻(World 어디서든 '소리를 들을 수 있다'라는 뜻)

	5. 실제 음원파일을 재생하는 함수 종류가 몇 가지 있는데(간단한 함수의 설명은 생략)
	- PlaySound2D
	- PlaySoundAtLocation
	- PlaySoundAttached : Component에 붙여 그 위치에서 소리나게 끔 할 수 있음(Attach Point Name(Name 타입) 인자도 받는데)
	(사실 궁금한 점은 Name을 받아서 그 위치에서 동작 시켜주는 것 중에 아는 건 SkeletalMesh의 Socket 정도 밖에 없는데 다른 Scene Component에도 Name으로
	위치를 특정할 수 있는게 있는가 궁금함)

	6. AIPerception이 인지한 대상은 이벤트를 통해 확인할 수 있음(OnTargetPerceptionUpdated, OnPerceptionUpdated, OnTargetPercpetionInfoUpdated)
	- 인지를 얻거나 인지를 잃었을 때 이벤트가 발생하는 점은 비슷하나 넘어오는 정보가 다름(기본적으로 OnTargetPercetpionUpdated가 인지된 Actor를 반환함)
	- 어느 이벤트든 Stimulus(자극) 구조체가 넘어오는데 break하여 내게 필요한 정보만 사용할 수 있음(유용한 핀 중에 Successfully Sensed의 True or False 여부로
	인지를 얻은지 잃은지를 구분할 수 있음)

	7. AIPerception에서 여러 Sense Config를 사용하여 구성하고자 한다면
	- AIPerception Component를 시각용, 청각용, 팀 전용 등으로 구분하여 Component당 감각 하나씩 맡아서 처리하는 간단하고 무식한 방법이 있음
	- GetCurrentlyPercievedActors 노드를 통해 어떤 감각을 통해 인지 된 Actors 인지를 배열로 반환하기 때문에 이 노드를 이용하면 어떤 감각에 걸린지를 알 수 있음
	- GetKnownPercievedActors를 통해 인지가 한 번이라도 된 actors를 전부 얻어 올 수도 있고
	- GetPercivedActors는 Deprecated된 노드이므로 사용하지 않기로

	- GetKnownPercievedActor를 통해 인지된 적이 있는 Actors를 전부 구해올 수 있는 것으로 보아 게임 시간이 길어지면 내부적으로 메모리가 쌓이지 않을까 생각이 듬

	8. RotateToFaceBBEntry Task는 Rotation을 Set으로 처리하는 방식
	- 이 노드를 쓰려면 UseControllerRatationYaw 옵션을 켜줘야 함
	- 이 노드의 Detatil에 Precision 옵션이 몇 도 단위로 돌릴지 ? 인 듯

	9. 부드러운 회전을 처리해보기 위해 RInterpTo노드를 사용했는데
	- 회전시킬 Actor의 기존 Rotation을 Current에 받고 Target을 보기 위해 어떤 Rotation을 가져야 하는지를 계산해서 Target에 넣어주고 어떤 속도로 돌지를 float으로 넘겨주고
	돌릴 대상의 Rotation을 Set해주면 되는 듯

	10. 시각과 청각 등 2개의 인지를 같이 쓸 때는 감각 구분 없이 인지를 잃고와 얻고로 Target을 잡기 때문에 다른 감각이 Target을 None으로 만들거나 할 수 있기 때문에 주의

	11. Simple Parallel의 Main Task가 바로 끝나는 노드라면 Sub Task가 끝날 때까지 기다려준다는 옵션을 설정해도 애초에 SubTask까지 흐름이 가버리질 못하는 듯

*/