#pragma once
/*
	1. �ִϸ��̼� �뷮 ���� �� ������ ��
	- ������ ������ ������ �̸� ���� �� �ִϸ��̼��� �ִٸ� ���� ��� �뷮�����ϰ� �� ���� �̿��ؼ� ������ ���� ó��

	2. �ִϸ��̼� ��带 ó���ϴ� ��� ��
	- ��忡�� AnimSequence�� ���� ������ �°ݽ����ְ� cpp������ ���� ��忡 ���� � �ִϸ��̼��� ���� ���ϴ� ������� ó���� ����

	3. sit to stand, stand to sit �ִϸ��̼��� ����
	- �� �ڿ������� �ִϸ��̼� ������ ���ؼ���� ����ϴ� ���� ����
	- ������ �ɾ� �ִ� ����� �� �ִ� ���� ���� ��ȯ���� �Ͼ�� ���尡 ������ �ʴٸ� ������� �ʾƵ� ��
	- ���� ����� �ִϸ��̼����� ���� ��ȯ �� ���� �������� ǥ���ϴ� �ִϸ��̼ǵ��� ���� �ִµ� ��͵� ���������� ��������ִ� ���� ����

	4. SkeletalMeshComponent ����� ������Ʈ ?
	- ĳ������ �⺻ SkeletalMeshComponent�� ��ü ������
	- �ٵ� �� ?
	- GetMesh()->GetAnimInstance()-> ��Ÿ�� ���� ó�� �� ���ؼ� SkeletalMeshCompoenent���� ����ؼ� �̸� ó���ϱ� ����

	5. ACharacter�� �����ڴ� ���ڰ� ���� ����
	- �𸮾��� ���ڰ� ���� �����ڿ� FObjectInitializer ����ü�� �޴� ������ 2������ ����� �� �ִµ�
	- ACharacter�� ���ڰ� ���� ������ ��� FObjectInitializer�� �޴� �����ڸ� ����, ��� ����ü�� ���� �⺻���� �־� ��� �� �⺻ �����ڰ� �Ҹ��� ��ó�� ���̴� ��
	- ATPSCharacter���� �⺻ �����ڸ� ȣ�� �� : Super()�� ��������� ���� �ʾƵ� �Ҹ��� �Ǵµ� �� �� �Ҹ��� �����ڴ� ���� ����� FObjectInitilizer�� �⺻���� �� �������� ���̴�.
	- �� �����ڸ� �츮�� Ŭ���������� �Ȱ��� �������̵� ���ְ� �Ǹ�(FOjbectInitializer�� �⺻���� ��) 4������ ����ߴ� SkeletalMeshComponent�� ��ü�� ��������

	6. UObject ��� Ŭ������ new, delete�� ���� �ʴ´�
	- ��� UObject ����� �ƴϿ��� �޸� ������ ���ο� �ξ� new, delete ��� ����Ʈ �����͸� Ȱ���ϴ� ��찡 ����
	
	7. Actor�� �ƴ� UOjbect ��ݿ� ���� new �� ó���ϴ� ����� ũ�� 2������ ���� �� �ִµ�
	- ������ : CreateDefaultSubbject
	- �����ڰ� �ƴ� ���� : NewObject Ȥ�� CreateObject

	- ������ ����� new Ű���� ��ü ���丮 �Լ��� CreateDefaultSubObject�� 2���� �ø�� �� ����, CreateEditOnlySubobject, CreateOptionalDefaultSubobject
	- ĳ���� �������� ���� CreateEditOnlySubobject : �ַο� ������Ʈ��, CreateOptionalDefaultSubobject : ���̷�Ż �޽� ������Ʈ�� ����ϰ� ����(ACharacter�� �����ڿ���)

	- EditOnly�� ��Ű¡ �� ��ȿ���� �ʰ� ������ �󿡼� �׽�Ʈ�� ���� ��ȿ�ϴٴ� �ǹ��� Ű�����̰�
	- Optional�� �ڽĿ��� ��ü�� �� ������ �ǹ���

	8. ���̷�Ż �޽� ������Ʈ�� ACharacter ������ CreateOptionalDefaultSubobject�� ���� �ֱ⿡ �̸� ��ü�ϴ� ����� �ִµ�
	- ATPSCharacter::ATPSCharacter(FObjectInitializer const & ObjectInitializer)
		: Super(ObjectInitializer.SetDefaultSubobjectClass<UTPSCharacterMeshComponent>(Super::MeshComponentName) {}

	- ���� ���� ATPSCharacter�� �����ڿ��� ���� ó���� ���ְ� �Ǹ� �θ��� ������Ʈ�� �ٲ� �� ����
	- �߰��� ObjectInitializer�� ����Լ� �߿� ������ �͵��� �� �־���

	9. �θ��� ������Ʈ�� �ٲٴ� ����� ���� Shooter �帣�� ��� �ѱ��� ������ �ٲٴ� ��� ������ �� ����
	- ������ �ݸ��� ������Ʈ�� �ٲٴ� �͵� �����ٰ� ������

	10. Crouch�� CharacterMovementComponent�� ������ �Ʒ��ʿ� bCrouch�� ���־�� ���� ������
	- �⺻������ Character �Լ��� Crouch, UnCrouch�� �θ��� �˾Ƽ� ĸ���� ���δٰų� ī�޶� ��ġ�� �ٲ۴ٰų� ó���� ����
	- �ɾ��� �� ĸ�� ������Ʈ�� height�� ���̴� ���� �������ָ� ����

	11. hit�� ���� BoneName�� �޴� ��� hit�� ����� SkeletalMesh���� �Ѵ�
	- ���̷����� �� ������ �ƴ϶� PhysicsAsset�� �� ������ ������ ��
	- PhysicsAsset�� ��� ���̷��濡 ���� ����ȭ �� �� ������ ������ �ִ�

	12. ������ �������� �ٸ��� ��� �� ��� ó���� ���� ������
	- Head�� ���� �켱 ó��
	- ���ڿ��� "_l", "_r"�� ��������(��, �ٸ�) (FString::EndsWith)
	- �� ��(Body)
	- Ȥ�� Miss

	13. ���Ÿ��� Hit�� ���쳪 �ٰŸ��� Hit�� ���� ����
	- �ٰŸ��� Hit�� ���� ó���� �ϰ� �ʹٸ� �˽ſ� Ʈ���̽��� �־� HitResult�� ������� ó���� �����ϱ� ��
*/