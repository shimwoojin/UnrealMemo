#pragma once
/*
	1. ��� ��Ŭ�� ��� -> ����, ��Ŭ�� ª�� -> ������ ���� ����
	- Timer�� �� ���� ���� �ϴ� ����� ���� ������
	- Sequence, Gate�� ���� -> Gate ���� ���� �� ��ũ�ο� ���� �� Output�� Gate�� ������� �ʾ��� �� Pin�� ����� �� ���� ����

	2. Spline Component�� �Լ� �� GetLocationAtSplinePoint�� Local�� World�� ���̴� World�� ���� ��ġ �� ��ġ(World�� 0,0,0 ����)�� �Ű� Local�� World�� ��ġ�� Actor�� Gizmo�� �������� ��
	- World�� �ٲ���

	3. BTT_Patrol�� �����ϱ� ���� Controlled Pawn���� GetComponentByClass�� BP_PatrolComponent�� ���Ŀ��µ� �������̽��� �����ϴ� ���� �� ����
	- GetComponentByClass�� �����ϸ� �ȵ� -> ������ �Լ�
	- �������̽��� �ƴ� ����ȯ���ε� ó���� �����ϳ� ��ȹ�ǵ��� �¾ƾ� ��(cast�ϴ� ������ �ڽ����� patrol ����� �����ٰų� �ϴ�?)

	4. MoveToLocation�̶�� �Լ��� �̵���Ű���� ��� ���� Location�� �ָ� �̵���(�� �Լ��� MoveTo���� �ٸ� �̵� �Լ��� �ƴ϶�� ����� ������ ������)
	- Return Value�� Failed, AlreadyAtGoal, RequestSuccessful�� �����µ� �̰� switch�� Ȱ���Ͽ� execute ����, ���� �̵� ��� ���ϰ� execute ����, execute ���� ���� ó���� ��

	5. BTT_Patrol���ο��� ���� BP_PatrolComponent�� �ʿ��ѵ� �� ������ ������ ������ ó�� �� ���� �����ϰԲ� �ϵ��� �ٲ� �����
	- BP_PatrolComponent������ ������ ���� Valid �˻縦 �ϰ� InValid�� ���� Setting���ָ� ���� �õ����� �� �����ϰ� ��
	- ���� �õ� �� Component�� �� �������ְ� ������ valid�˻縦 �ϴµ� �̶� Invalid��� ���� ó��

	6. IsAtLocation ���ڷ����Ϳ� �����ִ� taget�̳� MoveTo�� �����ִ� Target�� Invalid��� ���з� ó���Ǵ� ��
	- MoveTo�� Target�� ��ȿ�ؼ� ����� ���۵ǰ� ���� �߰��� Target�� Invalid�� �ٲ���� ��� ����� -> Target�� Invalid�Ǹ� MoveTo ���� �� �ϰ� �Ϸ���
	Target�� ���� ������ ���ڷ�����(������)�� �����ڿ� ���� ��������� ��

	7. ������� �����Ͻñ� Task �⺻ MoveTo�� Success Ȥ�� Fail�� �����ؾ� FinishExecute�� �׶����� Ǯ���ִ� �Ŷ�� �Ͻ�
	- AIMoveTo���� �׳� 1) �׳� ���� �� 2) Success 3) Fail�� �ִµ� �Ƹ� �⺻ Task�� MoveTo�� �׳� �����ɿ� ������ ���� ��
	- AIMoveTo�� �׳� ���� ������ ���� FinishExecute �ָ� �帧�� �ٷ� �� �� ����

	8. ���� BP_Patrol���� Tick���� ó���ϴ� MoveToLocation�� ��� �� Tick �ߵ��� ����
	- MoveToLocation�� ��ȯ �� 3�������� ��� FinishExecute �ع����� ����
	- ExecuteAI�� ���� ��� �̻�

	9. ���� �� �ǰ� ���ϸ� ���� ������ �ȵǴ� ���׸� ��ġ�� ���� �ǵ�鿡��
	- �ϴ� ������ �ٽ� Key�� AttackEnalbed�� �°� OnCompleted�� �帧�� ���� ���ϱ� ������
	- �׷��� �����ϰ� �������� �� Montage�� OnInterrupted���� ó���Ϸ��� ������ �߸��� ������
	- OnInterrupted��� �� �ٸ� ��Ÿ�ְ� ����Ǵ� ��Ȳ���� �߻��Ǵ� ���̱� ������
	- �޺� ���ݿ��� ���� ��Ÿ�ְ� �� ��Ÿ���� OnInterrupted�� �߻���Ŵ

	- �޺� ������ �帧�� �����ϸ�
	1Ÿ ���� �߻� -> ���� �޺��� �̾��� �� ������ BlendOut���� ���� ��Ÿ�ָ� ����϶�� ��� -> ���� ��Ÿ�� ����� ���� ��Ÿ�ֿ��Դ� OnInterrupted�� �ۿ� �� OnCompleted�δ� �帧�� ���� ����

	- ���� ��Ÿ�� ���忡�� �ڽ��� �����߿� ���ع��� ������ ó���Ǳ� ������ ���� ��Ÿ�ְ� ���� ��Ÿ�ֿ� BlendOut�� �Ǵ� ���� �ƴ϶� ���� ��Ÿ�ְ� ������ ��Ÿ�ָ� BlendIn�ϴ� ������� ó���ϴ� ��

	10. BlendOut ���� �ɼ� �߿� �ִϸ��̼� ������ �ʿ��� <���� BlendOut�� �����ϴ� �ð�>�� <BlendOut���μ� �����ϰԲ� Trigger> ��Ű�� �ð��� �ٸ��� �� �� �ִ� �ɼ��� ����
	- BlendOutTriggerTime�� Default�� -1�ε� BlendOutTime�� ���� ���� �����ڴٴ� �ǹ���
*/