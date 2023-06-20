#pragma once
/*
	1. StackFrame : 함수가 호출될 때 불린 함수만의 스택 영역을 구분하기 위하여 생성된 공간
	- <지역 변수>, <매개 변수>, <복귀 주소>를 저장
	- 함수가 끝나면 그 함수를 불러준 Caller(이전 함수)의 주소로 복귀함 -> 이 때 함수 호출 규약에 의해 Caller가 StackFrame을 정리할 지 Callee가 정리할 지 정하게 됨(stdcall, cdecl)
	- VS에서 기본값으로 설정해 둔 함수 하나 당 지역 변수의 공간은 1MB이다 -> 1MB는 1000000Byte이고 이 수치는 Int(4Byte) 250000(25만)개를 선언할 수 있는 수치임
	- int a[250001]; 은 불가능하단 뜻이고 이 이상의 공간을 할당하고자 한다면 동적할당을 하거나 VS의 기본값을 바꿔주어야 함

	2. 언리얼에서 문자열을 사용하기에 앞서
	- MBCS(Multi - Byte Character Set) : char (1Byte) -> 우리가 흔히 아는 아스키코드 생각하면 됨
	- UNICODE : wchar_t (2Byte) -> 온 지구의 모든 말을 담기 위해 문자 당 2Byte면 충분한가 봄(전에 알기로 문자 당 4Byte까지도 늘어날 수 있는 걸 봤었는데..)

	- 프로젝트의 성격에 따라 문자를 char 혹은 wchar_t로 받는 경우가 다른데

	- 이를 일반화 하기 위해 TEXT("나 문자열임 ㅋ")를 MBCS로 쓸지 UNICODE로 쓸 지 정할 수 있게 해놨다고 보면 됨

	- 간단하게는 어딘가에 프로젝트 세팅에서 바꿀 수 있겠지만 근본적인 코드로서 알아보자면

	#if defined _UNICODE
	#define TEXT(Text) L##Text
	#else
	#define TEXT(Text) Text
	#endif

	라고 보면 됨

	- L은 이 문자열이 유니코드임을 나타내고 ##은 문자열간에 구분을 위한 문법이라고 보면 됨

	3. 언리얼 C++의 디버깅 방법은 중단점을 걸고(F9) (혹은 코드의 좌측에 클릭) F5로 디버깅을 하게 되면 에디터가 새로 켜지게 됨
	- 이때 디버깅 하고자 하는 상황을 만들고(액터를 레벨에 배치한다거나) <플레이>를 하게 되면 중단점에 걸리게 됨

	- 위 방법이 번거롭다면

	- VS상에선 디버그가 진행 중(F5가 눌린 상태)이고 그 상태로 코드를 편집하고 나서 '저장' 후 에디터 상에서 '컴파일' 버튼을 누르고 에디터의 레벨을 '플레이' 해주면 됨
	- 근데 사실 이것도 번거로워 보이니깐 그냥 사양 좋게 맞춰서 필요할 때 마다 중단점 걸고 F5 누르고 '플레이' 할 것 같음

	4. 핫 리로드를 믿지 말고 에디터의 '컴파일' 버튼을 믿자 -> VS상 빌드보다 강력한 듯

	5. UE_LOG(LogTemp, Log, "문자열", 가변 인자)
	- 로그를 찍기 위해 3개의 인자 + 가변 인자를 넘기면 되는데
	- LogTemp : 로그의 제목, 로그의 맨 좌측 이름임
	- Log : Verbosity라고 하는데 Log의 정도? 얼마나 심각한가 정도를 찍어주는 거라고 보면 됨 -> Log 키워드는 이 표시를 안 하는 키워드인 듯
	- "문자열" : printf의 사용법과 같다고 보면 됨 -> 언리얼 식으로 쓰려면 TEXT("")를 사용하여 안전한 코딩하자

	6. 리플랙션 : 런타임에 클래스가 자기 자신을 조사할 수 있는 기능(어떤 변수가 있고 어떤 함수가 있고)
	- 현재 파악한 바로는 리플랙션이란 결국 UPROPERTY, UCLASS, UFUNCTION, UPARAM 등 언리얼이 제공하는 매크로들임
	- 리플랙션이 강력하긴 하지만 C++ 내부에서 사용하는 변수 혹은 함수에는 위 키워드들을 사용하지 않아도 됨
	- 리플랙션이란 결국 <에디터 혹은 엔진>에게 정보를 주는 것

	7. 변수에 UPROPERTY() 키워드를 붙여 리플랙션을 활용한다면
	- 일단 UPROPERTY가 없이 C++문법을 따라 작성한 변수는 에디터의 블루 프린트에 노출도 되지 않고 getter, setter 등 블프 상에선 아무것도 할 수 없음
	- UPROPERTY(EditDefaultsOnly) int i; 로 선언함으로서 블프의 클래스에서 이 변수의 기본 값을 편집할 수 있게 됨 -> Instance에서는 불가능
	- 다른 키워드들은 설명없이 나열만 하겠음
	- EditDefaultsOnly, EditInstanceOnly, EditAnywhere, VisibleAnywhere, VisibleDefaultsOnly, VisibleInstanceOnly, BlueprintReadOnly, BlueprintReadWrite 는 꽤나 자주 쓸 내용
	- BlueprintGetter = GetterFunctionName, BlueprintSetter = SetterFunctionName 이거는 한 번 써봄직 함

	- 위 키워드 중에 EditAnywhere -> VisibleAnywhere로 바꾸는 등의 작업을 하면 Instance별로 편집 된 값에 대해선 바뀌지 않는 의도치 않은 상황이 있을 수 있음

	- Edit과 Visible 시리즈는 공존할 수 없음

	- 문서 참조 : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/Specifiers/

	- Category = CategoryName 으로 체계적인 설계도 습관화하도록

	8. 함수에 붙는 지정자는 UFUNCTION()임
	- UFUNCTION(BlueprintCallable)을 함으로서 블루프린트에서 호출 가능
	- BlueprintGetter, BlueprintCallable, BlueprintImplementableEvent, BlueprintNativeEvent, BlueprintPure, BlueprintSetter 등

	- 문서 참조 : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Functions/Specifiers/

	- UFUNCTION(BlueprintCallable, meta = DisplayName = "Blueprint Node Name")으로 블프 함수 이름을 대체할 수도 있는 듯
	- SpawnActorFromClass가 블프 버전에서 이런 이름인 건 위 방법으로 쓰인거 같음 -> C++ 버전은 SpawnActor<ClassName>()
	
	9. 프로젝트이름.h 는 <미리 컴파일 된 헤더> 정도의 용도임
	- 자주 추가할 헤더들이나 프로젝트 진행을 도울 매크로를 정의하여 사용

	- 기본으로 #include "CoreMinimal.h"가 <프로젝트이름.h>에 추가 되어 있는데
	언리얼 마법사로 Uobject 밑으로 생성하게 되면 헤더마다 맨 윗 줄에 CoreMinimal.h를 추가해주게 되는데 이걸 <프로젝트이름.h>으로 대체하여 사용하는 경우가 종종 있는 듯

	- CoreMinimal.h 에 대해선 4.x 버전 이후 IWYU(Include What You Use)로 엔진의 규모가 커지면서 컴파일 시간을 단축시켜주고자 정말 필요한 필수 헤더들만 포함한
	CoreMinimal.h만 포함하고 필요한 것들은 직접 cpp에 추가하여 사용하는 방법을 채택함

	- 4.x 버전 이전에선 Engine.h 혹은 EngineMinimal.h 등을 추가하여 거의 모든 헤더들을 추가하여 사용했다고 함
*/