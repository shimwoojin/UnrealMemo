#pragma once
/*
	1. CameraShake에서 피격 시 설정된 값들을 나열하면
	- 얼마나 ? : 0.25(BlendIn, BlendOut -> 0)
	- Y위치에 대해 진폭 : 5, 주기 : 150
	- Z위치에 대해 진폭 : 5, 주기 : 150

	2. Player의 AnyDamage에서 CameraShake를 처리하는데
	- Player가 소유한 Controller에 접근하고
	- Controller를 PlayerController로 Cast하고(PlayerCameraManager에 접근하기 위해, 그냥 Controller 클래스는 카메라 매니저 없는 듯)
	- PlayerController에서 PlayerCameraManager에 접근해서
	- StartMatineeCameraShake를 호출 함

	- PlayPlace는 Local로 줬음 / World로 준다면 World 좌표 기준으로 y,z가 흔들릴 것(의도한 바가 아님)
	- StopCameraShake는 안해줘도 기간이 끝나면 알아서 종료

	3. StartMatineeCameraShake VS StartCameraShake
	- Matinee가 더 구체화 된 클래스로 return
	- 기능상에 좋은 점이 있다고 하셨기 때문에 StartMatineeCameraShake를 쓰는 게 더 최신이라고 하심
	- 근데 내가 알기로 Matinee는 사장 된 구버전의 유물이고 Sequence가 최신인 것으로 알고 있었는데
	- CameraShake는 Matinee가 더 쓰기 편한 듯
	
	- SequenceCameraShake 블프를 만들어서 확인해봤는데 SequenceSineActor인가 아무튼 그래프가 어떻게 생겼는지를 직접 만들어서 대입해줘야 함(이게 더 직관적일 거 같긴한데 사용법을 모르니 나중에 알아보기로)

	4. 2번에서 Controller를 얻어오는 방식에서 GetPlayerController로 얻어올 수도 있으나 저런 방식으로 처리한 것이 의아했고 GetPlayer계열 함수를 조사하는 게 과제였음
	- 그렇다면 외부에서 GetPlayer계열을 안 쓰고 얻어올 수 있는 방법은 GameInstance에 등록하고 쓰는 것

	5. 원거리 Enemy를 만들기 위해 새롭게 EnemyRanged 만들고 무기는 안 주고 스킬만 2개 새로 물려 줌
	- BT도 원거리용으로 물려 줌

	6. AIPerception에서 문자열로 Target을 잡는 부분에 대해 문자열 의존성을 줄이면 좋다고 하셨는데 그 방법은
	- Enemy에서 Target을 갖고 있고
	- Service에서 Enemy에 접근할 수 있기 때문에 Enemy가 들고 있는 Target을 BT의 Target과 일치시켜주는 작업을 할 수 있음

	7. 루트 밑에는 대체로 Selector

	8. 일단 임시로 작성된 로직이지만 BT 로직을 보면
	- Target이 Set되어 있으면 Target방향으로 돌고 스킬을 장착하고 공격함

	9. 스킬을 장착하는 Task를 만들었는데
	- Tick에서 처리하기 때문에
	- Idle이 False일 때도 Task를 끝내지 않고
	- 어떤 스킬도 활성화가 돼있지 않다면 스킬을 활성화 함
	- 다른 스킬을 활성화 하기 위한 스위치가 켜져 있다면 다른 스킬로 활성화하고
	- 스위치가 꺼져 있다면 Task를 성공으로 종료

	- 스위치 On/Off, 인덱스는 <인스턴스 편집>으로 BT에서 편집

	- 스킬을 장착하는 로직 자체로만 보면 그냥 스킬을 장착하기만 하면 되기 때문에 간단하지만 다른 스킬이 On되어 있을 때의 예외처리 때문에 복잡해보이는 것

	10. <데코레이터>에서 Task가 실행 중이건 말건 중지 시켜버릴수도 있는 기능이 있는데
	- <데코레이터 - 블랙보드>의 FlowControl 탭에서 <관찰자 중단>, <NotifyObserver> 값을 입맛에 맞게 바꿔주면 됨

	10.1) 관찰자 중단
	- None : 아무것도 안함
	- Self : 자기 자신
	- LowerPriority : 지금 실행하는 노드보다 늦게 실행 될 Task들
	- Both : Self와 LowerPriotiry에 대한 Both로 자기 자신도 취소하고 LowerPriority들도 다 취소시킴

	- 어떤 것이 취소가 될지에 대해서 설정하고 나면 색깔로 확인 가능

	10.2) NotifyObserver
	- ResultChange : Setting된 값이 None이 됐거나 새로 생겼거나
	- ValueChange : Setting된 값이 바꼈거나 None이 됐거나 새로 생겼거나 -> ResultChange의 상위 호환

	- 관찰자 중단이 특히 MoveTo 같은 Task랑 같이 사용하면 강력함

	11. 8번 9번대로 스킬을 장착하고 스킬을 날리면 Montage는 재생하는데 스킬 자체의 Fireball이 안 날라감
	- 그 이유는 스킬 내부에서 어디로 날릴지 정하는 함수가 실패(정확히는 Camera가 Cast실패함)했기 때문에 Fireball을 Spawn하지 않기 때문임
*/