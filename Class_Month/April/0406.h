#pragma once
/*
	1. �ڷ���Ʈ ����� ���� ������ ������ �����Ÿ� �̻��� �� ��Į�� �� ���̴� ���ε� 
	- Decal�� FadeScreenSize�� 0���� �ٲ���(default 0.01)
	- ȭ���� �� �ۼ�Ʈ ������ ũ�Ⱑ �۾����� ȭ�鿡�� �� ���̰� �ϴ� �ɼ�(default 1%)

	2. ���ο� ��ų FireStrom�� ������
	- BP_Skill ��ӹް�
	- ParticleSystem �߰��ϰ�
	- ParticleSystem�� AutoActivate����
	- collision �߰����ְ� ũ�� �����ְ�(z��ġ300 ĸ��ũ�� ���� : 500, ������ : 200)
	- ĸ���� overlapevents ���ְ�

	3. �ٴ���Ʈ�� �����ϱ� ����
	- beginoverlap�Ǹ� �迭�� �ְ� endoverlap�Ǹ� �迭���� ����
	- �迭�� ����ִ� �ֵ鿡 ���� 0.���ʸ��� �������� �ִ� ���

	4. �ֺ��� ���� ȭ�� ����� �����ϱ� ���� ��ų �ߵ��ϸ� ĳ������ ���� vector�� ���� ���ͷ� ��� ������ 0���� �ʱ�ȭ����(EndAction, ��Ÿ���� ��Ƽ����)
	- particle�� activate���ְ� capsule�� overlap�� ����

	5. �������̵� ������ �̺�Ʈ���� �����ǿ��� ��Ŭ�� �� �Լ��� ��ȯ ����(local������ �ʿ��ϴٸ�? �Ẽ����)

	6. tick������ particle�� active��� �ұ���� ���ư��� ó���� ���־�� �ϴµ� 2���� ����� ����
	- ����� ����� �ﰢ�Լ��� cos, sin�� �̿��ؼ� actor��ġ �������� ���� ����ؼ� setactorlocation ���ִ� ��

	7. tick���� ������ ���� +1 �� ���ִ� ����� ������ ����
	- ��ǻ�� ��翡 ���� tickȣ�� Ƚ���� �޶� ����� ������ ��ų�� ������ �������� ������
	- AngularSpeed * DeltaSeconds�� Angle�� tick���� �����ָ� ��翡 ������� ���� ����� ���� �� ����

	8. 0.125�ʸ��� �迭�� ��� ���͵�����(�ұ�վȿ� ����) �������� �ֱ� ���� ������ ������
	- Tick���� Delay�� ó���ϴ°� ������ ���(Retriggable�� ���⼭ ���� �ȵ�)
	- Deligate�� �Ἥ �ذ��غ���

	9. SetTimerByEvent�� CustomEvent(DamageEvent���� �Ҵ����ְ� .125�ʸ��� �ߵ��ϰ� �� ó��
	- CustomEvent(DamageEvent�� ���� ó�����ִ� ��

	10. 5�� �ڿ� ��ų�� ���ֱ� ����
	- SetTimerByEvent���� Event�ɿ� EventDispatcher���� �����ؼ� ��ų�� ���� �Լ��� ������(OnTimeOver)
	- �Լ��� �̺�Ʈ�μ� timer�� ���ε����ִ� ����
	- OnTimeOver�� particle�� deactivate�ϰ� capsule�� overlapevents�� ���ִ� �Լ�
	

*/