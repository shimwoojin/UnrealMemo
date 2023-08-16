#pragma once
/*
	1. 인터페이스 간의 상속에도 다이아몬드 상속에서 생기는 거와 비슷한 문제가 생길 수 있음

	2. ControlledOne 인터페이스와 Weapon 인터페이스에서 공통의 이름이 있던 함수들이 있었는데
	- Action 인터페이스로 공통의 함수는 묶고
	- ControlledOne의 나머지는 Pose 인터페이스로 묶었음

	- 컨트롤러는 Action, Pose를 상속
	- 플레이어는 Action, Pose를 상속
	- 무기는 Action만 상속

	3. CurrentWeapon에 대해서 Weapon*을 변수로 갖는 것이 아닌 Action 인터페이스* 를 변수로 갖게 되는데
	- CurrentWeapon은 Action 인터페이스가 가지고 있는 함수성만 부르게 될 것임을 의미 -> 의도를 알 수 있음, 필요없는 내용 노출 x
	- decltype(Weapon) 을 통해 무기의 배열의 변수도 정해줄 수 있었음 -> Weapon과 Weapons의 타입을 일원화

	4. TSubclassOf는 Abstract 키워드에 대해선 공개하지 않음
	- 적어도 에디터에서 편집할 땐 공개되지 않음
	- Cpp에서 TSubclassOf 변수를 추가하게 되면 Abstract에 대해 어떻게 반응할지는 모르겠음
	- TSubclassOf에 대해서 spawn을 하게 되면 헤더가 필요할 수 있음 -> 은 아닌 걸로, 반환 값이 Actor이기 때문, 다운 캐스팅을 하고 싶다면 헤더가 필요할 것
*/