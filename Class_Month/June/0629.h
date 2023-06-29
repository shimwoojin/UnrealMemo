#pragma once
/*
	1. ���� ���
	- �Լ� ������ ���� ��� : ��ȯ�� (*�����̸�)(�Ű�����Ÿ��,...);
	- �Լ� �������� �ڷ���ȭ : 1) typedef ��ȯ�� (*�ڷ������� �� �̸�)(�Ű�����Ÿ��,...); 2) using �ڷ������ξ��̸� = ��ȯ�� (*) (�Ű�����Ÿ��,...);
	- #include <functional> : std::function<��ȯ��(�Ű�����,...)> ���� �̸�;

	- �Լ��� �Լ� �̸� �� ��ü�� �ּ� -> �Լ� �����Ϳ� ���� �� &�� �ٿ��� �� �ٿ��� ����(��� �Լ��� & �����)

	- ��� �Լ��� ��� �Լ� ������ : void (ADrawer::*begin_play)() = &ADrawer::BeginPlay;
	�� �������� call : (this->*begin_play)();

	2. std::function<void(ADrawer&)> fvd = &Adrawer::BeginPlay;
	- ��� �Լ��� ��� �Լ� �������� std::function ����
	- call : fvd(*this);

	3. std::function<void()> fvv = [](){};
	- ���� ����
	- void(*fvv)() = [](){}; �굵 ����

	4. c ���� �Լ� �����Ϳ� std::function ���� �� ���Ե� ����
	- void (*funcptr)() = fvv.target<void(void)>();

	5. std::function�� functor�� ���

	struct A
	{
		void operator()(){}
	}
	
	A b;

	- functor ȣ�� : b();
	- functor�� �Լ� �����Ϳ� ��� �� : void (*funcptr)() = b;
	- call : funcptr();

	- void (*funcptr)() = A(); �� ���� -> �ӽ� ��ü�� �Ѱ��൵ ����

	6. functor�� �Լ� �����͸� ���� �����ϰ� ����ϴ� ��
	- ȣ�� ������ ����ü�� ���� ���� ���� functor�� ���� ���� �Լ� �������� ����� �ٸ��� �ϰ� ���� ��

	struct Sum
	{
		int i;
		int j;

		int operator()()
		{
			return i + j;
		}
	};

	Sum sum;
	sum.i = 5;
	sum.j = 7;
	std::function<int()> fiv = sum;
	fiv();

	- fiv�� �Ҹ��� ������ i, j ���� ���� ����� �޶��� �� ����

	7. ���� ���ݴ��� �������� i,j�� �Լ��� binding �Ǵ� ������ ������ ���� ������ ����� ����(lambda)

	int i = 5;
	int j = 7;
	std::function<int()> fvv = [i, j]()
	{
		return i + j;
	}

	- �� fvv �Լ��� �ٸ� ���� ���� �Ҹ��� i,j�� ���� �ٲ������ return�� ����� 12�� ����

	8. ����ü�� functor, �Լ������� ���� ����ؼ� ������ �Լ��� �θ����� ������ �� �� ����

	struct ADrawerBeginPlay
	{
		ADrawer* This;
		std::function<void(ADrawer&)> BeginPlay;

		void operator()()
		{
			BeginPlay(*This);
		}
	};

	9. 8���� ����� std::bind�� ���� ó�� ����
	- std::function<void()> fvv = std::bind(&ADrawer::BeginPlay, this);

	10. std::function<void()> fvv = std::bind(&ADrawer::Tick, this, 4.25f);
	- std::bind�� ������ �� ���� ADrawer::Tick(ADrawer* this, float DeltaSeconds)�� ���� this�� 4.25f��� ������ �̸� ���� �Ѱ��ְ� �Ű������� ���� �Լ�ó�� ��޽�����
	
	- std::function<void(float)> fvv = std::bind(&ADrawer::Tick, this, std::placeholders::_1);
	- std::function<void(ADrawer&)> fvv = std::bind(&ADrawer::Tick, std::placeholders::_1, 4.25f);

	- std::placeholders::_1�� �̸� �� ä�� ���� ���ؼ� �������� ���� �� ����(�����Ұ� �������� _2, _3,...)

*/