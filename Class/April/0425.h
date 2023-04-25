#pragma once
/*
	1. ���� �ǵ�� �߿� �����͸� �����ϴ� ��Ŀ��� 2������ �ִٰ� �Ͻ� 1) Get���� �ްų� 2) Set���� �����ϰų�
	- ���� ��� Character�� ������ ���� Weapon�� i��� �ϸ� �̰� ó���ϴ� ���� 1) Weapon���� Character�� getter�� ���ͼ� ó���ϰų� 2) Character���� Weapon�� ���� set�� �ϰų�
	- �������� �� ������ �ִ� �� ���������� �� �Ǵ��ϱ�
	- �̰ſ� �� ������ ���� �ִ� �������� IsArmed�� Tick���� Ȯ���ϴ� �� �ƴ϶� Character�� ���� �ٲ� �� �ִ� ������ �˷��ִ� �� �´� ��

	2. Widget�� Component�� �ٷ�� �Ǹ� Ingame���� Transform�� ������ �ϴ� ��� ����ϰ� �ƴ� ��� �����μ� CreateWidget, AddToViewport�� �ٷ�� �� �� ����
	- CrossHair : ������ CreateWidget, AddToViewPort
	- Enemy�� ü�¹� : Widget Component
	- Player�� ü�¹� : ������ CreateWidget, AddToViewPort

	- ó���� Component�μ� PlayerController���� Crosshair�� ���� �۵��� ������ controller�� default�� hiddeningame�̱� ������ ����󿡼� component�μ� �ۿ��� �� �� �� ��.
	Component�� widget�� ����ص� AddToViewport�� �ϰ� �Ǹ� ������ ���� �Ͱ� �� ���̰� ����
	- 2D�� ȭ�鿡 ǥ���ϱ� ���ؼ� Component�� �߰��ؼ� HiddenInGame�ɾ��ְ� AddToViewport�ص� �Ǳ� �ϳ� ���ӻ��� �°� ������ ���� ������,,
	
	3. CreateWidget�� OwningPlayer�� ���� �� �ָ� GameMode���� �ɾ��� default controller�� ���� ��

	4. ü�� �������� ��� ü���� ���ϸ� �������� ���ϴ� �ڵ尡 �׻� �߰��Ǿ�� �ϱ� ������ ü���� ���ϴ� setter Ȥ�� add, sub�� �ϴ� �ڵ忡 �������� ������Ʈ �ϴ� �Լ��� ���� ó���ϴ� �� ȿ���� ����
	- ���� �̷� ���̽��� �ֱ� ������ ������� setterȤ�� getter�� �ִٸ� �װ��� ����Ͽ� ó���ϴ� ���� ����

	5. Character���� SetLifeNow��� �Լ��� ó���ϴ� �κ��� �ְ�
	- SetLifeNow�� ���ؼ� Enemy, Player���� ���� �������̵� �߱� ������
	- Enemy, Player�� ���� �ڱ��� widget�� �´� ó���� ���� ��(������ ������ ��), Character���� Beginplay�� AnyDamage���� 1���� SetLifeNow ȣ��

	6. ���� setter�� ó���ϰ� ���� ���� ���ؼ� return ���ִ� ��찡 ��κ� �� ��

	7. WBP_Gauge���� �������̽� ������(SetGaugeColor, SetGaugeRatio)�� WBP_PlayerGauge���� �� �������̽� ������ְ� ���� �����ؾ��ϴµ�
	- WBP_PlayerGauge ������ WBP_Gauge�� <����� ����> �ǿ��� ��Ȱ���ϰ� �ֱ� ������ 
	WBP_PlayerGauge�� ������ WBP_Gauge�� �������̽� �Լ��� ���ؼ� WBP_PlayerGauge�� �������ϸ� �����ϰ� ���� ����� ���� �������̽� �Լ� ���� ����


*/