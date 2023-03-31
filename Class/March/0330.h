#pragma once
/*
	1. Hitó���� �ϱ�� ��
	- �ִϸ��̼��� ó������� �ϰ�
	- ü�� ����
	- ü���� 0���� ������ ū���� ���� hit, die �б�

	2. �������� ���� ü���� ���̴� �κп��� �����̳� �� ��Ÿ ��ҵ��̶� ����� ������ �ʿ��ϴٸ�
	- mathexp ��� ���

	3. sequnce�� ����ؼ� then0������ ���� �ް� �� ������ ü�¾� ���� 0���� ū�� �ƴ��� �˻��ؼ� ���¸� �������ְ�
	- then1������ ���� ���¸� ���� ���� ���¿� �´� ��Ÿ�ָ� ���
		- DamagedData�� DiedData�� ���� �����Ϳ����� ���� 0�� �迭�� ä������
		- �ε����� 0�� �ָ� ��(�ε����� ���ϴ� ������ ��� ��, �پ��ϰ� �°ų� �״´ٸ� ���⼭ ó��)

	4. LifeNow�� Beginplay���� LifeMa�� set����

	5. ��Ÿ�ְ� �������� ������� �ʴ´ٸ� ��κ� ���� ����

	6. ü�¿� ���� �ִϸ��̼��� �� �������� �߰����� ó���� �ʿ���
	- �׾��µ� �ٽ� ���� �� ����
		- ���¸� Died�� �ٲ� ���� GenerateOverlapEvent(capsule) ����
	- �׾��µ� �� �����
		- GenerateOverlapEvent(capsule) �� ���Ŀ� DestroyActor�� ó��(�ٷ� ������� �ϸ� �ȵ�)
		- Delay ��� ����
		- SetLifeSpan���� �� ���� ó�� ����
		- �� ���� ó���� ��Ÿ�� ��� ����� BlendOut�ɿ��� Died ���� ���� üũ�� �� DestroyActor���ָ� �� (BlendOut�� BlendTime �⺻�� 0.25, ���� 0.25�ʴ� �������)
		- �� ����� ����� �� ������ Died�ִϸ��̼��� ������ �� ���� ���� ���
			- Died_Montage�� ���� BlendOut�� BlendTime�� 0���� �ٲٰ� Completed���� Died�� ��� DestroyActor���ָ� ��, Died�� �ƴ� ��� SetState(Idle)
	- �׾��µ� ���� �Ͼ
		- �� ó���� �ߴٸ� �̷� ������ �߻� ���Ұ����� ���� �� �ɼ��� BlendOut

	7. ��Ÿ�ָ� ����ϴٰ� �ٸ� ��Ÿ�ְ� ����ǹ����ٸ�? (���� ��Ÿ�ְ� ����ٸ�)
	- ���� ��Ÿ���� BlendIn�� ����ȴٰ� ��

	8. ���� �� flash�� ��(�ǰ� ����� ���� ���ϰ�)
	- Material�� ���� �ٲ��ִ� �������
	- Runtime���� Material�� ��ȭ �Ұ���
	- Beginplay���� Material�� DynamicMaterial�� �ٲٰ� �����ؾ� ��
	- Mesh - GetMaterials(MaterialInterface, Material�� �ֻ��� Ŭ����) - ForEachLoop - CreateDynamicMaterialInstance
		- ������ 2���� �ִµ� ����� �ٽ� Set�� �ؾ� �ϴ� ������ �ְ�
		- �����ڸ��� ������ִ� ������ ���� (�� �ϳ� �� �ִ°� �� ����, primitive component)

	9. ���� material�� �ٲٰ� ���� AnyDamage���� �� Material�鿡 ���� MaterialInstanceDyanmic�� ����ȯ�ؼ� ��� ( ���� �ִ� ���� ������ LinearColor)
	- SetVectorParamaterValue ��带 ���� Material�� ��� �ִ� BodyColor�� �ٲٴ� ������� ó���غôµ� �� ����� �ʹ� ������ ���ڿ������� ������
	- �����ϰ� ���� �� �ְ� EmissiveColor��� parameter�� ���� ���� ���ؼ� �Ѱ��ָ�
	- Material�ʿ��� ���� ���� ���� EmissiveColor�� ��� ���� ����
	- �ٵ� �� ��ĵ� ���� ���� �κа��� �� ���ϰ� ���̰� ���� ���� �κа��� ���ϰ� ���̴� �� ������ ����

	- Material�� ��Ŭ�� �� �ν��Ͻ��� �ϳ� ����� �ش��� BodyColor�ǿ� üũ �� ���� 0 0 0 0���� �ٲ���
	- ��� ��Ƽ���� �� �̷��� ���ְ�
	- BP_Enemy�� �̰� �������� (�ϴ� �̷��� ������, �Ƹ� �߰� �۾� ���� ��)

	10. ���� �� ���ۿ��� ����� ó���� ����
	- AnyDamage�� Instigator - GetControlledPawn - SetCustomDilation(0.01) - Delay(0.1) - SetCustomDilation(1)
	- �̷��� �ϸ� �������� ���Ÿ� ���ݿ��� ���ۿ��� ����

	- ����� �Űܼ� ó�����ִµ�(Overlap �̺�Ʈ�� ������ ���� ����)
	- GetInstigator - SetCustomDilation(0.01) - Delay(0.1) - SetCustomDilation(1)�� ó���� ��
*/