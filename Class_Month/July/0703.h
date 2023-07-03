#pragma once
/*
	1. AddDynamic을 통한 델리게이트 바인드는 "::"이 필수임
	- 누구의 함수인지를 명확히 해야 함

	2. C에서 안되는 문법 한 번 보고 가자

	int const i = 5;
	int arr[i] = {0,1,2,3,4};

	- C++은 허용하는 문법이나 C는 안됨
	- 이유는 C++에선 const가 conextpr로 읽혀 컴파일 타임 이전에 i에 대해 상수로 인식시켜 줄 수 있으나
	C는 컴파일 타임이 되어서야 i가 const로서 값이 변하지 않는 불변변수가 되기 때문에 컴파일 타임 이전의 오류를 막을 수 없음

	3. 바인딩이 되어있다는 가정하에 델리게이트를 동작시키는 코드 2가지를 보면
	- 1) if(Trigger.IsBound()) Trigger.Execute();
	- 2) Trigger.ExecuteIfBound();

	4. NamedBox를 상속한 DelegateTrigger가 본인의 이름을 띄우지 못하는 문제가 있는데
	- NamedBox에서 Text->SetText(StaticClass()->GetDisplayNameText()); 이 코드가 문제임
	- 해결 : Text->SetText(GetClass()->GetDisplayNameText());

	- 다른 해결 버전들 : 
		Text->SetText(UKismetSystemLibrary::GetDisplayName(this)));
		Text->SetText(GetName());

	5. 4번의 내용을 사용함에 있어 알아야 하는 내용이 있음
	- 생성자의 this는 본인을 호출하는 것임 -> 자식에서 생성자를 부름에 있어 A -> B -> C 로 상속을 시켰다 했을 때 생성자가 불리는 순서는 A -> B -> C 임
	A의 생성자가 사용됨에 있어 C는 아직 초기화가 안 되어 있기 때문에 접근이 불가능함

	- 그렇다면 4번에서 GetClass()를 했을 떄 자식의 클래스를 얻어 올 수 있었던 이유는
	UObjectBase에서 멤버변수로 최종 상속받은 클래스를 UClass* 타입으로 들고 있는 엔진의 설계방식 덕분임 -> GetClass()는 UClass* 타입의 멤버변수를 return하는 함수

	- 추가로 UObjectBase가 Actor보다 상위 클래스이고 GetClass()가 오버라이드 되지 않은 함수였기 때문에 UObjectBase가 정의한 내용이 그대로 불려질 수 있었음

	- 생성자에서 어떤 함수를 불렀을 때 자식에서 오버라이드 된 함수라면 오버라이드 된 내용이 아니라 생성자를 만들고 있는 그 클래스의 버전 함수가 불릴 것임

	6. TEnumAsByte를 사용함에 있어 전방선언이 가능함(TEnumAsByte는 언리얼의 템플릿 버전 Enum임)
	- TEnumAsByte<EDrawDebugTrace::Type> DrawDebugType; 멤버변수에 대해
	namespace EDrawDebugTrace { enum Type; }

	7. float 자료형에 대해 10의 몇승 이런 표현
	- float MyFloat = 1e5f;
	-> 10의 5승이라는 뜻 ->100000

	- float MyFloat2 = 3e5f;
	-> 3 * 10의 5승이라는 뜻 -> 300000
*/