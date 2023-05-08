#pragma once
/*
	1. CameraShake���� �ǰ� �� ������ ������ �����ϸ�
	- �󸶳� ? : 0.25(BlendIn, BlendOut -> 0)
	- Y��ġ�� ���� ���� : 5, �ֱ� : 150
	- Z��ġ�� ���� ���� : 5, �ֱ� : 150

	2. Player�� AnyDamage���� CameraShake�� ó���ϴµ�
	- Player�� ������ Controller�� �����ϰ�
	- Controller�� PlayerController�� Cast�ϰ�(PlayerCameraManager�� �����ϱ� ����, �׳� Controller Ŭ������ ī�޶� �Ŵ��� ���� ��)
	- PlayerController���� PlayerCameraManager�� �����ؼ�
	- StartMatineeCameraShake�� ȣ�� ��

	- PlayPlace�� Local�� ���� / World�� �شٸ� World ��ǥ �������� y,z�� ��鸱 ��(�ǵ��� �ٰ� �ƴ�)
	- StopCameraShake�� �����൵ �Ⱓ�� ������ �˾Ƽ� ����

	3. StartMatineeCameraShake VS StartCameraShake
	- Matinee�� �� ��üȭ �� Ŭ������ return
	- ��ɻ� ���� ���� �ִٰ� �ϼ̱� ������ StartMatineeCameraShake�� ���� �� �� �ֽ��̶�� �Ͻ�
	- �ٵ� ���� �˱�� Matinee�� ���� �� �������� �����̰� Sequence�� �ֽ��� ������ �˰� �־��µ�
	- CameraShake�� Matinee�� �� ���� ���� ��
	
	- SequenceCameraShake ������ ���� Ȯ���غôµ� SequenceSineActor�ΰ� �ƹ�ư �׷����� ��� ��������� ���� ���� ��������� ��(�̰� �� �������� �� �����ѵ� ������ �𸣴� ���߿� �˾ƺ����)

	4. 2������ Controller�� ������ ��Ŀ��� GetPlayerController�� ���� ���� ������ ���� ������� ó���� ���� �Ǿ��߰� GetPlayer�迭 �Լ��� �����ϴ� �� ��������
	- �׷��ٸ� �ܺο��� GetPlayer�迭�� �� ���� ���� �� �ִ� ����� GameInstance�� ����ϰ� ���� ��

	5. ���Ÿ� Enemy�� ����� ���� ���Ӱ� EnemyRanged ����� ����� �� �ְ� ��ų�� 2�� ���� ���� ��
	- BT�� ���Ÿ������� ���� ��

	6. AIPerception���� ���ڿ��� Target�� ��� �κп� ���� ���ڿ� �������� ���̸� ���ٰ� �ϼ̴µ� �� �����
	- Enemy���� Target�� ���� �ְ�
	- Service���� Enemy�� ������ �� �ֱ� ������ Enemy�� ��� �ִ� Target�� BT�� Target�� ��ġ�����ִ� �۾��� �� �� ����

	7. ��Ʈ �ؿ��� ��ü�� Selector

	8. �ϴ� �ӽ÷� �ۼ��� ���������� BT ������ ����
	- Target�� Set�Ǿ� ������ Target�������� ���� ��ų�� �����ϰ� ������

	9. ��ų�� �����ϴ� Task�� ������µ�
	- Tick���� ó���ϱ� ������
	- Idle�� False�� ���� Task�� ������ �ʰ�
	- � ��ų�� Ȱ��ȭ�� ������ �ʴٸ� ��ų�� Ȱ��ȭ ��
	- �ٸ� ��ų�� Ȱ��ȭ �ϱ� ���� ����ġ�� ���� �ִٸ� �ٸ� ��ų�� Ȱ��ȭ�ϰ�
	- ����ġ�� ���� �ִٸ� Task�� �������� ����

	- ����ġ On/Off, �ε����� <�ν��Ͻ� ����>���� BT���� ����

	- ��ų�� �����ϴ� ���� ��ü�θ� ���� �׳� ��ų�� �����ϱ⸸ �ϸ� �Ǳ� ������ ���������� �ٸ� ��ų�� On�Ǿ� ���� ���� ����ó�� ������ �����غ��̴� ��

	10. <���ڷ�����>���� Task�� ���� ���̰� ���� ���� ���ѹ������� �ִ� ����� �ִµ�
	- <���ڷ����� - ������>�� FlowControl �ǿ��� <������ �ߴ�>, <NotifyObserver> ���� �Ը��� �°� �ٲ��ָ� ��

	10.1) ������ �ߴ�
	- None : �ƹ��͵� ����
	- Self : �ڱ� �ڽ�
	- LowerPriority : ���� �����ϴ� ��庸�� �ʰ� ���� �� Task��
	- Both : Self�� LowerPriotiry�� ���� Both�� �ڱ� �ڽŵ� ����ϰ� LowerPriority�鵵 �� ��ҽ�Ŵ

	- � ���� ��Ұ� ������ ���ؼ� �����ϰ� ���� ����� Ȯ�� ����

	10.2) NotifyObserver
	- ResultChange : Setting�� ���� None�� �ưų� ���� ����ų�
	- ValueChange : Setting�� ���� �ٲ��ų� None�� �ưų� ���� ����ų� -> ResultChange�� ���� ȣȯ

	- ������ �ߴ��� Ư�� MoveTo ���� Task�� ���� ����ϸ� ������

	11. 8�� 9����� ��ų�� �����ϰ� ��ų�� ������ Montage�� ����ϴµ� ��ų ��ü�� Fireball�� �� ����
	- �� ������ ��ų ���ο��� ���� ������ ���ϴ� �Լ��� ����(��Ȯ���� Camera�� Cast������)�߱� ������ Fireball�� Spawn���� �ʱ� ������
*/