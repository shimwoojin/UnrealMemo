#pragma once
/*
	1. UWorld�� Level�� ����� SceneManager�� Scene�� ���� ����
	
	2. GetPlayer�迭 �Լ��� PlayerController�� ����� �Ǿ �������� ó����
	- ��Ƽ �÷��� ���ӿ��� �ο����� �ε����� ���� ����(�� �ε����� ID�ʹ� �� ����)

	3. BT���� <���ڷ�����>�� ������ �ߴ��� ���� �帧�� ���� ���� ��ҽ�Ű���� ����� ����(Self Ȥ�� LowerPriority Ȥ�� �Ѵ�)�� ��ҽ�Ŵ

	4. Fireball�� �׳� Enemy�� ���� �� Enemy�� ���麤�� �������� ����
	- Enemy�� �ǴܵǴ� ������ fireball�� destination ������ �ȵ� ������ �� �� ����(ī�޶� ���� ����)
	- BT���� Rotate�� �Ѵٴ� ������ ���ֱ� ������ ���� ������ �Ѵٴ� ������ �ʿ����
	- Z�� ���̰� ������ �� ������ �Ǵ� �����̱� ��

	5. EQS�� SimpleGird�� ����
	- EQS�� BT���� Run EQS Query�� Task�� ó����
	- �츮�� ���� EQS�� �� Run EQS Query��忡 ������� �ϴµ� ������ �ǿ� Deprecated�� ������ �ֱ⿡ ����
	- ���� ����� EQS - EQS Request���� �ؾ� ��(Query Template)
	- EQS���� ������ ���� �� ��ġ�� ���ؼ� BB�� � ���� ���������� ������ �ǿ��� ����
	- ���� ��%���� Random�� ���� ���� ���ϴ� �ɼǵ� ���� -> �⺻ ���� SingleBestItem

	6. EQS ����� ����� ' ���� �� Ű�е� 3

	7. EQS SimpleGrid�� ������ ��
	- GridHalfSize : Querier Ȥ�� Item�� ��ġ�� �������� ���簢�� ��縸ŭ ( 500�̶�� 1000 * 1000�� ���簢�� ��ŭ ��ġ ���� )
	- SpaceBetween : GridHalfSize�� ������� �����ȿ� �� ��ġ�� �󸶸�ŭ�� �������� ��������
	- GenerateAround : Querier���� Item���� �ε� Item�� � �� �ǹ��ϴ� ���� ?

	8. SimpleGrid�� �׽�Ʈ �߰��غ� (Distance)
	- Test Purpose : Filter Ȥ�� Score Ȥ�� Filter�� Score �� �� ����(Filter�� �� �� �ֵ� �ɷ����� ��)
	- TestMode : Distance2D, Distance3D, Z�� ����, Z ���밪�� ���� ����(2D�� 3D�� ���̴� 3D�� ���� Actor�� Location�� �������� ��, 2D�� Actor�� Location�� X,Y�� Ȱ��)
	- DistanceTo : Querier�� �ְ� �ٸ� �� ���� ���� ?
	- ���� : Minimum�̸鼭 500�� �ָ� 500���� ������ �ִ� �ֵ��� ���� ���͸� �ȴٴ� ��
	- Score : ���� ���� -> �ᱹ ������ ���� ��ġ�� ���ߵǴ� ��
	- Score Equation : InverseLinear�� �Ÿ��� �ּ��� ������ ������
	- Scoring Factor : ������ �׳� ���ϱ� ���ִ� ��(�� ���� ?����)
	- NormalizationType : Absolute VS RelativeToScores�� Absolute�� ������ �������� ���� �ޱ�� ���ڴ� �����ڿ��� ���� ������ ���� �ޱ�Ÿ� �������� ������ �ޱ�
	- Reference Value : �� ���� ���� ������ �������� ���� ���� �űⰡ �� ���� �������� ������ ����(������ ������ ���ƾ� �ϴµ� �ݴ��� ��Ȳ, Linear, InverseLinear�� �ٲ� �� ������ ���µ� �������)
	- Clamp : Ư�� ������ ���� ������ 0��, ������ ���� -> InverseLinear�̸� �ݴ��� �� ?

	- Test�� ���� Test�� �ٿ��� �����ϰ� �ٿ����� On/Off�� ����
*/