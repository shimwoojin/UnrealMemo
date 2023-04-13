#pragma once
/*
	1. ApplyRadialDamage�� �ٿ����κ��� �־������� �������� �� ���°� �⺻��
	- �յ��ϰ� �ַ��� bool�� üũ����� ��

	2. fireball�� ��� ��ġ���� � �������� ������ �ϴ����� �����ε�
	- �տ��� ������ �ϰ�
	- ���س��� �� �������� ������ ��

	- �տ��� �����°� GetInstigator - GetComponentByClass�� �Ͽ� SkeletalMeshComponent���� ������ ���Ŀ�
	- SkeletalMesh�κ��� Socket��ġ�� �޾ƿ��� GetSocketLocation���� hand_r�� ��ġ�� �޾ƿ�

	3. 2�� ����� ������ ������ �����(������� GetComponentByClass�� �Ұ��ϱ� ���� ����� ����� ��
	- �� ����� ���� ����ؾ� �Ѵٸ� ���
	- GetInstigator - CastToCharacter - GetComponentByClass - IsValid - GetSocketLocation ������ ���ų�
	- Interface�� Character�� ��ӹ޾Ƽ� GetSkeletalMeshSocketLocation ���� �̸����� �ǳ��ִ� ����� �׳��� ������ ��

	- FireBall���� �޾ƿ� SkeletalMesh�� SetSkeletalMesh ���� �Լ��� ĳ������ �޽ø� �ٲ������ ������� �� ������ ���� �������

	4. GetComponentByClass�� �� class�� ������ �ִ� Ư�� component�� ó�� ������ �� �׳� �� �ϳ��� ��� ���� (���� ������ ���� ������Ʈ�� �ɸ� Ȯ�� ����)
	- GetComponentsByClass�� �� class�� ������ �ִ� Ư�� component�� ���δ� ������� �迭�� ��������

	5. FindLookAtRotation���� ���������� ������ �ְ� �� ������ Destination�� �־ Projectile_FireBall�� Rotation���� �Ѱ���
	- ���� fireball�� rotation�� ������ ��

	6. ���� fireball�� overlap�� �ȵǸ� �Ҹ��� �ȵǴµ�
	- �ð��� ������ ���͸� ������� �ϱ� ���� lifespan�� �������־�� �ϴµ�
	- actor�� �⺻ ���� ����

	7. �ð��� �� �Ǽ� ����� �� �����ؼ� ���õ� ��������
	- ���� �������� ���Ϳ� �¾��� �� �������� �ִ� ����� beginoverlap���� ó���ϰ�
	- DestroyedActor�̺�Ʈ���� ���õ��� ó���� ��(�� �̺�Ʈ�� �Ҹ� ������ �����ϴ� ��, ���� Actor�� None�� �ƴ�)
	
	8. �浹�� ���� ��� �¾Ҵ����� ó���ϴ� �� ������ ���Դµ�
	- component�� overlap���� � component�� �ε����������� GetObjectType�� �����ͼ� ����ġ�� ó���� �� ����
	
	- overlap(component����) �̰� ���� �� �غôµ� overlappedcomponent�� ������ ���� �ڱ� �ڽ��̰�
	- othercomponent�� ������ ���� overlap�� ����ε�
	- �� �� ĳ���ʹ� mesh���� collision�� �ְ� capsule���� collision�� �־ ���� ������ ������ �غôµ�
	- overlapevent�� �� �� �����ִٰ� �������� �� mesh�� �浹�Ǿ���
	- ���� ������ mesh�� overlap �̺�Ʈ�� �����־��� ������ capsule�� collision�� �Ͼ��

	- enemy���� capsule�̶� mesh���� �Ѵ� overlap���� �غôµ� �����ϰ� ����

	9. fireball�� �� ���¿��� ��Ŭ���� ������ zoomin ���� zoomout�� ����� ����
	- BP_skill�� �� Ŀ���� �̺�Ʈ BeginActionB, EndActionB�� �����
	- BP_Fireball���� ������ �� �� GetInstigator���� Zoonin, Zoomout�� ���� �������̵� �� BeginActionB, EndActionB�� ����
	- ���� ZoomIn�� ZoomOut�� player���� ����

	- �ᱹ zoomin, zoomout�� �ϱ� ���� ���� �ǵ���� �ϴ� �κ��� player�� ������ �ִ� camera, springarm�̱� ������ �� ���� �ǵ�� �Լ�(�������̽�)��
	player���� ó���ϰ�
	- �� �Լ��� fireball�� Ư�� �ൿ���� ���� �ؼ� �����ϰ� �ϰ�
	- ���� �׼� ���ε��� ���� �߰����� current_skill�� Ư���ൿ�� ���ϴ� ���

	- ������ ������ �Ⱬ�ϳ� ������
	- �ٸ� ��ų���� �ٸ� Ư���ൿ�� ���� © �� ��������

	10. Zoomin�� �����ϱ� ���� �ǵ���� �� ������ camera::FieldOfView, springarm::targetarmlength, springarm::socketoffset

	11. �� �Է°� �׼� �Է¿� ���� ���̸� �˾ƺ���
	- �� �Է��� �� ������ ����Ǵ� tick ���� �Լ�
	- ���� �Է��� ������ �� � ���� �������� ���ؼ� �� ������ ó����

	- �׼� ������ �Է��� ���� �� �� ���� ������ ó����

	12. ZoomIn, ZoomOut���� TimeLine�� �̿��� ó���� �ϴµ�
	- float, vector, color, event�� ���� ó���� �� �ְ�
	- event�� ������ 3���� float�� ������� �ٸ�
	- �� �ʿ� � ���� ������ �� �� �ʿ��� � ���� �������� ���������� ������ �� �ִµ�
	�� ���� �÷��̾��� Ư�� ���� set���ָ� �ð��� ���� ���� ���� Ȥ�� ���Ҹ� �� �� ����
	- ���ۿ��� play�� ���� ���� ���� ���·� ���ư��� ���� reverse�ɿ� �־��ִµ�

	- �̶� timeline���ο��� ���̸� ���� ���ϴ� ������ �������־�� ��
	�� �ߴٸ� reverse�� ������ �ʴ� ����� ����(maxwalkspeed�ٲ㺸�ٰ� �˰Ե�)


	
*/