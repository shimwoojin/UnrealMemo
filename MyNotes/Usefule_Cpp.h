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
*/