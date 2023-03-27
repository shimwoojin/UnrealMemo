#pragma once
/*
1. 언리얼의 이동은 연속적일 수 없음
 - 게임이라는 것은 결국 프레임단위로 쪼개어 밀리초당 업데이트, 렌더를 하는 것임
 - 상자가 직접 와서 부딪혔을 때 Sweep 옵션이 꺼져있었다면 Hit Event가 발생하지 않았음
 - AddActorOffset의 Sweep 옵션을 켜주게 되면 Hit판정이 나게 되고 상자가 움직여서 캐릭터에 부딪혔을 땐 Hit Event의 Self Moved의 반환값이 True가 됨
 - Sweep이란 빗질을 하는, 이라는 뜻이 있음

2. 캐릭터에 새로운 동작을 주기 위해서 에셋을 새로 추가했는데 이 때 추가하고 나서 BlendSpace1D를 편집하던 과정에서 Animation Sequence들이
편집 목록에 나타나지 않았음
 - Animation Sequence들이 어떤 스켈레톤을 대상으로 하는지에 대한 규칙이 안 정해져 있었기 때문
 - 스켈레톤을 다시 정해주기 위해서 Sequence폴더를 기준으로 필터를 켜주었는데 필터 - Animation - Animation Sequence의 모든 항목을 보고
 - 콘텐츠 브라우저에 나타난 모든 sequence들에 대해 스켈레톤을 재설정해줌 ( 모두 선택 : ctrl + a )

3. 새로운 에셋을 이주하면서 기존에 있던 애니메이션 관련 폴더들을 지웠기 때문에 BP_Player의 MeshComponent에서 Animation Mode에 설정이 깨져있었음
 - 정확히 Animation Mode가 Use Animation Asset이 되어 있었고 이걸 다시 Use Animation Blueprint로 바꾸고 우리가 만든 ABP_Character를 연결해주어야 함

4. 2번에서 필터로 sequence들을 찾았는데 걸었던 필터들을 풀어주려면 필터 누르고 최상단에 필터 리셋 버튼 있었음

5. Roll과 Back Sequence에 대해 montage를 만들어 주었는데 에셋 우클릭 - 생성 - 애님 몽타주 생성 클릭하여 생성 가능
 - montage에 대해서는 montage 폴더 만들어서 따로 관리

6. 몽타주의 노티파이라는 기능이 있는데 몽타주가 진행 중 어느 시점에 대해 알림을 보낼 수 있고 그 알림에 대해 처리를 할 수 있는 기능
 - sequence에도 있는 기능이지만 강화 버전 정도로 생각하면 됨

7. 몽타주는 1회성 동작에 대해 생성한다고 생각하면 됨

8. BP_Character에서 키 입력에 대해 어떤 몽타주를 재생 시켜줄지 함수가 있는데 그쪽에서 어떤 몽타주를 재생시켜줄지에 대한 로직을 짜주고
ABP_Character에서는 그룹 - 슬롯에 맞는 몽타주는 흐름에 맞게 연결시켜주어야 함. 그냥 선형으로 연결해주면 되는거같음
 - 어떤 슬롯인지 찾아서 지정할 때 일단 default sloat을 검색해서 찾아보고 노드에 좌클릭 후 디테일 탭에서 슬롯 변경 가능

9. 몽타주에서 Root의 트랜스폼(위치)에 영향을 주는 옵션이 있는데 몽타주에서 찾을게 아니라 몽타주를 만든 sequence에서 옵션을 찾을 수 있었음
 - Enable Root Motion옵션을 끄게 되면 애니메이션이 Player의 위치를 바꾸지 못하게 됨
 - Capsule Component의 판정 범위를 키고 봤을 떄 enable root motion이 꺼져있었으면 capusle component는 그 자리 그대로 있었음
 - Enable root motion 옵션을 켜게 되면 애니메이션이 재생되는 동안 애니메이션의 데이터가 root에 보내진다 라고 설명하셨음
 - roll sequence에서 캐릭터 - 루트 모션 표시를 켜게 되면 어떻게 진행될지가 보임, 제자리 이동이 아니라

10. 캐릭터 화면 전환 옵션 관련해서는 팁 쪽에 정리해두겠음
 - 입력에 따른 roll, backstep의 방향 정하기가 있었는데 이때 controller가 플레이어의 yaw회전에 영향을 옵션을 켜줬음
(마우스 좌우에 캐릭터 rotation이 영향을 받는 옵션)
*/