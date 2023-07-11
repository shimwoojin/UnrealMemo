#pragma once
/*
	1. TArray�� ä��� ����� ��������
	- AddDefaulted
	- Init
	- Emplace(���� ��� �迭�� ����)
	- Add(���� �� ����� �迭�� ����)

	- ���� �� : empalce�� add���� ������ �������� ������ ������ �鿡�� add�� ���� ���̴� ������ �� add, �� �ܿ� emplace ���

	2. ��� �������� �����ڿ� : Super()�� �� �ٴ� ������ ���ڰ� ���� �����ڴ� ��������� �� �ᵵ ��
	- �θ��� ���ڰ� �ִ� �����ڸ� ����ϰ� ���� ��쿣 : (�̴ϼȶ�����)�� ����Ͽ� �ʱ�ȭ
	- �̴ϼȶ�����(:)�� ����Ͽ� TArray���� ��������� �ʱ�ȭ �� �� ����
	ex. TArray<int> MyInt;�� �ִٸ� MyClass() : MyInt(10, 3) {} ó�� -> MyInt(10,3)�� TArray�� �����ڸ� Ȱ���� �� -> ũ��� 3��ŭ �� ���Ҵ� 10���� �ʱ�ȭ

	3. ���� Ʈ���̽�(Objects, Profile, Channel)
	- #include "Kismet/KismetSystemLibrary.h"
	- UKismetSystemLibrary::LineTraceSingleByObjects();

	- ���� Ʈ���̽� ��(�Լ��̸� ���� Objects�� ��) � Object�� �浹���� �˻��ϱ� ���� ObjectTypeQuery�ΰ� �������� �Ѱ��� �ϴµ�
	ECollisionChannel�� ObjectType ���� ��ȯ�� ���ִ� Convert �Լ��� ����(UEngineTypes�� static �Լ�)

	- ECC_Pawn�� ��� ObjectTypeQuery3�� ��Ī��
	- ECC�� Object, Chanel���� ä�ο� ���ؼ� 3,4�� �� �������� ������ �� ����(����� ���� object, channel �����ؼ��� ���� ����)

	4. Kismet�� �ִ� ���� Ʈ���̽��� ����� ����ȭ ���ִ� ���� �Լ�
	- ���� ���̳� ? : GetWorld()->LineTraceSingleByObjects(); �ε� ���� Ʈ���̽��� �� �� ������ �Ѱܾ� �ϴ� ���ڰ� ��ٷӱ� ������ �̰��� ����ȭ���ִ� �Լ��� ����

	5. LineTrace �� hit�� actor�� character�� cast�� �����ϸ� LaunchCharacter�� �ϰ� �Ǵµ�
	- LaunchCharcter�� Character.h�� �Լ��̰�
	- ���������� ĳ������ MovementComponent�� ã�� MovementComponent::Launch()�� ���ؼ� �����ϴ� ����̸�
	- BlueprintImplementable �Լ��� OnLaunched()�� �θ��� ������ �� -> OnLaunched�� �������� �������̵��ϸ� launch�� call ���� �� callback�Ǵ� ������ ��������Ʈ���� �۵��� ��

	6. CreateDefaultSubobject�� �迭 �������� ���� ��ũ�� ��� �� ���� ������ �迭�� �ε����� ���� �����ϴ� ����̱� ������
	- TArray�� ����Կ� �־� �迭�� ũ�⸦ ���� ��Ƴ��� �ʴ� �̻� ������ �� �� ���� -> ��ũ�ζ� �˾�ä�⵵ ���� ����

	7. 6���� ������ �迭�� �ε����� ���� ��Ƴ��� ��ũ�ο��� ������ ���ǵ�
	- ������ �� ������ ���� �����
	- ���� ���� ���� ������ ���� �� ������ �� ������ ���ļ� ��ũ�θ� ����ٸ� ���� ����� �ڵ��̶�� �� �� �ְ���
*/