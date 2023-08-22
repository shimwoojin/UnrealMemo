#pragma once
/*
	1. friend
	- 클래스, 멤버함수, 함수에 대한 friend를 할 수 있음
	- private, protected에 대한 접근을 허용해주는 키워드
	- 훔쳐 쓰고자 하는 놈이 당할 놈에게 통보하는 방식

	class A
	{
		friend class B;				//클래스의 friend
		friend void B::Hello(A* a);	//멤버함수 friend
		friend void Hi(A* a);		//함수 friend

	private:
		int i;
	}

	class B
	{
		//B의 멤버함수 어디에서든 A::i에 접근할 수 있음
	public:
		void Hello(A* a) 
		{
			a->i;	//가능
		}
	}

	void Hi(A* a)
	{
		a->i;	//가능
	}

	- friend는 상속에 적용받지 않음, friend는 친구의 친구가 되지 않음

	2. Aiming에 대해 bool로 처리할 수도 있는데
	- blend time만 잘 조절하면 자연스런 설정 가능
	- ZoomIn의 Blend를 더 빠르게, ZoomOut을 느리게 하는 등 컨셉의 설정도 가능(bool로 포즈 블렌딩 노드)

	3. inline, __inline, __forceinline
	- #define FORCEINLINE __forceinline
	- 대문자 FORCEINLINE은 언리얼이 한 번 더 래핑한 forceinline
	- inline은 컴파일러가 알아서 잘 처리해주지만 -> 그러니 우리가 명시적으로 inline을 적지 않아도 최적의 컴파일 결과가 나올 테지만
	- 강제로 해야하는 경우란
	- 예시로 들수 있는 상황은 다른 플랫폼에 대응하기 위함 -> 윈도우에선 inline, mac에선 inline이 아니라면 무조건 inline 처리를 해야 할 때 forceinline 처리

	4. .inl
	- 단순 텍스트 파일
	- 인라인, 템플릿의 구현부가 적혀있음
	- 헤더의 마지막 부분에서 이 파일을 #include 해준다고 생각하면 됨
	- .inl을 보게 된다면 "아, 템플릿 코드나 인라인 코드를 구현해놨구나" 하면 됨 -> 헤더는 깨끗하게 쓰고 싶었구나

	5. enum에 대해서도 전방 선언이 가능한 것으로 알고 있으나
	- 구현부까지 헤더에 같이 적게 될 경우 전방선언은 의미가 없음 -> cpp에 적게 될 경우는 유효
*/