#pragma once
/*
	1. ���� ��ҵ� : 
		- �÷��̾� (Attacker, Constructor, Farmer) <3����> 
		- Enemy (Animal, Undead, InfinityBlades) 3���� * �� 5���� �� = <15����> 
		- EnemyBoss <1����>
		- Weapon (Attacker 2��, Constructor 1��, Farmer 1��)  <4����>
		- Skill (Attack ���� 4��, Constructor ���� 2��, Farmer ���� 2�� -> ��� ���� ���� �� 2������) <8����>
		- TowerMaker (Splash, Slow) <2����> 
		- Tower (Splash, Slow) <2����>
		- Crops <1����>
		- CropsSpawner <1����>
		- Spawner (���͸��� ������ �ִµ� �̰Ŵ� �ϴ� ���Ŀ� ó��)
		- DeffensePoint <1����>
		- UI��(Aim�� UI, ������ UI, Player�� UI, Damage�� UI)

	2. �������̽� ����
		2.1) Character ��ӿ� �������̽�
			2.1.1) BPI_CharacterAction
				- void SwapWeapon(bool) : ���⸦ ����
				- void Action1() : Player�� ��� ���콺 ��Ŭ�� ����, Enemy�� ��� Attack
				- void Action2()
				- void Run() : Player�� ��� Timeline�� ���� �ε巯�� MaxWalkSpeed ��ȯ
				- Jumping() : Player�� AnimInstance���� ����� ����
				- EndJumping() : ��
			2.1.2) BPI_CharacterState
				- bool IsState(CharacterState) : state�� input state�� ������ true, false
				- CharacterState GetState() : ���� state ��ȯ
				- bool IsArmed() : Depracated
				- void CollisionOff() : Player�� Enemy�� �浹 off(SetCollisionResponseToChannel ����Ͽ� pawn�� ���� ignore), Enemy�� ��� Player���� �浹�� ���
				- void CollisionOn() : Player�� Enemy�� �浹 on(SetCollisionResponseToChannel ����Ͽ� pawn�� ���� block)
				- void SetState(CharacterState)
				- float GetLifePercent() : LifeNow / LifeMax�� return, Player���� UI�� ����� ����
				- IsEnemy() : Enemy��� true
			2.1.3) BPI_CharacterFunc (Action Ȥ�� State�� ������ ����� ��� Character ���� �������̽��� ���� ���⿡ ����)
				- void ActivateAttack() : player�� ��� CurrentWeapon�� ���ݿ� �Լ� ȣ���� ����
				- void DeactivateAttack() : ActivateAttack()�� ���� �˸��� ����
				- void EnableAttack() : �޺� ���ݿ� bool ���� ����
				- void DisableAttack() : ��
				- Vector GetRightHandSocketLocation() : Skeletal Mesh�� ������ ��ġ ��ȯ (Player�� ��� ��ų ��ġ ��� ����)
				- Vector GetLeftHandSocketLocation() : Skeletal Mesh�� �޼� ��ġ ��ȯ (Player�� ��� ��ų ��ġ ��� ����)
				- void SetCurrentWeaponHiddenInGame(bool) : current weapon�� ���� �� ǥ�ø� ����
				- float GetBodyHalfHeight() : Capsule Component�� ���� ����
				- void ZoomIn()
				- void ZoomOut()
		
		2.2) Character Animation ��ӿ� �������̽�
			2.2.1) BPI_CharacterAnimation(Character�� ��ӹ��� Ŭ�������� Animation BluePrint�� ����� ����, Enemy�� �ʿ��ϴٸ� ���)
				- bool SetIsJumping() : bool ���� setter

		2.3) Controller ��ӿ� �������̽�
			2.3.1) BPI_Controller(PlayerController�� �� �������̽��� ���)
				- BP_Player* GetPlayers() : Player Controller�� Player 3������ �˰� ����(�迭�� ��ȯ)
				- bool NotPlayer(Actor) : input actor�� player���� �ƴ��� true or false
				- void UpdatePlayerSkillUI() : ĳ���� ��ȯ �� SkillUI�� ���� ��� Update(Skill���� ���� UI�� ����)
				- void UpdatePlayerLifeGaugeUI() : LifeGauge�� ���� ��� ó��(�ǰ� Ȥ�� ���ο� player�� possess�ϴ� ��쿡 Update)
				- void UpdatePlayerAllUI() : SkillUI, LifeGaugeUI �� Player ���� UI�� �� �Լ��� ��� Update

		2.4) Player ��ӿ� �������̽�
			2.4.1) BPI_PlayerCommon(Player�� ������ �� Ư���� �ִٸ� �� �������̽����� ����, ������Ʈ�� ũ�� �����Ƿ� Player ���տ� �������̽� �ϳ��� ó��)
				- bool AmIControlledPawn() : Player�� CurrentControl bool ������ ��ȯ(�����ϴ� player�� actor�� 3�� �̹Ƿ� ���� ���� ���¸� �˱� ����)
				- void ControllingOn() : player ��ȯ �� CurrentControl bool ������ �����ϱ� ����
				- void ControllingOff() : player ��ȯ �� CurrentControl bool ������ �����ϱ� ����
				- Texture2D GetSkillEImage() : Player�� ������ CurrentWeapon���� Skills[0]�� PlayerUI ���� Texture2D�� ����(Controller���� UIó���� ����)
				- Texture2D GetSkillRImage() : Player�� ������ CurrentWeapon���� Skills[1]�� PlayerUI ���� Texture2D�� ����(Controller���� UIó���� ����)
				- Texture2D GetWeaponImage() : Player�� ������ CurrentWeapon�� PlayerUI ���� Texture2D�� ����(Controller���� UIó���� ����)
				- float GetSkillECoolTimePercent() : PlayerUI ���� ��ųUI�� ESkill CoolTime ǥ�ø� ����(���� ���� ���� Player�� Player ���� UI�� �˰��ִ� BP_PlayerController���� PlayerUI ������Ʈ�� ����)
				- float GetSkillRCoolTimePercent() : PlayerUI ���� ��ųUI�� RSkill CoolTime ǥ�ø� ����(���� ���� ���� Player�� Player ���� UI�� �˰��ִ� BP_PlayerController���� PlayerUI ������Ʈ�� ����)
				
		2.5) Enemy ��ӿ� �������̽�
			2.5.1) BPI_EnemyCommon
				- void SetWalkSpeed() : Enemy�� �� ��ü���� ������ Walk�� Run�� �ӵ��� ������ �ֱ� ������ ��Ȳ�� ���� �� ���� MovementCompoenent�� MaxWalkSpeed�� �������ֱ� ����
				- void SetRunSpeed()
				- float GetWalkSpeed()
				- float GetRunSpeed()

				- EnemyController���� call�� ������ ���� ���̰� Player���� ����� ���ؼ��� �߰��� ������ ���� ����

		2.6) Damage�� �� �� �ִ� ��ü���� ��ӿ� �������̽�(Skill, Weapon, Enemy)
			2.6.1) BPI_Damage
				- Integer WhatDamageType() : DamageType Integer ��ȯ(�� �������̽��� ��ӹ��� Ŭ�������� DamageType�̶�� Bitmask Integer�� ����, �������� �������� �� �� �ִ����� ���� ����)
				- bool WhoCanDamage(DamageType) : AnyDamage�� ó���ϴ� actor�鿡�� call�� �������̽�, ������ damage�� �� �� �ִ� DamageType�� ��츸 damage�� �Դ� ������� ó��
				- Actor GetTargetActor() : Target�� ���ϰ� damage�� �ִ� �ൿ�� �ִٸ� target ��ȯ(ex. Homing)

		2.7) Widget ��ӿ� �������̽�
			2.7.1) BPI_Widgets(Interface�� �ʿ��� ��� widget�� �� �������̽��� ��� ����)
				- void SetGaugePercent(float) : ProgressBar�� Percent�� Setter
				- void SetGaugeColor(Linear Color) : ProgressBar�� Color Setter
				- void SetSkillQImage(Texture 2D) : ���� UI Image Setter, �÷��̾� ��ȯ Ȥ�� ���� ���� �� call
				- void SetSkillEImage(Texture 2D) : ���� UI Image Setter, �÷��̾� ��ȯ Ȥ�� ���� ���� �� call
				- void SetSkillRImage(Texture 2D) : ���� UI Image Setter, �÷��̾� ��ȯ Ȥ�� ���� ���� �� call
				- void SetSkillEPercent(float) : PlayerUI�� E��ų cooltime ����
				- void SetSkillRPercent(float) : PlayerUI�� R��ų cooltime ����
				- void SetHPNow(float) : ����UI�� DeffensePoint�� ���� ü�� ǥ�ÿ� Text Setter��
				- void SetHPMax(float) : ����UI�� DeffensePoint�� �ִ� ü�� ǥ�ÿ� Text Setter��
				- void SetHPpercent(float) : ����UI�� DeffensePoint�� ü�¹� Setter��
				- void SetMoney(Integer64) : ���� UI�� Money ǥ�ÿ�

		2.8) ��ȣ�ۿ��� ������ actor�� ��ӿ� �������̽�(�ʿ��ϴٸ� �߰�)

	3. ���
		3.1) Player�� ���
			3.1.1) Player�� Skill, Weapon�� ����
				- Player�� BeginPlay���� Weapon���� spawn �� ������ ����(Attacker�� 2����, Constructor�� 1����, Farmer�� 1����)
				- Weapon�� Owner�� Player, Instigator�� Player
				
				- Weapon�� BeginPlayer���� Skill���� spawn �� ������ ����(���⸶�� ��ų 2����(E,R))
				- Skill�� Owner�� Player, Instigator�� Player

				- Skill�� spawn�ϴ� ����ü Ȥ�� actor�� �ִµ�
				- spawn�� ��ü�� Owner�� Skill, Instigator�� Player

			3.1.2) Player�� PlayerController, UI�� ����
				- Constructor�� Farmer�� Controller���� Spawn
				- Attacker, Consructor, Farmer�� Player 3������ Controller�� �迭�� �����Ͽ� �˰� ����
				- Player���� UI�� PlayerController�� �˰� ����
				- ȭ�鿡 ü�� �������� ��ų Image, ��ų Cooltime���� ǥ���ϱ� ���� �ϴ� ó������ Controller���� ���(Controller�� UI�� �˰� �ְ� ���� Play ���� Player�� �˰� �ֱ� ����)

			3.1.3) Constructor�� ��ų ��Ŀ����
				- Constructor�� E Ȥ�� R �ߵ� �� TowerMaker�� ��ӹ��� Class�� Spawn�ϰ� ��
				- TowerMaker�� ü���� ������ Constructor�� �⺻ ��Ÿ(��Ŭ��)�� TowerMaker�� �������� �� �� ������
				- ü���� 0���ϰ� �Ǹ� TowerMaker�� Tower Class�� Spawn�ϰ� �Ҹ�
				- Spawn�� Tower�� Owner, Instigator�� PlayerConstructor

			3.1.4) Enemy�� Player�� �����ϴ� ���
				- AIPerception Component�� Update�� ���� ���� Actor�� ���� ���� ���� ���� Player���� ���� �������̽��� ���ؼ� target�� ����

		3.2) �������� ���
			- BP_GameInstance�� ����Ͽ� ���

			3.2.1) DeffensePoint ���
				- ���� UI, Money, ��������� ü���� �����ϴ� DeffensePoint�� �������� ������ �� �ְ� ����

			3.2.2) SpawnerManager ���
				- Spawn�� Enemy�鿡 �����ϱ� ����(SpawnerManager�� Spawner���� ���� �ְ� Spawner�� ���� �ڽ��� Ÿ�Կ� �´� ���͸� ���� ����)
				- Spawner�� ���� ���������μ� World �� ���� ���Ϳ� ó���� ���뿡 ���� ���⼭ ó�� ����

			3.2.3) ���� ��ȯ �� �ʿ��� ���� ���
				- ���� UI�� ���� ����, ��ų ��ȭ �� �� ���鿡 ���� BP_GameInstance�� ���� �� ���ο� level open �� �� Ŭ�������� �� ���� ��ȿ�ϴٸ� �ٽ� set�� �ϴ� ������� ó��
				- Weapon Ŭ����, Skill Ŭ����, Skill�� Spawn�� Projectile Ȥ�� Actor���� ���� �ڽſ� �ʿ��� ���� ���忡�� ���ŵ� ���� ���� BeginPlay�� BP_GameInstance�� �����Ͽ� ���� ������ ���

			
	4. ���� Ŭ�������� ���� ����(���� Ŭ�������� �������� ���� ���뿡 ���� ����)
		4.1) BP_Character
			4.1.1) �Լ� �� ����
				- Life����
				- State
				- State�� ���� Montage Asset
				
			4.1.2) �������̽� ����
				- BeginPlay, CollisionOn/Off, AnyDamage(���� ������ ó��, ���� Ŭ�������� Damage �������̽��� WhoCanDamage�� DamageType Ȯ�� �� Damage ó��), SetState

		4.2) BP_Player
			4.2.1) �Լ� �� ����
				- ���� �������� �÷��̾�����
				- Spawn�� Weapon�� Spawn�� Weapon ����

			4.2.2) �������̽� ����
				- BeginPlay, ControlOn/Off, Run, Jumping, Tick, ZoomIn/Out, AnyDamage, En/DisableAttack, De/ActivateAttack, SetCurrentWeaponHiddenInGame, SwapWeapon, Skill, Action1

		4.3) BP_Enemy
			4.3.1) �Լ� �� ����
				- Target�� ���� �� ���� ���� Speed
				- � �ֱ�� Spawn�� ����
				- �������� Damage�� �� �� �ִ���

			4.3.3) �������̽� ����
				- SetWalkSpeed, SetRunSpeed,AnyDamage

		4.4) BP_Weapon
			4.4.1) ���� �� �Լ�
				- ���� ��ü�� Damage
				- ���Ⱑ ������ skill��
				- ȭ�鿡 ��� ���� UI Image
				- �������� �������� �� �� �ִ���(Attacker ������ Enemy���Ը�, Constructor ������ TowerMaker����, Farmer ������ Crops����)
				- ���Ⱑ �������� �� �� �ִ� Ÿ�̹��� �����ϴ� ����
				- ������ effect�� ������ Ÿ�̹��� �����ϴ� ����

			4.4.2) �������̽� ����
				- BeginPlay, BeginOverlap

		4.5) BP_Skill
			4.5.1) ���� �� �Լ�
				- cooltime ����
				- UI�� �̹���
				- �������� �������� �� �� �ִ���

		4.6) BP_TowerMaker
			4.6.1) ���� �� �Լ�
				- Life����(Constructor�� ������ �μ��� ����, �μ����� ���� Tower ����)
				- �μ����� ���� Spawn�� Ÿ���� Ŭ���� ���۷���

			4.6.2) �������̽� ����
				- BeginPlay, AnyDamage, Destroyed

	5. Crops ���� ���(������ ������̿��� ����, �߰�����)
		- CropsSpawner�� World�� n�� ��ġ
		- CropsSpawner�� Spawn�� Crops�� ���Ǹ�(�ı�) ���� �������� �ð��� ��� Respawn�� ��Ű�� ����
		- Crops�� ü���� ����(Constructor�� TowerMaker�� �ϴ� ��İ� ����)
		- Crops�� Farmer�� E,R ��ų�� ��ȭ�Ǿ� ��ȭ �� Mesh�� ��ȭ�ϰ� ��� ���� Gold���� ��ȭ��(��ȭ�� �ܰ�� 4�ܰ� ���� ���� ��)
		- Crops�� ��ȭ�Ǵ� �߿� �����̸� ���� �Ⱓ�� Gauge�� ǥ��

*/