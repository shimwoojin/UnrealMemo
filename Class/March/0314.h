#pragma once
/*
1. 입력 방향에 따라 구르거나 백스텝을 밟는 과제를 해결하기 위해
 1-1) GetActorForwardVector
 1-2) CharacterMovement - GetLastInputVector
 1-3) 이 두 벡터에 대한 내적, 외적을 하는것이 필요했음

2. 애니메이션이 root의 트랜스폼을 결정하는 옵션이 켜져있었기 때문에 에니메이션 자체가 앞뒤로 구르는 모션밖에 없었기 떄문에
애니메이션을 재생하기 전에 액터의 rotation을 돌려주어야 했음
 - 얼마나 rotation을 돌려줄지 정하는 과정에서 MakeRotFromX라는 함수를 사용하여 input 벡터에 대해 rotation을 바로 뽑아낼 수 있었는데
이걸 몰라서 정면, 좌우 판별을 하여 내적, 외적 등 돌아가게 됨

3. GetInputLastVector는 A+W, D+S등 축이 다른 키입력이 2개이면 정규화된 값이 아니였음

4. Dodge를 Space에 액션매핑 해주었고 controller가 조종하고 있는 폰이 dodge를 구현했으면 space바를 눌렀을 때 폰이 구현한 dodge에 따라서
다르게 작동할 수 있게끔 하는게 블프 인터페이스였고 블프 인터페이스를 새로 만들어서 BP_Character에서 인터페이스를 구현해서 1,2에서 했던 노드에
shift 키입력 대신 dodge 이벤트를 이어줌. controller쪽에서는 dodge 액션 매핑에 대해 GetControlledPawn의 Dodge 이벤트가 호출되게 바꿔줌
 - 이렇게 하고나면 BP_Character가 아닌 다른 조종할 pawn에서 인퍼페이스를 상속받고 dodge에 대해서 구현하기만 하면 거기서 구현한 dodge에 대해
space입력 시 다른 동작을 하게 해줌
*/