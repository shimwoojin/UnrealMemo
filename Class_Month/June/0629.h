#pragma once
/*
	1. 과제 요약
	- 함수 포인터 선언 방법 : 반환값 (*변수이름)(매개변수타입,...);
	- 함수 포인터의 자료형화 : 1) typedef 반환값 (*자료형으로 쓸 이름)(매개변수타입,...); 2) using 자료형으로쓸이름 = 반환값 (*) (매개변수타입,...);
	- #include <functional> : std::function<반환값(매개변수,...)> 변수 이름;

	- 함수는 함수 이름 그 자체가 주소 -> 함수 포인터에 대입 시 &를 붙여도 안 붙여도 가능(멤버 함수는 & 강요됨)

	- 멤버 함수를 담는 함수 포인터 : void (ADrawer::*begin_play)() = &ADrawer::BeginPlay;
	위 포인터의 call : (this->*begin_play)();

	2. std::function<void(ADrawer&)> fvd = &Adrawer::BeginPlay;
	- 멤버 함수를 담는 함수 포인터의 std::function 버전
	- call : fvd(*this);

	3. std::function<void()> fvv = [](){};
	- 람다 가능
	- void(*fvv)() = [](){}; 얘도 가능

	4. c 버전 함수 포인터와 std::function 버전 간 대입도 가능
	- void (*funcptr)() = fvv.target<void(void)>();

	5. std::function엔 functor도 담김

	struct A
	{
		void operator()(){}
	}
	
	A b;

	- functor 호출 : b();
	- functor를 함수 포인터에 담는 것 : void (*funcptr)() = b;
	- call : funcptr();

	- void (*funcptr)() = A(); 도 가능 -> 임시 객체를 넘겨줘도 가능

	6. functor와 함수 포인터를 엮어 유용하게 사용하는 법
	- 호출 시점에 구조체의 변수 값에 따라 functor를 엮어 놓은 함수 포인터의 결과를 다르게 하고 싶을 때

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

	- fiv가 불리는 시점에 i, j 값에 따라 결과가 달라질 수 있음

	7. 위와 정반대의 성격으로 i,j를 함수가 binding 되는 순간의 값으로 묶어 버리는 방법이 있음(lambda)

	int i = 5;
	int j = 7;
	std::function<int()> fvv = [i, j]()
	{
		return i + j;
	}

	- 위 fvv 함수가 다른 곳에 가서 불리고 i,j가 값이 바뀌었더라도 return의 결과는 12일 거임

	8. 구조체와 functor, 함수포인터 등을 사용해서 누구의 함수를 부를지를 지정해 둘 수 있음

	struct ADrawerBeginPlay
	{
		ADrawer* This;
		std::function<void(ADrawer&)> BeginPlay;

		void operator()()
		{
			BeginPlay(*This);
		}
	};

	9. 8번의 방법을 std::bind로 쉽게 처리 가능
	- std::function<void()> fvv = std::bind(&ADrawer::BeginPlay, this);

	10. std::function<void()> fvv = std::bind(&ADrawer::Tick, this, 4.25f);
	- std::bind가 위에서 한 일은 ADrawer::Tick(ADrawer* this, float DeltaSeconds)에 대해 this랑 4.25f라는 값으로 미리 값을 넘겨주고 매개변수가 없는 함수처럼 취급시켜줌
	
	- std::function<void(float)> fvv = std::bind(&ADrawer::Tick, this, std::placeholders::_1);
	- std::function<void(ADrawer&)> fvv = std::bind(&ADrawer::Tick, std::placeholders::_1, 4.25f);

	- std::placeholders::_1로 미리 안 채울 값에 대해선 땜빵으로 쓰는 게 가능(땜빵할게 많아지면 _2, _3,...)

*/