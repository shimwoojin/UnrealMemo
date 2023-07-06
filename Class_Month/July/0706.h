#pragma once
/*
	1. PrimitiveComponent란?
	- 형태를 가지는 컴포넌트
	- 메쉬 계열 혹은 콜리전 계열

	2. SetupPlayerInputComponent의 주석을 보면 functionality라는 단어가 있는데
	- input시 기능을 묶는다는 의미를 표현하기 위해 기능을 뜻하는 function을 쓸 수도 있었지만 function은 다른 의미로 해석될 수 있으니 이런 단어를 쓴 것으로 보임

	3. 함수에 대해선 정의로 이동(F12) 혹은 호출 계층구조 보기(Ctrl T) 하면 어떤 내용인지를 확인할 수 있고
	- 변수에 대해선 모든 참조 찾기(Shift F12)로 엔진 내부 구현을 살펴볼 수 있음
	- 모든 참조 찾기에 대해선 범위를 지정할 수 있는데(현재 문서 혹은 전체 솔루션 등등)
	- CharacterMovementComponent의 Velocity같은 변수는 굉장히 많이 쓰이고 있으므로 모든 참조 찾기를 눌렀다간 렉 걸려 재부팅할 경우도 생김

	4. 조건을 표현하는데 있어서
	1) if(PendingImpulseToApply.Z != 0.f || PendingForceToApply.Z != 0.f)
	2) if( ! (PendingImpulseToApply.Z == 0.f && PendingForceToApply.Z == 0.f)

	두 구문은 같은 의미를 같지만 강사님은 2번을 선호하신다고 함
	사실 나는 1번이 더 잘 읽힘

	5. Movement 계열의 ApplyRadialDamge를 좀 더 알아보면
	- 멤버 변수인 PendingImpulseToApply 변수를 한 프레임동안 팍 올렸다가
	- Velocity에 더해준 후 PendingImpulseToApply는 다시 0값을 가지게 됨
	- Pending이란 뜻이 '보류'라는 뜻을 가짐에서도 유추할 수 있으며 실제 엔진 내부에서도 위 설명과 같이 구현되어 있음

	- 추가로 CharacterMovementComponent의 Velocity는 OldVelocity 혹은 LastUpdateVelocity 등 다른 변수의 값을 정하는 곳에도 쓰이고 있음(Velocity 그 자체로 속도를 정하는 것은 아닌 것 같음)

	6. 헤더를 추가함에 있어 #include "" 혹은 #include <>의 2가지 경우가 있는데
	- "" : 현재 파일 기준으로 먼저 탐색 후 지정 된 경로를 탐색
	- <> : 지정 된 경로를 탐색

	- 지정 된 경로라 함은 VS에서 <속성 페이지 - VC++ 디렉터리 - 포함 디렉터리>와 같은 곳에서 미리 정해둔 경로를 의미

	- 앞으로 언리얼헤더는 <>, 우리 프로젝트 헤더는 ""로 사용하여 구분짓기로 함

	7. 애니메이션을 적용해주기 위해 AnimInstance를 상속하여 MyAnimInstance를 만듬(C++)
	- 이 클래스가 해줄 작업은 블프에서 이벤트 그래프에서 처리해주던 변수들의 값을 바꿔주기 위함임
	- BlueprintUpdateAnimation을 사용하여 매 프레임 업데이트 하던 내용을 C++로 처리해주어야 함

	- BlueprintNativeEvent로 되어서 C++내용을 블프에서 오버라이드하는 식으로 처리할 줄 알았으나
	
	- C++에서는 NativeUpdateAnimation을 오버라이드하여 우리의 변수를 업데이트 시켜줄 수 있음
	
	- 어떤 함수를 사용할지가 막막할 때 virtual 키워드를 찾는 것이 좋아 보임

	- 위와 같은 함수를 인터페이스처럼 제공했는데 이런 경우 접근 지정자에 대해선 부모의 접근 지정자를 따라가는 것이 좋음

	- 접근 지정자 symbol을 구분지을 때 public은 우하단에 아무것도 안 붙어있었는데 좌하단에 화살표가 붙어있는 것은 다른 파일에 정의가 있다는 뜻임
	(NativeUpdateAnimation은 좌하단엔 화살표, 우하단엔 아무것도 x -> 정의는 다른 파일에 있고 접근 지정자는 public이라는 뜻)

	8. 오버라이드 시 부모가 붙여둔 const는 자식에서 무조건 지켜져야 하지만 부모가 안 붙여둔 const를 자식에서 더 붙인다고 문제가 되진 않음

	9. auto로 변수를 받는 경우는 우측의 값이 명백한 경우
	- 명백하다는 건 함수 이름에서 티가 나는 정도라고 할 수 있을 듯

	10. Actor에서 GetVelocity를 받을 수 있기 때문에
	- GetOwningActor()로 받아서 처리하는 것도 낫배드(TryGetPawnOwner() 대신)
	
	11. C++에 우리가 정의한 AnimInstance를 애님 블프로 만들기 위해선
	- 콘텐츠 브라우저 우클릭 - 애니메이션 - 애니메이션 블루프린트로 만들어주어야 함
	- 다른 C++을 블프로 만드는 방식으로 하면 안됨

	12. 멀티캐스트 델리게이트는 반환값이 void여야만 함
	- 호출 순서가 보장이 안 되기 때문에 반환값을 배열에 담아서 돌려준다던가 하는 방법도 불가능

	13. 싱글캐스트 델리게이트가 반환값을 받기 위한 문법은
	- DECLARE_DELEGATE_RetVal_OneParam(int, FTriggerType1, int) 임
	- 반환값을 return받기 위해선 ExecuteIfBound 대신 IsBound()를 체크 후 Execute()함수를 통해 반환값을 반환 받을 수 있음
	- ExecuteIfBound()는 반환값이 bool 고정

	14. 델리게이트는 NineParams가 최대이며 OneParam 이후 TwoParams 이후 부터는 's' 붙이는 것 유의

	15. 월드 상 큐브 125개에 대해 전체 클릭 후 우클릭 액터 병합 + 폴더에 담아두어 월드 상 액터에 대한 관리도 해두었음
*/