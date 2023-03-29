#pragma once
/*
	1. 검의 유효한 공격판정을 만드는 과제가 있었는데
	- 수업 파일 중에 노티파이가 2개 들어갔던 몽타주가 있었는데 이걸 통해서 알 수 있었던 점은
	- Notify와 NotifyState의 차이를 대략 알 수 있었던 것이
	- NotifyState의 NotifyBegin, NotifyEnd가 각각 계산되는 것
	- Notify는 NotifyBegin만 있고 NotifyState는 NotifyBegin, NotifyEnd가 다 있음
	- 몽타주 재생의 핀에서 NotifyBegin이 여러번 불릴 수 있고 NotifyEnd가 여러번 불릴 수 있음
	- 그래서 몽타주 이름으로 빼서 Switch로 제어하는 방법도 있지만 후지다고 하고
	- 몽타주 이름을 빼낼 떄 <클래스 디폴트 가져오기>에 클래스 이름을 줘서 NotifyName 빼낼 수도 있긴 함
	- 그래서 NotifyState클래스 만들어서 NotifyBegin, NotifyEnd를 오버라이딩해서 쓰는 방법이 좋음
	- 참고로 검 뽑는 모션이 잘 안됐던 이유가 NotifyBegin이 두번 작동해서 검은 잡자마자 놓는 식의 동작이여서 그랬음

	2. 과제 풀이 내용
	- BP_Weapon의 overlap 이벤트 발생할 수 있는지 여부를 껐다 켰다 하는 식으로 구현
	- NotifyBegin에서 overlap 이벤트 키고 NotifyEnd에서 overlap 이벤트 끄고
	- 이 과정에서 capsule에서 overlap 이벤트 껐다 켰다 할 수 있으니 이거 제어 할 수 있는 함수 만들어 주고
	- 그 함수를 사용하는 다른 이름의 함수로 한 번 캡슐화해줌
	- 결국에 흐름이 어떻게 되냐 했을 때
	- NotifyState에서 오버라이딩 한 NotifyBegin, NotifyEnd에서 BP_Character의 Activate, Deactivate Attack 인터페이스를 콜하고
	- BP_Character의 입장에선 현재 장비하고 있는 무기에 대한 동작이니깐 SelectedWeapon의 ActivateAttack을 켜주면 됨
	- BP_Weapon의 ActivateAttack은 또 EnableCollision을 동작시키니깐 굉장히 캡슐화가 많이 되어 있음

	3. 세팅하고 나서 실행해보니깐 안되던 이유중에
	- 무기의 기본 overlap 이벤트 꺼놔야하고
	- 노티파이가 실제로 몽타주에 배치되어야 작동함

	4. 이벤트 그래프를 하나 이상 더 만들어서 사용 가능
	- 공간이 다른거지 용도가 다른 게 아님
	- 성격이 비슷한 이벤트끼리 모아두는 용도로 활용해볼만 함

	5. Action 1,2,3,4에 대해서 마우스 좌클릭으로 깔끔하게 컨트롤 하는 법을 만들었는데
	- 마우스를 연타하면 1,2,3,4 Action간에 전환이 부드러워야 하고
	- 공격을 다시 할 때는 1번 Action부터 다시 나오고
	- 연속 공격에 대해선 어느 시점에 클릭이 들어와야 연속공격으로 처리할 지(bAttackTransited)
	- 선입력 방지를 위한(bAttackEnabled)

	6. 몽타주에 노티파이를 2개 배치했는데
	- BP_Weapon의 overlap을 켜는 노티파이
	- BP_Character의 bAttackEnabled를 끄고 켜는 노티파이
	- bAttackEnabled는 넉넉하게 주는 편이 좋음(범위를 좁게 주면 플레이어가 답답해 함)
	- bAttackEnabled는 기본값 켜줘야 함

	- 노티파이를 2개 이상 배치할 때 겹치게 되면 가시성이 안 좋기 때문에
	- 노티파이 에디터 - 아래 화살표 - 노티파이 트랙 추가
	
	7. 연속동작을 부드럽게 만들어주기 위해 몽타주의 디테일 탭에서 BlendOut의 시간을 조정했는데
	- 기본값이 보통 0.25였고 0.3초 ~ 1초 정도 값을 줬음
	- 물론 애니메이션을 보고 직접 정해야하는 거임

	- 블렌드 옵션중에 블렌드를 어떤 방식으로 할지를 정할 수도 있는데 기본값은 Linear, 선형보간임
	- ctrl + alt 눌러서 그래프 볼 수 있음

	8. ActionA의 흐름(최종이맞나?)을 좀 읽어보면
	- bAttackEnabled이고 IsArmed여야 흐름에 들어올 수 있고
	
	- IsState가 Idle이면 Acting으로 바꾸고 몽타주 재생하는 흐름으로 들어감
		- 몽타주 노티파이 중에 bAttackEnabled를 제어하는 노티파이가 있어서 그 노티파이의 begin~end중에는 공격 불가능
		- 몽타주가 재생하면 기본적으로 몽타주 관리하는 index가 증가해서 다음 몽타주 준비
		- 몽타주의 blendout은 completed에 도달할 수 없기 때문에 completed에서 index를 0으로 초기화 하는 건 몽타주가 온전히 재생 되었을 때임
		- blendout하는 시점에도 bAttackTransited가 꺼져 있다면 다음 몽타주를 재생하지 않음(bAttackTransited가 켜지는 건 공격 중 bAttackEnabled가
		켜져 있는 시점에 공격 키 입력이 들어와있고 연속 공격이 가능하게끔 노티파이를 설정해놓은 구간에서만 이 변수를 킬 수 있음)
	
	- IsState가 Idle이 아니면 bool변수 bAttackEnabled는 false, bAttackTransited는 true로
		- 공격 중에 연속 공격을 가능하게 하는 흐름
	
	- 몽타주가 온전히 재생했다면
		- index를 0으로 바꾸고
		- bAttackEnabled를 true로 바꾸고
		- State를 Idle로 초기화
*/