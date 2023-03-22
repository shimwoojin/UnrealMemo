#pragma once
/*
1. 블프 클래스 그래프에서 북마크 사용 -> 그래프 좌측 상단 별 클릭 후 저장하고자 하는 위치 북마크 만들어줄 수 있음

2. 퀵 북마크 -> ctrl + 0 ~ 9로 보고 있던 노드의 줌, 위치 등 저장 후 shift + 0 ~ 9로 이동 가능

3. 블프 그래프에서 ctrl + f : 찾기, 블루프린트에서 찾기랑은 조금 다름

4. 커스텀 이벤트 만들어서 매개변수도 줄 수 있고 이벤트에서 이벤트를 호출할 수도 있음

5. hit은 한쪽, overlap은 양쪽

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

 9. 블프에서 노드에 Alt + G 누르면 함수 정의 볼 수 있음

 10. 블프 그래프에서 Ctrl + P 누르면 글로벌 에셋 들어가서 검색할 수 있음
  - 번거롭게 콘텐츠 브라우저로 안 나가도 됨

  
*/