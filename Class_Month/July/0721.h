#pragma once
/*
	1. FMath::IsNearlyEqaul()
	- 오차 허용 범위 지정 가능

	2. 헷갈렸던 for문

	 for(int32 i = 0; i < 5 && Data == nullptr; i++
	 {
		Data = FindData(i);
	 }

	- (i < 5)이고 (Data == nullptr)이 둘 다 true여야 for문이 진행 됨

	3. 파쿠르 순서
	- 장애물 확인 -> 머리 쪽에 장애물 있고 파쿠르 가능하면 climb -> 아니라면 아래 쪽에 장애물 없고 파쿠르 가능하면 slide -> 아니라면 일반 파쿠르
*/