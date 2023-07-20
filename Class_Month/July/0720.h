#pragma once
/*
	1. float YawToFace;
	- ���� �� �츮�� ������ ������ yaw ��

	2. ��ſ��� ������ Ʈ���̽��� ��Ʈ�� �����ϸ� �޼�, ������, ��, �Ӹ������� Ʈ���̽��� ��µ�
	�ķ�ũ�� �����Ϸ��� �޼�, �������� Ʈ���̽��� �����ؾ� �ϰ� �޼�, ������ Ʈ���̽� ����� Normal�� ��� Ʈ���̽� ����� Normal�� �� �� ���ƾ� ��
	- �޼�, �����յ� ���� ������ �־�� �Ѵٴ� ��

	3. void BeginParkour();
	- EParkourType::None�̸� return;
	- �ƴ� ��� ���� Ÿ�Կ� �´� ���� ������ ��

	4. FVector�� dot�� cross
	- dot : |
	- cross : ^

	- ������ �����ε� �Ǿ� �ִ� ����

	- �������� �� ������ FMath::DotProduct(FVector, FVector); ���� �Լ��� ó������

	5. FVector�� ==�� Equal(FVector)�� ����
	- == : ������ ���е��� float�ӿ��� �ұ��ϰ� x,y,z�� ���� ���� == �񱳸� �� -> 0.000001�̶� ������ �� ��� �ٸ��� ��
	- Equal : ���� ��� ���� -> KINDA_SMALL_NUMBER�ΰ� ��ư ����� �̸��ε� 10e-4�ΰ� �׷���, 0.0001����

	6. FMath::Cos()�� cosf()�� ������ �Լ�
	- �𸮾��� �ܺ� ���̺귯���� ���� ������ �� �ؼ� '�ܺ� ���̺귯�� ���� ���� �츮�� ���'��� ���ڰ� ���ÿ� �ϰ����� ��Ų ���

	7. cos, sin �ٷ� �� degree, radian �׻� ����
	- FMath::DegreesToRadians();

	8. auto�� �� ���� ������ ����
	- int() + float() �� ��� float
	- float() + double() �� ��� double

	9. ���� ��ȯ
	
	template<class T>
	static auto FMath::DegreesToRadians(const T& DegVal) -> decltype((Degval * (PI / 180.0f))
	{
		//...
	}

	- Degval�� int�� ��쿡�� float�� ��ȯ ���� ��
	- template<class T> static auto ��� template<class T> static decltype((Degval * PI / 180.0f)) ó�� �� ���� ������ ���� ��ȯ�� ����ϴ� ��

	- �߰��� ���ø��� ������ Ÿ�ӿ� �Լ��� ����� �����ϱ� ������ �� auto�� ��� ������ Ÿ�ӿ� �̹� decltype�� ���� type�� �̹� �߷� ��

	10. �޽��� ���������� ���̴� ���� ������ ���� ������������ ���� ��찡 ����

	11. Vector�� dot�� ����ȭ �� ���� �ٷ�� �ִ��� �� �� �� ����
*/