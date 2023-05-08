#pragma once
/*
	1. AI�� �����ϴ� ���� ���� ������ ������ �ٷ� target�� �Ҿ������ ���� �����߿�
	- AIPerception Component�� ������ ��ų� �Ҿ��� �� ȣ��Ǵ� �̺�Ʈ�� 3�� �ְ�(ȣ������� ����)
	- Stimulus ����ü�� ���� �����߿� AIPerception���� �����س��� <�ִ� ����>�� Ȱ���Ͽ� ������ �ۼ��Ϸ��� ������ �̺�Ʈ���� ������ ��� �� ����� �� ���� ���� �� �� �ִ� ����� ����
	- Age : Stimulus�� ���� �� �� <�ִ� ����>�� ���� ������ ���� �������� �ð��� ��� �Ű�
	- Expiration Age : <�ִ� ����> �� ��ü -> �� ������ �׳� �� ���� SetTimerByEvent�� Ȱ���ϴ� �� ���� ��

	2. GetKnownPerceivedActors�� GetCurrentlyPerceivedActors�� ���̴�
	- GetKnownPerceivedActors : <�ִ� ����>�� �ð����� ���� Actor��
	- GetCurrentlyePerceivedActors : <�ִ� ����>�� ������� ������ �� Actor�� ( Succesfully Sensed�� false�� ������ ���� �ֵ� )

	3. BT�� ����(?)�� �ִµ�
	- Root �ٷ� ���� ��� ���� ���� ��

	4. AIPerception Component�� Ȱ���Կ� �־ <�̺�Ʈ>���� Ȱ���ϱ⿣ �������� ����
	- GetKnownPerceivedActors�� GetCurrentlyPerceivedActors �� AI ���� �Լ��� �� �����ؼ� ���� ¥���

	5. Enemy�� �ֻ� Ŭ�������� BTAsset�� �����ϰ� �ű⼭ RunBehaviorTree�� ���ְ� �ڽĿ��� BTAsset�� �ٸ� ������ �������ָ� ������ ����
	- GetAIController�� Self Ȥ�� ������ ��Ʈ�ѷ����� �˷���� ��(valid üũ�� ����)

	6. ķ ����ũ �θ�� <MatineeCameraShake> ���
	- ������ �󸶳� ����(BlendIn, BlendOut�� ���� -> �ǰ� �� ȿ���� ���� BlendIn, BlendOut�� ȿ���� ���ζ� 0)
	- Rotation�� ���� Location�� ���� FOV�� ���ؼ��� Oscillation�� �� �� ����
	- ���� x,y,z�� ���� ������ �󸶳� �ֱ⸦ �󸶳� ���� �� �� �ְ�
	- sin ���� Ȥ�� Perlin Noise �������� �� ���� ���� -> ������ ��� �������� ������ ���� ���� offset�� �� �� ����(random Ȥ�� 0)

*/