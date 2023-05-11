#pragma once
//Attacker, 목수, 농부의 화면 전환에 관한 팁

/*
	1. Possess는 PlayerController에서 키 입력을 통해 처리함
	- Player가 BeginPlay에서 목수, 농부를 spawn후 소유하고 있으며 Default 캐릭터인 Attacker도 목수, 농부와 함계 배열에 담아 관리함
	- 키 입력에 따라 LocalVariable(static)의 인덱스를 바꿔주어 배열에 접근

	2. 키 입력을 잘 받고 배열 인덱스에도 잘 접근했다면 possess하기 전후로 처리해야 할 작업들이 있는데
	- 현재 조종 중 인지에 대한 bool변수를 바꿀 캐릭터와 바꾸기 전 캐릭터에 대해 바꿔주어야 하고(인터페이스로 처리)
	- Player 캐릭터마다 소유중인 AIController가 있는데 이 AIController의 빙의를 끄거나 키는 등의 동작을 함
	내부적으로 AIController에서 처리해야 할 내용까지 대신 처리해줌

	3. Player가 valid인지에 대한 체크를 하기 때문에 사망한 상태에서 캐릭터 교체에 대한 키 입력이 들어와도 에러없이 동작함
*/