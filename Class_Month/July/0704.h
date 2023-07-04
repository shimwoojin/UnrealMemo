#pragma once
/*
	1. TEnumAsByte<EDrawDebugTrace::Type> DrawDebugType;
	
	UENUM(BlueprintType)
	namespace EDrawDebugTrace
	{
		enum Type
		{
			None,
			ForOneFrame,
			ForDuration,
			Persistent
		};
	}

	- UENUM에 BlueprintType을 해야 블프에서 사용 가능
	- C의 문법 enum을 네임스페이스로 구분지어 enum class와 비슷하게 사용

	2. enum이나 enum class나 따로 타입을 정하지 않으면 int 형인데(4byte)
	- enum class TestType : uint8 같은 문법으로 타입의 크기를 정해줄 수 있음
	- 추가로 enum에 정의한 열거자들이 순서대로 0,1,2,... 이런 literal 값들을 가지게 되는데
	이 literal조차 명시한 타입의 크기만큼 잡히게 됨

	3. 접미어 u는 unsigned int, ul은 unsigned long, ull은 unsigned long long

	4. unsigned long operator ""_deg(int i)
	{
		return i;
	}

	- 접미어의 오버라이딩을 하여 1_deg;는 int형이 아닌 unsigned long임
	- _(언더바)는 표준과 겹치는 이름이 될 수도 있으니 권고사항 -> 언리얼 프로젝트는 빌드 오류를 냄

	5. UENUM(BlueprintType)은 : uint8이 강제 됨
	- enum은 BlueprintType이 붙게 되면 enum의 선언에서 : uint8이 강제되는 것은 아니지만 사용함에 있어 TEnumAsByte<>를 거쳐 사용하고
	- enum class는 BlueprintType이 붙게 되면 선언에 : uint8이 강제됨 -> 빌드 오류가 나버림

	- UENUM(BlueprintType)을 사용하게 되면 namespace + enum 을 사용하고 TEnumAsByte까지 사용하는 것이 번거롭지만 나아보임

	6. #include <Kismet/GameplayStatics.h>는 Gameplay에 대한 class 내부의 static 함수들의 모임
	- 사실 상 전역 함수
	- 임시로 DelegateTrigger를 찾기 위해 UGameplayStatics::GetActorOfClass(this, ADelegateTrigger::StaticClass())로 찾았음

	7. #include "Particles/ParticleSystemComponent.h"
	- 파티클은 헤더 경로가 이런데 자주 쓸 거 같으니 외우도록

	8. Particle->Activate(true);
	- true의 파라미터 네임은 bReset임 -> true라는 건 활성화 돼 있는 중에 이 코드가 불리면 다시 시작한다는 뜻
	- 기본값은 false임

	9. GetActorLocation은 내부적으로 RootComponent의 Location을 얻어 옴

	10. 스태틱 메쉬의 모빌리티가 스태틱이라면 이동 관련 코드에도 영향을 미침 -> 무버블로 변경
	- SimulatePhysics로 바꾸면 Collision Preset이 PhysicsActor로 바뀌고 조명도 무버블로 자동으로 바뀜

	11. SphereOverlapActors C++ 버전 사용
	
	UKismetSystemLibrary::SphereOverlapActors
	(
		this,
		GetActorLocation(),
		500,
		{ EObjectTypeQuery::ObjectTypeQuery4 } ,
		AActor::StaticClass(),
		{ this },
		OutActors
	);

	- EObjectTypeQuery에 대해 ObjectTypeQuery4를 준 건 ObjectType이 PhysicsBody인 물체와의 충돌 검사임

	- ECollisionChannel, EObjectTypeQuery, ETraceTypeQuery 콜리전 관련하여 이렇게 3가지 열거자를 언리얼에서 제공하는데 각각 쓰임 방법이 다름

	1) ECollisionChannel : 엔진이 제공하는 기본 ObjectType 6개 + Channel 2개 + 엔진이 예약한 채널 6개 + 우리가 프로젝트 세팅에서 직접 정의할 수 있는 커스텀 채널 18개, 
	총 32개의 채널에 대해
	ObjectType에 대해선 각각 이름으로 접근 가능 ECC_WorldStatic, ECC_WorldDynamic, ECC_Visibility 등
	우리가 커스텀 정의한 채널들에 대해선 정의한 순서대로 ECC_GameTraceChannel1, ECC_GameTraceChannel2, ... 로 접근 가능

	이 때 유의할 점은 Object이건 Channel이건 구분 없이 정의한 순서대로 <Config - DefaultEngine.ini>에 적혀 있음

	Object1 - Channel1 - Channel2 - Object2 순으로 새로운 콜리전을 정의하게 되어도 만든 순서대로 ECC_GameTraceChannel로 구분지어 짐

	2) EObjectTypeQuery : 콜리전이 Object와 Channel에 대해 크게 구분지어지기 때문에 EObjectTypeQuery는 ObjectType에 대해서만 접근 가능함
	ObjectTypeQuery1, ObjectTypeQuery2, ObjectTypeQuery3, ObjectTypeQuery4, ... 이렇게 접근되어지는데
	기본적으로 ObjectTypeQuery6까지는 엔진이 기본 제공하는 ObjectType임(ObejctTypeQuery1 : WorldStatic, ObejctTypeQuery2 : WorldDynamic, ObejctTypeQuery3 : Pawn 등)
	순서로 유추가능하고
	ECollisionChannel과 다르게 Custom ObjectType들에 대해선 Channel과 관계없이 ObjectType이 추가된 순서로만 구분한다

	ex) Object1 - Channel1 - Channel2 - Object2 순으로 콜리전에 대해 커스텀 정의가 생기게 되면 
	ObjectTypeQuery7 : Object1 이고
	ObjectTypeQuery8 : Object2 인 것임

	3) ETraceTypeQuery : 2번의 설명에서 Obejct와 Channel의 차이를 이해한다면 같은 방법임

	ex) Object1 - Channel1 - Channel2 - Object2 순으로 콜리전에 대해 커스텀 정의가 생기게 되면
	TraceTypeQuery3 : Channel1
	TraceTypeQuery4 : Channel2

	12. 참고로 엔진에서 사용자 정의 채널에 대해선 #define COLLISION_WEAPON ECC_GameTraceChannel1 과 같은 매크로를 사용할 것을 권고함
	- ex. #define OBJ_COLLISION_OBJECT1 EObjectTypeQuery::ObjectTypeQuery7
	- ex. #define CHN_COLLISION_CHANNEL1 EObjectTypeQuery::TraceTypeQuery3
*/