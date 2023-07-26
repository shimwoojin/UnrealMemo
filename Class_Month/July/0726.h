#pragma once
/*
	1. AActor::SetActorEnableCollision(bool); 로 collision에 대한 제어가 가능한데
	- Actor가 들고 있는 bool 변수에 대해 값을 바꿔주고
	- 값이 바뀐 것에 대해 Actor가 들고 있는 component들에 대해 요 값이 바꼈다고 알려주는 역할을 하는 함수임

	- 정확히 이 bool 값이 collision 관련해서 어떤 역할을 하는지 파악은 불가능했으나(bActorEnableCollision이라는 bool 변수가 있고 요 변수의 getter 함수를 여기저기 갖다 쓰더라)
	- 적어도 Collision 관련 옵션을 만질 수 있는 Component들의 옵션을 건드리는 것과는 다른 결이라는 것을 파악할 수 있었음

	- 그렇게 판단한 이유는 만약 캐릭터의 capsule이 NoCollision 상태가 되면 바닥과도 Collision이 일어나지 않아 중력의 영향을 받아 바닥으로 떨어지게 되는데
	- 적어도 그런 현상은 일어나지 않았고
	- 코드를 얕게 파봤지만 저 bool 값에 따라 Component의 Collision 관련 옵션을 사용할지 아니면 저 bool 값 그대로를 사용할지에 대한 코드가 있던 것까지는 파악했음

	- UPrimitiveComponent가 들고 있는 BodyIntance라는 멤버 변수(구조체인듯?)가 Collision 관련 옵션을 담당하는 듯 싶음

	- Actor가 충돌 자체에 반응하는 것과 ObjectType간에 hit일지 overlap일지 ignore일지는 또 다른 얘기인 것 같음

	2. 캐릭터의 캡슐 관련해서 NoCollision으로 시작할때랑 시작하고 나서 Capsule을 NoCollision으로 바꿀 때랑 차이가 있는데
	- 이게 버그인지 의도한건지는 모르겠으나
	- 시작 전에 Capsule이 NoCollision으로 시작하면 중력의 영향을 받고 메쉬와는 충돌이 일어나지 않아 무한히 바닥으로 떨어지나
	- 게임 중에 Capsule을 NoCollision으로 바꾸게 되면 그대로 가만히 멈추게 됨

	3. 내 딴에 결론을 내렸는데
	- AActor::SetActorEnableCollision(bool)로 collision을 안 하겠다고 하나 Capsule의 콜리전을 NoCollision으로 돌리나
	외부에서 보기엔 같은 결과가 나와야 하는 것이 맞음 -> Mesh가 기본 세팅을 안 건드렸다는 가정 하에(Query Only 유지)

	- Capsule을 NoCollision으로 시작하면 바닥을 뚫고 추락함
	- AActor::SetActorCollision(false)를 ConstructionScript에서 불러도 무한히 추락함

	- 하지만 BeginPlay에서 Capsule을 NoCollision으로 바꾸면 제자리에 멈춤
	- 마찬가지로 BeginPlay에서 AActor::SetActorCollision(false)를 부르면 제자리에 멈춤

	- 결론 : 캐릭터의 경우 ConstructionScript를 포함한 이전에 Collision을 안 하겠다라고 했을 경우 우리가 의도한 결과를 얻을 수 있으나
	적어도 BeginPlay 이후에서 Collision 관련 옵션을 NoCollision으로 바꾼다고 했을 때 우리가 의도한 결과가 나오지 않을 수 있음

	4. 에셋의 래퍼런스 경로에서
	- Game은 환경변수로 설정 된 프로젝트의 Content 폴더를 의미하고
	- 마지막에 에셋의 이름을 찍기 전에 . 전에는 패키지 이름인데
	- 패키지란 ? -> 에셋이 여러개여도 하나의 파일로 이루어져 있을 수 있음

	- 추가로 '' 랑 앞에 어떤 타입인지를 알려주는 문자를 빼도 되긴하지만 안 되는 경우가 있으니 풀네임으로 적도록 합시다

	5. IK를 하기 위해
	- AnimInstance에 발에서부터 바닥으로 트레이스 하기 위해 FName으로 구성 된 양 발 뼈 이름을 가진 변수 2개를 선언해 둠
*/