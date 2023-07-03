#pragma once
/*
	1. AddDynamic�� ���� ��������Ʈ ���ε�� "::"�� �ʼ���
	- ������ �Լ������� ��Ȯ�� �ؾ� ��

	2. C���� �ȵǴ� ���� �� �� ���� ����

	int const i = 5;
	int arr[i] = {0,1,2,3,4};

	- C++�� ����ϴ� �����̳� C�� �ȵ�
	- ������ C++���� const�� conextpr�� ���� ������ Ÿ�� ������ i�� ���� ����� �νĽ��� �� �� ������
	C�� ������ Ÿ���� �Ǿ�� i�� const�μ� ���� ������ �ʴ� �Һ������� �Ǳ� ������ ������ Ÿ�� ������ ������ ���� �� ����

	3. ���ε��� �Ǿ��ִٴ� �����Ͽ� ��������Ʈ�� ���۽�Ű�� �ڵ� 2������ ����
	- 1) if(Trigger.IsBound()) Trigger.Execute();
	- 2) Trigger.ExecuteIfBound();

	4. NamedBox�� ����� DelegateTrigger�� ������ �̸��� ����� ���ϴ� ������ �ִµ�
	- NamedBox���� Text->SetText(StaticClass()->GetDisplayNameText()); �� �ڵ尡 ������
	- �ذ� : Text->SetText(GetClass()->GetDisplayNameText());

	- �ٸ� �ذ� ������ : 
		Text->SetText(UKismetSystemLibrary::GetDisplayName(this)));
		Text->SetText(GetName());

	5. 4���� ������ ����Կ� �־� �˾ƾ� �ϴ� ������ ����
	- �������� this�� ������ ȣ���ϴ� ���� -> �ڽĿ��� �����ڸ� �θ��� �־� A -> B -> C �� ����� ���״� ���� �� �����ڰ� �Ҹ��� ������ A -> B -> C ��
	A�� �����ڰ� ���ʿ� �־� C�� ���� �ʱ�ȭ�� �� �Ǿ� �ֱ� ������ ������ �Ұ�����

	- �׷��ٸ� 4������ GetClass()�� ���� �� �ڽ��� Ŭ������ ��� �� �� �־��� ������
	UObjectBase���� ��������� ���� ��ӹ��� Ŭ������ UClass* Ÿ������ ��� �ִ� ������ ������ ������ -> GetClass()�� UClass* Ÿ���� ��������� return�ϴ� �Լ�

	- �߰��� UObjectBase�� Actor���� ���� Ŭ�����̰� GetClass()�� �������̵� ���� ���� �Լ����� ������ UObjectBase�� ������ ������ �״�� �ҷ��� �� �־���

	- �����ڿ��� � �Լ��� �ҷ��� �� �ڽĿ��� �������̵� �� �Լ���� �������̵� �� ������ �ƴ϶� �����ڸ� ����� �ִ� �� Ŭ������ ���� �Լ��� �Ҹ� ����

	6. TEnumAsByte�� ����Կ� �־� ���漱���� ������(TEnumAsByte�� �𸮾��� ���ø� ���� Enum��)
	- TEnumAsByte<EDrawDebugTrace::Type> DrawDebugType; ��������� ����
	namespace EDrawDebugTrace { enum Type; }

	7. float �ڷ����� ���� 10�� ��� �̷� ǥ��
	- float MyFloat = 1e5f;
	-> 10�� 5���̶�� �� ->100000

	- float MyFloat2 = 3e5f;
	-> 3 * 10�� 5���̶�� �� -> 300000
*/