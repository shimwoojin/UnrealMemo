#pragma once
/*
1. controller�� ��, <player controller>
 - Ŭ���� ����Ʈ���� find camrera component when view target�ɼ��� �Ѽ� player�� ��Ÿ���� ���� �� ī�޶� ������Ʈ�� ã��
 player camera manager class���� ã�� camera component�� ���, �� �� auto manager active camera target �ɼǵ� üũ�� �� �־�� ��

2. Blend Space 1D���� ���̷��濡 ������ �Ǹ� ĳ���� - �� �׸��� ��� ���������� ���� ���밡 ��� ���� �� Ȯ�� ����
 - ������ root�� �������� �����ġ���� ��������(�ܼ��� transform matrix��� ��)

3. ���̷����� Ʈ�������� �����ϴ°� �ִϸ��̼��� �⺻ ����

4. �ִϸ��̼ǿ��� ���� ������ ���� ������ �о� ����¥�� �ִϸ��̼����� Ȯ�� ����
 - �����ӵ� ��� �̷�����ִ��� Ȯ�� ����

5. 3D �ִϸ��̼��� ���� : key frame animation
 - Ư¡���� �� ������ �� �� ������ �̵��� ���������� ���� �ڿ������� ���̰� ��
 - (1-r)x + ry �� ���� ���� ���� ( 0 <= r <= 1 )
 - Idle, Walk, Run�� �ִϸ��̼� ���յ� speed���� �������� �������� �� ��
 - (1 - speed / 300)(Idle) + (speed / 300)(Walk) �̷� ��
 - bone�� bone�� ���� �������� , animation�� animation�� ���� ���� ����

6. ���� �ִϸ��̼� ����
 - ABP_Characer���� AnimGraph���� State machine ����
 - state machine�� ����Ŭ���ؼ� ������ �Ǹ� entry, ������ ��尡 ����
 - ������ �����ξ��� BS_Unarmed ����, BS_Unarmed�� �������� jump�� ������ �ϰ� jump�� ������ �ٽ� �� ���·� ���ƿ;� ��

7. jump������ ��� �����ϴ��� ?
 - getowner���� getmovementcomponent�� �ϰ� isfalling�� �ϸ� jump���� �� �� ����
 - ������� ���� �츮�� �߷��� �̰ܳ��� �ö󰡴� ���̱⿡ ������ �ϴ� �������� isfalling�� return���� true(true��� ���� jump ����)
 - isfalling�� return���� �̺�Ʈ �׷������� �� ������ �޾ƿͼ� bFalling�� bool������ ��Ƶ�
 - �� ���� Ȱ���� ���� ������ ������ �������� �Ǵ� ����

8. jump���۰� ���� bFalling������ ���� �˼� �ְ� jump_loop�� jump_start�� �ִϸ��̼��� �󸶳� ���Ҵ����� �������� �Ǵ�
 - time remaining(ratio) - jump_start�� ����ͼ� 0 ~ 1������ ������ ��� ��

9. ����� ȭ��ǥ�� ���� ��带 ������ ���� �ִ� ǥ�ø� ������ ���� �����Ͽ��� �ɼ� ���� ����

10. �̷��Ը� �ϰ� ���� jump �� ����ó�� Ź Ƣ������� �Ǵµ� �� ������ jump_start�� jump_end�� animation_loop�� Ǯ���־�� ��
 - state machine���� �ִϸ��̼� Ŭ�� �� ~~��� �ǿ��� �ɼ� ���� ����

11. ĳ���Ͱ� �޸��� ���� Ű�� ���ԵǸ� �ʹ� Ź ���߰� �Ǵµ� character�� movement component�� ������� �����ϴ� �ɼ� ����
 - general settings�� use separate braking fiction

12. BP_BoxCollision ���� ���͸� ������� Box�� root, text�� �ڽ����� �޾���
 - �� Ŭ������ ��ӽ��� collision�� �Ͼ�� �� �پ��� �̺�Ʈ�� �ϴ� �뵵, text�� �ڱ� Ŭ������ �̸��� ��Ÿ���� ��
 - �⺻������ ����� ��ġ�� �� ������ �̷������ �ϱ� ������ contruction script���� ������ ������

13. text�� ��ġ�� box extent�� z�� �� 30���� ����ֱ� ���� set relative location�� ���� text render�� ��ġ�� �����
 - get scaled box extent�� z���� 30�� ���� text�� z location�� �޾���

14. text�� ��� text�� Ŭ���� ������ �̸����� �Ϸ��� �ϴµ� �� �� C++������ Ű���� this�� �ƴ� self ����
 - getclass -> getdisplayname -> totext(string)�� ���� text�� �޾���
 - string���� text�� ����ȯ�ߴµ� �ڷ��� ���̴� ���߿�..

15. ������ box�� scale�� ������ ���� �ʴ� text�� �����ؾ� ����
*/