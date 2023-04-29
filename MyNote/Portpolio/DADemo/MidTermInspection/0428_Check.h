#pragma once
/*
	1. 게임 요소들 : 
		- 플레이어 (Attacker, Constructor, Farmer) <3종류> 
		- Enemy (Animal, Undead, InfinityBlades) 3종족 * 각 5마리 씩 = <15종류> 
		- EnemyBoss <1종류>
		- Weapon (Attacker 2개, Constructor 1개, Farmer 1개)  <4종류>
		- Skill (Attack 전용 4개, Constructor 전용 2개, Farmer 전용 2개 -> 사실 무기 마다 각 2개씩임) <8종류>
		- TowerMaker (Splash, Slow) <2종류> 
		- Tower (Splash, Slow) <2종류>
		- Crops <1종류>
		- CropsSpawner <1종류>
		- Spawner (몬스터마다 종류가 있는데 이거는 일단 차후에 처리)
		- DeffensePoint <1종류>
		- UI들(Aim용 UI, 상점용 UI, Player용 UI, Damage용 UI)

	2. 인터페이스 설명
		2.1) Character 상속용 인터페이스
			2.1.1) BPI_CharacterAction
				- void SwapWeapon(bool) : 무기를 스왑
				- void Action1() : Player의 경우 마우스 좌클릭 공격, Enemy의 경우 Attack
				- void Action2()
				- void Run() : Player의 경우 Timeline을 통한 부드러운 MaxWalkSpeed 전환
				- Jumping() : Player는 AnimInstance와의 통신을 위해
				- EndJumping() : 〃
			2.1.2) BPI_CharacterState
				- bool IsState(CharacterState) : state가 input state와 같은지 true, false
				- CharacterState GetState() : 현재 state 반환
				- bool IsArmed() : Depracated
				- void CollisionOff() : Player는 Enemy와 충돌 off(SetCollisionResponseToChannel 사용하여 pawn에 대해 ignore), Enemy의 경우 Player와의 충돌에 사용
				- void CollisionOn() : Player는 Enemy와 충돌 on(SetCollisionResponseToChannel 사용하여 pawn에 대해 block)
				- void SetState(CharacterState)
				- float GetLifePercent() : LifeNow / LifeMax를 return, Player전용 UI와 통신을 위함
				- IsEnemy() : Enemy라면 true
			2.1.3) BPI_CharacterFunc (Action 혹은 State로 구분이 어려운 경우 Character 전용 인터페이스는 전부 여기에 정의)
				- void ActivateAttack() : player의 경우 CurrentWeapon의 공격용 함수 호출을 위함
				- void DeactivateAttack() : ActivateAttack()의 끝을 알리기 위함
				- void EnableAttack() : 콤보 공격용 bool 변수 제어
				- void DisableAttack() : 〃
				- Vector GetRightHandSocketLocation() : Skeletal Mesh의 오른손 위치 반환 (Player의 경우 스킬 위치 잡는 역할)
				- Vector GetLeftHandSocketLocation() : Skeletal Mesh의 왼손 위치 반환 (Player의 경우 스킬 위치 잡는 역할)
				- void SetCurrentWeaponHiddenInGame(bool) : current weapon의 숨김 및 표시를 위함
				- float GetBodyHalfHeight() : Capsule Component의 절반 높이
				- void ZoomIn()
				- void ZoomOut()
		
		2.2) Character Animation 상속용 인터페이스
			2.2.1) BPI_CharacterAnimation(Character를 상속받은 클래스들의 Animation BluePrint의 통신을 위함, Enemy도 필요하다면 상속)
				- bool SetIsJumping() : bool 변수 setter

		2.3) Controller 상속용 인터페이스
			2.3.1) BPI_Controller(PlayerController는 이 인터페이스를 상속)
				- BP_Player* GetPlayers() : Player Controller는 Player 3종류를 알고 있음(배열로 반환)
				- bool NotPlayer(Actor) : input actor가 player인지 아닌지 true or false
				- void UpdatePlayerSkillUI() : 캐릭터 전환 등 SkillUI가 변할 경우 Update(Skill마다 고유 UI를 가짐)
				- void UpdatePlayerLifeGaugeUI() : LifeGauge가 변할 경우 처리(피격 혹은 새로운 player로 possess하는 경우에 Update)
				- void UpdatePlayerAllUI() : SkillUI, LifeGaugeUI 등 Player 전용 UI는 이 함수로 모두 Update

		2.4) Player 상속용 인터페이스
			2.4.1) BPI_PlayerCommon(Player만 가져야 할 특성이 있다면 이 인터페이스에서 정의, 프로젝트가 크지 않으므로 Player 통합용 인터페이스 하나로 처리)
				- bool AmIControlledPawn() : Player의 CurrentControl bool 변수를 반환(조종하는 player용 actor가 3개 이므로 현재 조종 상태를 알기 위함)
				- void ControllingOn() : player 전환 시 CurrentControl bool 변수를 제어하기 위함
				- void ControllingOff() : player 전환 시 CurrentControl bool 변수를 제어하기 위함
				- Texture2D GetSkillEImage() : Player의 변수인 CurrentWeapon에서 Skills[0]의 PlayerUI 전용 Texture2D를 얻어옴(Controller에서 UI처리를 위함)
				- Texture2D GetSkillRImage() : Player의 변수인 CurrentWeapon에서 Skills[1]의 PlayerUI 전용 Texture2D를 얻어옴(Controller에서 UI처리를 위함)
				- Texture2D GetWeaponImage() : Player의 변수인 CurrentWeapon의 PlayerUI 전용 Texture2D를 얻어옴(Controller에서 UI처리를 위함)
				- float GetSkillECoolTimePercent() : PlayerUI 전용 스킬UI의 ESkill CoolTime 표시를 위함(현재 조종 중인 Player와 Player 전용 UI를 알고있는 BP_PlayerController에서 PlayerUI 업데이트를 위함)
				- float GetSkillRCoolTimePercent() : PlayerUI 전용 스킬UI의 RSkill CoolTime 표시를 위함(현재 조종 중인 Player와 Player 전용 UI를 알고있는 BP_PlayerController에서 PlayerUI 업데이트를 위함)
				
		2.5) Enemy 상속용 인터페이스
			2.5.1) BPI_EnemyCommon
				- void SetWalkSpeed() : Enemy는 각 개체마다 정해진 Walk와 Run의 속도가 정해져 있기 때문에 상황에 따라 이 값을 MovementCompoenent의 MaxWalkSpeed를 지정해주기 위함
				- void SetRunSpeed()
				- float GetWalkSpeed()
				- float GetRunSpeed()

				- EnemyController에서 call할 내용이 많을 것이고 Player와의 통신을 위해서도 추가될 내용이 있을 예정

		2.6) Damage를 줄 수 있는 개체들의 상속용 인터페이스(Skill, Weapon, Enemy)
			2.6.1) BPI_Damage
				- Integer WhatDamageType() : DamageType Integer 반환(이 인터페이스를 상속받은 클래스들은 DamageType이라는 Bitmask Integer를 가짐, 누구에게 데미지를 줄 수 있는지를 위한 변수)
				- bool WhoCanDamage(DamageType) : AnyDamage를 처리하는 actor들에서 call할 인터페이스, 나에게 damage를 줄 수 있는 DamageType인 경우만 damage를 입는 방식으로 처리
				- Actor GetTargetActor() : Target을 정하고 damage를 주는 행동이 있다면 target 반환(ex. Homing)

		2.7) Widget 상속용 인터페이스
			2.7.1) BPI_Widgets(Interface가 필요한 모든 widget은 이 인터페이스를 상속 받음)
				- void SetGaugePercent(float) : ProgressBar의 Percent용 Setter
				- void SetGaugeColor(Linear Color) : ProgressBar의 Color Setter
				- void SetSkillQImage(Texture 2D) : 무기 UI Image Setter, 플레이어 전환 혹은 게임 시작 시 call
				- void SetSkillEImage(Texture 2D) : 무기 UI Image Setter, 플레이어 전환 혹은 게임 시작 시 call
				- void SetSkillRImage(Texture 2D) : 무기 UI Image Setter, 플레이어 전환 혹은 게임 시작 시 call
				- void SetSkillEPercent(float) : PlayerUI의 E스킬 cooltime 전용
				- void SetSkillRPercent(float) : PlayerUI의 R스킬 cooltime 전용
				- void SetHPNow(float) : 상점UI의 DeffensePoint의 현재 체력 표시용 Text Setter용
				- void SetHPMax(float) : 상점UI의 DeffensePoint의 최대 체력 표시용 Text Setter용
				- void SetHPpercent(float) : 상점UI의 DeffensePoint의 체력바 Setter용
				- void SetMoney(Integer64) : 상점 UI의 Money 표시용

		2.8) 상호작용이 가능한 actor들 상속용 인터페이스(필요하다면 추가)

	3. 통신
		3.1) Player와 통신
			3.1.1) Player와 Skill, Weapon의 관계
				- Player는 BeginPlay에서 Weapon들을 spawn 후 가지고 있음(Attacker는 2종류, Constructor는 1종류, Farmer는 1종류)
				- Weapon의 Owner는 Player, Instigator는 Player
				
				- Weapon은 BeginPlayer에서 Skill들을 spawn 후 가지고 있음(무기마다 스킬 2종류(E,R))
				- Skill의 Owner는 Player, Instigator는 Player

				- Skill이 spawn하는 투사체 혹은 actor가 있는데
				- spawn된 개체의 Owner는 Skill, Instigator는 Player

			3.1.2) Player와 PlayerController, UI의 관계
				- Constructor와 Farmer는 Controller에서 Spawn
				- Attacker, Consructor, Farmer인 Player 3종류는 Controller가 배열에 보관하여 알고 있음
				- Player전용 UI는 PlayerController가 알고 있음
				- 화면에 체력 게이지나 스킬 Image, 스킬 Cooltime등을 표시하기 위해 하는 처리들은 Controller에서 담당(Controller가 UI도 알고 있고 현재 Play 중인 Player도 알고 있기 때문)

			3.1.3) Constructor의 스킬 매커니즘
				- Constructor는 E 혹은 R 발동 시 TowerMaker를 상속받은 Class를 Spawn하게 됨
				- TowerMaker는 체력을 가졌고 Constructor의 기본 평타(좌클릭)만 TowerMaker에 데미지를 줄 수 있으며
				- 체력이 0이하가 되면 TowerMaker는 Tower Class를 Spawn하고 소멸



			 Spawn한 Enemy들에 접근해야 할 때
				- Spawner에서 Spawn 후 Spawn한 Enemy들에 대해 배열에 저장
				- Spawner는 GameInstance에 등록(이렇게 하면 Spawn한 Enemy들에 대해 전역에서 접근 가능










=====================================================================================
			
	3. 클래스마다 특이사항 설명(변수, 함수 위주로)
		3.1) BP_Character
			3.1.1) 변수
				- E_CharacterState State
				- Map<E_CharacterState, MontageDataAsset> MontageDataMap (State에 따라 실행 할 Montage들)
				- float LifeNow
				- float LifeMax
				- bool bAttackEnabled
				- bool bAttackTransited
				- AttackIndex
			3.1.2) 함수
				- void AttachActorToMesh()
				- void EuqipWeapon()
				- void UnenquipWeapon()
				- void CollisionOffWithPawn() : Collision의 ObjectType이 pawn인 객체들과 collision 자체를 하지 않음(event를 끄는 게 아님)
				- void CollisionOnWithPawn() : 
				- void SetLifeNow()
				- void SetLifeMax()
				
			3.1.3) 인터페이스 구현
				- BeginPlay, CollisionOn/Off, AnyDamage(공용 데미지 처리, 하위 클래스들은 Damage 인터페이스의 WhoCanDamage로 DamageType 확인 후 Damage 처리), SetState

		3.2) BP_Player
			3.2.1) 변수
				- bool CurrentControl : Player가 3종류이기 때문에 현재 누가 조종 중인지를 위한 bool 변수
				- BP_Weapon*(class) WeaponClasses : Weapon spawn용 배열
				- BP_Weapon* Weapons : Weapon 실제 주소를 담은 배열
				- CurrentWepaon

			3.2.2) 인터페이스 구현
				- BeginPlay, ControlOn/Off, Run, Jumping, Tick, ZoomIn/Out, AnyDamage, En/DisableAttack, De/ActivateAttack, SetCurrentWeaponHiddenInGame, SwapWeapon, Skill, Action1

		3.3) BP_Enemy
			3.3.1) 변수
				- Float RunSpeed
				- Float WalkSpeed
				- Float SpawnPerTime : Spawn 주기
				- Integer DamageType(Bitmask)

			3.3.2) 함수
				- bool IsEnemy() (인터페이스 오버라이드, enemy를 상속받았는지 확인)
				- void SetLifeNow(float) : lifenow 변경 및 체력 표시용 gauge 변경
				- void SetLifeMax(float) : lifemax  변경 및 체력 표시용 gauge 변경
				- void SetLifeGaugePercent() : lifenow, lifemax 변경 시 실행 할 내부용 함수(private)

			3.3.3) 인터페이스 구현
				- SetWalkSpeed, SetRunSpeed,AnyDamage

		3.4) BP_Weapon
			3.4.1) 변수
				- Float Damage
				- Name SockOnEquipped
				- Name SockOnUnequipped
				- Name SocketOnTrailStarted
				- Name SocketOnTrailEnded
				- Map<E_CharacterState, MontageDataAsset> MontageDataMap
				- BP_Skill*(class) SkillClasses
				- BP_Skill* Skills
				- Integer DamageType : 누구에게 Damage를 줄지 정하는 Bitmask
				- Texture2D UIImage : PlayerUI용 Image

			3.4.2) 함수
				- 
*/