#pragma once
/*
	1. Wizard_Attack이 메시스페이스에서 로테이트 블렌딩하는 옵션을 켜지않았을 때 문제가 생긴 이유는
	- 애니메이션 자체가 루트 본이 회전하는 형태이기 때문
	- 루트본이 회전하는 이유가 있는데 Wizard_Attack의 애니메이션 출처가 mixamo라는 사이트에서 가져온 건데
	- 루트본이 없는 상태인데 언리얼로 임포트하는 과정에서 루트본이 pelvis의 회전을 따라가기 때문임
	- 앵간하면 본마다 레이어로 블렌딩 노드에서는 메시스페이스에서 회전 블렌딩 옵션을 켜는 게 좋다고 함

	2. fireball을 구현하기 위해 GetDestinationData 함수를 하나 만드는데
	- 카메라의 위치에서 카메라가 바라보는 방향으로 10000만큼의 거리를 라인 트레이스 하는건데
	- 이때 카메라를 가져오는 방법이 신기했음
	- playercontroller에서 cameramanager를 가지고 와서 location과 rotation을 가져옴
	- player가 카메라를 들고 있기 때문에 player에 형변환을 해서 camera를 직접 가져오는 방법도 있지만 유연하지 않음
	
	3. camera의 위치와 camera의 정면벡터로부터 10000 떨어진 지점을 목표지점으로 잡고 LineTrace를 하는데
	- 어떤 종류의 대상을 감지할지를 정하고(TypeObject, Pawn(우리는 몬스터한테 데미지 줄거니까)), TypeObject는 콜리전 관련 옵션에 있는 것
	- 어떤 종류의 대상을 무시할지를 정하고(Instigator)
	- 디버그 할 때 어떤 경로로 LineTrace찍었는지도 보여줌, hit한 대상에 대해선 네모박스로 보여줌(duration으로 시간지나면 사라지게 가능, persistant도 있음)
	Duration은 밑에 옵션 DrawTime에 영향 받음

	4. 우리가 던질 파이어 볼은 발동 시 무조건 나가야 하기 때문에
	- LineTrace결과가 성공이라면 Hit한 결과를 return하고
	- 실패라면 TraceEnd 지점을 겨냥해서 쏨

	5. 파이어볼 같은 투사체를 위한 component가 있음 -> projectile movement
	- 투사체가 파이어볼인지 화살인지에 따라 어떤 속성을 부모에서 물려주어야 할지 모호한데
	- 콜리전도 어떤 모양을 가져야 할지가 모호함
	- 투사체 최상위 부모에선 projectile movement 만을 가지고 있고
	- damage 변수를 하나 만들긴 했지만
	- 오버워치의 아나의 투사체는 힐을 주기에 damage가 최상위 부모에 오기엔 부적합함
	- fm으로 처리를 하려면 damage를 주는 투사체와 다른 역할을 하는 투사체로 한 번 더 분기를 나눴어야 함
	- Check라는 함수를 만들고 instigator도 아니고 owner도 아닌지 판별하는 퓨어함수를 하나 만듬
	- beginoverlap에서 applydamage처리를 하는 이벤트를 추가함(BP_Projectile, 최상위)

	6. BP_ProjectileFireball로 자손을 만들고 
	- particle과 collision(sphere)을 추가하고 particle 세팅해주고 정면 설정해 줌
	- 지금 상태로는 놓으면 중력에 영향을 받음
	- projectile movement에서 옵션 설정을 좀 해주어야 하는데 projectile - projectile gravity scale을 0으로 (1이 기본 중력)
	- projectile - Rotation follows Veclocity도 켜주고 (날아가는 방향으로 전방을 바꿈)
	- 위에를 키게 되면 Rotation remains Vectical을 켜고 끌 수 있는데 yaw에 대해서만 회전할 수 있게 바꾸는 것(좌우), 우리는 꺼줌
	- bounce에 대한 옵션도 있고 (마찰 등)
	- Homing도 있음(유도탄)

	- projectile 옵션 중에 initial velocity in localscale이 있는데 이걸 켜야 로컬 축 방향으로 속도 영향 받음
	- 밑에 velocity 옵션에서 설정하는 것
	- 만약 끄게 된다면 world의 x축 방향으로 날아감

	7. 액터마다 start with tick enabled 옵션은 다 꺼주는 것이 좋음
	- tick을 얼마마다 할지도 지정할 수 있음
	- fireball이 데미지를 입을리 없으니 canbedamaged같은 옵션도 여력이 된다면 꺼주는 게 좋음

	8. fireball의 beginoverlap 로직은
	- 일단 부모에서 만든 check함수가 true일때 (자기는 안 맞추고)
	- 맞은 위치에서 emitter를 스폰해주고(spawn emitter at location) apply radial damage함수로 광역딜 넣어주고 본체에 대한 딜도 넣어줌

	9. 카메라 위치를 시작위치로 정할 수 있음(fireball 테스트 중)

	10. BP_Fireball의 EndAction에서 fireball을 스폰해주면 됨(스폰 위치, 방향, 속력 처리 해줘야 함)
	- EndAction은 애니메이션 중에 던지려는 자세에 노티파이를 만들어 놨음
*/