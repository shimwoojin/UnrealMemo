#pragma once
/*
	1. FMath::IsNearlyEqaul()
	- ���� ��� ���� ���� ����

	2. �򰥷ȴ� for��

	 for(int32 i = 0; i < 5 && Data == nullptr; i++
	 {
		Data = FindData(i);
	 }

	- (i < 5)�̰� (Data == nullptr)�� �� �� true���� for���� ���� ��

	3. ���� ����
	- ��ֹ� Ȯ�� -> �Ӹ� �ʿ� ��ֹ� �ְ� ���� �����ϸ� climb -> �ƴ϶�� �Ʒ� �ʿ� ��ֹ� ���� ���� �����ϸ� slide -> �ƴ϶�� �Ϲ� ����
*/