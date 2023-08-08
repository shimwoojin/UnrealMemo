#pragma once
/*
	1. TPS 프로젝트 새로 만듬
	- Animation Starter Pack 에셋 추가
	- Millitary Weapon Dark 에셋 추가

	2. C++ -> 블프로 상속하여 클래스 만들었을 때
	- 클래스 명을 바꾸는 것은 블프에서의 래퍼런스가 깨지지 않는 것으로 알고 있었으나
	- 파일명을 바꾼 것이 원인이 되어 래퍼런스가 깨졌던 것으로 추정됨

	3. Character, Player, PlayerCotroller 만들어줌
	- 키 바인딩은 PlayerController에서 하기로 하였음
	- void APlayerController::SetupInputComponent() 함수에 키 바인딩 해주면 됨
	- w,a,s,d, 마우스 조작에 따른 바인딩을 해주었고 움직임, 화면 전환을 담당할 예정
	- 착각하기 좋은 포인트가 있는데 w,a,s,d 움직임은 조종하는 pawn에 대해 하는 것이고 마우스 조작에 따른 화면 전환은 Controller 자체의 회전인 것임

	4. 키 바인딩을 하기 위해 프로젝트 세팅에서 해줄 수도 있지만 C++에서도 가능함
	- 간단하게 소개하면 (APlayerController::SetupInputComponent를 오버라이드하여 처리)

	FInputAxisKeyMapping MoveForward("MoveForward", EKeys::W, 1.f);
	FInputAxisKeyMapping MoveBackward("MoveForward", EKeys::S, -1.f);
	UPlayerInput::AddEngineDefinedAxisMapping(MoveForward);
	UPlayerInput::AddEngineDefinedAxisMapping(MoveBackward);

	InputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);

	- BindAxis에서 "MoveForward"가 프로젝트 세팅 혹은 위의 코드에서 추가해둔 입력 매핑에 대한 문자열이고
	&ThisClass::MoveForward는 우리가 바인드할 함수 그 자체임, 위 코드에선 저 함수가 있는지는 알 수 없음(있다고 가정)
	
	- 굳이 Cpp에서 입력 매핑해야하면 좋은 이유는 잘 모르겠으나 알아둬서 나쁠 거 없음

	- 참고로 GetWorld()->GetFirPlayerController()->PlayerInput->AddAxisMaping(MoveForward); 로
	UPlayerInput::AddEngineDefinedAxisMapping(MoveForward); 이 코드를 대체할 수 있다고 함(이건 테스트 안 해봄)
	
*/