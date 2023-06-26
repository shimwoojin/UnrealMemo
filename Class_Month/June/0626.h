#pragma once
/*
	1. 언리얼 마법사를 통하지 않고 에디터와 소통할 수 있는 헤더와 CPP를 만들 수 있음
	- Source 폴더 하위에 헤더와 CPP를 추가하고 CoreMinimal.h, 상속받은 부모의 헤더, generated.h(UCLASS 키워드가 붙는 클래스라면)를 추가해주면 됨
	- 언리얼 마법사를 통하게 되면 헤더와 CPP도 만들지만 빌드도 하기 때문에 시간이 걸리는 측면이 있음
	- 빈 Actor를 미리 만들어두고 경로만 잘 잡아서 만든 헤더와 CPP에 복붙해넣는 방식도 괜찮다고 함

	2. 언리얼 마법사가 우리의 클래스를 만들어주는 비밀을 조금 알아보면
	- C:\Program Files\Epic Games\UE_4.26\Engine\Content\Editor\Templates 이 경로에서 <.template> 확장자를 가진 파일들을 메모장으로 열게 되면
	우리가 클래스를 만들면 제공할 틀이 잡혀 있음
	- %와 %사이에 적어둔 환경 변수를 통해 우리가 정할 클래스 이름 혹은 ClassName.generated.h의 접두어를 빼는 등에 대해서도 대응하여 만들어지는 것

	3. int32는 언리얼의 4byte 정수형을 의미함
	- 멀티 플랫폼에 대응하기 위한 흔한 기법임
	- 플랫폼이 다르면 같은 자료형 이름이여도 byte수가 다를 수 있음(상대적인 크기만 지정한다고 함)
	- byte수가 다르게 되면 문제점이 있는데 1) Overflow, 2) 구조체 등을 다룰 때 주소로 접근하는 코딩은 불가능해짐
	
	- window를 예를 들면 우리가 추가하고 있는 헤더 중 어딘가에

	#if defined _WIN64
	typedef unsigned int uint32;

	이런 느낌으로 적히게 됨

	4. UE_LOG(LogCategoryName, Verbosity, 하고 싶은 말, ...) 에서 LogCategoryName을 우리가 직접 정의할 수 있음(2가지 방법)
	- 1번 방법 : cpp파일에 DEFINE_LOG_CATEGORY_STATIC(GPC, Log, All)
	- 2번 방법 : cpp파일엔 DEFINE_LOG_CATEGORY(GPC), 헤더 파일엔 DECLARE_LOG_CATEGORY_EXTERN(GPC, Log, All)

	1번은 해당 cpp파일에서만 쓸 수 있고
	2번은 헤더를 추가한 곳이라면 어디든 사용 가능함

	- 위의 함수 이름에 적힌 STATIC은 다른 파일에서 사용이 불가능함을 알리는 전역에서의 static의 의미를 담고 있음

	5. static과 extern을 좀 더 알아보면
	- 같은 프로젝트 내 다른 cpp파일이지만 같은 변수명을 사용하게 되면 빌드 오류가 나게 됨(각각의 cpp파일은 각각의 obj 파일을 만들지만 obj 파일이 모여 만든 exe파일(혹은 lib 혹은 dll)을 구동함에 있어 문제가 생김)
	- 이 때 등장할 수 있는 키워드가 extern임 -> 다른 cpp에서 전역 변수를 사용하고 싶으면 extern 키워드를 붙여 사용해주면 됨
	- 근데 이 extern을 막아주는 키워드가 static임 -> static이 붙은 전역 변수를 extern이 불가능함

	- 함수에는 extern이 기본으로 포함(생략)되어 있음

	6. 전역변수에 대해 이름이 겹칠 경우 <::변수이름> 으로 구분지을 수 있음
	- 전역의 namespace는 비어 있게 사용
*/