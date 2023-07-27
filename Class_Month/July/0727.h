#pragma once
/*
	1. void TraceForIK(FName const& Bone, float& Distance, FRotator& Rotator) const;
	- Bone을 받아서 Distance랑 Rotator를 수정 반환할거라는 것을 함수 원형만 보더라도 알 수 있음

	2. AnimInstance의 GetOwningComponent()는 대체로 SkeletalMesh임
	
	3. USceneComponent::GetSocketLocation(FName);
	- 소켓의 이름(FName)을 받아 그 위치를 돌려주는 함수임
	- 소켓이 넓은 의미를 가지고 있어 소켓 뿐만 아니라 Bone의 이름을 넘겨주게 되면 Bone의 위치도 돌려줄 수 있음
	- USceneComponent::GetBoneLocation(FName) : 함수 이름이 거슬린다면 요런 함수도 있으니 취향껏 사용하면 됨

	- 추가로 GetSocketLocation이 반환값이 FVector인데 (0,0,0)의 값이 나왔을 때 함수가 실패한건지 실제 (0,0,0)의 위치해서 그 결과가 나온건 지는 알 수 없음
	- 에픽 분들이 함수를 간결하게 작성하기 위해 이런 예외처리는 제외하고 만든 듯 싶음

	4. ANSICHAR, WIDECHAR
	- ANSICHAR : char
	- WIDECHAR : wchar_t

	- 각각 char, wchar_t를 typedef으로 한 번 더 감싸놓은 형태라 할 수 있음
	- FName의 경우 char를 인자로 받든 wchar_t를 인자로 받든 생성자를 다 만들어둬서 TEXT("")를 사용하여 캐릭터 자료형의 바이트를 고민하지 않아도 됨

	- TEXT("")에 대응하는 클래스(?)가 맞나,, TCHAR가 있음(아마 클래스 맞을 듯, 템플릿 클래스 ?)

	5. GetOwningComponent()->GetSocketLocation("Root")를 같은 의미로 쓰면
	- GetOwningCompoennt()->GetComponentLocation();
	- 캐릭터의 모델링은 보통 root 본의 위치와 컴포넌트(skeletal)의 위치가 동일함

	6. 발에 대해 IK를 적용한다는 것이 결국 계단 같은 곳에서 다른 층계여도 각각 발이 딛고 있게끔 만들수 있기 위함인데
	- 기본적으로 CharacterMovementComponent에 계단의 높이가 얼마나 높아야 올라갈 수 있는지를 정할 수 있는 변수가 있음 - 기본값은 45

	7. 캐릭터의 MovementComp에서 다루는 내용 중 Braking Sub Step Time 이라는 옵션이 있는데
	- Sub Step : 컴퓨팅 환경 상 움직임이 있어도 Analog한 것이 아니라 매 frame마다 텔레포트하는 방식으로 동작하게 되는데
	이 때 속도가 너무 빨라서 벽을 뚫고 가버릴수도 있는데 이런 상황을 방지하고자 일정 시간마다 보정을 해주는 개념이라고 생각하면 됨
	(다른 스레드라고 볼 수도 있겠으나 그걸 알기엔 Too Much)

	8. 벽을 탄다 -> 다 같은 구현이 아님
	- 덩굴을 자유롭게 타면서 이동하는 구현과
	- 일정 간격마다 짚을 수 있는 포인트가 있다거나 하는 구현

	은 다름

	9. Possess가 컨트롤러가 없게 되면 캐릭터는 공중에 있어도 멈추게 되는데
	- CharterMovementComp에 <컨트롤러가 없어도 피직스 실행>이라는 옵션이 있음

	10. 경사각에 따라 가속도를 다르게 줄 수 있는 옵션도 있으나 잘 작동하는지는 모르겠다고 하심

	11. 앉기(Crouch)를 제공하는 의의는
	- Capsule의 HalfHeight를 줄여준다거나 캠 위치를 바꿔준다거나 하는 동작을 제공한다는 것에 의의가 있음

	12. 1번에서 언급한 함수를 마저 얘기하면
	- 우리는 결국 Distance랑 Rotator를 값을 채워서 반환해주어야 하는데

	Distance = Result.Location.Z - Root.Z;
	
	float const Roll = +UKismetMathLibrary::DegAtan2(Result.Normal.Y, Result.Normal.Z);
	float const Pitch = -UKismetMathLibrary::DegAtan2(Result.Normal.X, Result.Normal.Z);

	Rotator = {Pitch, 0, Roll};

	- Distance는 차렷한 자세를 기준으로 그 발의 위치에서부터 땅이 어딨는지를 나타냄 -> Distance가 (-)라면 땅이 발보다 밑에 있고 (+)라면 땅이 발보다 위에 있음
	
	- DegAtan2 : Degree, Tangent 역함수, 인자는 2개의 의미

	- Rotator를 만드는 의의를 먼저 생각하면 땅이 경사진 땅이라면 발바닥과 땅이 닿으려면 발바닥이 그만큼 돌아있어야 함
	- 결국 발이 땅과 일치하게 만드려면 땅의 Rotator만큼 돌려야 함
	- 결국 위의 Rotator는 땅이 얼만큼 경사져 있나를 알려주는 건데

	Roll은 Y/Z에 대해 Tanget 역함수를 취한거고
	Pitch는 X/Z에 대해 Tanget 역함수를 취한라 할 수 있는데

	일단 왼손을 들고 언리얼의 축을 만들게 되면 검지가 z축, 중지가 x축, 엄지가 y축이라 할 때
	검지의 끝에서 중지, 엄지의 끝으로 가상의 선을 긋게 됐을 때 각각 그 선과 Z축이 이루는 각(위에서 구한 Roll, Pitch)이라 할 수 있겠음

	13. 언리얼의 축은 왼손을 사용하여 표현할 수 있는데 일반적인 좌표계와 비교했을 때 어떻게 돌리고 돌려도 일치시킬 수 없음
	- 어떻게 돌리고 돌려서 X축과 Z축을 일치시키게 됐을 떄 Y축을 반전시켜야만 언리얼의 축과 일치하게 되는데 이것이 Pitch가 Minus여야 하는 이유임
	- 이 개념이 Controller에서 Pitch Scale이 기본 값이 -2.5 였던 것과도 연결되는 개념임

	14. Actor를 월드에 배치하고 E를 눌러 Rotator를 바꾸는 모드로 전환하고
	- 각 축을 오른쪽으로 돌려봤을 때 X, Z축은 +로 변하는 것을 볼 수 있으나 Y축은 -로 변하는 것을 볼 수 있음
*/