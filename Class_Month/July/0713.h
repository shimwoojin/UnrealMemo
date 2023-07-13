#pragma once
/*
	1. C++의 MyInterface를 블프의 BP_Explosion에 상속 후 (C++의 인터페이스를 블프에 직접 상속)
	- C++ 코드로 (Execute_) 실행시켜보려 했을 때 블프에서 그 함수를 오버라이드 하지 않았음에도 "블프에 함수 구현이 있는 걸 부르겠다" 라는 흐름으로 빠짐(gen.cpp)
	- 이 테스트 과정에서 UINTERFACE() 였던 것이 0순위로 의심됨(지정자를 채우거나) or native의 동작이 원래 그렇거나

	- C++의 인터페이스를 블프 직접 상속 시 NativeEvent 사용은 고려를 해보자

	2. 솔루션 탐색기의 '검색'창 활용
	- '몽타주 재생' 노드의 정체를 밝히기 위해 '검색'창에 playmontagecallbackproxy 검색

	3. UPlayMontageCallbackProxy를 까보면
	- private으로 감추고 static 으로 선언한 'CreateProxy 어쩌구 저쩌구' 함수가 있음
	- 예를 부르게 되면 private으로 감춰둔 PlayMontage를 부르게 됨
	- 몽타주는 같은 몽타주여도 ID가 다름
	
	4. '몽타주 재생'의 출력 핀이 여러개일 수 있는 원리는 간단하게 말하면 'DynamicMulticastDelegate'임
	- AnimInstance가 갖고 있는 BlendOut, Interrupted, ... 등의 델리게이트에서 Proxy의 델리게이트를 호출하고
	- 우리가 연결해 놓은 핀들은 Proxy의 델리게이트에 바인드를 하게 되는 것

	- 위 과정을 거치면 우리의 애님 인스턴스가 몽타주마다 BlendOut, Interrupted,... 등의 상황에서 타이밍에 맞게(얘네도 델리게이트를 호출하는 것) Proxy의 델리게이트를 호출하는 함수를 호출하는데
	이 때 바인드되어 있는 것이 있다면 불리게 되는 것(Broadcast)

	- '몽타주 재생' 자체가 Proxy임 -> 이 노드가 불리는 만큼 Proxy가 만들어지게 된다고 보면 됨
	- 걸어놨던 내용은 '몽타주 재생' = Proxy 가 Destroy 되는 시점에 모두 Unbind 하게 됨

	5. Proxy : 중개자 정도의 의미로 받아들이면 됨

	6. 각각의 출력 핀(흐름)들은 UPROPERTY(BlueprintAssingable)로 걸려있어 우리가 거는 흐름은 다이내믹 멀티캐스트 델리게이트에 '할당' 하게 되는 것과 마찬가지
	- UPROPERTY(BlueprintAssingable) : dynmulticastdelegate를 블프에서 '할당'할 수 있게 만드는 키워드임
	- 이게 핀으로서 출력될 수 있었던 이유는 UObject - UEdNode - K2Node - ,... - K2Node_PlayMontage 로 상속받은 구조 자체로 엔진에서 처리를 해주는 듯
	- 위에서 설명한 Proxy도 K2Node_PlayMontage가 참조하는 형태로 가지고 있고 실질적으로 K2Node_PlayMontage가 Proxy를 만들어서 처리하는 듯

	7. Proxy를 만들어서 부르는 '몽타주 재생' 이건 Character의 함수인 PlayAnimMontage이건 결국엔
	- AnimInstance의 MontagePlay를 내부에서 부르고 있음
	- 결국 AminInstance의 MontagePlay가 끝판왕임 -> 얘 부르면 됨

	8. uasset의 경우 Content 이후의 경로만 망가뜨리지 않는다면 '이주'가 아닌 폴더에서 복사나 이동으로 넘겨줘도 됨

	9. 에디터 유틸리티 - 에디터 유틸리티 블루프린트가 있음
	- 에디터에 기능을 더 추가해줄 수 있는 듯

	10. 애니메이션을 다룸에 있어 블프가 아쉬운 점은
	- MetaData를 다룰 수 없음

	- 애니메이션 에디터에서 배열로 추가해 줄 수 있고
	- MetaData 클래스를 만들어서 그 클래스를 위 배열에 추가해 줄 수 있음
	- 하지만 CPP에서나 처리해 볼 수 있는 듯

	- 애니메이션의 MetaData를 유용하게 쓸 수 있는 경우는 '공격 애니메이션' 자체가 공격 계수를 가지고 있어 원래 공격력에 배수로 데미지가 들어간다던가
	하는 애니메이션 단위로 처리가 가능함(다른 유용한 활용이 많을 듯)

	- 유틸리티 블루프린트에서는 'GetMetaData'를 가지고 올 수 있긴 함(인 게임내 적용 받을 내용이 아니라 애니메이션의 관리를 위해 여기에만 풀어놓은 것 같기도)

	11. 애니메이션 에디터에서 '커브'를 시간 별로 편집하게 되면
	- 애니메이션 블루프린트에서 'Get Curve Value'로 현재 애니메이션의 시점에서의 커브 값(float)이 얼마인지를 알 수 있음
	
	- 게임에 적용시키기 좋은 예는 공격 타이밍에 따라 데미지가 다르게 들어갈 수 있게끔 처리할 수도 있을 듯
*/