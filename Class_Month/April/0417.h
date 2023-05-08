#pragma once
/*
	1. SpringArm::TargetOffset, SpringArm::SocketOffset
	- TargetOffset : RootComponent�� WorldLocation�� �������� World �󿡼��� x,y,z�� ���� ��ġ
	- SocketOffset : RootComponent�� WorldLocation�� �������� Root�� Local �󿡼��� x,y,z�� ���� ��ġ

	- �������� Player�� world�� ��ġ�� ������ rotation�� ��¦ ������ �׽�Ʈ���� �� Ƽ�� �� �ȳ��µ�
	- rotation.x�� 90 ȸ���ϰų� rotation.y�� -90 ȸ�� �� targetoffset.z�� socketoff.z�� �ٲ㺸�� ��� �ٸ��� �� �� ����

	2. WidgetComponent�� ���� �ִ� BeginOverlap, EndOverlap, Hit �̺�Ʈ ���� ��򰡿��� ��� ���� ���̰� ����� ���� �� ����(Ȯ������ ����)

	3. Timeline�� Play, Reverse�� ������ �������� pause �س��� �κк��� �ٽ� �����ϴ� �����̰� PlayFromStart, ReverseFromEnd�� ������ ���� Ȥ�� ������ ���� �����ϴ� ��
	- Play, Reverse�� Stop�ɿ� ���� �߰��� �����Ǵ� ��찡 �ִµ� ������ �������� �ٽ� Play Ȥ�� Reverse�� �� �� �ִ� ��

	4. ���� ��ȹ�� �ǵ�� �߿�

	���� ��ȯ(+CameraFade): 
	- ���� ��ȯ �����ؼ� OpenLevelByName ���� OpenLevelByObjectReference�� ���� �Ѿ�� �� ���ٰ� �Ͻ�(���ڿ� ������ ���̱�)
	- ������ ��ȯ�Ǿ PlayerStart���� �����Ǵ� �� pawn�� �� �� ������ ������ ��� �ʱ�ȭ �Ǵ� ���̰�
	- �׷��� ������ �����ϰ� �� �� �ִ� ���� GameInstance��(������Ʈ ���ÿ��� ���� ���� GameInstanceClass ��������� ��)
	- GameInstance�� �̱������μ� �����ϰ� ���������� ��Ƶδ� �������μ� Ȱ���� �� ����(Save & Load ��� �����ϰ� ó���Ϸ��� ����غ��� ��, ������Ʈ �Ը� Ŀ���� ���)
	- ���� ��ȯ �� Ź �ϰ� ī�޶� �Ű����� �ͺ��� scene�� fade�Ǹ鼭 openlevel�� �ʿ��� �ð��� ���� �ε巯�� ȭ����ȯ�� �����ϰ� ���� �� ����
	- �� �� ����� �Լ��� StartCameraFade���� FromAlpha�� 0, ToAlpha�� 1�̸� ȭ���� ��ο����� ȿ��, FromAlpha�� 1, ToAlpha�� 0�̸� ������� ȿ���� �� �� �ְ�
	- Duration��ŭ Delay�� �ɾ��� ���� OpenLevel�� ���ָ� ��
	- open�� level�ʿ��� ���� �������� beginplay���� ��ο��ٰ� ������� ȿ���� �ָ� ��(level �������� �� �۾��� �ؾ��ϴ� �� ����)

	Spawner :
	- Map ������� ���� Class ����Ʈ�� ���ͼ� ���� ������ ���� ������(spawn�� ������ Ŭ������ �����ؼ� �̸� ������ �� �󸶳� ���� spawn������ float����(SpawnTime)�� ��� ��)

	������ ��ƼŬ ��ġ : 
	- �ٲ� �ʿ� ����

	Homing�ϴ� ��ų :
	- GetAllActorsWithTag -> SphereOerlapActors �Լ��� ��ü(������ �Լ��� ��δٰ� ��)
*/