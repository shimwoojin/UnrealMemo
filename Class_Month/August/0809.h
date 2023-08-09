#pragma once
/*
	1. 주석 대신 #pragma region
	- 클래스 내 멤버함수들도 성격에 따라 주석을 달아서 그룹을 짓는다거나 할 수도 있고
	특히 인터페이스를 상속받은 함수 모음들에 대해 주석으로 정리하기 보다 고급 방법으로 pragma region 사용가능함

	#pragma region MySpace
	void DoSomething();
	void DoSomething2();
	#pragma endregion

	2. 가상함수의 시작을 알리는 virtual
	- 오버라이드를 알리는 override
	- override가 이 밑으로는 이루어지지 않을 것임을 알리는 final
	- final과 같은 동작을 하는 final override

	3. Cpp 상에서 입력 매핑하는 것이 가능한데

	#include "GameFramework/PlayerInput.h" 해주고
	
	- MoveFB에 대해서 입력 매핑을 작성하면

	PlayerInput->AddAxisMapping(FInputAxisKeyMapping("MoveFB", EKeys::W, 1.f));
	PlayerInput->AddAxisMapping(FInputAxisKeyMapping("MoveFB", EKeys::S, -1.f));

	- 여기에 바인드까지 작성하면

	InputComponent->BindAxis("MoveFB", this, &ThisClass::MoveFB);

	- InputComponent는 AActor에서 부터 상속받은 접근 가능한 멤버 변수(UInputComponent)이고
	PlayerInput은 APlayerController로 부터 상속받은 접근 가능한 멤버 변수(UPlayerInput)임
*/