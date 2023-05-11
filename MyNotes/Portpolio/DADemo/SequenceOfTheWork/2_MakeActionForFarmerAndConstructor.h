#pragma once
//Farmer, Constructor의 세부 구현 팁

/*
	1. Constructor와 Farmer도 스킬을 2개씩 가짐
	- Constructor는 E,R키를 통해 SplashTowerMaker, SlowTowerMaker를 Spawn시키고
	- Farmer는 E키를 통해 반경 안에 있는 BP_Crops계열의 Actor들의 강화를 하고(이 Actor들은 일정시간 후 강화가 완료되며 강화 중엔 무적)
	R키를 통해 반경 안에 있는 BP_Crops계열의 Actor들에 Damage를 주어 광역 수확을 가능하게 함

	2. Constructor는 TowerMaker를 마우스 좌클릭으로 Damage를 주어 Tower로 업그레이드 가능하고
	Farmer는 BP_Crops에 마우스 좌클릭으로 Damage를 주어 파괴 시 Money를 Drop함
	
	3. Farmer와 Constructor는 비 조종 시 AI에 의해 조종되는데
	- Constructor는 주변에서 가장 가까운 TowerPoint로 이동 후 E 혹은 R 스킬을 랜덤으로 발동하여 TowerMaker를 파괴 후 Tower를 Spawn 시킨 후
	다음 TowerPoint로 이동하며 Tower들을 만들어가고
	- Farmer는 주변에서 가장 가까운 Crop을 찾아 이동 후 스킬의 사용은 없이 마우스 좌클릭을 통한 기본 공격으로만 파괴 후 Money를 얻게 됨
*/