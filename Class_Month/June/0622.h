#pragma once
/*
	1. UPARAM(ref)를 사용하여 블프와 C++에서 input 인자에 대해서 수정이 가능하게끔 설계 할 수 있음 -> 납득이 안 가는 부분은 UPARAM(ref)가 없을 때 C++에선 인자를 받아야 사용가능한 함수이지만
	블프에서는 인자로 받는 input이 아닌 output으로서 출력이 되는 다른 함수로 사용되게 됨
	- 이 부분에 대해서 엔진에선 어떻게 활용하는지를 좀 더 알아볼 필요가 있겠음
	
	2. 래퍼런스에 대해서 좀 더 알아보면 일단 래퍼런스를 쓰는 이유 2가지 -> 1) 반환하기 위해(값의 수정) 2) 인자 전달의 경량화
	- 위 2가지 경우에 대해서 구분하는 방법은 프로그래머의 의도로 작성된 const 지정자임
	- 경량화를 위한 래퍼런스는 const 지정자를 붙이게 됨

	3. const의 사용은 크게 3가지로 나뉨 -> 1) 원본의 수정을 막는 const (const int* a; 혹은 int const * a;) 2) 주소의 수정을 막는 const (int * const a) 3) 멤버변수의 수정을 막는 함수 뒤에 붙는 const
	- 위는 포인터와 같이 쓴 const에 대해서 나열했고
	- 래퍼런스에 대한 const는 위 2번의 특징을 기본으로 갖고 있는 const임(래퍼런스는 선언과 동시에 어떤 주소를 물고 있어야 하고 이 값은 수정 불가능함 -> 이 사실이 사실은 *const였던 거임)

	4. void TestFunction(const int& testInt)에 대해서 블프의 함수가 되게 된다면
	- 위 함수는 수정 반환이 아닌 경량화의 목적이므로 블프에서 핀이 input으로 받아지게 됨
	
	5. Actor는 RootComponent가 없다면 Transform이 없음
	- SetRootcomponent(루트가 될 컴포넌트); 혹은 RootComponent = 루트가 될 컴포넌트; 를 해주면 됨

	6. 루트를 정하고 루트 밑에 다른 컴포넌트를 붙이는 식으로 액터가 구성되는데 붙이는 작업이 이루어지지 않는다면 안 붙은 컴포넌트는 자유 분방한 트랜스폼을 갖게 됨
	- 불일 컴포너트->SetUpAttachment(루트컴포넌트의이름); 혹은 불일 컴포넌트->SetUpAttachment(GetRootComponent()); 혹은 루트에 붙이기 않겠다면 불일 컴포너트->SetUpAttachment(붙고 싶은 컴포넌트의 이름);

	7. CreateDefaultSubobject를 통해 생긴 컴포넌트의 이름은 겹치면 안 됨

	8. 리플랙션이 없게 되면 블프 에디터에서 디테일 탭이 안 보이게 됨
	- 이러한 현상을 가지는 컴포넌트가 있는데 Character 밑에 달린 Arrow Component가 이러함
	- Arrow는 정면을 바라보는 것을 강요하기 위함인듯
	- Arrow도 리플랙션을 켜게 되면 사실 많은 정보를 가지고 있음

	9. 컴포넌트 변수에 대해 UPROPERTY 지정자는 VisibleAnywhere가 관습적으로 많이 붙게 됨
	- VisibleAnywhere라고 해서 블프에서 디테일 탭의 편집이 불가능한 것이 아님
	- EditAnywhere인 경우 물고 있는 포인터 주소가 바뀔 수 있는 것이라 알고 있었는데 VisibleAnywhere도 가능한 것으로 보임
*/