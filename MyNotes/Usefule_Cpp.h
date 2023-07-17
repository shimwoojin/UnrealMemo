#pragma once
/*
	1. UPROPERTY�� ���� ��������� �̸� ����� �⺻������ �ʱ�ȭ���� �����
	- int32�� ��� 0���� �ʱ�ȭ���� �����

	- UPROPERTY�� ������ ���� �˾Ҵµ� UCLASS ������ � Ű���� ������ �� �𸣰�����(�ƹ�ư ���÷��� �ΰ� ������) int, bool, float �� �⺻ �������� ���� �ʱ�ȭ�� �� �ص� �ʱ�ȭ���� �����

	2. F12�� �Լ��� ���Ǻη� �̵����ִ� Ű������
	- Alt + F12�� �� �ڸ����� �Ķ� â�� ��� ���Ǻθ� ��������ִ� Ű����

	3. ������Ʈ�̸�.h �� <�̸� ������ �� ���> ������ �뵵��
	- ���� �߰��� ������̳� ������Ʈ ������ ���� ��ũ�θ� �����Ͽ� ���

	- �⺻���� #include "CoreMinimal.h"�� <������Ʈ�̸�.h>�� �߰� �Ǿ� �ִµ�
	�𸮾� ������� Uobject ������ �����ϰ� �Ǹ� ������� �� �� �ٿ� CoreMinimal.h�� �߰����ְ� �Ǵµ� �̰� <������Ʈ�̸�.h>���� ��ü�Ͽ� ����ϴ� ��찡 ���� �ִ� ��

	- CoreMinimal.h �� ���ؼ� 4.x ���� ���� IWYU(Include What You Use)�� ������ �Ը� Ŀ���鼭 ������ �ð��� ��������ְ��� ���� �ʿ��� �ʼ� ����鸸 ������
	CoreMinimal.h�� �����ϰ� �ʿ��� �͵��� ���� cpp�� �߰��Ͽ� ����ϴ� ����� ä����

	- 4.x ���� �������� Engine.h Ȥ�� EngineMinimal.h ���� �߰��Ͽ� ���� ��� ������� �߰��Ͽ� ����ߴٰ� ��

	4. �𸮾��� ��� Ŭ������ ���忡 ��ġ���� �ʾƵ� ���� �ν��Ͻ��� �������
	- C++ ������ ���� ���� �Լ�, �߻� Ŭ������ ������ �ʴ� ����
	- ���� ���� �Լ��� �Լ� ����� �ڿ� PURE_VIRTUAL(�Լ� �̸�, ...) �� �Ѱ��ְ� �߻� Ŭ������ UCLASS(Abstract)�� �ϴ� ���� �𸮾��� ���
	
	5. C++�� �����ϰ� �Ǹ� .dll ����(���, ���� ��ũ ���̺귯��)�� ������ ��
	- C++�� ���� �� ������ �Ǵ� ����� ���� ����� ����� ����� �ƴ϶� ����� �̸� �ڿ� ���ڸ� ���� ���ο� ���Ϸ� ������
	- �ָ��ε�� �ᱹ ���ο� ���Ϸ� ������ ���� ���Ƴ���� ��
	- �̷� ������ ������ ������ �����Ͱ� ����Ǹ� �ڵ����� ���ŵȴٰ� ��

	6. ���� ���� ����
	- AABPlayerController::PostInitializeComponents();
	- AABGameMode::PostLogin(APlayerController* NewController);
	- AABPawn::PostinitializeComponents();
	- AABPlayerController::OnPossess(APawn* aPawn);
	- AABPawn::OnPossessedBy(AABController* NewController);
	- AABGameMode::PostLogin�� ��

	7. vs�� ������ �� ������ �������� <���� - visual studio ���ΰ�ħ>�ϸ� vs�� �������� �� ����
	- �غ��� �Ѱ��� �̰͵� ������������ ����

	8. �������α� : ctrl k s

	9. �������� alt drag�� ����

	10. Montage_JumpToSection()�� Montage_Play()�� ����Ǿ�� ��
	- JumpToSection�� ���ڷ� �Ѱܹ޴� ��Ÿ�ְ� ���� play���̾�� �ǵ��� ����� ���� �� ����
	
	11. Montage_IsPlaying()�� BlendOut�� ����Ǵ� �������� false�� ��� �Ǵ� ��

	12. 10, 11�� ����� ��Ÿ���� BlendOut�� ����Ǵ� �������� �� ��Ÿ�ְ� �÷��� �Ǵ� ���� �ƴ�

	13. rfor -> tab
	- range ��� for�� �ڵ� �ϼ�

	14. if(auto* cont Mesh = Cast<UStaticMeshComponent>(OutActor->GetRootComponent()) {}
	- if �� ���� ���� ���� �� ���Ա��� ������
	- C++ �� �̻� ���� �������� ������ ����

	15. Delay�� UKismetSystemLibrary::Delay(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo);
	- FLatentActionInfo LatentInfo(int32 inLinkage, int32 UUID, const TCHAR* InFunctionName, UObject* InCallbackTarget);
	
	�ǻ��
	- FLatentActionInfo LatentInfo(0, GetUniqueID(), "FunctionName", this);
	- UKismetSystemLibrary::Delay(this, 3.0f, LatentInfo);

	FLatentActionInfo�� 4�� ���ڸ� �޴� �����ڶ� ���ڸ� �� �޴� ������ 2���� ����

	16. Collision ä�� ���� ��ȯ
	- UEngineTypes::ConvertToObjectType(ECC_Pawn);
	- ECC���� ObjectType���� ��ȯ�Ѱǵ� ECC -> Channel Ȥ�� Channel, ObjectType���� ECC�� ��ȯ�� ����

	17. DynamicDelegate�� C++ �Ӹ��� �ƴ϶� ���������� ����� �����ϰԲ� ���ִ� Ű������
	- �������� ActorOverlap�� ���ε��� �����Ѱ��� �� Ű���带 ����� ��������Ʈ�̸�
	- �� ��������Ʈ�� UPROEPRTY(BlueprintAssignable)�� ����Ͽ� �Ҵ��� �����ϰ� ����� �� ��
	- �������� call�� �ϰ� �ʹٸ� UPROPERTY(BlueprintCallable) �� ���ָ� ��

	- �� ��������Ʈ�� AddDynamic�� ��ũ�� �Լ��� ���ε� �����ϸ�

	- �Ϲ� DYNAMIC Ű���尡 ���� ���� ��������Ʈ�� ���ε��ϴ� ����� �ٸ�

	- �̱� ĳ��Ʈ ��������Ʈ�� DYNAMIC Ű���带 ���� ���� ������ �������Ʈ���� �θ� �� �ִ� �� ������ ����
	- �̱� ĳ��Ʈ�� DYNAMIC Ű���带 ���� �Ǹ� BINDDYNAMIC���� ���ε� ���־�� ��

	18. C++ Interface�� �𸮾� �����翡�� ���� �� ����
	- <��� Ŭ���� ǥ��>�� �ƴ� �⺻ ����ȭ�鿡��

	19. �������̽��� ���÷��� ������ ���� U ���ξ�� �����ϴ� UInterface�� ��ӹ��� �������̽���
	���� �Լ����� ��� I ���ξ�� �����ϴ� �������̽� 2���� �ۼ��ؾ� ��(I������ ����� ����)
	- ���÷��� ���� Ű������� U ���ξ�� �����ϴ� UINTERFACE()�� ä���ָ� �Ǵµ�

	- BlueprintType : �� �������̽��� ��� ����Ʈ���� ������ ����� �� ����(��������� ���� ���� �� ����)
	�� Ű���尡 �־�� NativeEvent�� Implementable�� ��밡���� �� ����

	20. BlueprintNativeEvent, BlueprintImplementableEvent Ű���尡 ���� �Լ��� C++���� �ٸ� ������� ���
	- IInterfaceName::Execute_FunctionName(�������̽��� ������ ��ü);

	- �������̽��� ��� ����Ʈ�� �����ϱⰡ ������ ����� ���� ����
	�� ���� ����Ʈ�� �ִµ�
	
	- �������̽��� cast�� �ϰ� ���� -> �� FunctionName(); �� �θ��� �Ǹ� assert �ɸ� (gen.cpp�� ��������)
	- gen.cpp �������� native�� ������ ���� �� �Ǿ� ������ _Implementation�� �θ��� �ƴ϶�� ���� ������ �θ�
	- ���� ���������� ImplementationEvent�� ���� ������ �־�߸� ���� ���� ������ �θ�

	- �߰��� Native, Implementation�� �ִٸ� -->> IInterfaceName::Execute_FunctionName(�������̽��� ������ ��ü);
	�θ� C++���� �Լ��� �θ� �� ������ <�������̽��� ������ ��ü> �κ��� �������̽��� ��ӹ��� ��ü�� �ƴ� ��� assert(check)��
	�ɸ��� ��
	- ��� ����Ʈó�� �������̽��� ��ӹ��� ���� ��󿡰� �Լ��� call�ص� �ƹ��ϵ� �Ͼ�� �ʴ� ���� �ƴ϶� crash ���� ������
	1) cast�� �ϰų�
	2) bool bIsImplemented = OriginalObject->GetClass()->ImplementsInterface(UReactToTriggerInterface::StaticClass()); 

	U���ξ ���� �������̽��� StaticClass�� ���ͼ� �� �˻縦 ���ְ� �������̽��� call ���־�� ��

	21. ���带 �ٷ뿡 �־� 1) ���� ť 2) ���� ���̺�(wav)�� �ִµ�
	- ���� ���̺�� ���� ť�� �����Ѵٰ� ��(���� ť�� ���� �����)
	- ���� ť �����Ϳ��� ���� �Ҹ��� �󸶳� ������ �Ҹ��� ��ġ�� ���� �۾��� �� �� �ִ� ��
*/