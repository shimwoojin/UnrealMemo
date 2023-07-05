#pragma once
/*
	1. impulse��movement �迭 component Ȥ�� primitive component�� ��ӹ��� ������Ʈ�� �� �� ����
	- Mesh->AddRadialImpulse();
	- �� �Լ��� PrimitiveComponent�� �Լ�

	2. �� ���� �� LookUD�� Scale -1 ��µ�
	- �Ƹ� PlayerController���� yaw,pitch, roll �߿� pitch ���� �ɼ� �⺻���� ȥ�� -2.5 ���� ���� �ִµ� �Ƹ� �⺻ ��Ʈ�ѷ��� ���� ����ؼ� �̷��� ���� ��

	3. Ű �Է��� �Լ��� �����ֱ� ���� Character�� SetupPlayerInputComponent()����
	- PlayerInputComponent->BinxAxis("MoveFB", this, &Acharacter::MoveFB); �� ó���� �� ����

	- ��ũ�η� ������ ����� #define BindAxisAuto(FunctionName) BindAxis(#FunctionName, this, &ThisClass::FunctionName) ... #undef BinxAxisAuto

	4. FRotator�� FQuat�� ������ Ŭ���� �̱� ������ GetForwardVector()�� �Ұ�����
	- FRotator���� quaternion�� �ҷ��� quaternion�� ���� forwardvector�� ���� ��

	5. AMyCharacter�� �������Ʈ AMyMyCharacter�� ����� ���� ���� �� ��ġ, ���� ����ְ� ���� �� ĳ���ͷ� ������ �Ϸ��� GameMode���� DefaultPawnClass�� ������ ��
	- �⺻ ���� �Ǵ� GameMode���� DefaultPawnClass = ?; �� ����� �ϴµ� �츮�� ������ ĳ���Ͱ� �������Ʈ Ÿ����
	- �����ڿ��� ó���ϱ� ���ؼ� ConstructorHelpers::FClassFinder<APawn> MyPawn(TEXT("AMyMyCharacter ���� ���_C")); �� ���� ��
	- if(MyPawn.Succeeded()) { DefaultPawnClass = MyPawn.Class; }

	6. TSubclassOf�� Ŭ���� ���۷������ �� �� ������
	- �� ��Ȯ���� UClass�� Ŭ���� ���۷�����

	- ���� ���� : UClass�� �� �� Ÿ�Ը� / TSubClassOf�� ��ӹ��� �ֵ���� üũ ����

	7. springarm, camera ��� �ܿ��
	- #include <Gameframework/SpringArmComponent.h>
	- #include <Camera/CameraComponent.h>

	8. CreateDefaultSubObjectAuto(SpringArm)->SetupAttachment(GetRootComponent());
	- ������ ���ÿ� ���̱�
*/