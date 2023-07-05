#pragma once
/*
	1. impulse는movement 계열 component 혹은 primitive component를 상속받은 컴포넌트에 줄 수 있음
	- Mesh->AddRadialImpulse();
	- 위 함수는 PrimitiveComponent의 함수

	2. 축 매핑 중 LookUD는 Scale -1 줬는데
	- 아마 PlayerController에서 yaw,pitch, roll 중에 pitch 관련 옵션 기본값이 혼자 -2.5 였던 값이 있는데 아마 기본 컨트롤러에 대해 고려해서 이렇게 만든 듯

	3. 키 입력을 함수랑 엮어주기 위해 Character의 SetupPlayerInputComponent()에서
	- PlayerInputComponent->BinxAxis("MoveFB", this, &Acharacter::MoveFB); 로 처리할 수 있음

	- 매크로로 간단히 만들면 #define BindAxisAuto(FunctionName) BindAxis(#FunctionName, this, &ThisClass::FunctionName) ... #undef BinxAxisAuto

	4. FRotator는 FQuat를 래핑한 클래스 이기 때문에 GetForwardVector()가 불가능함
	- FRotator에서 quaternion을 불러서 quaternion에 대해 forwardvector를 얻어야 함

	5. AMyCharacter를 블루프린트 AMyMyCharacter로 만들고 나서 외형 및 위치, 방향 잡아주고 나서 그 캐릭터로 게임을 하려면 GameMode에서 DefaultPawnClass로 잡아줘야 함
	- 기본 제공 되는 GameMode에서 DefaultPawnClass = ?; 를 해줘야 하는데 우리가 지정할 캐릭터가 블루프린트 타입임
	- 생성자에서 처리하기 위해선 ConstructorHelpers::FClassFinder<APawn> MyPawn(TEXT("AMyMyCharacter 블프 경로_C")); 로 얻어온 후
	- if(MyPawn.Succeeded()) { DefaultPawnClass = MyPawn.Class; }

	6. TSubclassOf를 클래스 래퍼런스라고 볼 수 있으나
	- 더 정확히는 UClass가 클래스 래퍼런스임

	- 둘의 차이 : UClass는 딱 그 타입만 / TSubClassOf는 상속받은 애들까지 체크 가능

	7. springarm, camera 헤더 외우기
	- #include <Gameframework/SpringArmComponent.h>
	- #include <Camera/CameraComponent.h>

	8. CreateDefaultSubObjectAuto(SpringArm)->SetupAttachment(GetRootComponent());
	- 생성과 동시에 붙이기
*/