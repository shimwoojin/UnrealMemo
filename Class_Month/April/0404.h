#pragma once
/*
	1. 스킬 장착부분을 구현하는 것이 과제였음
	- weaponA,B를 장착하는 것과 비슷한 로직
	- getter에 유효성 검사를 해서 CurrentSkill에 유효성 검사를 적용하면 스킬 장착 여부를 알 수 있었고
	- 장착하지 않았다면 장착해주면 되고
	- 장착한 상태라면 지금 누른 스킬과 장착한 스킬이 같은지 아닌지를 검사해서 추가적인 처리를 해줌

	2. 정씨 과제중에 getter의 유효성 검사하는 노드에 대해서 호출 시점인지 아니면 cache된 내용일지에 대해 논란이 있었는데
	- 결론은 호출 시점에서 getter를 다시 돌리는 식임(본질이 getter이기 때문, 실행핀이 있지만)

	3. 게임에서 안 보이게 하는 방법 중에
	- CurrentWeapon - SkeletalMesh - SetVisibility보다
	- CurrentWeapon - ActorHiddenInGame 핀이 더 낫다고 하는데
	- 그 이유는 액터가 가지고 있는 딱 어느 대상을 집어서 동작시키는 코드는 피하는 게 좋다고 함

	4. 스킬이 장착되어 있지 않을 때만 무기 장착이 가능해야 하기 때문에
	- WeaponA,B쪽에서 진입 근처에 CurrentWeapon이 유효하지 않을때만 들어갈 수 있게 바꿈
	- 아마 공격도 마찬가지(Action)

	5. IsArmed같이 무기 장착 중인지 확인하기 위해 만들어놓은 함수 혹은 인터페이스가 있다면 이것을 쓰는 것이 맞음
	- CurrentWeapon을 검증된 get으로 변환해서도 같은 작업이 동일하지만 이렇게 IsArmed를 써야 하는 이유는
	- 코드의 가독성도 그렇고 IsArmed가 변화했을 때 일괄 처리되어야 하기 때문임

	6. BS_Caster 블렌드 스페이스를 만들어줌
	- Wizard_Idle, WizardWalk 4방향, WizardRun 4방향 적용해줌(Speed, Direction)

	7. ABP_Character의 이벤트 그래프 중에 수정해 준 부분이 있는데
	- ABP_Character가 Armed 변수를 가지고 있었고 그 변수를 매 tick마다 업데이트를 해주는 방식이였는데
	- 그 방법이 IsArmed 인터페이스를 콜해서 얻어오는 식이였음
	- 그것이 아니라 캐릭터가 무기를 장착하는 과정에서 ABP_Character의 변수를 업데이트하는 ABP의 인터페이스를 콜해주는 것이 맞는 방식
	- 하지만 기존 ABP의 bArmed로 스테이트 머신을 제어하는 방법은 안 쓰기로 했기 때문에 기존 bArmed 부분은 다 지워줌

	8. bArmed를 지웠기 때문에 캐릭터가 무장상태인지 비무장상태인지 알 방법이 없어짐
	- WeaponType 열거형을 추가하고(일단 None과 Sword를 가짐)
	- ABP전용 인터페이스를 만들어서
	- WeaponType을 input으로 받는 인터페이스 함수 정의해줌, 추가로 skill의 activate를 제어하는 input이 bool인 인터페이스 함수도 하나더 정의함
	- 무기의 최상위인 BP_Weapon이 아니라 상속받은 BP_Sword쪽에서 WeaponType값 지정해주고(Sword) BP_Weapon에선 이 type을 블프읽기전용으로 처리(야메임)

	- WeaponA,B 쪽 로직 끝 부분에 가서 ABP의 WeaponType변수를 바꾸는 로직 추가
	- ABP의 WeaponType으로 블레드 포즈 하는 노드가 있음

	9. ABP쪽에서 기존 Idle과 Sword상태를 전환하는 스테이트 머신을 지우고 
	- BlendPose(E_WeaponType)노드를 추가하고 (ABP가 가지고 있는 WeaponType변수가 무엇인지에 따라 애니메이션 결정함)
	- BlendSpace3개(Unarmed, Sword, Wizard)3개를 놓고
	- 각각 입력 핀에 변수를 연결해줘야 하는데 더 좋은 방법은
	- 노드 클릭 후 디테일 탭에서 핀에서 바로 X,Y값에 어떤 변수쓸지 할당해 줄 수 있었음

	- BlendPose 기본 포즈에 Unarmed주고 E_WeaponType이 Sword이면 BS_Sword포즈로 바뀌게끔 하고
	- Wizard포즈는 Sword에서도 갈 수 있고 Unarmed에서도 갈 수 있는 포즈이기 떄문에 bool로 블렌드 포즈하는 노드를 새로 만들어서
	- bSkillActivated변수로 제어함

	- 결론적으로 ABP가 가지고 있는 E_WeaponType으로 어떤 포즈 취할 지 먼저 정하고
	- bSkillActivated 변수가 켜져 있으면 BS_Wizard를 우선하는 방식으로 처리하는 것

	- BlendPose(E_WeaponType)에서 새로운 E_WeaponTyep이 생겨서 새로운 무기에 Type을 다르게 주면 새로운 BlendSpace를 넘겨서 다를 포즈를 취할 수 있게 됨

*/