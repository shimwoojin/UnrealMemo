#pragma once
/*
	1. SetupAttacment�� ���� �̸��� ���� �� ���� ���� �ƴ�
	- �����ڿ��� ó���ϱ⿣ �������� ������ ������ ���� �𸣴� �� ����
	
	2. �ִϸ��̼� �뷮 ���� ����
	- �ټ� Ŭ���ϰ� ��Ŭ�� - ���� �׼� - ������Ƽ ��Ʈ������ ���� �뷮 ����

	3. cpp���� Ÿ�Ӷ��� ����
	- UTimelineComponent, UCurveFloat, FOnTimelineFloat
	- float�� curve ������ ���� UCurveFloat�� ������ �� ������� �۾� -> t : 0�� �� 0, t : 1�� �� 1�ε�
	�� ���� PlayRate�̳� Curve�� y�� ���� ���� ������ �־� Ȱ�� ����
	- FOnTimelineFloat�� float�� ���ڷ� �޴� �Լ��� ���ε� ���ְ� UCurveFloat�� FOnTimeineFloat�� ����� Ÿ�Ӷ����� ���ڴٴ� �ǹ̷� AddInterpFloat()���� �߰�
*/