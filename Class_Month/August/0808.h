#pragma once
/*
	1. TPS ������Ʈ ���� ����
	- Animation Starter Pack ���� �߰�
	- Millitary Weapon Dark ���� �߰�

	2. C++ -> ������ ����Ͽ� Ŭ���� ������� ��
	- Ŭ���� ���� �ٲٴ� ���� ���������� ���۷����� ������ �ʴ� ������ �˰� �־�����
	- ���ϸ��� �ٲ� ���� ������ �Ǿ� ���۷����� ������ ������ ������

	3. Character, Player, PlayerCotroller �������
	- Ű ���ε��� PlayerController���� �ϱ�� �Ͽ���
	- void APlayerController::SetupInputComponent() �Լ��� Ű ���ε� ���ָ� ��
	- w,a,s,d, ���콺 ���ۿ� ���� ���ε��� ���־��� ������, ȭ�� ��ȯ�� ����� ����
	- �����ϱ� ���� ����Ʈ�� �ִµ� w,a,s,d �������� �����ϴ� pawn�� ���� �ϴ� ���̰� ���콺 ���ۿ� ���� ȭ�� ��ȯ�� Controller ��ü�� ȸ���� ����

	4. Ű ���ε��� �ϱ� ���� ������Ʈ ���ÿ��� ���� ���� ������ C++������ ������
	- �����ϰ� �Ұ��ϸ� (APlayerController::SetupInputComponent�� �������̵��Ͽ� ó��)

	FInputAxisKeyMapping MoveForward("MoveForward", EKeys::W, 1.f);
	FInputAxisKeyMapping MoveBackward("MoveForward", EKeys::S, -1.f);
	UPlayerInput::AddEngineDefinedAxisMapping(MoveForward);
	UPlayerInput::AddEngineDefinedAxisMapping(MoveBackward);

	InputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);

	- BindAxis���� "MoveForward"�� ������Ʈ ���� Ȥ�� ���� �ڵ忡�� �߰��ص� �Է� ���ο� ���� ���ڿ��̰�
	&ThisClass::MoveForward�� �츮�� ���ε��� �Լ� �� ��ü��, �� �ڵ忡�� �� �Լ��� �ִ����� �� �� ����(�ִٰ� ����)
	
	- ���� Cpp���� �Է� �����ؾ��ϸ� ���� ������ �� �𸣰����� �˾Ƶּ� ���� �� ����

	- ����� GetWorld()->GetFirPlayerController()->PlayerInput->AddAxisMaping(MoveForward); ��
	UPlayerInput::AddEngineDefinedAxisMapping(MoveForward); �� �ڵ带 ��ü�� �� �ִٰ� ��(�̰� �׽�Ʈ �� �غ�)
	
*/