#pragma once
/*
	1. 애니메이션 대량 편집 시 간단한 팁
	- 수정할 내용이 같은데 미리 편집 된 애니메이션이 있다면 같이 묶어서 대량편집하고 그 값을 이용해서 나머지 값들 처리

	2. 애니메이션 노드를 처리하는 방법 중
	- 노드에서 AnimSequence에 대해 변수로 승격시켜주고 cpp적으로 같은 노드에 대해 어떤 애니메이션을 쓸지 정하는 방식으로 처리도 가능

	3. sit to stand, stand to sit 애니메이션의 의의
	- 더 자연스러운 애니메이션 연출을 위해서라면 사용하는 것이 맞음
	- 하지만 앉아 있는 포즈와 서 있는 포즈 간의 전환에서 일어나는 블렌드가 나쁘지 않다면 사용하지 않아도 됨
	- 저런 비슷한 애니메이션으로 방향 전환 시 발의 움직임을 표현하는 애니메이션들이 종종 있는데 요것도 마찬가지로 적용시켜주는 것이 좋음

	4. SkeletalMeshComponent 상속한 컴포넌트 ?
	- 캐릭터의 기본 SkeletalMeshComponent는 교체 가능함
	- 근데 왜 ?
	- GetMesh()->GetAnimInstance()-> 몽타주 관련 처리 에 대해서 SkeletalMeshCompoenent에서 상속해서 미리 처리하기 위함

	5. ACharacter의 생성자는 인자가 없지 않음
	- 언리얼은 인자가 없는 생성자와 FObjectInitializer 구조체를 받는 생성자 2가지를 사용할 수 있는데
	- ACharacter는 인자가 없는 생성자 대신 FObjectInitializer를 받는 생성자를 쓰며, 대신 구조체에 대해 기본값을 주어 사실 상 기본 생성자가 불리는 것처럼 쓰이는 듯
	- ATPSCharacter에서 기본 생성자를 호출 시 : Super()를 명시적으로 적지 않아도 불리게 되는데 이 때 불리는 생성자는 위에 언급한 FObjectInitilizer에 기본값을 준 생성자일 것이다.
	- 이 생성자를 우리의 클래스에서도 똑같이 오버라이드 해주게 되면(FOjbectInitializer에 기본값을 준) 4번에서 언급했던 SkeletalMeshComponent의 교체가 가능해짐

	6. UObject 기반 클래스엔 new, delete를 하지 않는다
	- 사실 UObject 기반이 아니여도 메모리 누수를 염두에 두어 new, delete 대신 스마트 포인터를 활용하는 경우가 많다
	
	7. Actor가 아닌 UOjbect 기반에 대해 new 를 처리하는 방식을 크게 2가지로 나눌 수 있는데
	- 생성자 : CreateDefaultSubbject
	- 생성자가 아닌 어디든 : NewObject 혹은 CreateObject

	- 생성자 기반의 new 키워드 대체 팩토리 함수인 CreateDefaultSubObject는 2개의 시리즈가 더 있음, CreateEditOnlySubobject, CreateOptionalDefaultSubobject
	- 캐릭터 기준으로 각각 CreateEditOnlySubobject : 애로우 컴포넌트에, CreateOptionalDefaultSubobject : 스켈레탈 메시 컴포넌트에 사용하고 있음(ACharacter의 생성자에서)

	- EditOnly는 패키징 시 유효하지 않고 에디터 상에서 테스트할 때만 유효하다는 의미의 키워드이고
	- Optional은 자식에서 교체할 수 있음을 의미함

	8. 스켈레탈 메시 컴포넌트가 ACharacter 선에서 CreateOptionalDefaultSubobject를 쓰고 있기에 이를 대체하는 방법이 있는데
	- ATPSCharacter::ATPSCharacter(FObjectInitializer const & ObjectInitializer)
		: Super(ObjectInitializer.SetDefaultSubobjectClass<UTPSCharacterMeshComponent>(Super::MeshComponentName) {}

	- 위와 같이 ATPSCharacter의 생성자에서 저런 처리를 해주게 되면 부모의 컴포넌트를 바꿀 수 있음
	- 추가로 ObjectInitializer의 멤버함수 중에 쓸만한 것들이 꽤 있었음

	9. 부모의 컴포넌트를 바꾸는 기법에 대해 Shooter 장르의 경우 총기의 파츠를 바꾸는 경우 유용할 수 있음
	- 무기의 콜리전 컴포넌트를 바꾸는 것도 괜찮다고 생각함

	10. Crouch는 CharacterMovementComponent의 디테일 아래쪽에 bCrouch를 켜주어야 정상 동작함
	- 기본적으로 Character 함수인 Crouch, UnCrouch는 부르면 알아서 캡슐을 줄인다거나 카메라 위치를 바꾼다거나 처리를 해줌
	- 앉았을 때 캡슐 컴포넌트의 height를 줄이는 값도 조정해주면 좋음

	11. hit에 대해 BoneName을 받는 경우 hit된 대상은 SkeletalMesh여야 한다
	- 스켈레톤의 본 네임이 아니라 PhysicsAsset의 본 네임이 나오게 됨
	- PhysicsAsset의 경우 스켈레톤에 비해 간략화 된 본 구조를 가지고 있다

	12. 뼈마다 데미지가 다르게 들어 갈 경우 처리에 대해 꿀팁은
	- Head에 대해 우선 처리
	- 문자열이 "_l", "_r"로 끝나는지(팔, 다리) (FString::EndsWith)
	- 그 외(Body)
	- 혹은 Miss

	13. 원거리는 Hit이 쉬우나 근거리는 Hit이 쉽지 않음
	- 근거리도 Hit에 대해 처리를 하고 싶다면 검신에 트레이스를 주어 HitResult를 기반으로 처리가 가능하긴 함
*/