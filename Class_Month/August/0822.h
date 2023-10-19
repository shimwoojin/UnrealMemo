#pragma once
/*
	1. friend
	- Ŭ����, ����Լ�, �Լ��� ���� friend�� �� �� ����
	- private, protected�� ���� ������ ������ִ� Ű����
	- ���� ������ �ϴ� ���� ���� �𿡰� �뺸�ϴ� ���

	class A
	{
		friend class B;				//Ŭ������ friend
		friend void B::Hello(A* a);	//����Լ� friend
		friend void Hi(A* a);		//�Լ� friend

	private:
		int i;
	}

	class B
	{
		//B�� ����Լ� ��𿡼��� A::i�� ������ �� ����
	public:
		void Hello(A* a) 
		{
			a->i;	//����
		}
	}

	void Hi(A* a)
	{
		a->i;	//����
	}

	- friend�� ��ӿ� ������� ����, friend�� ģ���� ģ���� ���� ����

	2. Aiming�� ���� bool�� ó���� ���� �ִµ�
	- blend time�� �� �����ϸ� �ڿ����� ���� ����
	- ZoomIn�� Blend�� �� ������, ZoomOut�� ������ �ϴ� �� ������ ������ ����(bool�� ���� ������ ���)

	3. inline, __inline, __forceinline
	- #define FORCEINLINE __forceinline
	- �빮�� FORCEINLINE�� �𸮾��� �� �� �� ������ forceinline
	- inline�� �����Ϸ��� �˾Ƽ� �� ó���������� -> �׷��� �츮�� ���������� inline�� ���� �ʾƵ� ������ ������ ����� ���� ������
	- ������ �ؾ��ϴ� ����
	- ���÷� ��� �ִ� ��Ȳ�� �ٸ� �÷����� �����ϱ� ���� -> �����쿡�� inline, mac���� inline�� �ƴ϶�� ������ inline ó���� �ؾ� �� �� forceinline ó��

	4. .inl
	- �ܼ� �ؽ�Ʈ ����
	- �ζ���, ���ø��� �����ΰ� ��������
	- ����� ������ �κп��� �� ������ #include ���شٰ� �����ϸ� ��
	- .inl�� ���� �ȴٸ� "��, ���ø� �ڵ峪 �ζ��� �ڵ带 �����س�����" �ϸ� �� -> ����� �����ϰ� ���� �;�����

	5. enum�� ���ؼ��� ���� ������ ������ ������ �˰� ������
	- �����α��� ����� ���� ���� �� ��� ���漱���� �ǹ̰� ���� -> cpp�� ���� �� ���� ��ȿ
*/