#pragma once
/*
1. Į ������ ������ ������ �׷������� �������� ã�ƺ��� ���� ���������µ� �� �� ������ ����ƴ� �� �� �ϳ��� Į�� ���� �� ������ ���� Į�� ������ ����� �ٽ�
�����ϴ� ���̿���
 - �̰��� ������ ��Ÿ�ְ� ����ϰ� ���� ������Ʈ �ӽ��� entry���� �ٽ� �����ϰ� �Ǳ� �����ε�
 - �����ϰ� �ذ��� �� �ִ� ����� ��Ÿ���� �ɼ��߿� Always update source pose �ɼ��� üũ���ָ� �ذ�Ǿ���
 - �� �ɼ��� ��ġ�� anim graph ���� ���Կ� ��Ŭ�� �� ������ �ǿ��� ���� ����

2. ���� �����鼭 ���������� �͵� ���� �߿� �ϳ����µ� ������ �ذ���� root motion�� ���ִ� ���̾���
 - Draw1, Draw2�� enable root motion�� ���ְ� ABP_Character�� Ŭ���� ����Ʈ���� root motion ���� �ɼ��߿� ��Ÿ�ֻӸ� �ƴ϶� ���ο� ������ �� �ִµ�
�� �ɼ��� �Ѱ� �Ǹ� �ذ��� �����ϳ� �� ����� �ƴ�

3. �������� ������ϴ� ����� ���ؼ��� ���Դµ�
 - ���� ������� �ν��Ͻ��� ���� ��������� �÷��� �߿� Ư�� �ν��Ͻ��� ���� �ߴ����� �ɾ Ȯ���� �� �� ����

4. ��Ƽ���� �����ؼ��� ���̷��濡 ��Ƽ���� �߰��� �ϰ� �Ǹ� Ư�� ������ ����Ǵ� ��Ƽ���̰� �Ǵ� ���̱� ������ Ȯ�强�� ������ (���� 1)
 - ���� ���̷��濡 ���� ���� ������ �����ϰ� ������ �� ����� �����ؾ� ��

5. BP_Character�� ����ȯ�ؼ� ����ϴ� �̷� ����� Ȯ�强�� ������, �������� �Ҹ� (���� 2)

6. ���ڿ��� �����ϴ� ���� �����ؾ� �ϴµ� ���ڿ��� ���� �����μ� �����ϴ� ����� �׻� ������ ���� ��
 - socket�� ���� �̰� �����غ��ٸ� GetOwningComponent - GetAllSocketNames �� ���ͼ� ó���ϴ� ����� �����ϱ� �ϳ�
 - socket�� ��� �׳� �����ؼ� ����ؾ� �ϴ� �� ����

7. ����ȯ�� �𸮾� �⺻ ���� Ŭ������ ���ؼ��� �� �ʿ��� �� �ϴ� ���� ��õ�ϰ� Ű�Է� �̺�Ʈ�� �׽�Ʈ�����θ� ����غ��� �ް��ϸ� controller �ʿ��� ó���ؾ� ��

8. �ᱹ �𸮾� �����̶� ���� 1) ������ �Ѵٸ� �� ���� �ٷ� �� �ȴٴ� ���� �˷��ִ� ���̰� 2) �������踦 ���ߴٸ� �����ϸ� ���� �� ����

9. AnimGraph���� �����ų� ���� �� �������ɶ��� �̺�Ʈ�� ���� �̸� �����־ �ٸ� Ŭ������ �̺�Ʈ�׷������� ����� �� �־���
�̰��� Ʈ�����ǿ� ���ؼ��� ��������(Ʈ������ : �ִϸ��̼��� ���ϴ� ���� �������� ��)
 - ��Ÿ�ְ� �ƴ� �ִϸ��̼� ������ Ȥ�� ���¸ӽſ� ���ͼ� �ִϸ��̼� �������� ���ؼ� �� �ɼ� ���� ����
 - ���¸ӽſ��� Ʈ������ �꿡 ���ؼ��� ���������� �̺�Ʈ ���� ����
 - �ִϸ��̼� ���� �������� ���ؼ��� �ɼ��� ����, �ð� ���� ���� ������ ?

10. ���� �׷��� �����ϴ� �Ϳ� ���ؼ� ��ü �巡�� �� ���� q ������ �ڵ����� ���� �ǰ�
 - shift + wsad �� �����ϴ� �� ���� ����

11. ������ ���μ������� �� â �ߴ� �͵鿡 ���� main window�� ���̴� �Ϳ� ���� �ɼ��� �־���
 - �Ϲ� - ���� - ���� ������ ���� ��ġ ���� ���� ����
 - ������ ���μ������� ���� �׷��� �����̴� ��� �������ϰ� �ٲ� �� �ְ� (�׸��� ũ��?)
 - �� �� ���ִ� ������ �־���

12. ���� ����� ���忡�� ��ġ ������� ������ �� bone_spine_03�� �ٽ� �ٿ��ִ� ����̿��ٸ�
 - ���Ⱑ ĳ������ ��� �پ�� ������ ���� ������ ������ �� ������ �����ڸ��� ���ִ� ó���� �Ѵ��� �� ����

13. ������ ����� Ư�� Ŭ������ ����ȯ �ϴ� ���� ������ �Ǳ� ������ WeaponA, WeaponB�� ��� ���ۿ� ���� �׼Ǹ����� ���־���
�� ���ۿ� ���� �������̽��� ������־���
 - ������ ���ۿ� ���� �׼Ǹ����� �̺�Ʈ�� ȣ���� �� ���� �������̽��� ������ �Լ��� �θ��⸸ �ϸ� ��
 - �������̽��� ��ӹ��� Ŭ�������� �ٸ��� ó���ؾ� �� ������ �ִٸ� �ű⼭ ó��

14. �Է¿� ���ؼ�(�Ƹ��� ������Ʈ ���ÿ��� �����س��� Ű �Է� �̺�Ʈ�� ���� �͸� �ش��ϴ� ��) ������ ���簡 �Է��� �Ҹ��ع����� �ؿ����� �Է��� �� �ް� �Ǵ� ������ ��µ� �� ������
 - 1) input enabled actor 2) controller 3) level blue print 4) pawn ���ε�
 - ������ �Է� �̺�Ʈ�� ó���߾ �Է��� �Ҹ��Ű�� �ʴ� �ɼ��� �ִµ� ����ĸ�
 - ������� ����ϰڴٰ� �̺�Ʈ�� ��ġ�� ������ ��Ŭ�� �� ������ �ǿ��� Ȯ�� ����, consume input �ɼ�

15. �Է¿� ���ؼ� ������ ������ 4�� ������ ���ؼ� ������ �ƿ� input�� �� ������ڴٴ� ������ ���� ������ ���� ��� player controller ������ �� ���� �Ϸ���
 - controller���� Ŭ���� ����Ʈ�� �Է� ���� �ɼǿ� block input �ɼ��� ����
 - ������ �̷��� ���� ���� ���ƺ��̰� �۾��ϴ� �������� �׽�Ʈ input�� �޾� ���� �ϱ� ������ �ɼ� Ǯ����

16. BP_Character���� �������̽��� ���� ��� �ް� WeaponA, WeaponB�� ���ؼ� �������ִµ�,,
 - �̺�Ʈ���� �������� ������ �Ұ����ѵ� �̰Ϳ� ���ؼ� �ļ�? ó�� ���� ����� ����
 - �������� �����ؼ� make float, make int ��� �������ش� ����

17. 16������ ���� �ļ��� Uobject�� ���ؼ� ��ũ�� ���̺귯���� �ϳ� ���� ����� ��ũ�θ� �ϳ� ���� ���� ��� ���� ���ϵ� ī��� �ִ� ����̿���
 - �Ƹ� ���ϵ�ī�尡 � �����ε� ��ȯ�ؼ� ��밡���ϰ� �̰� �̺�Ʈ�� ����ó�� ���� �� ����

18. ��ũ�θ� ���� �� ������ �������ִ� ������ character�� ������ �Լ��� jump�� ���� ��� �� �Լ��� uobject �ؿ��� ��ũ�η� �Ǿ� ������ ������ ����ٴ� ����
 - character�� �ƴ� ���� ġȯ�Ǵ� ������ �� �Լ��� ���� ����
*/