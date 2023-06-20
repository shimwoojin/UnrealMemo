#pragma once
/*
	1. StackFrame : �Լ��� ȣ��� �� �Ҹ� �Լ����� ���� ������ �����ϱ� ���Ͽ� ������ ����
	- <���� ����>, <�Ű� ����>, <���� �ּ�>�� ����
	- �Լ��� ������ �� �Լ��� �ҷ��� Caller(���� �Լ�)�� �ּҷ� ������ -> �� �� �Լ� ȣ�� �Ծ࿡ ���� Caller�� StackFrame�� ������ �� Callee�� ������ �� ���ϰ� ��(stdcall, cdecl)
	- VS���� �⺻������ ������ �� �Լ� �ϳ� �� ���� ������ ������ 1MB�̴� -> 1MB�� 1000000Byte�̰� �� ��ġ�� Int(4Byte) 250000(25��)���� ������ �� �ִ� ��ġ��
	- int a[250001]; �� �Ұ����ϴ� ���̰� �� �̻��� ������ �Ҵ��ϰ��� �Ѵٸ� �����Ҵ��� �ϰų� VS�� �⺻���� �ٲ��־�� ��

	2. �𸮾󿡼� ���ڿ��� ����ϱ⿡ �ռ�
	- MBCS(Multi - Byte Character Set) : char (1Byte) -> �츮�� ���� �ƴ� �ƽ�Ű�ڵ� �����ϸ� ��
	- UNICODE : wchar_t (2Byte) -> �� ������ ��� ���� ��� ���� ���� �� 2Byte�� ����Ѱ� ��(���� �˱�� ���� �� 4Byte������ �þ �� �ִ� �� �þ��µ�..)

	- ������Ʈ�� ���ݿ� ���� ���ڸ� char Ȥ�� wchar_t�� �޴� ��찡 �ٸ���

	- �̸� �Ϲ�ȭ �ϱ� ���� TEXT("�� ���ڿ��� ��")�� MBCS�� ���� UNICODE�� �� �� ���� �� �ְ� �س��ٰ� ���� ��

	- �����ϰԴ� ��򰡿� ������Ʈ ���ÿ��� �ٲ� �� �ְ����� �ٺ����� �ڵ�μ� �˾ƺ��ڸ�

	#if defined _UNICODE
	#define TEXT(Text) L##Text
	#else
	#define TEXT(Text) Text
	#endif

	��� ���� ��

	- L�� �� ���ڿ��� �����ڵ����� ��Ÿ���� ##�� ���ڿ����� ������ ���� �����̶�� ���� ��

	3. �𸮾� C++�� ����� ����� �ߴ����� �ɰ�(F9) (Ȥ�� �ڵ��� ������ Ŭ��) F5�� ������� �ϰ� �Ǹ� �����Ͱ� ���� ������ ��
	- �̶� ����� �ϰ��� �ϴ� ��Ȳ�� �����(���͸� ������ ��ġ�Ѵٰų�) <�÷���>�� �ϰ� �Ǹ� �ߴ����� �ɸ��� ��

	- �� ����� ���ŷӴٸ�

	- VS�󿡼� ����װ� ���� ��(F5�� ���� ����)�̰� �� ���·� �ڵ带 �����ϰ� ���� '����' �� ������ �󿡼� '������' ��ư�� ������ �������� ������ '�÷���' ���ָ� ��
	- �ٵ� ��� �̰͵� ���ŷο� ���̴ϱ� �׳� ��� ���� ���缭 �ʿ��� �� ���� �ߴ��� �ɰ� F5 ������ '�÷���' �� �� ����

	4. �� ���ε带 ���� ���� �������� '������' ��ư�� ���� -> VS�� ���庸�� ������ ��

	5. UE_LOG(LogTemp, Log, "���ڿ�", ���� ����)
	- �α׸� ��� ���� 3���� ���� + ���� ���ڸ� �ѱ�� �Ǵµ�
	- LogTemp : �α��� ����, �α��� �� ���� �̸���
	- Log : Verbosity��� �ϴµ� Log�� ����? �󸶳� �ɰ��Ѱ� ������ ����ִ� �Ŷ�� ���� �� -> Log Ű����� �� ǥ�ø� �� �ϴ� Ű������ ��
	- "���ڿ�" : printf�� ������ ���ٰ� ���� �� -> �𸮾� ������ ������ TEXT("")�� ����Ͽ� ������ �ڵ�����

	6. ���÷��� : ��Ÿ�ӿ� Ŭ������ �ڱ� �ڽ��� ������ �� �ִ� ���(� ������ �ְ� � �Լ��� �ְ�)
	- ���� �ľ��� �ٷδ� ���÷����̶� �ᱹ UPROPERTY, UCLASS, UFUNCTION, UPARAM �� �𸮾��� �����ϴ� ��ũ�ε���
	- ���÷����� �����ϱ� ������ C++ ���ο��� ����ϴ� ���� Ȥ�� �Լ����� �� Ű������� ������� �ʾƵ� ��
	- ���÷����̶� �ᱹ <������ Ȥ�� ����>���� ������ �ִ� ��

	7. ������ UPROPERTY() Ű���带 �ٿ� ���÷����� Ȱ���Ѵٸ�
	- �ϴ� UPROPERTY�� ���� C++������ ���� �ۼ��� ������ �������� ��� ����Ʈ�� ���⵵ ���� �ʰ� getter, setter �� ���� �󿡼� �ƹ��͵� �� �� ����
	- UPROPERTY(EditDefaultsOnly) int i; �� ���������μ� ������ Ŭ�������� �� ������ �⺻ ���� ������ �� �ְ� �� -> Instance������ �Ұ���
	- �ٸ� Ű������� ������� ������ �ϰ���
	- EditDefaultsOnly, EditInstanceOnly, EditAnywhere, VisibleAnywhere, VisibleDefaultsOnly, VisibleInstanceOnly, BlueprintReadOnly, BlueprintReadWrite �� �ϳ� ���� �� ����
	- BlueprintGetter = GetterFunctionName, BlueprintSetter = SetterFunctionName �̰Ŵ� �� �� �ẽ�� ��

	- �� Ű���� �߿� EditAnywhere -> VisibleAnywhere�� �ٲٴ� ���� �۾��� �ϸ� Instance���� ���� �� ���� ���ؼ� �ٲ��� �ʴ� �ǵ�ġ ���� ��Ȳ�� ���� �� ����

	- Edit�� Visible �ø���� ������ �� ����

	- ���� ���� : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Properties/Specifiers/

	- Category = CategoryName ���� ü������ ���赵 ����ȭ�ϵ���

	8. �Լ��� �ٴ� �����ڴ� UFUNCTION()��
	- UFUNCTION(BlueprintCallable)�� �����μ� �������Ʈ���� ȣ�� ����
	- BlueprintGetter, BlueprintCallable, BlueprintImplementableEvent, BlueprintNativeEvent, BlueprintPure, BlueprintSetter ��

	- ���� ���� : https://docs.unrealengine.com/4.26/ko/ProgrammingAndScripting/GameplayArchitecture/Functions/Specifiers/

	- UFUNCTION(BlueprintCallable, meta = DisplayName = "Blueprint Node Name")���� ���� �Լ� �̸��� ��ü�� ���� �ִ� ��
	- SpawnActorFromClass�� ���� �������� �̷� �̸��� �� �� ������� ���ΰ� ���� -> C++ ������ SpawnActor<ClassName>()
	
	9. ������Ʈ�̸�.h �� <�̸� ������ �� ���> ������ �뵵��
	- ���� �߰��� ������̳� ������Ʈ ������ ���� ��ũ�θ� �����Ͽ� ���

	- �⺻���� #include "CoreMinimal.h"�� <������Ʈ�̸�.h>�� �߰� �Ǿ� �ִµ�
	�𸮾� ������� Uobject ������ �����ϰ� �Ǹ� ������� �� �� �ٿ� CoreMinimal.h�� �߰����ְ� �Ǵµ� �̰� <������Ʈ�̸�.h>���� ��ü�Ͽ� ����ϴ� ��찡 ���� �ִ� ��

	- CoreMinimal.h �� ���ؼ� 4.x ���� ���� IWYU(Include What You Use)�� ������ �Ը� Ŀ���鼭 ������ �ð��� ��������ְ��� ���� �ʿ��� �ʼ� ����鸸 ������
	CoreMinimal.h�� �����ϰ� �ʿ��� �͵��� ���� cpp�� �߰��Ͽ� ����ϴ� ����� ä����

	- 4.x ���� �������� Engine.h Ȥ�� EngineMinimal.h ���� �߰��Ͽ� ���� ��� ������� �߰��Ͽ� ����ߴٰ� ��
*/