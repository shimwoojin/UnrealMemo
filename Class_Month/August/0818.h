#pragma once
/*
	1. �ܹ�, ������ �ٲٴ� ���� �ַ��
	
	enum EFireMode
	{
		Single,
		Auto
	};

	TArray<EFireMode> FireModes = { EFireMode::Single };
	EFireMode FireMode = FireModes[0];

	//�ܹ�, ���� ��ü ��
	FireMode = FireModes[(FimeModes.Fina(FireMode) + 1) % FireModes.Num()];

	- enum�� ������ ���߰ų� FireModes �迭�� �� ������ ������ ������ ���� �� �ִ� ���� �����ؾ� ��

	2. ������ ������ Timer �̿�
	- �ٸ� ������ ���� ���,,

	3. AudioComponent�� �⺻�� 3D ���忩�� Camera�� ��ġ�� �������� �Ҹ��� �ٸ��� �鸲
*/