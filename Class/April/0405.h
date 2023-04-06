#pragma once
/*
	1. 스킬의 장착과 동작 전환까지 처리가 되었음
	- 스킬을 든 상태에서 action을 하면 칼 휘두르는 모션이 나감(weapon을 들다가 스킬을 꺼낸 경우)

	2. BP_Teleport를 구현하기 위해 Teleport의 tick에서는 매 프레임 커서가 가 있는 방향의 위치 정보와 그 위치의 법선벡터를 받아와서
	처리하게 되는데
	- 커서의 위치와 법선벡터를 구하는 함수 GetDestinationData를 만들었고
	이 함수는 GetHitResultUnderCursorForObjects에서 필요한 정보만 뽑아 낸 함수
	- 원래 이 처리를 하기에 적합한 함수는 아니나 소개할 기회가 없을 것 같아서 소개했다고 함(롤, 스타의 이동 같은 거 처리가 더 적합한 함수)
	- 적합한 함수는 LineTracing
	- cursor가 worldstatic에 대해서만 hit할 수 있도록 함수 배열에 넣어줌

	3. Tick마다 GetDestinationData를 활용해 cursor위치에 hit된게 있으면 그 위치에 Decal을 찍어주도록 만듬(visibilityOn, setlocation(decal))
	- 법선벡터를 활용해 decal의 rotation을 바꿈(decal의 전방을 hit된 곳의 법선벡터로 만들어줌, MakeRotFromX)

	4. 스킬을 들게 되면 무기를 든것과 동일하게 OrientRotationToMovement 옵션 건들여줌

	5. getter를 아끼지 마라
	- 가독성이 더 나음

	6. 마우스 좌클릭으로 무기를 통한 공격이나 스킬 공격을 둘 다 처리하는데
	- 스킬 공격을 우선 처리하도록
	- 무기를 든 상태에서 스킬을 활성화하면 IsArmed이기도 하고 스킬도 있지만 스킬을 우선 발동하도록 처리함
	- ActionA쪽에서 스킬쪽과 무기쪽으로 분기가 나뉨

	7. BP_Skill쪽에 BeginAction, EndAction이라는 커스텀 이벤트 만들고
	- Action쪽에서 스킬 발동하면 불러주는 식으로

	8. 스킬 발동은 스킬 시전하는 모션이 나오기 전에 BeginAction이 콜 되고 스킬에 만들어놓은 노티파이에 대해 EndAction을 부르는 식으로 만듬

	9. BP_Skill쪽에서 GetMontageData 기본 형태만 만들고 BP_Teleport에서 Teleport하는 몽타주를 연결해주기만 하면 되는데
	- Wizard_Spell_Montage를 실행하게 만들어주고
	- 시퀀스에서 몽타주를 만들 떄 만들고나서 슬롯설정을 필수 spell은 fullbody

	10. Teleport의 BeginAction에서 처리하는 내용은 Destination이 유효한지에 대해 bool에 저장하고 실제 이동위치를 그 위치의 수직 150 위로 Destination변수에 설정

	11. EndAction에서는 Emitter를 발생시키고 실제 캐릭터의 SetActorLocation으로 설정해 줌

	12. 이미터는 도착지랑 출발지에 둘다 설치하기로 함
	
	13. 이미터 눈뽕이 오져서 이미터를 살짝 바꿔줬는데
	- 스케일을 .5로 줄이고 이미터 자체의 눈뽕 효과를 꺼줌
	- 아쉽게도 파티클(이미터)은 머티리얼 인스턴스처럼 상속해서 개별로 뻗어나가는 식의 처리는 불가능
	- 복사해서 이름 바꿔서 사용해야 하는 듯
*/