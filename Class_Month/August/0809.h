#pragma once
/*
	1. �ּ� ��� #pragma region
	- Ŭ���� �� ����Լ��鵵 ���ݿ� ���� �ּ��� �޾Ƽ� �׷��� ���´ٰų� �� ���� �ְ�
	Ư�� �������̽��� ��ӹ��� �Լ� �����鿡 ���� �ּ����� �����ϱ� ���� ��� ������� pragma region ��밡����

	#pragma region MySpace
	void DoSomething();
	void DoSomething2();
	#pragma endregion

	2. �����Լ��� ������ �˸��� virtual
	- �������̵带 �˸��� override
	- override�� �� �����δ� �̷������ ���� ������ �˸��� final
	- final�� ���� ������ �ϴ� final override

	3. Cpp �󿡼� �Է� �����ϴ� ���� �����ѵ�

	#include "GameFramework/PlayerInput.h" ���ְ�
	
	- MoveFB�� ���ؼ� �Է� ������ �ۼ��ϸ�

	PlayerInput->AddAxisMapping(FInputAxisKeyMapping("MoveFB", EKeys::W, 1.f));
	PlayerInput->AddAxisMapping(FInputAxisKeyMapping("MoveFB", EKeys::S, -1.f));

	- ���⿡ ���ε���� �ۼ��ϸ�

	InputComponent->BindAxis("MoveFB", this, &ThisClass::MoveFB);

	- InputComponent�� AActor���� ���� ��ӹ��� ���� ������ ��� ����(UInputComponent)�̰�
	PlayerInput�� APlayerController�� ���� ��ӹ��� ���� ������ ��� ����(UPlayerInput)��
*/