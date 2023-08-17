#pragma once
/*
	1. TSubclassOf에 걸어두고 Spawn을 할려고 했던 Actor들에 대해
	- TSubclassOf가 템플릿 인자로 걸어둔 클래스까지는 헤더를 알고 있어야 했고
	- 하지만 Spawn된 Actor는 실제 최종 클래스의 형태로 스폰되어 사용하는데 지정이 없다.

	- Spawn이라는 과정이 Cpp의 관점에서 New + World에 추가하는 것 정도로 생각했었는데
	- New를 하기 위해선 생성자를 포함한 헤더의 추가가 불가피한데
	- 이런 네이티브한 방법을 사용하지 않고 블프와 엮어서 사용하기 위해 에픽에서 UClass라는 꼬름한 방법을 사용하는 것 같다.

	- UClass로 받게 되면 위처럼 헤더 추가 없이도 실제 소환하고자 하는 클래스에 맞는 클래스를 소환할 수 있다.

	2. Cpp에서 Spawn시 Instigator와 Owner에 대해서 따로 설정을 해주어야 하는데
	- SpawnActor 함수에서 최종적으로 SpawnActorParamters 라는 구조체를 받게 되는데 이 구조체 안에 Instigator와 Owner를 채워줘야 한다.
	- Template 이라는 Actor 포인터도 있었는데 복제본(?)을 받는 것 같다.

	3. Shooting Game 장르에선 1,2,3,4 번 슬롯을 쓰게 되는데
	- 이것에 대해 TArray 보다는 각각의 슬롯에 맞는 포인터 변수를 두는 게 더 관리하기 편하다고 한다

	4. UClass도 None일 수가 있는데
	- 에디터에서 배열만 TSubclassOf 의 배열 원소만 늘리고 지정을 안 해주면 그럴 수 있다.
	- 블프 기준 IsValidClass 노드로 체크할 수 있는데 (Kismet)
	- 결국 IsValidClass는 IsValid를 내부적으로 불러서 사용하고 있음
	- IsValid는 nullptr 체크와 pendingkill 체크를 하므로 null 체크로 충분하다고 할 수 있겠다

	5. 총알 보간에 대해선 RInterpTo
	- 혹은 카메라에서 쏘고 총구 근처에서부터 보이게끔
*/