#pragma once
/*
	1. UFUNCTION 지정자 중 BlueprintNativeEvent를 사용할 때 <함수이름_Implementation> 이라는 이름의 함수를 새로 정의해주어야 하는데
	- BlueprintNativeEvent 키워드가 붙게 된 함수는 <문서이름.gen.cpp>에 기본 구현을 갖게 됨 -> 이 파일의 경로는
	C:\UnrealProjects\<프로젝트이름>\Intermediate\Build\Win64\UE4Editor\Inc\<프로젝트이름> 임
	- generated 파일은 언리얼 헤더 툴이 우리 파일을 분석해서 자동으로 만들어주는 파일로 알고 있음 -> 헤더의 맨 밑에 generated.h를 추가하는 이유이기도 함
	- 그 구현의 내용은 C++ 버전으로 호출할 땐 <함수이름_Implementation>을 호출하고
	블루프린트에 오버라이딩 된 구현이 있다면 그 내용을 호출한다는 뜻

	- 하여 우리는 BlueprintNativeEvent를 사용하여 C++에 기본 구현을 갖고 블루프린트로 오버라이드하여 사용하고자 하는 경우가 있다면
	
	기본 함수는 구현을 비워두고 ( gen.cpp에서 이미 <함수이름_Implementation>을 부르기로 약속돼있음 )
	<함수이름_Implementation>을 정의부와 구현부를 마련해두어야 함

	이 때 <함수이름_Implementation>에는 어떠한 지정자도 사실 의미가 없는 것이(어떤 것은 있을수도) 블프에서 오버라이드 안 할 시 이 함수를
	부르게 되는데 블프 관점에서 노출된 함수는 <함수이름> 이기 때문 -> <함수이름>이 내부적으로 <함수이름_Implementation>을 부르는 것

	하여 리플랙션 기능을 이용하고 싶다면 블프에 노출될 함수인 <함수이름>을 통하는 것이 의도와 맞을 듯

	추가로 virtual은 C++의 그것과 같음

	2. BlueprintNativeEvent 키워드를 적은 후 함수 본체의 구현부를 만들고 빌드를 해봤을 때 아래와 같은 오류 목록이 나옴
	- C2084 : '함수이름' 함수에 이미 본문이 있습니다. / 파일 : MyActor.gen.cpp

	- 위에서도 적어놨지만 BlueprintNativeEvent 키워드가 붙는 순간 엔진에서 gen.cpp에 그 함수의 기본 구현은 gen.cpp에도 적히게 됨
	- 그걸 한 번 더 정의하려고 했을 경우 위와 같은 오류가 나는 것

	- 그렇기 때문에 BlueprintNativeEvent 키워드가 붙은 함수는 구현부만 작성하고 추가로 _Implementation 키워드를 붙인 함수를 따로 작성하는 것

	- BlueprintImplementableEvent는 구현부만 작성하고 노터치

	3. 2번과 마찬가진데 본체의 구현부는 빼고 빌드를 하게 되었을 때도 오류가 나는데
	- LNK2001 : 확인할 수 없는 외부기호

	- 위 상황이 의미하는 바는 <함수이름_Implementation>이 작성되어 있지 않기 때문

	- gen.cpp에 자동으로 작성해 준 우리의 <함수이름>에는 C++ 기본구현만 되어있으면 <함수이름_Implementation>을 부르도록 되어있는데 이 정보를 찾을 수 없기 때문에 링크에러가 나는 것

	4. 오류 목록에서 확인하기 힘든 경우
	- <출력>을 살펴보면 됨

	- BlueprintNativeEvent가 붙은 함수에는 Virtual 키워드를 못 붙임
	- _Implementation이 붙은 함수는 Virtual 키워드가 가능함
	- 하지만 C++에서 상속관계를 가질 것이 아니고 상속을 하더라도 그 자식이 다른 구현을 가질 것이 아니라면 '굳이'가 되겠음(지양하는 편이 낫다라는 것은 virtual을 적음으로서 생기는 부하가 있다고 알고 있음)

	5. 클래스를 리플랙션 시키기 위한 키워드(혹은 지정자)인 UCLASS()를 알아보자
	- UCLASS를 알아보기에 앞서 언리얼의 모든 클래스는 월드에 배치됨과 상관없이 인스턴스를 하나씩은 무조건 가짐
	- 이 말인 즉슨 C++의 추상 클래스가 불가능하다는 뜻
	- C++ 문법 상 추상 클래스가 성립하기 위해선 1) 멤버 함수 중 순수 가상 함수가 하나 이상 있을 것 2) class name 뒤에 abstract 키워드를 통해 가능(둘 중 하나만 하면 됨)
	- 그렇기 때문에 언리얼에선 이 문법이 불가능함 + 순수 가상 함수도 가질 수 없음

	- 위의 얘기를 정리하면 언리얼 클래스는 1) 추상 클래스가 불가능 2) 순수 가상 함수가 불가능 이라는 것

	- 언리얼식 문법으로 추상 클래스를 하기 위해선
	- UCLASS(Abstract)

	- 언리얼식 문법으로 순수 가상 함수를 하기 위해선
	- 함수의 이름 뒤에 PURE_VIRTUAL(함수이름, ...)
	- virtual int PureVirtual() PURE_VIRTUAL(AMyActor::PureVirtual, return 0;)

	#define PURE_VIRTUAL(func, __VA_ARGS__) 는 결국 매크로인 것이고
	이것이 순수 가상 함수로서 동작할 수 있는 원리는
	순수 가상 함수 : 자식 클래스에선 부모의 순수 가상 함수를 무조건 재정의(오버라이드)하지 않으면 안됨 -> 정의하지 않을 경우 에러가 뜨거나 빌드가 불가능
	결국 오버라이딩을 해야 하는 것에 목적을 두어 기본 구현이 불리게 되면 static_assert가 불리게 됨(기본 구현을 부르면 안 된다는 뜻, 오버라이드를 강제함)
	그리고 이 때 첫 번째 인자로 넘겨주는 func은 # 연산자를 통해 문자열로 변환되어 static_assert의 경고 문구의 일부분이 됨(이것이 순수 가상 함수이고 어떤 함수이름인지 나타내기 위한 경고 문구)

	- 수업 중에 return 0;가 필요 없는 것 아니냐 했는데 int가 반환형이라면 return 값이 있긴 있어야 하겠음 -> static_assert에 대해 무시하고 진행하게 되면 정상진행 될 수도 있기 때문
	- LowLevelFatalError는 프로그램을 중단한다고 함 -> 무시하고 정상 진행은 안 되는 듯

	- 가변인자의 공간은 return이기 보다는 추가적인 내용(메시지를 더 쓴다거나)을 적기 위한 공간 정도

	6. 기본적으로 UPROPERTY 혹은 UFUNCTION은 public 혹은 protected에 적게 되는 경우가 많은데
	- 프로젝트 구조 상 private에 정의해야 하나 블루프린트에서 call할 필요가 있는 경우 사용할 수 있는 meta 지정자가 있음 -> meta = (AllowPrivateAccess)

	- 다른 프로퍼티들과 함께 쓰게 되면
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess)

	- 사실 C++에서 기본 구현을 갖고 블루프린트는 C++를 상속받으면 되는데 그렇기에 드는 생각이 위의 private을 허용하는 메타지정자를 사용하기 보단 protected로 접근 지정자를 제한하여
	블프에선 접근을 허용하는 것은 어떤가 싶기도 함

	7. 추가로 UFUNCTION, UPROPERTY에서 getter랑 setter를 지정하는 키워드 BlueprintGetter, BlueprintSetter, BlueprintGetter = "BlueprintGetterName", BlueprintSetter = "BlueprintSetterName"을 사용해봤는데
	- 과제로 했던 EditByIntRef에서 위 키워드를 추가한 변수가 값이 바뀌지 않았었음
	- 언젠간 알아보는 걸로

	8. class UStaticMeshComponent* Mesh;
	- 포인터 변수(64비트 환경에선 8바이트)에 대해선 전방선언을 통해 헤더의 추가 없이 변수를 선언 가능함
	- class 키워드가 없다면 UStaticMeshComponent를 구현할 수 있는 클래스를 가진 헤더를 추가해야 할 것

	- 이 방법이 IWYU(Include What You Use)의 원칙임
	- 헤더는 전방선언을 하고 cpp에서 실제 구현 혹은 사용할 헤더를 추가해서 사용하는 것
*/