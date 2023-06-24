#pragma once
/*
	1. 심볼을 보고 부모의 접근 지정자를 알 수 있음
	- public : 우측 하단에 암것도 x, proteced : * , private : 자물쇠로 잠겨 있음
	
	2. Setter, Getter는 있으면 이걸로 쓰자
	- SetRootComponent만 해도 부모의 proteced 변수 RootComponent에 값을 주는 것 뿐이지만 SetRootComponent() 함수를 통하면 추가적인 작업을 거쳐줌

	3. CreateDefaultSubobject, SetupAttachment등의 함수는 생성자에서만 쓸 수 있는 Construction 함수임
	- CretaeDefaultSubobject에 대응하는 NonConsturction 함수는 NewObject 임
	- Actor는 GetWorld()->SpawnActor()

	4. Root = CreateDefaultSubobject<USceneComponent("Root"); 라 했을 때
	- 템플릿 함수의 반환 값을 Root인 포인터에 반환 받는 것임
	- 위의 경우 USceneComponent를 명시하였지만 템플릿 함수 중에 인자로 USceneComponent를 받는다고 가정하면 템플릿 인자 없이도 타입 추론이 가능함
	- 위의 경우는 인자로 받는 USceneComponent 인자가 없기 때문에 우리는 템플릿 인자를 직접 지정해줘야 함

	5. 고급 코딩을 하기 위해 매크로를 잘 써보면
	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<>("#Component")

	- 일단 위까지는 나도 쓸 수 있음 -> 하지만 템플릿 인자를 채워줘야 하는데 변수의 이름으로부터 무슨 타입인지를 알아내야 함

	- decltype(*Component)까지 하게 되면 Component& 까지 받을 수 있음 -> 포인터 변수에 대해 역참조한 값을 decltype에 넣으면 왜 래퍼런스가 나오는지는 잘 모르겠음

	- &를 떼줘야 하는 상황임
	
	- <type_traits> 헤더 추가해주고

	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<std::remove_reference<decltype(*Component)>::type>("#Component")

	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<std::remove_reference_t<decltype(*Component)>>("#Component")
	
	- 저 구조체의 헤더를 까보면 멤버변수 중에 type이라는 변수는 래퍼런스가 떼진 본래 타입을 갖는 변수임

	6. 익명구조체도 decltype을 통해 재사용할 수 있음
	- struct
	{
	int i1;
	int i2;
	} ii;

	decltype(ii) ii2;

	7. #define PI 3.14 는 컴파일 이전에 수행(전처리)되고 컴파일 코드에는 3.14가 적혀있어서 추적이 불가능함
	- const 변수를 활용

	8. 생성자 기본 생성 시 tick을 켜주는 코드도 자동으로 적히는데 이 코드를 지워주게 되면 Actor의 tick은 작동하지 않음
	- Actor에 붙은 Component와는 별개

	9. 엔진의 입장에서 tick에 대해 크게 2가지로 구분하면 1) 게임 tick 2) 엔진 tick
	- 엔진 tick 중 collision에 대해서 간단하게 이해하면 collision 관련해서 누구랑 누구랑은 block일거고 누구랑은 overlap일거고 정해놓은거에 대해 매 프레임 실제로 actor끼리 충돌했나 확인해보고
	충돌했으면 각 actor들에게 '너 충돌했음', '너 겹쳤음'을 callback으로 보내주는 느낌

	10. 에셋을 바인딩해주는 4가지 방법
	- 1) 블프에서 직접 2) 소프트 래퍼런스 3) ConstructorHelpers::FObjectFinder<형식> 변수명(경로) 4) 블프에서 적용한(혹은 적용할) 에셋을 C++에서 ConsturctionScript에서 적용
	- 위 4가지보다 사실 FM은 생성자에서 AssetManager를 활용하는 것(하지만 굉장히 고급이니깐 엄청 나중에 해보도록)

	11. 소프트 래퍼런스란 ?
	- 경로를 물고 있는 것
	- 이 변수를 활용하려면 로드해서 그 결과물에 대해 활용 가능함
	- 동기 혹은 비동기를 고를 수 있는데(동기는 우리의 게임 시간과 같은 타임라인, 비동기는 다른 타임라인(다른 스레드일 듯))
	- 비동기를 사용함에 있어 결국 Completed 핀을 활용해야 하는데 Completed 이전에 변수를 활용하려면 None임

	- C++ 변수로 표현하게 되면 TSoftObjectPtr<>(소프트 오프젝트 래퍼런스), TSoftClassPtr<>(소프트 클래스 래퍼런스)

	12. 언리얼에선 멤버 변수를 덮어쓰는 지역변수가 불가능함(혹은 인자도 같은 이름 허용이 안됨)
	- this가 굳이가 되버리는

	13. C++과 블프를 같이 활용함에 있어서 C++의 생성자는 블프에 설정해둔 값을 읽어올 수 없음
	- 최소 ConstructionScript 혹은 Beginplay는 되어야 함

	14. void OnConstruction(FTransform const& Transform) override;
	- ConstructionScript의 C++ 버전 이름

	15. Ctrl + . -> 정의 만들기는 남발하지 말자 ㅋㅋ
	- 인텔리전스가 다 읽고 나서 해야 바로 만들어짐

	16. Super는 습관화 -> 부모의 함수를 물려받았다면
	- 빈 부모의 함수라도 오버헤드보다 우리 게임이 잘 돌아가는 걸 생각한다면,,

	17. 빌드 중에 오류가 날 것 같다면 빌드 취소 -> ctrl + break / 빌드 : ctrl + shift + b

	18. 위의 ConstructorHelpers::FObjectFinder<>의 NonConsturction 버전은(NonConstruction이라 함은 생성자가 아닌 이라 볼 수 있음)
	- UStaticMesh* MyMesh = LoadObject<UStaticMesh>(this, TEXT("StaticMesh'/Game/Cube.Cube'"));
	- UObject* MyMesh2 = StaticLoadObject(UstaticMesh::StaticClass(), this, TEXT("StaticMesh'/Game/Cube.Cube'"));
*/