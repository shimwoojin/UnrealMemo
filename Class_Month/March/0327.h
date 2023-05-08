#pragma once
/*
	
	1. Roll, BackStep을 입력이 없이 Dodge면 BackStep, 입력이 있으면서 Dodge이면 그 방향으로 Roll하게 만듬

	2. UseControllerRotaionYaw 옵션을 풀어주어서 카메라 시점이랑 캐릭터 시점이랑 다르게 됐고 1번에서 PlayRotation을 돌려주기 때문에
	UseControllerRotataionYaw 옵션이 묶여있으면 아마 동작 안 함

	3. 무장상태일 때 애니메이션을 컨트롤러의 벡터와 input 벡터의 차이로 애니메이션을 다르게 작동했는데 2번에서 옵션을 건들고 나니깐
	애니메이션에 문제가 생김
	- 비무장일때는 이동방향으로 캐릭터가 회전하고 무장상태일 때는 그 옵션을 잠궈주는 식으로 세팅 할 예정

	4. UseControllerRotationYaw는 꺼주고
	OrientRotationToMovement는 비무장일때는 켜주고 무장일때는 꺼주고
	UseControllerDesiredRotation은 켜주고
	- 캐릭터가 회전 후 카메라의 묶인 시선으로 Add방식으로 돌아옴, UseControllerRotationYaw를 켜고 끄는 방식은 set방식이여서 탁 하고
	화면전환되는 느낌일 것임

	5. WeaponA이벤트 정의에서 SelectedWeapon을 비울 때 같은 노드를 2번 썼는데 이걸 앞에서 먼저 비우는 것은 불가능했음
	- 직전에 SelectedWeapon의 값에 대해 비교를 하고 있기 때문

	6. IsArmed에 대해 True이면 OrientRotationToMovement를 True로 False이면 False로 바꿔줌

	7. 무기를 등에 붙이고 손에 붙이기 위해 변수를 2개 더 만들었음
	- name 유형의 변수를 2개 만들어서 소켓의 name을 설정해 줌
	- 블프 읽기 전용 변수로 바꿔줌(name같은 문자열에 대해 이 정도로 관리하는게 최선인 듯)

	8. 무기를 장비하는 함수, 무기를 해제하는 함수를 각각 만듬
	- AttachActorToComponent에 단지 socket을 바꿔주는 동작이지만 함수로 따로 관리

	9. AttachActorToMesh를 만들고 Equip과 Unequip에 대해 앞에 만든 함수를 안에서 또 쓰는 식으로 만들어줌

	10. WeaponA 이벤트 끝 부분에서 Equip과 Unequip 추가
	- Unequip은 SelectedWeapon을 Unequip해주고 Equip은 끼려는 무기를 받아와서 껴줌, 이벤트 시작하자마자 인덱스 정하고 나온 배열에서 가져옴

	11. UseControllerRotationYaw가 마이너한 옵션이긴 하지만 FPS 같은 게임에서 마우스 반응에 민감하면 쓰기도 한다고 함

	12. 공격 모션을 추가하기 위해 한 작업들
	- Action 1,2,3,4 Sequence들 몽타주로 만들어주고(폴더 위치 잡아주고)
	- 슬롯 설정해주고(FullBody 슬롯)
	- 액션 매핑해주고(마우스 왼 클릭)
	- 인터페이스 함수 추가(ActionA)
	- 몽타주 데이터 추가(데이터 에셋, Acting과 관련된 몽타주 세팅)
	- Controller에서 이벤트와 메시지 이어주고
	- Character에서 ActionA 구현해주고

	13. ActionA를 구현하면서 ActionA가 동작하기 위해서 선행으로 처리할 작업들이 있다면
	- IsArmed가 True인지
	- State가 Idle인지(공격 가능 상태인지)
	- State를 Acting으로 바꾸기까지

	14. 공격이 성공하고 났는데 공격 모션에 공격이 성공하는게 아니라 overlap이벤트에 맞춰서 공격이 성공함
	- NotifyState를 통해 해결 가능
	- 이거 해결하는게 과제였음, BP_Weapon에서 bool변수 추가해서 해결

	15. Notify 관련해서 추가 설명이 있었는데 기존에 쓰던 Notify는 스켈레톤 노티파이로 해당 스켈레톤에만 적용되어서
	범용성이 떨어짐
	- Notify 블프 클래스를 만들 수 있음

	16. 기존 방식도 몽타주나 시퀀스 에디터에서 Notify이름 정할 수 있었고 이걸 PlayMontage쪽에서
	- NotifyName 핀 뽑아서 이름에 대한 스위치를 통해 Notify 이름 정해준거에 대해선 이렇게 처리하겠다 라는 식의 처리가 가능
	- 이름을 맞춰야 하는 것이 상당히 디메리트이기 때문에 이런 방식은 지양함, 그래서 notify 클래스를 만듬

	17. noitfy클래스 만들고 나서 처리해줘야 하는 건 오버라이드 할 함수들이고
	- 결국 이 클래스도 엔진의 클래스를 상속한 형태이기 때문에 상속한 변수 보기를 통해 어떤 변수를 들고 있는지 볼 수 있었음
	예를 들면 NotifyName 같은 변수

	18. 하지만 이 클래스도 결국 NotifyName을 직접 변수에서부터 설정하는 거라 애로함

*/