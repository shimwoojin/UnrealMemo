#pragma once
/*
	1. ǥ�� - ������ - ��
	- ���� �÷��� �߿� �� Ȯ�� ����

	2. IK�� �ٷ뿡 �־� Effector�� Joint Target�� �˾ƾ� �ϴµ�
	- Effector : IK�� ������ ������ ���� ������ ��ġ Ȥ�� ȸ��
	- Joint Target : IK�� ������ ���� �θ� ��� ������ �;��ϴ����� ���ϴ� ��(�� ���� �߸� �����ϸ� ������ ���̸� �� �� �������� ���δٰų� �� �� ����)

	- Effector�� �̸� ���� ���� ���� BoneSpace�� �Ѱ��ְ�
	JointTarget�� ������ ���� �θ��� BoneSpace ������ �Ѱ��ָ� �ȴ�

	- �� �� �츮�� IK�� foot�� ��������� ������ ���ؼ��� ���� ���� ������µ� ������ ������ �� ��� ������ ��ġ�� �����ؾ� �ϴ� ��찡 �ֱ� ������
	����(�θ� ��)�� ���ؼ��� ���� ���� ����� �ξ� �����ϴ� ���� Ȯ�强 �鿡�� ���� ����

	3. �츮�� ������ IK�� ����� ������ �������� �߻������� �����ϸ�
	- IK�� �����ؼ� ���� ���� ���̿� �°� ���� ��ġ�� �����ϰ�
	- �̷��� ���� �� �޽��� �þ�ٴ� ������ ���ϰ� �Ǹ� ���ϴ� ����� ���� �� ����(�þ�ٰ� �ϴ� �͵� �� ���� ���ݿ� �о����� ���ϴ� ����� �ƴ�)
	- IK �����ϱ� ���� �޹�, �������� ��ġ �� ���� �߸�ŭ ����� �����ְ�
	- ��ġ�� ������ �޹�, �����߿� ���ؼ��� ������ ��ݸ�ŭ ���־�� ��

	- IK ���� �� ���� ĸ������ ���̷�Ż �޽� ��ü�� ���鿡�� ���� ��ġ�� ���� �� ����

	- ���� �����ϱ⿣ ���� �߸� ��ġ�� ������ ������ ���ذ� �� -> ����� �������� ������ ��ݸ�ŭ �ؿ� ���� �ٽ� ���ִϱ� +- 0 �̿��� �ؿ� ���� ��ġ ��ȭ ����

	4. ����Ʈ���̽��� ���� ��ġ��ŭ ������ ���� Ȥ�� IK ���� �ְ� ������ ���� �ִٸ� <����IK> ���� �����ϰ� ó���� ���� ����
	- ���������� ĸ���� ��翡 ��ġ�� �޹��� IK ������ �� �Ǿ ��� ���̸� ���ߴ� ���� ��ü�� �������־�� ��

	5. �ִϸ��̼� ���̾� ���� �������̽��� ����
	- Instance Class�� �����Ͽ� �ٸ� �ִ� ������ �ִ� ���̾ �����ų ���� ����(������ �� �� ���� ��� �����ϰ� �ִ��� �ؼ��� �� �ɵ�;)
*/