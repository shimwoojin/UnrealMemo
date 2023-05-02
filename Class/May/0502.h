#pragma once
/*
	1. Interface�� Naming�� �� �� ����������
	- ex. SkillQ ���� ���̹��� Ű ���ε��� �ٲ�� �Ǹ� Q�� �ƴϰ� �� �� ����
	- ex. DrinkPotion() -> UseItem()
	- DrinkPotion�� ���� ��üȭ�ϴ� Ŭ���� �ʿ� ���� DrinkPotion() �Լ��� ����� UseItem() �������̽��� �����ִ� ������ �ؾ� ���� ������ ��

	2. BT�� ���ڷ����� �߿� IsAtLocation�� ����Ͽ� Target�� �������ϴ� enemy ���� �Ÿ� �˻簡 �����ѵ�
	- �� �� �ν����� AI�� ����� ���ؼ� Aceptable Radius�� 150�� ��
	- �� ���� �ʹ� ���� ������� ������ �ϴٰ��� ���ݸ� �־����� �ٽ� �������

	3. AI�� ������ ���� AI�� ��ǥ�� ���� location�� ���� ���� ���·� ���� SplineComponent�� ����
	- BP_PatrolRoute : �� Actor�� Splinecomponent�� ������
	- BP_PatrolComponent : ActorComponent�̰� ������ ���� Actor�� ������Ʈ ���۷����� ������ <�ν��Ͻ� ����>�� �־ ����� ��ġ�� �ϰ� �� �� Actor�� ���� ������ �˰� ����(���忡�� ��ġ ���� �������־�� ��)

	4. BP_PatorlRoute�� ���� �� ��ġ�ϰ� ���� Point 2���� �����ؼ� ���� ���� ���� �� �ִµ�
	- ����Ʈ�� ���콺 ��Ŭ�� �ϰ� <����> �� ������ ���ܳ� point�� ������ ��ġ�� �Ű��ָ� ��
	- ���� AI�� �̵��� point�� �������� �����̱� ������ ��ġ �� ���ܳ� ��� ���°� �ƴ� Point�� ���ؼ� ������

	5. ��ġ�� BP_PatrolRoute�� ���ϰ� �ٷ�� ��� �߿�
	- ��ġ�� actor�� component�� ���� ���� �ٲ��ִµ�
	- 0�� point -> 1�� point�� ������ Curve -> Constant�� �ٲ� ���� ��� �������� �������� ���� �� �ְ�
	- CloseLoop�� True �ְ� �Ǹ� Point�� �� �������� �ٽ� 0�� �������� �̵��ϰ� �� ( �ƴ϶�� �� ������ �����ϰ� �� -1 , �� -2 �̷��� ������ ����)

	6. BP_PatrolRoute�� ����� ó���� �޶��� ���� �ִµ�
	- 0�� point�� ���� ��ġ�� �ű�� �Ǹ� �׷� �� ����(Actor ��ü�� �ű�� �ƴ϶�)

	7. ������ ���� BP_PatrolComponent�� Enemy Ȥ�� Enemy_Melee�� �޾��ְ� (�뵵�� ���� ��ġ�� ����) ���� ���忡 ��ġ�� Enemy�� ���� BP_PatrolComponent�� ���� ���� ���忡 ��ġ�� BP_PatrolRoute�� ������ �������־�� ��
	
	8. Enemy�� ������ PatrolComponent�� �ϴ� ���� ���忡 ��ġ�� SplineComponent�� ��� �ִ� Actor�� �˰� �� Actor�� SplineComponent�� �����ؼ� ��ġ�� ������ ó���� �ϴ� �� ����
	- �츮�� ����� �� point�� 0���� n������ ���� Index�� �ʿ��ϰ�
	- 1) 0���� n���� ���� 2) n���� 0���� ���� 3) 0���� n���� �׳� �� loop�� ������ ���� bReverse�� �ʿ��ϰ�

	9. �ᱹ Enemy���忡�� �˾ƾ� �ϴ°� �ᱹ ���忡 ��ġ�� Actor�� SplineComponent�� �����ؼ� GetLocationAtSplinePoint(Index�� �� point��ġ�� ���� �� ����)
	- �� ó���� ����� �� BP_PatrolComponent�� ���� ����

	10. GetDestination�� Boolean ��ȯ ���� �ִ� ������ �����Ӱ� patrol point�� ����(0,0,0)�� �� ���� �ִµ��� �����ΰ��� ���� ��� �����ΰ����� �˰� ����


	
*/