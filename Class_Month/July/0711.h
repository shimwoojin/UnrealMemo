#pragma once
/*
	1. TArray를 채우는 방법은 여러가지
	- AddDefaulted
	- Init
	- Emplace(생성 즉시 배열에 대입)
	- Add(생성 후 복사로 배열에 대입)

	- 문서 왈 : empalce가 add보다 성능이 떨어질리 없지만 가독성 면에서 add가 나을 것이니 가벼운 건 add, 그 외엔 emplace 사용

	2. 뜬금 질문으로 생성자에 : Super()가 안 붙는 이유는 인자가 없는 생성자는 명시적으로 안 써도 됨
	- 부모의 인자가 있는 생성자를 사용하고 싶은 경우엔 : (이니셜라이저)를 사용하여 초기화
	- 이니셜라이저(:)를 사용하여 TArray같은 멤버변수도 초기화 할 수 있음
	ex. TArray<int> MyInt;가 있다면 MyClass() : MyInt(10, 3) {} 처럼 -> MyInt(10,3)은 TArray의 생성자를 활용한 것 -> 크기는 3만큼 각 원소는 10으로 초기화

	3. 라인 트레이스(Objects, Profile, Channel)
	- #include "Kismet/KismetSystemLibrary.h"
	- UKismetSystemLibrary::LineTraceSingleByObjects();

	- 라인 트레이스 시(함수이름 끝이 Objects인 것) 어떤 Object와 충돌인지 검사하기 위해 ObjectTypeQuery인가 열거형을 넘겼어야 하는데
	ECollisionChannel과 ObjectType 간에 변환을 해주는 Convert 함수가 있음(UEngineTypes의 static 함수)

	- ECC_Pawn의 경우 ObjectTypeQuery3과 매칭됨
	- ECC와 Object, Chanel간의 채널에 대해선 3,4일 전 정리에서 설명한 적 있음(사용자 설정 object, channel 관련해서도 적혀 있음)

	4. Kismet에 있는 라인 트레이스는 사용을 간편화 해주는 래핑 함수
	- 무슨 말이냐 ? : GetWorld()->LineTraceSingleByObjects(); 로도 라인 트레이스를 할 수 있으나 넘겨야 하는 인자가 까다롭기 때문에 이것을 간편화해주는 함수인 것임

	5. LineTrace 시 hit한 actor가 character로 cast가 성공하면 LaunchCharacter를 하게 되는데
	- LaunchCharcter는 Character.h의 함수이고
	- 내부적으론 캐릭터의 MovementComponent를 찾아 MovementComponent::Launch()를 콜해서 동작하는 방식이며
	- BlueprintImplementable 함수인 OnLaunched()를 부르며 마무리 함 -> OnLaunched를 블프에서 오버라이드하면 launch를 call 했을 때 callback되는 일종의 델리게이트같은 작동인 듯

	6. CreateDefaultSubobject를 배열 버전으로 만든 매크로 사용 시 좌측 값으로 배열의 인덱스에 값을 대입하는 방식이기 때문에
	- TArray를 사용함에 있어 배열의 크기를 먼저 잡아놓지 않는 이상 오류가 날 수 있음 -> 매크로라 알아채기도 힘들 수도

	7. 6번이 좌측에 배열의 인덱스를 먼저 잡아놓은 매크로여서 오류가 난건데
	- 좌측을 뗀 버전을 먼저 만들고
	- 좌측 값도 넣은 버전을 만들 땐 좌측을 뗀 버전과 합쳐서 매크로를 만든다면 나름 깔끔한 코딩이라고 할 수 있겠음
*/