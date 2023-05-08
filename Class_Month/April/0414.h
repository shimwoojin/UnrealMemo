#pragma once
/*
	1. WBP�� <�����̳�>���� �ְ� <�׷���>���� �ִµ� <�����̳�>�� �ȷ�Ʈ�� �߰��� �̹���, ��ư, �ؽ�Ʈ � ���� ������ ���� �� �־���
	- ������ ����� �Ǹ� <�׷���>���� �ٸ� ���� Ŭ����ó�� ������ �� �ִµ�(����, �Լ�, ��ũ��, �̺�Ʈ ����ó, �������̽�, �̺�Ʈ)
	- �̺�Ʈ�� ���ؼ� construct, tick, ���콺 ���� �̺�Ʈ���� Ȱ�� �� �� ���� ��, overlap�̳� hit���� �̺�Ʈ�� widget�� ���� ��

	- ������ ����� ���� �� �� WBP�� �����ϰ� ���� Controller�ʿ��� CrossHair �̹����� ���� ���߿� �ٲ� �� �ֳ� �׽�Ʈ�� �غôµ� ������
	- �� WBP Ŭ������ �����ϰ� ���� controller�ʿ��� <UserWidget ������Ʈ ���۷���>�� CastToWBP_Crosshair�� ���� ������ �Լ��� �������� ������ �����߰�
	- Cast�ϴ� ����� ���� �� ��ٸ� �������̽��� ����� ������ ������ Ȯ�� ��
	- ��Ÿ�� �߿� palette�� �߰��� image ������ ���浵 ������ �� Ȯ������(CrossHair - GetWidget - CastToWBP_CrossHair - CrossHair - SetBrushFromTexture)
	- ����ȯ�� �ؾ� �ϴ� ������ GetWidget�� return���� UserWidget ������Ʈ ���۷��� �̱� ����(�Ƹ� WidgetŬ������ �ֻ��� �θ� �ε�)

	2. UI�� ���ݿ� ���� ��� ���� ���� �� ����� �� �غ����ϴµ�
	- ������ ��ü KDA, ���� �ð�, ���� ���� �� ��ü���� ���뿡 ���ؼ� GameMode
	- CrossHair, HP ��������, �ñر� ������ �� �÷����ϴ� ĳ���Ͱ� �ٲ� ��� ȭ�鿡 ����� �ϴ� ������ Controller
	- Player�� �÷����ϴ� ĳ���Ͱ� �ٲ�ٸ� �ٲ��� �� ������ Player

	- �츮�� ���� CrossHair�� Controller���� ���� ���� ����

	3. BP_PlayerController�ʿ��� WidgetComponent�� �߰����ְ� WidgetComponent�� UserInterface - WidgetClass�� WBP_CrossHair�� �����μ� �츮�� ����� ���� Ŭ������ ����
	- WidgetComponent - GetWidget - AddToViewport�� �����μ� �츮�� ���� ũ�ν��� ȭ�鿡 ��� �� �־��µ�
	- UserInterface - Space���� Screen���� ������ �ٲ��־��µ� World�� �츮 ȭ���� �ƴ϶� ���忡 �ν��Ͻ��� ���Ե� ��ó�� ����ϴ� �� ����

	- �Ǿ��ߴ� �κ��� GetWidget�� ���� ���� ���̰� �̰� ���� WidgetComponent��� ���� WidgetClass�� �����ϰ� �ٸ� �߰����� ����� �� �� �ִ� �Ŷ�� ������
	- �׷��� ������ �غôµ�
	- ������ <UserWidget Ŭ���� ���۷���>�� �߰��ؼ� BeingPlay�� CreateWidget�� ���� ����� �Ǹ� component���� GetWidget���� ���� �Ŷ� ���� ȿ������
	- Ŭ���� ���۷����� �߰��ϱ� ���� <UserWidget ������Ʈ ���۷���>�� �־� ���� WBP_CrossHair�� �����ַ��� �ߴµ� �̰� �Ұ��� �� �� ����

	4. ȭ�鿡 WBP_CrossHair�� ��� �� �ְ� �ƴµ� ShowCrossHair, HideCrossHair�� ���� ZoomIn�� ���� ���� �� ������ ȭ�鿡 ǥ���ϰ� �ٲ��ַ���
	- GetWidget - SetVisibility�� ���� ��� ������
	- Controller ���� �������̽� �ϳ� ���� ZoomIn, ZoomOut �Լ� �����
	- ShowCrossHair�� SetVisibility�� NotHitTestable(Self&AllChildren)�� �ְ� HideCrossHair�� Collpased �ɼ��� ��

	- SetVisibility�� �ɼ� 5���� ��

	1) Visible : ǥ��o, ��ȣ�ۿ� ����
	2) Collpased : ǥ��x, ���� ����x 
	3) Hidden : ǥ��x, ���� ���� o -> ������ ���� �Ѵٴ� ���� �Ƹ� Zorder�� ���Ƽ� ȭ�鿡 ǥ�õ� �켱������ ���� Widget�� Hidden���� ���������� ZOrder�� ��������� ���� UI�� �������� �� �ִ� �� ����
	�̷� �� Collpased �Ἥ �ٸ� UI�� ������ ���ƾ� �� ��
	4) NotHitTestable(Self&AllChildren) : ǥ��o, ��ȣ�ۿ� x
	5) NotHitTestable(Self) : 4�� ������ �ڽĿ� ����x

	5. 4���� ���� ShowCrossHair, HideCrossHair�� TimeLine�� Start�� Reverse�� �߰��� ������ ��
	- Timeline�� �ɿ��� Finished�� Direction�� �����ؼ� ó���ϰų�
	- PlayfromStart, ReverseFromEnd ���� ������ �� ������ ���� ������ �� ���� ��

	6. Fireball�� ���� ���ư��� ����� �������� ����� �ִµ�
	- ����ü �ӷ��� ������ �׳� ķ ��ġ���� �������� ��찡 ����
	- fps������ ��κ� ķ ��ġ���� �������⵵ �ϴµ� �� ��ġ���� ī�޶� ���� line�� ���� �����ϴ� ����� ����
	- ī�޶� line�� �߰��������� ���ư��� ��쵵 ����
	- linetrace�� �ɸ��� �׳� �̹� �¾��ְ� ��ƼŬ�� ������ ��ĵ� ����(��������)
	
	- fireball�� �տ��� target���� ���°Ŷ� camera�� line�� ���󰡴� �� aim�� �� �´� ������ �� ���������� �±� ������(taret���� ������ �������� ����)
*/