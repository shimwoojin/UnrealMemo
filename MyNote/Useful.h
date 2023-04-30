#pragma once
/*
1. 블프 클래스 그래프에서 북마크 사용 -> 그래프 좌측 상단 별 클릭 후 저장하고자 하는 위치 북마크 만들어줄 수 있음

2. 퀵 북마크 -> ctrl + 0 ~ 9로 보고 있던 노드의 줌, 위치 등 저장 후 shift + 0 ~ 9로 이동 가능

3. 블프 그래프에서 ctrl + f : 찾기, 블루프린트에서 찾기랑은 조금 다름

4. 커스텀 이벤트 만들어서 매개변수도 줄 수 있고 이벤트에서 이벤트를 호출할 수도 있음

5. hit은 한쪽, overlap은 양쪽(이벤트)

6. 블프에서 배열 사용 시 find와 contain은 차이가 있음
 - find는 인덱스 반환, contain은 불린 값

7. 카메라가 보는 방향으로 캐릭터의 Rotation을 설정하는 옵션은 SpringArm에서 찾을 수 있음
 - Use Pawn Controll Rotation 옵션 True로 주면 됨

8. 캐릭터 카메라 및 방향 전환 이동 관련 옵션 설정
 - BP_Character - 클래스 디폴트 - Use Controller Rotation Yaw : 이 옵션을 키게 되면 Controller가 바라보는 방향을 플레이어도 같이 바라보게 됨
 컨트롤러의 Rotation을 플레이어가 똑같이 같게 되는 것
 - BP_Character - Character Movement - Rotation Settings - Orient Rotation to Movement : 가속하고 있는 방향으로 캐릭터를 회전시켜주는 옵션,
Use Controller Rotation Yaw 옵션이 비어져 있어야 적용되는 듯
 - BP_Player - SpringArm - Camera Settings - Use Pawn Controll Rotation : 이 옵션을 키게 되면 SpringArm이 Controller의 rotation값을 따라가게 됨

  9. 이벤트 그래프는 하나 이상 더 만들어서 사용 가능함

 10. Level이 바뀌면 모든 BeginPlay가 호출됨

 11. actor 자체는 기본적으로 리플리케이트 되어 있음
 - Character는 기본적으로 무브먼트 컴포넌트를 통해 tick velocity를 리플리케이션 함
 - Pawn도 같은 구현을 해준다면 가능(아마 안되어있다는 뜻으로 한 말 인듯)

 12. 클래스 디폴트 가져오기로 구조체 같은거 기본값 수정 가능
 
 13. 에임 오프셋으로 총구 방향을 바꿔놨는데 fire 몽타주는 정면을 향해서만 발사하는 문제
 - bone 단위로 블렌딩
 - 혹은 슬롯

 14. 리타기팅 할 때 T-POSE를 만들어주어야 하는데 MIXAMO에서 가져온 스켈레톤에 처음에 T-POSE가 지정이 안 돼있었는데
 스켈레톤 에디터에 가서 우측 패널에 프리뷰 관련에서 에셋에 적용 버튼이 활성화 되어있다면 그걸 눌러주어야 리타기팅할 때 포즈 적용 됨

 15. MIXAMO에서 받아온 애니메이션을 쓰려면 일단 애니메이션이 적용된 캐릭터와 함께 애니메이션을 다운받아서
 캐릭터를 먼저 언리얼에 임포트 시키고 임포트 시킨 스켈레톤에 대해 애니메이션을 추가시켜줘야 함

 16. 결국 그 캐릭터를 안 쓰고 애니메이션이 필요한 경우가 많을 텐데 리타기팅을 해주어야 하고 본을 일일히 맞춰줘야 하는데
 MIXAMO의 본들은 이름이 이상함
  - 직접 눈대중으로 맞춰가면서 어디 뼈인지 맞춰줘야 하고 (나름 할만함)
  - 언리얼 기본 스켈레톤이랑 비교했을 때 없는 뼈가 많았는데 그런 부분은 NONE으로 남겨주면 됨

 17. 블프에서 노드에 Alt + G 누르면 함수 정의 볼 수 있음

 18. 블프 그래프에서 Ctrl + P 누르면 글로벌 에셋 들어가서 검색할 수 있음
  - 번거롭게 콘텐츠 브라우저로 안 나가도 됨

  19. Tab키는 블프 그래프에서 우클릭과 같은 효과
*/