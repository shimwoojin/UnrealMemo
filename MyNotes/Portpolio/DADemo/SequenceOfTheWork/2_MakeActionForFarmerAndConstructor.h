#pragma once
//Farmer, Constructor�� ���� ���� ��

/*
	1. Constructor�� Farmer�� ��ų�� 2���� ����
	- Constructor�� E,RŰ�� ���� SplashTowerMaker, SlowTowerMaker�� Spawn��Ű��
	- Farmer�� EŰ�� ���� �ݰ� �ȿ� �ִ� BP_Crops�迭�� Actor���� ��ȭ�� �ϰ�(�� Actor���� �����ð� �� ��ȭ�� �Ϸ�Ǹ� ��ȭ �߿� ����)
	RŰ�� ���� �ݰ� �ȿ� �ִ� BP_Crops�迭�� Actor�鿡 Damage�� �־� ���� ��Ȯ�� �����ϰ� ��

	2. Constructor�� TowerMaker�� ���콺 ��Ŭ������ Damage�� �־� Tower�� ���׷��̵� �����ϰ�
	Farmer�� BP_Crops�� ���콺 ��Ŭ������ Damage�� �־� �ı� �� Money�� Drop��
	
	3. Farmer�� Constructor�� �� ���� �� AI�� ���� �����Ǵµ�
	- Constructor�� �ֺ����� ���� ����� TowerPoint�� �̵� �� E Ȥ�� R ��ų�� �������� �ߵ��Ͽ� TowerMaker�� �ı� �� Tower�� Spawn ��Ų ��
	���� TowerPoint�� �̵��ϸ� Tower���� ������
	- Farmer�� �ֺ����� ���� ����� Crop�� ã�� �̵� �� ��ų�� ����� ���� ���콺 ��Ŭ���� ���� �⺻ �������θ� �ı� �� Money�� ��� ��
*/