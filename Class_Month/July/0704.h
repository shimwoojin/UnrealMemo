#pragma once
/*
	1. TEnumAsByte<EDrawDebugTrace::Type> DrawDebugType;
	
	UENUM(BlueprintType)
	namespace EDrawDebugTrace
	{
		enum Type
		{
			None,
			ForOneFrame,
			ForDuration,
			Persistent
		};
	}

	- UENUM�� BlueprintType�� �ؾ� �������� ��� ����
	- C�� ���� enum�� ���ӽ����̽��� �������� enum class�� ����ϰ� ���

	2. enum�̳� enum class�� ���� Ÿ���� ������ ������ int ���ε�(4byte)
	- enum class TestType : uint8 ���� �������� Ÿ���� ũ�⸦ ������ �� ����
	- �߰��� enum�� ������ �����ڵ��� ������� 0,1,2,... �̷� literal ������ ������ �Ǵµ�
	�� literal���� ����� Ÿ���� ũ�⸸ŭ ������ ��

	3. ���̾� u�� unsigned int, ul�� unsigned long, ull�� unsigned long long

	4. unsigned long operator ""_deg(int i)
	{
		return i;
	}

	- ���̾��� �������̵��� �Ͽ� 1_deg;�� int���� �ƴ� unsigned long��
	- _(�����)�� ǥ�ذ� ��ġ�� �̸��� �� ���� ������ �ǰ���� -> �𸮾� ������Ʈ�� ���� ������ ��

	5. UENUM(BlueprintType)�� : uint8�� ���� ��
	- enum�� BlueprintType�� �ٰ� �Ǹ� enum�� ���𿡼� : uint8�� �����Ǵ� ���� �ƴ����� ����Կ� �־� TEnumAsByte<>�� ���� ����ϰ�
	- enum class�� BlueprintType�� �ٰ� �Ǹ� ���� : uint8�� ������ -> ���� ������ ������

	- UENUM(BlueprintType)�� ����ϰ� �Ǹ� namespace + enum �� ����ϰ� TEnumAsByte���� ����ϴ� ���� ���ŷ����� ���ƺ���

	6. #include <Kismet/GameplayStatics.h>�� Gameplay�� ���� class ������ static �Լ����� ����
	- ��� �� ���� �Լ�
	- �ӽ÷� DelegateTrigger�� ã�� ���� UGameplayStatics::GetActorOfClass(this, ADelegateTrigger::StaticClass())�� ã����

	7. #include "Particles/ParticleSystemComponent.h"
	- ��ƼŬ�� ��� ��ΰ� �̷��� ���� �� �� ������ �ܿ쵵��

	8. Particle->Activate(true);
	- true�� �Ķ���� ������ bReset�� -> true��� �� Ȱ��ȭ �� �ִ� �߿� �� �ڵ尡 �Ҹ��� �ٽ� �����Ѵٴ� ��
	- �⺻���� false��

	9. GetActorLocation�� ���������� RootComponent�� Location�� ��� ��

	10. ����ƽ �޽��� �����Ƽ�� ����ƽ�̶�� �̵� ���� �ڵ忡�� ������ ��ħ -> ������� ����
	- SimulatePhysics�� �ٲٸ� Collision Preset�� PhysicsActor�� �ٲ�� ���� ������� �ڵ����� �ٲ�

	11. SphereOverlapActors C++ ���� ���
	
	UKismetSystemLibrary::SphereOverlapActors
	(
		this,
		GetActorLocation(),
		500,
		{ EObjectTypeQuery::ObjectTypeQuery4 } ,
		AActor::StaticClass(),
		{ this },
		OutActors
	);

	- EObjectTypeQuery�� ���� ObjectTypeQuery4�� �� �� ObjectType�� PhysicsBody�� ��ü���� �浹 �˻���

	- ECollisionChannel, EObjectTypeQuery, ETraceTypeQuery �ݸ��� �����Ͽ� �̷��� 3���� �����ڸ� �𸮾󿡼� �����ϴµ� ���� ���� ����� �ٸ�

	1) ECollisionChannel : ������ �����ϴ� �⺻ ObjectType 6�� + Channel 2�� + ������ ������ ä�� 6�� + �츮�� ������Ʈ ���ÿ��� ���� ������ �� �ִ� Ŀ���� ä�� 18��, 
	�� 32���� ä�ο� ����
	ObjectType�� ���ؼ� ���� �̸����� ���� ���� ECC_WorldStatic, ECC_WorldDynamic, ECC_Visibility ��
	�츮�� Ŀ���� ������ ä�ε鿡 ���ؼ� ������ ������� ECC_GameTraceChannel1, ECC_GameTraceChannel2, ... �� ���� ����

	�� �� ������ ���� Object�̰� Channel�̰� ���� ���� ������ ������� <Config - DefaultEngine.ini>�� ���� ����

	Object1 - Channel1 - Channel2 - Object2 ������ ���ο� �ݸ����� �����ϰ� �Ǿ ���� ������� ECC_GameTraceChannel�� �������� ��

	2) EObjectTypeQuery : �ݸ����� Object�� Channel�� ���� ũ�� ������������ ������ EObjectTypeQuery�� ObjectType�� ���ؼ��� ���� ������
	ObjectTypeQuery1, ObjectTypeQuery2, ObjectTypeQuery3, ObjectTypeQuery4, ... �̷��� ���ٵǾ����µ�
	�⺻������ ObjectTypeQuery6������ ������ �⺻ �����ϴ� ObjectType��(ObejctTypeQuery1 : WorldStatic, ObejctTypeQuery2 : WorldDynamic, ObejctTypeQuery3 : Pawn ��)
	������ ���߰����ϰ�
	ECollisionChannel�� �ٸ��� Custom ObjectType�鿡 ���ؼ� Channel�� ������� ObjectType�� �߰��� �����θ� �����Ѵ�

	ex) Object1 - Channel1 - Channel2 - Object2 ������ �ݸ����� ���� Ŀ���� ���ǰ� ����� �Ǹ� 
	ObjectTypeQuery7 : Object1 �̰�
	ObjectTypeQuery8 : Object2 �� ����

	3) ETraceTypeQuery : 2���� ������ Obejct�� Channel�� ���̸� �����Ѵٸ� ���� �����

	ex) Object1 - Channel1 - Channel2 - Object2 ������ �ݸ����� ���� Ŀ���� ���ǰ� ����� �Ǹ�
	TraceTypeQuery3 : Channel1
	TraceTypeQuery4 : Channel2

	12. ����� �������� ����� ���� ä�ο� ���ؼ� #define COLLISION_WEAPON ECC_GameTraceChannel1 �� ���� ��ũ�θ� ����� ���� �ǰ���
	- ex. #define OBJ_COLLISION_OBJECT1 EObjectTypeQuery::ObjectTypeQuery7
	- ex. #define CHN_COLLISION_CHANNEL1 EObjectTypeQuery::TraceTypeQuery3
*/