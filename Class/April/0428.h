#pragma once
/*
	1. AIPerception Component�� Touch Config�� ������� Touch�� �ƴ϶� ���� ������Ʈ �� ��Ҵ����� ���� ������
	- CPP�� ���� �� �˾ƺ����

	2. Hearing Config�� ���� ������ Hearing Range 1������(LOS Hearing Range�� ����� �� ������ ǥ������, ����� ����)
	
	3. Sense Config�� EnableStarted�� ���� ���� ��ü�� �������� ����� �� ���� ǥ�ñ��� �������� ����

	4. ��Ÿ�ֿ� PlaySound Notify ��ġ�Ͽ� ���ϴ� Ÿ�ֿ̹� �������� ��� ����
	- ������ �츮�� ��� �Ҹ��� ������ AI�� �����ϱ� ���ؼ� '�Ҹ��� ����'��� �ٸ� �Լ��� ȣ���Ͽ��� ���� ������(�Լ� �̸� : Report Noise Event)
	- Report Noise Event�� Max Range�� 0�� ��� ���� ������ ������ �̶�� ��(World ��𼭵� '�Ҹ��� ���� �� �ִ�'��� ��)

	5. ���� ���������� ����ϴ� �Լ� ������ �� ���� �ִµ�(������ �Լ��� ������ ����)
	- PlaySound2D
	- PlaySoundAtLocation
	- PlaySoundAttached : Component�� �ٿ� �� ��ġ���� �Ҹ����� �� �� �� ����(Attach Point Name(Name Ÿ��) ���ڵ� �޴µ�)
	(��� �ñ��� ���� Name�� �޾Ƽ� �� ��ġ���� ���� �����ִ� �� �߿� �ƴ� �� SkeletalMesh�� Socket ���� �ۿ� ���µ� �ٸ� Scene Component���� Name����
	��ġ�� Ư���� �� �ִ°� �ִ°� �ñ���)

	6. AIPerception�� ������ ����� �̺�Ʈ�� ���� Ȯ���� �� ����(OnTargetPerceptionUpdated, OnPerceptionUpdated, OnTargetPercpetionInfoUpdated)
	- ������ ��ų� ������ �Ҿ��� �� �̺�Ʈ�� �߻��ϴ� ���� ����ϳ� �Ѿ���� ������ �ٸ�(�⺻������ OnTargetPercetpionUpdated�� ������ Actor�� ��ȯ��)
	- ��� �̺�Ʈ�� Stimulus(�ڱ�) ����ü�� �Ѿ���µ� break�Ͽ� ���� �ʿ��� ������ ����� �� ����(������ �� �߿� Successfully Sensed�� True or False ���η�
	������ ������ �������� ������ �� ����)

	7. AIPerception���� ���� Sense Config�� ����Ͽ� �����ϰ��� �Ѵٸ�
	- AIPerception Component�� �ð���, û����, �� ���� ������ �����Ͽ� Component�� ���� �ϳ��� �þƼ� ó���ϴ� �����ϰ� ������ ����� ����
	- GetCurrentlyPercievedActors ��带 ���� � ������ ���� ���� �� Actors ������ �迭�� ��ȯ�ϱ� ������ �� ��带 �̿��ϸ� � ������ �ɸ����� �� �� ����
	- GetKnownPercievedActors�� ���� ������ �� ���̶� �� actors�� ���� ��� �� ���� �ְ�
	- GetPercivedActors�� Deprecated�� ����̹Ƿ� ������� �ʱ��

	- GetKnownPercievedActor�� ���� ������ ���� �ִ� Actors�� ���� ���ؿ� �� �ִ� ������ ���� ���� �ð��� ������� ���������� �޸𸮰� ������ ������ ������ ��

	8. 
*/