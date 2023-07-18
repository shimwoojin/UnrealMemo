#pragma once
/*
	1. class UParkourComponent : public UActorComponent {} ����

	2. enum ����
	- enum class�� ������ BlueprintType�� �ٰ� �Ǹ� : uint8 �� ���� �� -> �� Ű���� ���� UENUM()�� �Ѵٸ� Ÿ�� ��� ����
	- namespace�� ���� enum�� : uint8 ���� ���� �Ұ��� -> enum class�� ������ ��
	- namespace�� ���� enum�� TEnumAsByte<>�� �����Ǵ� ��찡 �ִµ� �� ���� Member Variable�� ���

	3. <namespace�� ���� enum> vs <enum class>
	- ���� ���� Ȥ�� ���ó�� �����ٶ�� �� �� ���� -> enum class�� ��� ���������� auto cast�� �� �Ǳ� ������ �̷� ��Ȳ
	- enum�� ��ġ�� ���� ���� ������ ���� / enum class�� <���ÿ�> ���� ����

	4. ���÷��ǿ� ������� ���� �ڵ带 ���÷��ǿ� ����� �ڵ忡�� ����� ��� ������ �� ����
	- typedef 

	5. ����ü�� ������ ���̺�� Ȱ���ϱ� ���ؼ� : public FTableRowBase �� ���
	- #include "Engine/DataTable.h"
	- ����̱� ������ �θ��� ��� �ʿ�
	- ���� ������ ���̺��� ���� �ֱ� ���ؼ� class UDataTable* DataTable; �� ������ ��

	6. ������ ���̺� TArray�� ������
	- TArray<FParkourData const*> Rows;
	DataTable->GetAllRows("", Rows)
	- Rows�� ������ ���̺��� ���� ���ڷ� �Ѱ� �޾ƿ��� �ǵ�
	 ""�� �ѱ�� �� ��� rows�� �����ڴٴ� �� -> "" �ȿ� �̸��� ���Ե� ���ڿ��� �ִٸ� �� �༮�鸸 ������ ��

	 7. static ��� ������ UPROEPRTY Ű���� ���� �� ��(static�� Ÿ�Ը����� �о ������ �� ����)
	 - ��ȸ�ϴ� ����� static ��������� ��ȯ�ϴ� Getter�� ������ �������ָ� ��

	 8. ���������� ���� �����̳�(map���� key�� �迭�� ������ ��)�� �������� ����� �ȵ�����
	 - ��ȸ : ����ü�� �迭 ����� ������ �� ����ü�� key�� ������ map ���� -> �ǻ���� ���� ����
*/