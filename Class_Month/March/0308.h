#pragma once
/*
1. camera�� springarm�� ����
 - �� ��ó���� ī�޶� �Ÿ� ���� �ڵ����� ����
 - ī�޶� ��ġ �ʱ�ȭ, use pawn controll rotation�ɼ� ���� ����

2. �÷��̾ �ʹ� ȭ�� �߾��� �����ϴ� ���� ���� ���� spring arm�� target offset z�� �÷���

3. controller���� add movement input�� ���尪 �������θ� ������ �� �ְ� �Ǿ��־���
 - player�� ���͸� �������� �ؾ���
 - get actor forward vector, get actor right vector
 - get controlled pawn���� ����

4. �ִϸ��̼��� �ٷ�� ���� Ŭ���� ���� ����, ���ξ� ABP_
 - �ִϸ��̼� �������Ʈ ����
 - �θ� Ŭ���� : animinstance, ���̷��� : ���� ������ ���� ���� 1��
 - �̹� �����ӿ� ���� �ִϸ��̼��� ���ϱ� ���� Ŭ����

5. �ִϸ��̼� Ŭ������ �ϴ� ���� �� ������ GetOwner, �� ĳ���ͷκ��� velocity(�ӵ�)�� ����
xy�࿡ ���� vector length(ũ��)�� speed ������ ������ ��
 - Blueprint update animation�� actor�� tick�� ����� ����

6. idle, walk, run�� ���ؼ� ���� �ִϸ��̼��� ����� ���ؼ� <���� �����̽� 1D> Ŭ������ ���� �������
 - speed ������ �ϳ��� ������ ����� speed���� ��ȭ�� ���� �ִϸ��̼��� ���� ����

7. BS_Unarmed, ���� �����̽� 1D�� �ɼǿ��� Number of grid�� 2�� �����ؼ� ���� 3���� ���� ���� ����

7-1. ������� ABP_, �ִϸ��̼� �������Ʈ Ŭ������ character�� ��ӹ��� player�� animation mode���� ������ ���־�� �����

8. jump�� �������ֱ� ���ؼ� �׼� ������ ���ְ� controller���� �̺�Ʈ �׷������� ������ �������־�� ��
 - �⺻������ get controlled pawn���� ���� ����ٰ� � ��� ���������� �����־��µ�
 - �𸮾��� �⺻ ��Ӱ��迡�� uobject - aactor - pawn - character ������ ����� �Ǳ� ������
 - �츮�� ������ ��� ����Ʈ Ŭ������ character�� ������� ������� ������
 - pawn�� �ƴ� character�� down casting�� �ѹ� ���־� jump �Լ��� �ҷ��־�� �� (jump�� character�� �Լ�)
 - pressed �߿��� jump�̰� released�� �Ǹ� stop jumping�� �� �� �ְԲ� �Լ��� �����Ǿ� ����

9. Ű �Է��� �޾� ��, ��, ��, ��� �̵��� �ؾ� �� �� � ���� �������� �̵��� �ؾ��� ���� �����ϸ�
 - controller�� vector�� �������� �ؾ� �߰� controller�� forward vector, right vector�� �������θ� ���� ���� ������ ����
 - ������ ���� �Ʒ��� ���ϰ� �Ǿ��� �� forward vector�� ���̳� �ϴ��� ���ϰ� �ǰ� ���� �հ� �ǰų� �� ���� ���⿡ Ű �Է��� �� �԰� ��
 - �ذ�å�� controller�� yaw(Z��)�� �󸶳� ȸ���� �ְ� �װ� �������� forward vector�� right vector�� �̾Ƴ��� ������ ������
 - get controll rotation - make rotator - get forward vector������ ����
 - make rotator���� x,y�� 0 z�࿡ controller���� �̾ƿ� yaw���� ������
*/