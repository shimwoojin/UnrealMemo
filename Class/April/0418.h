#pragma once
/*
	1. GameInstance�� ������Ʈ&���� -> ��&��忡�� �����ؼ� ���
	- GetGameInstance�� ���� ������(ĳ���� �ʿ��ϴ� ����ȯ�� �س��� �Լ��� ���� return�ؼ� ���� ����)
	- GameInstance�� �̱������μ� �����ϴ� �� ������ ���� ����(������ �����뵵 ������ �ʾƺ���)

	2. HP Bar�� ����� ���� WBP�� ����� Canvas �г� �����ְ� SizeBox�� �߰�����(SizeBox�� �ڽ��� �ϳ��� ���� �� �ִٰ� �Ͻ�)
	- Canvas �г��� ȭ�� ��ü, SizeBox�� ���� ũ�⸦ ������ �г�(w : 125, h : 25)
	- Border �ڽ����� �߰�
	- Border�� �е��� 2������ �ִµ� �θ��� SizeBox�� ���� �е����� Border ���� content�� ���� �е�����(�츮�� content�� ���� ��ü 5 ��)
	- border�� ������ ȸ�� ��(r,g,b 0.25��)
	- ProgressBar�� �ڽĿ� �߰�

	3. SizeBox - Border - ProgressBar ������ ���
	- ProgressBar�� 0 ~ 1 ������ ����(Percent �ɼ�)�� �θ� ���� ������ �󸶳� ������ �� ���ϴ� ��
	- LeftToRight, RightToLeft �� ��𼭺��� �������� ä���� ������ �� ���� �� ����(Bar Fill Type)
*/