#pragma once
/*
1. ���� Ŭ���� �׷������� �ϸ�ũ ��� -> �׷��� ���� ��� �� Ŭ�� �� �����ϰ��� �ϴ� ��ġ �ϸ�ũ ������� �� ����

2. �� �ϸ�ũ -> ctrl + 0 ~ 9�� ���� �ִ� ����� ��, ��ġ �� ���� �� shift + 0 ~ 9�� �̵� ����

3. ���� �׷������� ctrl + f : ã��, �������Ʈ���� ã����� ���� �ٸ�

4. Ŀ���� �̺�Ʈ ���� �Ű������� �� �� �ְ� �̺�Ʈ���� �̺�Ʈ�� ȣ���� ���� ����

5. hit�� ����, overlap�� ����

6. �������� �迭 ��� �� find�� contain�� ���̰� ����
 - find�� �ε��� ��ȯ, contain�� �Ҹ� ��

7. ī�޶� ���� �������� ĳ������ Rotation�� �����ϴ� �ɼ��� SpringArm���� ã�� �� ����
 - Use Pawn Controll Rotation �ɼ� True�� �ָ� ��

8. ĳ���� ī�޶� �� ���� ��ȯ �̵� ���� �ɼ� ����
 - BP_Character - Ŭ���� ����Ʈ - Use Controller Rotation Yaw : �� �ɼ��� Ű�� �Ǹ� Controller�� �ٶ󺸴� ������ �÷��̾ ���� �ٶ󺸰� ��
 ��Ʈ�ѷ��� Rotation�� �÷��̾ �Ȱ��� ���� �Ǵ� ��
 - BP_Character - Character Movement - Rotation Settings - Orient Rotation to Movement : �����ϰ� �ִ� �������� ĳ���͸� ȸ�������ִ� �ɼ�,
Use Controller Rotation Yaw �ɼ��� ����� �־�� ����Ǵ� ��
 - BP_Player - SpringArm - Camera Settings - Use Pawn Controll Rotation : �� �ɼ��� Ű�� �Ǹ� SpringArm�� Controller�� rotation���� ���󰡰� ��

 9. �������� ��忡 Alt + G ������ �Լ� ���� �� �� ����

 10. ���� �׷������� Ctrl + P ������ �۷ι� ���� ���� �˻��� �� ����
  - ���ŷӰ� ������ �������� �� ������ ��

  
*/