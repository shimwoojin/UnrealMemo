#pragma once
//적의 상태와 애니메이션 처리에 관한 팁

/*
	1. Enemy는 크게 보아 Animal, Undead, InfinityBlades, Boss 정도로 4종류에 대해 구현할 예정이고
	전체 구현할 개체는 15~20 종류 정도로 예상 됨

	2. 각 Enemy마다 Skeleton이 다르기 때문에 Animation BluePrint를 개별 정의해주었는데(이 과정에서 공통으로 처리한 내용이 많은데
	오버라이드 하는 식으로 처리하는 방식이 있다면 수정해야 함)
	기본 BlendSpace1D를 정의하여 Speed에 따라 Idle, Walk, Run에 대해서만 기본 Animation 설정해주었고
	공격이나 스킬에 대한 Montage만 설정해 줌
*/