#pragma once
/*
	1. ��Ƽĳ��Ʈ ��������Ʈ�� ����� ���
	- TMultiCastDelegate<void(int)> a;
	Ȥ��
	- DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiTriggerType, int32, FLinearColor)

	2. UBT�� UHT�� ��ó������ �� ���� ����Ǵ� �𸮾��� ���� �����
	- UBT : Unreal Build Tool
	- UHT : Unreal Header Tool

	- UHT�� ���� UCLASS(), UFUNCTION()���� Ű������� �а� ���� ó���� �ϱ� ������ ClassName.generated.h�� ��ó���� ���Ͽ� ���ԵǴ� �������� ������ ������ ����
	- ����� Ȯ���غ��� �� ������ Ȯ���� �� ������ <���>�� �ִ� ������ �������� ����

	3. public�� ���� �ø��� �� ����ȭ
	- ���� ���ϱ� ����

	4. ������Ʈ�� �Ϲ� �迭�� ����� UPROPERTY()�� ���÷������� �����Ű���� �ϸ� ù ��° ���ڸ� �����ϰ� ������� ����
	- TArray<> �������
	- Ȥ�� ������Ʈ�� �迭�� ������ ����

	5. ��Ƽ������ �޴� �ڷ��� �߿� UMaterialInterface�� ����
	- ���� ��Ƽ������ UMaterialInstanceDynamic��
	- ��Ƽ������ ������ ��ȣ�ۿ��� �ϱ� ���ؼ� UMaterialInstanceDynamic �ڷ����̾�� ��(Cast)
	- ��Ƽ���� ������ ������ �� ���� ��Ƽ���� �ִ� ���� �̸��̿��� �ϸ� ���ڿ��� �Ѱ��ִ� ���� ����

	6. FString�� FName�� �Ͻ������� ��ȯ�� �� �ִ� �� ������
	- �����ڿ��� explicit���� Ȯ�� �ʿ�

	7. meshes[i]�� ���ڿ��� �״�� ������ ���� ���� ADDDYNAMIC, BINDDYNAMIC �� ����
*/