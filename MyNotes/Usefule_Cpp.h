#pragma once
/*
	1. UPROPERTY�� ���� ��������� �̸� ����� �⺻������ �ʱ�ȭ���� �����
	- int32�� ��� 0���� �ʱ�ȭ���� �����

	- UPROPERTY�� ������ ���� �˾Ҵµ� UCLASS ������ � Ű���� ������ �� �𸣰�����(�ƹ�ư ���÷��� �ΰ� ������) int, bool, float �� �⺻ �������� ���� �ʱ�ȭ�� �� �ص� �ʱ�ȭ���� �����

	2. F12�� �Լ��� ���Ǻη� �̵����ִ� Ű������
	- Alt + F12�� �� �ڸ����� �Ķ� â�� ��� ���Ǻθ� ��������ִ� Ű����

	3. ������Ʈ�̸�.h �� <�̸� ������ �� ���> ������ �뵵��
	- ���� �߰��� ������̳� ������Ʈ ������ ���� ��ũ�θ� �����Ͽ� ���

	- �⺻���� #include "CoreMinimal.h"�� <������Ʈ�̸�.h>�� �߰� �Ǿ� �ִµ�
	�𸮾� ������� Uobject ������ �����ϰ� �Ǹ� ������� �� �� �ٿ� CoreMinimal.h�� �߰����ְ� �Ǵµ� �̰� <������Ʈ�̸�.h>���� ��ü�Ͽ� ����ϴ� ��찡 ���� �ִ� ��

	- CoreMinimal.h �� ���ؼ� 4.x ���� ���� IWYU(Include What You Use)�� ������ �Ը� Ŀ���鼭 ������ �ð��� ��������ְ��� ���� �ʿ��� �ʼ� ����鸸 ������
	CoreMinimal.h�� �����ϰ� �ʿ��� �͵��� ���� cpp�� �߰��Ͽ� ����ϴ� ����� ä����

	- 4.x ���� �������� Engine.h Ȥ�� EngineMinimal.h ���� �߰��Ͽ� ���� ��� ������� �߰��Ͽ� ����ߴٰ� ��

	4. �𸮾��� ��� Ŭ������ ���忡 ��ġ���� �ʾƵ� ���� �ν��Ͻ��� �������
	- C++ ������ ���� ���� �Լ�, �߻� Ŭ������ ������ �ʴ� ����
	- ���� ���� �Լ��� �Լ� ����� �ڿ� PURE_VIRTUAL(�Լ� �̸�, ...) �� �Ѱ��ְ� �߻� Ŭ������ UCLASS(Abstract)�� �ϴ� ���� �𸮾��� ���
	
	5. 
*/