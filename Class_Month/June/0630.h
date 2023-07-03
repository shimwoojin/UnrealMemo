#pragma once
/*
	1. NamedBox Ŭ������ ����
	- UBoxComponent, UTextRenderComponent�� ����
	- Text�� ���� ������ ��� ���� ���س��� �����ڸ� �������� ���ӽ����̽��� EHorizTextAligment::EHTA_Center, EVerticalTextAligment::EVRTA_TextCenter��
	��Ÿ�ΰ� ����(SetHorizontalAlignment, SetVerticalAlignment)

	2. ThisClass�� ���� Ŭ������ �Ҽ��� ��Ÿ�� �� ����
	- ex. ThisClass::StaticClass(); Ȥ�� StaticClass();

	3. Overlap�� ���ε��� �ϱ� ���� Actor�� �����س��� ��������Ʈ�� AddDynamic�� ���־�� �ϴµ�
	- AddDynamic�� __Internal_AddDynamic�� ������ ��ũ�� �Լ����� ���ڸ����� �˻��� �ȵ�
	- OnActorBeginOverlap.AddDynamic(this,&ThisClass::OnActorOverlapStarted);
	- �츮�� ������ ���ε��� �Լ��� Ÿ���� ��ȯ���� void�̸� �Ű������� AActor*�� 2�� �޴� Ÿ���� �����־�� ��
	
	4. AddDynamic�� �ƴ� Add�� ����Ͽ� ���ε��� �ϰ��� �Ѵٸ� FScriptDelegate Ÿ���� ���ڷ� �Ѱ��־�� �ϴµ�

	FScriptDelegate SD;
	SD.BindUFunction(this, "OnActorOverlapStarted");
	OnActorBeginOverlap.Add(SD);

	- �� ó���� ���� AddDynamic�� ���� ó���� ������
	- Name���� �޴� ����̳� �ڵ尡 ������� ������ ����

	5. ���������� AddDynamic�� &ThisClass::OnActorOverlapStarted�� �޾Ƽ� ���������� �Լ� �̸��� ���ڿ� ���·� �����ϱ� ��
	- ����Լ��� ��� "::"�� ���ڿ��� ã�� �� �޺κи� �Լ��̸����μ� �����ϰ� ��

	6. AddDynamic���� ������ �Լ��� UFUNCTION()�̾�� ��

	7. �߻�Ŭ������ ����� ����� UCLASS(Abstract)�̰� ���������Լ��� PURE_VIRTUAL(�Լ��̸�) �ε�
	- UObject������ ��ӹ��� ��ü���� ���忡 ��ġ���� �ʾƵ� �ν��Ͻ��� �ϳ� �̻� ��������� ������ CPP�� �⺻������ ���Ұ�����
	- ������ CPP�� abstract�� ���������Լ��� ����� ���� �ƿ� �Ұ����������� ����

	8. NamedBox(����� ���� Ŭ����)�� ��ӹ��� DelegateTrigger Ŭ������ �𸮾� ������� ����� �Ǹ�
	- Actor�� ������� ���� �޸� �߰��� �� ������ ����ѵ�
	- Ư�� ����� UObjectClass.h.Template�� ������ �������ָ� ��(��δ� ���� ���뿡 ����)

	9. VS ���ڸ������� �����ϴ� �θ��� �������� ��� ������ �𸮾� ������Ʈ���� ��� �Ұ���

	10. �θ��� UFUNCTION�� ���� ������ �ڽĿ��� UFUNCTION�� �������̵尡 �Ұ�����
	
	11. MSB ��¼�� ������ ��ü�� �𸮾�� ������ Ʋ�� ����
	- Ȥ�� ����� ����Ǿ����ϴ� �� ���
	- �̷� �� ��� Ȯ��

	12. �θ��� ���� �����ڰ� �𸮾� �����簡 ����� �� ��� public�ε� �� �ǹ̴�
	- �θ��� public, protected, private���� ������ �����ϴٴ� ����(�򰥸��µ� ���� �� Ȯ�� �ʿ�)

	- �𸮾��� public�� �����(protected, private ����� �Ұ�����)

	13. C++�� C�� �⺻�� �޾Ƶ��̰� �� ���� ������ ������
	- Cast�� ��ȣ�� �ϴ� Cast�� Static_Cast ���� �߰����� ������ �����ϸ� ��

	- .cpp�� .c�� ���� ����� �ٸ�
	
	extern "C"
	{
		void Text() {
			_asm{}
		}
	}

	- ȣȯ�� ���ؼ� ���� ���� ������ ������, ��������� ��쵵 ���� ���� ��������

	14. ��������Ʈ�� ���� �����
	- TDelegate<void()> Trigger;
	- �Լ��������� typedef�� ��������Ʈ �������� ���� �Ǹ�
	- DECLARE_DELEGATE(FTriggerType)
*/