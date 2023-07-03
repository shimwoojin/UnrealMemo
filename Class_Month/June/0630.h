#pragma once
/*
	1. NamedBox 클래스를 만듬
	- UBoxComponent, UTextRenderComponent를 가짐
	- Text에 대해 정렬을 어떻게 할지 정해놓은 열거자를 구분짓는 네임스페이스가 EHorizTextAligment::EHTA_Center, EVerticalTextAligment::EVRTA_TextCenter로
	오타인가 싶음(SetHorizontalAlignment, SetVerticalAlignment)

	2. ThisClass로 본인 클래스의 소속을 나타낼 수 있음
	- ex. ThisClass::StaticClass(); 혹은 StaticClass();

	3. Overlap에 바인딩을 하기 위해 Actor가 정의해놓은 델리게이트에 AddDynamic을 해주어야 하는데
	- AddDynamic은 __Internal_AddDynamic을 포장한 매크로 함수여서 인텔리전스 검색이 안됨
	- OnActorBeginOverlap.AddDynamic(this,&ThisClass::OnActorOverlapStarted);
	- 우리가 정의한 바인딩할 함수의 타입은 반환값은 void이며 매개변수는 AActor*를 2개 받는 타입을 맞춰주어야 함
	
	4. AddDynamic이 아닌 Add를 사용하여 바인딩을 하고자 한다면 FScriptDelegate 타입을 인자로 넘겨주어야 하는데

	FScriptDelegate SD;
	SD.BindUFunction(this, "OnActorOverlapStarted");
	OnActorBeginOverlap.Add(SD);

	- 위 처리를 통해 AddDynamic과 같은 처리를 하지만
	- Name으로 받는 방식이나 코드가 길어지는 단점이 있음

	5. 내부적으로 AddDynamic도 &ThisClass::OnActorOverlapStarted로 받아서 내부적으론 함수 이름을 문자열 형태로 보관하긴 함
	- 멤버함수의 경우 "::"의 문자열을 찾아 그 뒷부분만 함수이름으로서 저장하게 됨

	6. AddDynamic으로 묶어줄 함수는 UFUNCTION()이어야 함

	7. 추상클래스를 만드는 방법은 UCLASS(Abstract)이고 순수가상함수는 PURE_VIRTUAL(함수이름) 인데
	- UObject밑으로 상속받은 객체들은 월드에 배치되지 않아도 인스턴스가 하나 이상 만들어지기 때문에 CPP의 기본문법이 사용불가능함
	- 하지만 CPP의 abstract로 순수가상함수를 만드는 것이 아예 불가능하지만은 않음

	8. NamedBox(사용자 정의 클래스)를 상속받은 DelegateTrigger 클래스를 언리얼 마법사로 만들게 되면
	- Actor를 만들었을 때와 달리 추가해 준 내용이 빈약한데
	- 특정 경로의 UObjectClass.h.Template의 내용을 편집해주면 됨(경로는 이전 내용에 있음)

	9. VS 인텔리전스가 제공하는 부모의 순수가상 모두 구현은 언리얼 프로젝트에선 사용 불가능

	10. 부모의 UFUNCTION을 붙인 내용은 자식에서 UFUNCTION의 오버라이드가 불가능함
	
	11. MSB 어쩌구 오류는 대체로 언리얼식 문법이 틀린 것임
	- 혹은 명령이 종료되었습니다 일 경우
	- 이럴 땐 출력 확인

	12. 부모의 접근 지정자가 언리얼 마법사가 만들어 줄 경우 public인데 그 의미는
	- 부모의 public, protected, private까지 접근이 가능하다는 뜻임(헷갈리는데 내용 재 확인 필요)

	- 언리얼은 public이 강요됨(protected, private 상속이 불가능함)

	13. C++는 C의 기본을 받아들이고 그 위에 덧쌓은 문법임
	- Cast가 괄호로 하는 Cast와 Static_Cast 등의 추가적인 문법을 생각하면 됨

	- .cpp와 .c는 빌드 방식이 다름
	
	extern "C"
	{
		void Text() {
			_asm{}
		}
	}

	- 호환을 위해선 위와 같은 문법이 가능함, 어셈블리어의 경우도 위와 같은 문법으로

	14. 델리게이트의 선언 방법은
	- TDelegate<void()> Trigger;
	- 함수포인터의 typedef을 델리게이트 버전으로 쓰게 되면
	- DECLARE_DELEGATE(FTriggerType)
*/