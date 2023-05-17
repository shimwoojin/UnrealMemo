#pragma once
/*
	1. ü�� �������� ���� �Ӹ����� ����ֱ� ���� ����� �� WBP_Gauge�� ��������־�� �ϴµ�
	- Character Ȥ�� Enemy�� WidgetComponent�� �߰��ϰ�
	- ���� Ŭ������ WBP_Gauge�� �������ְ�
	- World�� �ƴ� Screen���� �ٲٰ�(World�� ��� �����̽� �ø��Ǿ� �� ������ ������ ����)
	- ���ϴ� ������� ��θ� ���ְ�(üũ ���ϸ� WBP_Gauge�� �츮�� ����� �� ũ�Ⱑ �ƴ϶� ������Ʈ���� ���� ũ��� ��ο� ��)
	- AddToViewPort�� ���� ������ ���� ��(ĵ���� �г��� �ƴ϶� SizeBox�� �׷��� ?)

	2. ü�� �������� ü���� ���ϸ� ������Ʈ �Ǿ�� �ϱ� ������
	- WBP_Gauge�� ProgressBar�� Percent ���� ü���� ���ϴ� ���� ������Ʈ ���־�� ��
	- ü�� �������� �����ֿ��Լ� LifeNow / LifeMax �� ���� Progress�� Percent�� �����ؾ� ��
	- WBP_Gauge���� �Լ��� ���� ����ȯ�ؼ� AnyDamage���� ó���� ���� ������ �������̽��� ����Ͽ� ����

	- ��� AnyDamage������ ó���ϱ� �ϴµ� ü���� ȸ���Ѵٴ��� �ִ�ü���� ���Ѵٴ��� �ϴ� ������ �׻� ü�°������� ������Ʈ �ϴ� �ڵ尡 �־�� �ϴµ�
	�� ����� ���� ���� �� ������

	3. ������ ����� �� �ǰ� �ٸ� ������ ��ǰ���μ� �� �� ����
	- ��ǰ���μ� ���� �� ������ <����� ����> ��

	4. character�� skeletalmesh, collision ���� �ٲ� �� ����
	- cpp������ �����ϴٰ� ��

	5. ����ȯ ��� �������̽��� SetGaugeRatio, SetGaugeColor�� �����ϴ� �� �ʹ� ���������� �н�
	
	6. LinearColor�� 0 ~ 1 ������ ������ ǥ���� ��
	- RGBA ������ ���ؼ� �� ä�� �� 8��Ʈ �� �־ 0 ~ 255�� ������ ǥ���ϰ� ä�� �� 10��Ʈ �� �־ 0 ~ 1023�� ������ ǥ���ϰ�
	����, �Ķ�, �ʷ��� �ִ� ��(?), ���ϱ�(?)�� 255���� 1023���� ���ƾ� �ϱ� ������ �� ������ ǥ���� �� linearcolor

	- BPC : BitPerChanel, R,G,B,A�� ���� �� ä�ημ�. A�� Color�� �ƴϱ� ������ BitPerColor�� ��Ȯ�ϰԴ� �´� ���� �ƴ�
	- BPP : BitPerPixel, R,G,B�� ä���� ���� �� ��Ʈ ��. Alpha�� ���Ե��� ����

	7. ������ ������Ʈ�� ���� ���� �׻� GetWidget Ȥ�� GetUserWidgetObject�� ���� ���� Ŭ���� �ҷ����� �� ���� ����
	- Ư�� �������̽����� ���ϱ� WidgetComponent�� �������̽����� �ص� �������� �۵��� �� �ϴ� ��� �߸����� �� ���� ����

	8. ���� �Ӹ����� gauge�� �Ӹ����� ������� �÷��̾�� playergauge�� ���� ���� ó���Ұǵ�
	- �ϴ� �̷� �� ó���ϱ� ���� ���� �����ε� 2�� ������ �ϳ� �����غ���
	- �̹� ���̽��� �׷��� �� ��
	- SizeBox�μ� �ν��Ͻ� ���� �����ϴ� ������ �ƴ϶� �츮 ȭ�鿡 �� ä���� ������ UI�� ������ �ű� ������
	- ĵ���� �гο� �ٽ� �������־�� ��(����� �� WBP_Gauge�� <����� ����> �ǿ��� ��Ȱ��)

	9. ���� �� ������ �ִµ�
	- ȭ�� �»�ܿ� �÷��̾� �������� WBP_PlayerGauge�μ� �ߴµ�(Player���� WBP_PlayerGauge�� ���� AddToViewport���� ����)
	- �÷��̾� �Ӹ� ������ �������� ��(���� �ð��� �ذ��غ����)
	- WidgetComponent�� HiddenInGame�� Ű�� �ذ�Ǳ� ��
*/