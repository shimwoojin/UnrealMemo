#pragma once
/*
	1. float YawToFace;
	- 파쿠르 시 우리가 진행할 방향의 yaw 값

	2. 배꼽에서 나오는 트레이스가 히트에 성공하면 왼손, 오른손, 발, 머리에서도 트레이스를 쏘는데
	파루크를 성공하려면 왼손, 오른손의 트레이스가 성공해야 하고 왼손, 오른손 트레이스 결과의 Normal이 배꼽 트레이스 결과의 Normal과 둘 다 같아야 함
	- 왼손, 오른손도 잡을 공간이 있어야 한다는 뜻

	3. void BeginParkour();
	- EParkourType::None이면 return;
	- 아닐 경우 파쿠르 타입에 맞는 파쿠르 진행할 듯

	4. FVector의 dot과 cross
	- dot : |
	- cross : ^

	- 연산자 오버로딩 되어 있는 내용

	- 가독성이 안 좋으니 FMath::DotProduct(FVector, FVector); 같은 함수로 처리하자

	5. FVector의 ==과 Equal(FVector)의 차이
	- == : 벡터의 성분들이 float임에도 불구하고 x,y,z에 대해 각각 == 비교를 함 -> 0.000001이라도 오차가 날 경우 다른게 됨
	- Equal : 오차 허용 있음 -> KINDA_SMALL_NUMBER인가 암튼 비슷한 이름인데 10e-4인가 그랬음, 0.0001정도

	6. FMath::Cos()은 cosf()을 래핑한 함수
	- 언리얼이 외부 라이브러리에 대해 래핑을 다 해서 '외부 라이브러리 쓰지 말고 우리꺼 써라'라는 협박과 동시에 일관성을 지킨 경우

	7. cos, sin 다룰 땐 degree, radian 항상 생각
	- FMath::DegreesToRadians();

	8. auto는 더 넓은 범위로 잡힘
	- int() + float() 일 경우 float
	- float() + double() 일 경우 double

	9. 후행 반환
	
	template<class T>
	static auto FMath::DegreesToRadians(const T& DegVal) -> decltype((Degval * (PI / 180.0f))
	{
		//...
	}

	- Degval이 int일 경우에도 float이 반환 값이 됨
	- template<class T> static auto 대신 template<class T> static decltype((Degval * PI / 180.0f)) 처럼 쓸 수는 없으니 후행 반환을 사용하는 것

	- 추가로 템플릿은 컴파일 타임에 함수를 만들고 시작하기 때문에 위 auto의 경우 컴파일 타임에 이미 decltype에 대한 type이 이미 추론 됨

	10. 메쉬가 울퉁불퉁해 보이는 경우는 있지만 실제 울퉁불퉁하진 않은 경우가 많음

	11. Vector의 dot은 정규화 된 값을 다루고 있는지 한 번 더 생각
*/