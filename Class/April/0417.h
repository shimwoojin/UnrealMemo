#pragma once
/*
	1. SpringArm::TargetOffset, SpringArm::SocketOffset
	- TargetOffset : RootComponent의 WorldLocation을 기준으로 World 상에서의 x,y,z를 더한 위치
	- SocketOffset : RootComponent의 WorldLocation을 기준으로 Root의 Local 상에서의 x,y,z를 더한 위치

	- 수업에서 Player를 world에 배치한 다음에 rotation을 살짝 돌려서 테스트했을 땐 티가 잘 안났는데
	- rotation.x를 90 회전하거나 rotation.y를 -90 회전 후 targetoffset.z랑 socketoff.z를 바꿔보면 어떻게 다른지 알 수 있음

	2. WidgetComponent가 갖고 있는 BeginOverlap, EndOverlap, Hit 이벤트 등은 어딘가에서 상속 받은 것이고 기능이 없는 것 같음(확실하지 않음)

	3. Timeline의 Play, Reverse는 동영상 기준으로 pause 해놓은 부분부터 다시 시작하는 느낌이고 PlayFromStart, ReverseFromEnd는 무조건 시작 혹은 끝에서 부터 시작하는 핀
	- Play, Reverse가 Stop핀에 의해 중간에 정지되는 경우가 있는데 정지된 시점부터 다시 Play 혹은 Reverse를 할 수 있는 것

	4. 포폴 기획안 피드백 중에

	레벨 전환(+CameraFade): 
	- 레벨 전환 관련해서 OpenLevelByName 말고 OpenLevelByObjectReference을 통해 넘어가는 게 좋다고 하심(문자열 의존성 줄이기)
	- 레벨이 전환되어서 PlayerStart에서 생성되는 내 pawn은 그 전 레벨의 정보가 모두 초기화 되는 것이고
	- 그렇기 때문에 간단하게 쓸 수 있는 것이 GameInstance임(프로젝트 세팅에서 내가 만든 GameInstanceClass 설정해줘야 함)
	- GameInstance란 싱글턴으로서 존재하고 전역변수를 담아두는 공간으로서 활용할 수 있음(Save & Load 대신 간단하게 처리하려면 고려해볼만 함, 프로젝트 규모가 커지면 곤란)
	- 레벨 전환 간 탁 하고 카메라가 옮겨지는 것보단 scene이 fade되면서 openlevel에 필요한 시간도 벌고 부드러운 화면전환도 가능하게 해줄 수 있음
	- 이 때 사용한 함수가 StartCameraFade였고 FromAlpha가 0, ToAlpha가 1이면 화면이 어두워지는 효과, FromAlpha가 1, ToAlpha가 0이면 밝아지는 효과를 줄 수 있고
	- Duration만큼 Delay를 걸어준 다음 OpenLevel을 해주면 됨
	- open된 level쪽에선 레벨 블프에서 beginplay에서 어두웠다가 밝아지는 효과를 주면 됨(level 블프마다 이 작업을 해야하는 게 단점)

	Spawner :
	- Map 사용하지 말고 Class 디폴트를 얻어와서 직접 변수에 접근 가능함(spawn할 몬스터의 클래스에 접근해서 미리 지정해 둔 얼마나 자주 spawn할지의 float변수(SpawnTime)를 얻어 옴)

	무기의 파티클 위치 : 
	- 바꿀 필요 있음

	Homing하는 스킬 :
	- GetAllActorsWithTag -> SphereOerlapActors 함수로 대체(전자의 함수는 비싸다고 함)
*/