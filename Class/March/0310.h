#pragma once
/*
1. ���� Ǯ�� �߿� get unscaled box extent�� get scaled box extent�� ���̴�
 - unscaled�� Ŀ�� scale�� �� �������ɷ� ..?

2. ���� Ŭ������ ����Ʈ���� ī�޶� ���� ��ư�� ����
 - ī�޶� ������ �ʹ� �־����� ����Ҹ� ��

3. ������̳ʿ��� ��ġ�� ���͵鿡 ���� shift + Ŭ�� Ȥ�� ctrl + Ŭ�� ������ �ټ� ���� ����
 - �ټ� ���� �� Ʈ�������� ���ؼ� �ϰ� ���� ����

4. ȭ�鿡 ���ڿ� ��� �ϴ� �Լ��� print string�̿��� ���ڿ��� ���� append �Լ��� ����� ���ڿ� �߰� ����

5. actor overlap�� component overlap�� ���̴�
 - actor overlap : actor�� ���� � ������Ʈ�� ������ �� �̺�Ʈ �߻��ϰ�
 - component overlap�� Ư�� ������Ʈ�� ��Ҵ� ��� ��� �ɵ� �̾Ƴ� �� �ְ�
 ��ȣ�� �ش��ϴ�, �� component overlap �̺�Ʈ�� �θ��� component�� ���� ��ħ�̿��� ����

6. cube�� simulate physics �ɼ��� Ű�� �Ǹ� �߷� ���� �� type object�� �ٲ�

7. BP_Hit���� �������� Block All�� �ٲٰ� Generate Hit event�ɼǵ� ���־��� ������ Hit�� actor
�� ������ Hit event �߻�

8. ������ �÷��� ��ư �� ȭ��ǥ���� ���� ī�޶� ��ġ���� �����ϴ� �ɼǵ� ����

9. object type�� world static�̶�� �������� ���ϴ� ���Ͱ� �ƴ�
 - ���� �ݸ��� ������ ��� ���������� ���� �������� ����

10. �ݸ��� ������ simulation generates hit events / simulation generates overlap events��
������ �ɼ� ������� ��

11. hit�� ���ʸ� �����־ �ߴµ� overlap�� ���ʴ� �����־�� �� (event)

12. ������Ʈ ���� - �ݸ������� ���ο� object type ��� ����(�̸�, �ݸ��� ����)�ϰ� �����µ� ��� ����
 - �������� spring arm�� ���� ���ο� object type ����ϰ� �����ų object type �鿡 ���ؼ� �ݸ��� ������ ���÷� �ٲ����
*/