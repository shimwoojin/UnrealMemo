#pragma once
/*
	1. SetupAttachment�� �����ڿ��� ���� ������ �θ� ������Ʈ�� ������ ���ϴ� ��찡 ��κ��ε� ���ܰ� ����
	- Mesh �迭���� ������ ��ġ�� attach �Ϸ��� ��� SetupAttachment�� �Ұ�����
	- �� �� ����� �� �ִ� �Լ��� AttachToComponent�̰�
	- �� �Լ��� ó�� ��ġ�� OnConstruction���� ��� ��

	- �����ڰ� �ƴ� OnConstruction�� ������ �ִµ� �����ڰ� ����Ǵ� �������� SkeletalMeshComponent�� SkeletalMesh�� ������ �� �Ǿ� ���� �� �ְ�
	������ �� �Ǿ� �ִٸ� ���� ������ ��������൵ Root�� �ٰ� �� ����
	- ���̷�Ż �޽��� �������� �𸣰� ���Ͽ� attach �ؾ� �ϴ� Ư���� ��Ȳ ſ��
	- OnConstruction���� AttachToComponent�� ó���ϴ� ����

	2. ���� ���� - ����
	- �� ������ ������ ��Ȳ�� �Һ��� �����ۿ� ���� ���� Ŭ������ ��ȭ�ϰ� �Ǹ� ������ Ŭ�������� ���� ���̰� �� ��Ȳ�� ������ �����ϱ⿡ �������� �ȴٴ� ��
	
	StudentBuilder& SetName(FString const Name)
	{
		this->Name = Name;
		return * this;
	}

	StudentBuilder& SetID(int32 ID)
	{
		this->ID = ID;
		return * this;
	}

	Student* Build()
	{
		return new Student(ID, Name, Grade, PhoneNumber);
	}

	void Function()
	{
		Student* S = StudentBuilder()
						.SetID(123)
						.SetName("woojin")
						.Build();
	}

	- �ٽ��� �����ϰ��� �ϴ� Ŭ������ �ְ� �� Ŭ������ �������ִ� builder Ŭ������ ���� ��
	- �� builder Ŭ������ �����ϰ��� �ϴ� Ŭ������ �Ӽ��鿡 ���� setting�� �ϴ� ���̰�
	- setting�� �ϰ� ���� builder �ڽ��� ��ȯ�����μ� ���������� �ڵ带 �ۼ��� �� �ְԲ� �ϴ� ��
	- ���� ������ Ŭ������ ���� Build��� �Լ��� �������� ����ϴ� �ͱ����� ���� �����̶� �� �� ���� �� ����

	- ��� ���⿣ ������ Ŭ������ �����ڿ��� ���ڸ� �� �޾Ƽ� ó���ص� �Ǵ� ������ ������ ���� ������
	- Builder ������ �����μ� �⺻���� ���ؼ� �����ϰ� ������ �Ӽ��� ���ؼ��� �����Ͽ� ������� �� �� ����
	
*/