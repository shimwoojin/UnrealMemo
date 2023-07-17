#pragma once
/*
	1. UPROPERTY가 붙은 멤버변수는 미리 예약된 기본값으로 초기화됨이 보장됨
	- int32의 경우 0으로 초기화됨이 보장됨

	- UPROPERTY가 붙으면 인줄 알았는데 UCLASS 덕인지 어떤 키워드 덕인진 잘 모르겠으나(아무튼 리플랙션 인거 같긴함) int, bool, float 등 기본 변수들은 굳이 초기화를 안 해도 초기화됨이 보장됨

	2. F12가 함수의 정의부로 이동해주는 키워드라면
	- Alt + F12는 그 자리에서 파란 창을 띄워 정의부를 구경시켜주는 키워드

	3. 프로젝트이름.h 는 <미리 컴파일 된 헤더> 정도의 용도임
	- 자주 추가할 헤더들이나 프로젝트 진행을 도울 매크로를 정의하여 사용

	- 기본으로 #include "CoreMinimal.h"가 <프로젝트이름.h>에 추가 되어 있는데
	언리얼 마법사로 Uobject 밑으로 생성하게 되면 헤더마다 맨 윗 줄에 CoreMinimal.h를 추가해주게 되는데 이걸 <프로젝트이름.h>으로 대체하여 사용하는 경우가 종종 있는 듯

	- CoreMinimal.h 에 대해선 4.x 버전 이후 IWYU(Include What You Use)로 엔진의 규모가 커지면서 컴파일 시간을 단축시켜주고자 정말 필요한 필수 헤더들만 포함한
	CoreMinimal.h만 포함하고 필요한 것들은 직접 cpp에 추가하여 사용하는 방법을 채택함

	- 4.x 버전 이전에선 Engine.h 혹은 EngineMinimal.h 등을 추가하여 거의 모든 헤더들을 추가하여 사용했다고 함

	4. 언리얼의 모든 클래스는 월드에 배치되지 않아도 각각 인스턴스가 만들어짐
	- C++ 문법인 순수 가상 함수, 추상 클래스가 허용되지 않는 이유
	- 순수 가상 함수는 함수 선언부 뒤에 PURE_VIRTUAL(함수 이름, ...) 을 넘겨주고 추상 클래스는 UCLASS(Abstract)를 하는 것이 언리얼의 방식
	
	5. C++을 빌드하게 되면 .dll 파일(모듈, 동적 링크 라이브러리)이 나오게 됨
	- C++을 빌드 후 나오게 되는 모듈은 이전 모듈을 덮어쓰는 방식이 아니라 모듈의 이름 뒤에 숫자를 붙이 새로운 파일로 생성됨
	- 핫리로드는 결국 새로운 파일로 생성된 모듈로 갈아끼우는 것
	- 이런 식으로 생성된 모듈들은 에디터가 종료되면 자동으로 제거된다고 함

	6. 게임 세팅 순서
	- AABPlayerController::PostInitializeComponents();
	- AABGameMode::PostLogin(APlayerController* NewController);
	- AABPawn::PostinitializeComponents();
	- AABPlayerController::OnPossess(APawn* aPawn);
	- AABPawn::OnPossessedBy(AABController* NewController);
	- AABGameMode::PostLogin의 끝

	7. vs가 정신을 못 차리면 에디터의 <파일 - visual studio 새로고침>하면 vs가 정신차릴 수 있음
	- 해봄직 한거지 이것도 믿음직스럽지 못함

	8. 영역감싸기 : ctrl k s

	9. 레벨에서 alt drag는 복제

	10. Montage_JumpToSection()은 Montage_Play()가 선행되어야 함
	- JumpToSection이 인자로 넘겨받는 몽타주가 현재 play중이어야 의도한 결과를 얻을 수 있음
	
	11. Montage_IsPlaying()은 BlendOut이 진행되는 순간부터 false로 취급 되는 듯

	12. 10, 11번 결론은 몽타주의 BlendOut이 진행되는 시점부턴 그 몽타주가 플레이 되는 것이 아님

	13. rfor -> tab
	- range 기반 for문 자동 완성

	14. if(auto* cont Mesh = Cast<UStaticMeshComponent>(OutActor->GetRootComponent()) {}
	- if 안 에서 변수 선언 및 대입까지 가능함
	- C++ 몇 이상 부터 가능해진 것으로 보임

	15. Delay는 UKismetSystemLibrary::Delay(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo);
	- FLatentActionInfo LatentInfo(int32 inLinkage, int32 UUID, const TCHAR* InFunctionName, UObject* InCallbackTarget);
	
	실사용
	- FLatentActionInfo LatentInfo(0, GetUniqueID(), "FunctionName", this);
	- UKismetSystemLibrary::Delay(this, 3.0f, LatentInfo);

	FLatentActionInfo는 4개 인자를 받는 생성자랑 인자를 안 받는 생성자 2개를 지원

	16. Collision 채널 관련 변환
	- UEngineTypes::ConvertToObjectType(ECC_Pawn);
	- ECC에서 ObjectType으로 변환한건데 ECC -> Channel 혹은 Channel, ObjectType에서 ECC로 변환도 가능

	17. DynamicDelegate는 C++ 뿐만이 아니라 블프에서도 사용이 가능하게끔 해주는 키워드임
	- 블프에서 ActorOverlap에 바인딩이 가능한것이 이 키워드를 사용한 델리게이트이며
	- 이 델리게이트는 UPROEPRTY(BlueprintAssignable)을 사용하여 할당을 가능하게 만들어 준 것
	- 블프에서 call도 하고 싶다며 UPROPERTY(BlueprintCallable) 을 해주면 됨

	- 위 델리게이트는 AddDynamic인 매크로 함수로 바인드 가능하며

	- 일반 DYNAMIC 키워드가 붙지 않은 델리게이트와 바인드하는 방식이 다름

	- 싱글 캐스트 델리게이트도 DYNAMIC 키워드를 붙일 수는 있으나 블루프린트에서 부를 수 있는 것 같지는 않음
	- 싱글 캐스트가 DYNAMIC 키워드를 갖게 되면 BINDDYNAMIC으로 바인드 해주어야 함

	18. C++ Interface는 언리얼 마법사에서 만들 수 있음
	- <모든 클래스 표시>가 아닌 기본 제공화면에서

	19. 인터페이스는 리플랙션 제공을 위한 U 접두어로 시작하는 UInterface를 상속받은 인터페이스와
	실제 함수들을 담는 I 접두어로 시작하는 인터페이스 2개를 작성해야 함(I버전은 상속이 없음)
	- 리플랙션 관련 키워드들은 U 접두어로 시작하는 UINTERFACE()를 채워주면 되는데

	- BlueprintType : 이 인터페이스를 블루 프린트에서 변수로 사용할 수 있음(멤버변수로 갖고 있을 수 있음)
	이 키워드가 있어야 NativeEvent나 Implementable도 사용가능한 것 같음

	20. BlueprintNativeEvent, BlueprintImplementableEvent 키워드가 붙은 함수는 C++에서 다른 방식으로 사용
	- IInterfaceName::Execute_FunctionName(인터페이스를 구현한 주체);

	- 인터페이스를 블루 프린트와 연동하기가 굉장히 힘들어 보임 ㅋㅋ
	몇 가지 포인트가 있는데
	
	- 인터페이스로 cast를 하고 나서 -> 로 FunctionName(); 을 부르게 되면 assert 걸림 (gen.cpp에 적혀있음)
	- gen.cpp 기준으로 native는 블프가 구현 안 되어 있으면 _Implementation을 부르고 아니라면 블프 구현을 부름
	- 위와 마찬가지로 ImplementationEvent는 블프 구현이 있어야만 블프 구현 내용을 부름

	- 추가로 Native, Implementation이 있다면 -->> IInterfaceName::Execute_FunctionName(인터페이스를 구현한 주체);
	로만 C++에서 함수를 부를 수 있으며 <인터페이스를 구현한 주체> 부분이 인터페이스를 상속받은 객체가 아닐 경우 assert(check)에
	걸리게 됨
	- 블루 프린트처럼 인터페이스를 상속받지 않은 대상에게 함수를 call해도 아무일도 일어나지 않는 것이 아니라 crash 나기 때문에
	1) cast를 하거나
	2) bool bIsImplemented = OriginalObject->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass()); 

	U접두어가 붙은 인터페이스의 StaticClass를 얻어와서 위 검사를 해주고 인터페이스를 call 해주어야 함

	21. 사운드를 다룸에 있어 1) 사운드 큐 2) 사운드 웨이브(wav)가 있는데
	- 사운드 웨이브로 사운드 큐를 구성한다고 함(사운드 큐가 최종 결과물)
	- 사운드 큐 에디터에선 최종 소리가 얼마나 될지나 소리를 합치는 등의 작업을 할 수 있는 듯
*/