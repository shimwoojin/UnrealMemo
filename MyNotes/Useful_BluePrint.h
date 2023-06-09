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

  20. 언리얼 블프는 후위 증감이 없음 (전위증감만)

  21. 자식의 변수 우클릭하고 부모클래스로 이동 가능

  22. 블프 클래스 에디터에서 편집 -> 미사용 변수 삭제 가능

  23. ESC를 키로 PIE 모드에서 사용하려면
  - <에디터 개인설정 - 키보드 단축키> 에서 직접 설정할 수 도 있고
  - 잠깐만 테스트 할거라면 <플레이> 버튼 옆 화살표 클릭 후 <독립형 게임>으로 켜면 됨

  24. 언리얼 에디터에서 인게임에서(맞나?) ` 누른 후 <help> 치고 <프로파일링> 관련 찾아보자(20230510, spawn 혹은 BT의 Tick 관련해서 lag이 생김)

  25. StaticMesh Component를 액터에 기본으로 추가하게 되면 <모빌리티 - 무버블> 인데 여기에 옵션으로 CastShadow도 True로 켜져 있으면
  게임 실행 중에 GPU 계산을 많이 잡아먹게 됨
  - <모빌리티 - 스태틱>으로 변경하여 라이팅 맵을 미리 계산하여 런타임 중의 비용을 줄일 수 있음
  - 혹은 CastShadow를 꺼서 해결 가능

  26. Actor의 Tick과 Component의 Tick은 별개임
  - 최적화를 위해 돌아가지 않는 Tick은 꺼주는 게 좋음

  27. stat FPS, stat Game, stat GPU, profileGPU 등으로 프로파일링 가능

  28. 셰이더 컴파일 후 생길 목적 파일은 프로젝트 단위로 소유하고 있는 것이 아님
  - https://blog.naver.com/ryumr/221334719805
  - 위 링크에 잘 설명되어 있음
  - 핵심은 엔진 설치 경로에 DerivedCachedData 폴더에 .ddp 형식으로 저장되어 있기 때문에 작업 프로젝트를 옮겨서 실행하게 되면 최초 1번 옮긴 컴퓨터에서 엔진 설치 경로에
  셰이더 컴파일한 목적파일을 갖고 있게 됨
  - 프로젝트 폴더 단위로 컴파일된 셰이더의 목적파일을 가질 수 있게끔 설정하는 방법은 위 주소에 나와있고 이를 했을 때의 장점은 다른 작업자 간 그 목적파일이 있다면 셰이더 컴파일을 하지 않아도 되고
  단점은 프로젝트의 용량이 커진다는 것임

  29. Behavior Tree를 실행하기 위해 RunBehaviorTree를 할 수 있으나 StopBehaviorTree는 없음
  - 실행 중인 Behavior Tree를 멈추기 위해서는 Behavior Tree Component의 부모 클래스인 Brain Component에서 StopLogic을 통해 멈출 수 있음
  - 재시작하기 위해서는 RestartLogic, 시작하기 위해서는 StartLogic
  
  - 참고 : RunBehaviorTree에 None을 인자로 넘겨도 멈추지 않았고 Behavior Tree Component의 Deactivate를 사용해도 멈추지 않았었음

  30. Timeline Component를 정방향으로 Play하고 나서 끝까지 가고 나서 Reverse가 없는 상황에는 SetTime을 0으로 하여 초기화 해 주어야 하는 경우가 있을 수 있음

  31. SkeletalMesh에 대해 부르는 'Montage 재생' 노드는 StopAllMontages = true가 기본 값임 -> 그 동안 우리가 몽타주 재생 중 다른 몽타주를 재생하면 방해를 받은 이유(Interrupted)
  - (Mesh - GetAnimInstance)에 대해 PlayMontage는 StopAllMontages = false로 하여 몽타주의 동시 재생이 가능하게 함
*/