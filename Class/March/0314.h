#pragma once
/*
1. �Է� ���⿡ ���� �����ų� �齺���� ��� ������ �ذ��ϱ� ����
 1-1) GetActorForwardVector
 1-2) CharacterMovement - GetLastInputVector
 1-3) �� �� ���Ϳ� ���� ����, ������ �ϴ°��� �ʿ�����

2. �ִϸ��̼��� root�� Ʈ�������� �����ϴ� �ɼ��� �����־��� ������ ���ϸ��̼� ��ü�� �յڷ� ������ ��ǹۿ� ������ ������
�ִϸ��̼��� ����ϱ� ���� ������ rotation�� �����־�� ����
 - �󸶳� rotation�� �������� ���ϴ� �������� MakeRotFromX��� �Լ��� ����Ͽ� input ���Ϳ� ���� rotation�� �ٷ� �̾Ƴ� �� �־��µ�
�̰� ���� ����, �¿� �Ǻ��� �Ͽ� ����, ���� �� ���ư��� ��

3. GetInputLastVector�� A+W, D+S�� ���� �ٸ� Ű�Է��� 2���̸� ����ȭ�� ���� �ƴϿ���

4. Dodge�� Space�� �׼Ǹ��� ���־��� controller�� �����ϰ� �ִ� ���� dodge�� ���������� space�ٸ� ������ �� ���� ������ dodge�� ����
�ٸ��� �۵��� �� �ְԲ� �ϴ°� ���� �������̽����� ���� �������̽��� ���� ���� BP_Character���� �������̽��� �����ؼ� 1,2���� �ߴ� ��忡
shift Ű�Է� ��� dodge �̺�Ʈ�� �̾���. controller�ʿ����� dodge �׼� ���ο� ���� GetControlledPawn�� Dodge �̺�Ʈ�� ȣ��ǰ� �ٲ���
 - �̷��� �ϰ����� BP_Character�� �ƴ� �ٸ� ������ pawn���� �������̽��� ��ӹް� dodge�� ���ؼ� �����ϱ⸸ �ϸ� �ű⼭ ������ dodge�� ����
space�Է� �� �ٸ� ������ �ϰ� ����
*/