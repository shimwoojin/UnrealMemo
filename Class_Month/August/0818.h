#pragma once
/*
	1. 단발, 연발을 바꾸는 좋은 솔루션
	
	enum EFireMode
	{
		Single,
		Auto
	};

	TArray<EFireMode> FireModes = { EFireMode::Single };
	EFireMode FireMode = FireModes[0];

	//단발, 연발 교체 시
	FireMode = FireModes[(FimeModes.Fina(FireMode) + 1) % FireModes.Num()];

	- enum의 순서를 맞추거나 FireModes 배열에 들어갈 원소의 순서에 영향을 받을 수 있는 점은 유의해야 함

	2. 연발의 구현은 Timer 이용
	- 다른 구현은 없나 고민,,

	3. AudioComponent의 기본은 3D 사운드여서 Camera의 위치를 기준으로 소리가 다르게 들림
*/