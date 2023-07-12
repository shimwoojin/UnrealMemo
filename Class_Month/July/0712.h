#pragma once
/*
	1. TArray의 생성자 중 복사로 넘어가는 값에는 nullptr을 넘기면 안 됨 -> 다른 생성자 찾아야 함

	2. 오랜만에 나온 초기화 방법 3가지, copy, direct, uniform
	- copy : =
	- direct : ()
	- uniform : {}

	- uniform은 셋 중 제일 엄격하며 엄격하기 때문에 추천하는 초기화 방식
	- double d{3.4f}; 같은 초기화는 경고가 아닌 에러를 냄

	3. 인터페이스 생성은 언리얼 마법사로 가능함
	- <모든 클래스 표시>가 아닌 곳에서
	
	4. C++ 인터페이스는 UInterface를 상속받은 U 접두어가 붙은 클래스와
	아무 상속도 받지 않은 접두어가 I인 클래스 2개를 작성하게 됨
	- UINTERFACE()로 리플랙션에 노출은 U접두어 클래스가 해주고
	- 우리가 작성할 함수들은 I 접두어가 붙은 클래스에 적게 됨

	5. 블프의 인터페이스 = 순수 가상 함수 <-> C++의 인터페이스는 가상 함수도 가능하며 static도 가능

	6. I접두어 인터페이스에서 C++ 키워드인 abstract가 가능한데 그 이유는 리플랙션에 적용받지 않고 엔진에서 인스턴스를 안 만들기 때문에 가능함
	- abstract 사용엔 주의할 점이 있는데 I 인터페이스를 상속한 클래스에서 바로 abstract 키워드가 붙은 함수를 구현해주어야 함(클래스를 하나 건너뛰고 구현하면 에러)
	- 아니라면 상속받은 클래스가 abstract 키워드를 사용하게 되는데 리플랙션에 노출된 클래스라면 엔진이 인스턴스 1개 이상을 강제하기 때문에 이 과정에서 에러가 남

	7. 언리얼의 인터페이스 사용은 다중 상속으로
	- , public IMyInterface

	8. #include의 경우 선언 위치가 파일의 맨 위여야만 하는 것은 아님
	- 헤더가 필요한 곳에서 include해서 쓰는 것이 나은 경우가 있을 수 있음
	- 클래스 사이에 #include 적어서 쓰는 기법도 많은 듯

	9. 인터페이스의 기본 사용은 인터페이스의 헤더를 추가 후 인터페이스로 Cast하여 사용하면 됨
	- Cast의 유효 체크 후 사용하면 안전한 사용이 되겠음

	10. 가벼운 인터페이스 헤더를 추가함으로서 컴파일 타임을 줄이는 것만으로도 장점이라고 볼 수 있겠음
	- 언리얼 헤더들이 워낙에 무겁다 보니

	11. 인터페이스를 원래 인터페이스의 정의에 맞게끔 순수가상으로만 구성하고 싶다면
	- 1) abstract : C++ 문법이며 IInterface가 리플랙션에 노출되지 않아 가능, 하지만 상속받은 클래스들이 한 다리 건너뛰고 구현하면 에러
	- 2) PURE_VIRTUAL(FUNCTION_NAME) : 함수 구현부를 가지는 매크로이며 구현부가 실제 코드상에서 불리게 되면 LowLevelFatalError를 일으켜서 이 함수는 오버라이드가 강제됨
	- 3) unimplemented() : check(assert)를 포장한 매크로, check는 크래쉬를 일으켜 엔진을 중지시키는 언리얼의 assert 구문
	
	- PURE_VIRTUAL을 추천하는 이유는 어떤 함수에서 크래쉬가 난지 알려주는 관점에서 좋을 것 같음

	12. 간단한 복습으로 BlueprintNativeEvent, BlueprintImplementableEvent는 함수 원형을 virtual로 적으면 안 됨
	
	13. 인터페이스의 BlueprintNativeEvent 구현을 알아보면
	- _Implementation이 인터페이스의 기본 구현을 가진다면 기본 구현을 하고 아니라면 (PURE_VIRTUAL) 처리를 하여도 됨
	- 인터페이스를 상속하는 클래스에선 _Implementation을 오버라이드 하면 됨
	
	- 함수의 원형은 인터페이스에만 갖고 있으면 됨

	14. BlueprintNativeEvent, BlueprintImplementableEvent가 붙은 함수는 call을 할 때 일반 함수들과는 불리는 방식이 다름
	- IMyInterface::Execute_MyFunction(UObject* O);
	- 여기서 UObject로 넘겨주어야 하는 객체는 인터페이스를 구현한 클래스여야 함 -> 아닐 경우 check로 걸러 냄
	- 인터페이스를 블프에서 오버라이드 하려고 하는 경우 C++에서 그 함수를 부를 때
	Execute_ 가 붙은 static 함수 사용이 강제되는데 그 이유는
	함수의 원형과 _Implementation이 붙은(BlueprintNativeEvent) 함수는 gen.cpp에서 그 함수를 부를 경우 에러를 내게끔 만들어 놨음

	15. 추가로 라인트레이스시 FHitResult에 담기는 Actor는 약포인터이기 때문에 .Get()을 해야 함
	- 혹은 Actor를 날포인터로 넘겨줄 수 있는 GetActor()를 HitResult로부터 부를 수도 있음

	16. Blueprint에서 쓰게 끔 만들어 놓은 함수의 경우 (Native, Implementable) 함수 이름에 접두어로 K2_가 붙여서 식별하는 경우가 많은 듯(Kismet 2?? 뭐 이런 뜻이라나)
	- 블프에서 K2_ 가 붙게 되면 거슬릴 수 있으니 UFUNCTION()의 메타 지정자 중에 meta = (DisplayName = "NoK2Version") 로 블프에 보여질 이름을 바꿀 수도 있음

	17. 16번을 적다보니 생각난 건데 K2_ 버전이 있다면 인터페이스에 K2접두어가 없는 버전을 만들어 K2_가 붙은 버전을 부르는 함수를 만들면 되겠음
*/