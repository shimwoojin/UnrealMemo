#pragma once
/*
	1. 무기에 ParticleSystemComponent를 붙여서 공격시에만 이펙트가 나타나도록 변경해줌
	- BP_Weapon에 ParticleSystemcomponent를 2개 만들어서 각각 effect, trail이라는 이름으로 지어줌
	- 발동 시에만 파티클이 나타나도록 해줘야 하기 때문에 파티클 컴포넌트 디테일에서 AutoActivate를 꺼줌
	
	2. Trail과 Effect에 각각 Activate, Deactive하는 함수를 만들어주고
	- Effect는 Activate, Deactivate 노드에 이어주고
	- Trail은 BeginTrails, EndTrails 노드에 이어줌
		- Trail이라는 것이 무기에 붙은 파티클에 보통 이런 표현을 한다고 함(아마 경로가 있는 파티클에 이 함수 적용하는 듯)
	- Begintrail는 추가 핀이 더 필요한데 1번 소켓 이름, 2번 소켓 이름, 어떤 소켓에서 시작할지, 파티클 넓이
	
	3. 위에서 각각 만든 함수들을 ActivateAttack, DeactivateAttack에 Sequence로 더 이어주게 되면
	- 무기가 공격할 때 노티파이에 의해 호출됨(그렇게 되도록 앞에서 만들어 놨음)
	- ActivateAttack은 EnableCollision, ActivateEffect, ActivateTrail을 호출하고
	- DeactivateAttack은 DisableCollision, DeactivateEffect, DeactivateTrail, overlappedActor를 비워줌

	4. Begintrails에 넘겨 줄 인자중에 소켓이름이 있었는데 이거 변수로 따로 관리해주고 상속받은 BP_Weapon들에서 다시 세팅해 줌
	
	5. Effect쪽에서는 자동으로 어떤 소켓에 가서 Attach할지 정하는 옵션 있었는데 여기서 소켓이름 넘겨주면 됨

	6. 무기에 붙은 이펙트들은 scale 조정해서 쓰는 것이 좋음

	7. ParticleSystemComponent를 사용하기 위해 SkeletalMeshComponent 밑에 달아놨었는데 이걸 다른 곳에 달게 되면
	파티클이 안 나올 수 있음
	- particle의 부모에서 붙을 소켓의 이름을 찾는데 그게 만약 collision 같은 곳이라면 그 이름에 맞는 소켓이 없기 때문

	8. 피격 시 피격 대상의 몸 색 바뀌는 것에 대해 질문을 했었는데
	- 제일 처음에 했던 방법은 BodyColor의 색을 direct로 바꾸는 방법이였고
	- 두 번째 했던 방법은 BodyColor에 EmissiveColor를 더해주는 방식이였고
	- 세 번째 했던 방법은 두 번째 방법에서 그냥 머티리얼 인스턴스를 만들어서 까만색 BodyColor를 적용해준 강사님의 취향이였음

	- 결론은 EmissiveColor인자에 바꾸고 싶은 Color로 넘겨주는 게 맞고
	쉐이더 코드에서 이 넘겨 받은 값을 기존 값과 섞는 방식을 다르게 해줘야 한다는 것임
	- 기존 방법은 넘겨 받은 EmissiveColor랑 그냥 더해주는 방식이여서 진하면 더 진하게 연하면 더 연하게 나오는 문제가 있었음
	- 피격 색이 제대로 나오려면 쉐이더 코드 수정을 해줘야 함(다음에 더 알아보는 걸로)
	
	9. 무기는 끝났고 스킬로 넘어가는데 일단 처음 할 스킬은 teleport임
	- BP_Skill을 만들고
	- 상속받은 BP_Teleport를 만듬
	- 안 가져온 에셋이 있었는데 <내려보기> 프로젝트 만들어서 material 하나 가져옴

	10. Bk_Weapon쪽에서 Activate, Deactivate를 커스텀 이벤트로 만들어줌
	- bActivated 변수(bool) 끄거나 키는 커스텀 이벤트
	- 커스텀 이벤트가 함수와 다른 점 ?
		- 출력 핀이 없거나 뭐 기타 등등 있지만 결론은 취향 차이

	11. Teleport 스킬 매커니즘은
	- teleport를 사용 할 상태로 바꾸고 화면에서 텔레포트 할 지점을 정한 다음 그 위치로 텔레포트 하려면 텔레포트하고 취소하려면 취소하는 ?
	- 이 과정에서 Decal이라고 추가한 컴포넌트가 teleport 스킬 활성화 상태이면 visible이 켜지고 비활성화이면 visible이 꺼지는 식으로 동작

*/