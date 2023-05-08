#pragma once
/*
1. camera를 springarm에 붙임
 - 벽 근처에서 카메라 거리 조정 자동으로 해줌
 - 카메라 위치 초기화, use pawn controll rotation옵션 끄고 붙임

2. 플레이어가 너무 화면 중앙을 차지하는 것을 막기 위해 spring arm의 target offset z값 올려줌

3. controller에서 add movement input이 월드값 기준으로만 움직일 수 있게 되어있었음
 - player의 벡터를 기준으로 해야함
 - get actor forward vector, get actor right vector
 - get controlled pawn에서 얻어옴

4. 애니메이션을 다루기 위한 클래스 따로 있음, 접두어 ABP_
 - 애니메이션 블루프린트 생성
 - 부모 클래스 : animinstance, 스켈레톤 : 엔진 콘텐츠 끄고 남은 1개
 - 이번 프레임에 나갈 애니메이션을 정하기 위한 클래스

5. 애니메이션 클래스가 하는 일은 매 프레임 GetOwner, 즉 캐릭터로부터 velocity(속도)를 얻어와
xy축에 대한 vector length(크기)를 speed 변수에 저장해 줌
 - Blueprint update animation은 actor의 tick과 비슷한 개념

6. idle, walk, run에 대해서 섞은 애니메이션을 만들기 위해서 <블렌드 스페이스 1D> 클래스를 새로 만들어줌
 - speed 변수를 하나의 축으로 만들어 speed값의 변화에 대해 애니메이션을 섞는 역할

7. BS_Unarmed, 블렌드 스페이스 1D의 옵션에서 Number of grid를 2로 설정해서 상태 3개에 대한 블렌딩 가능

7-1. 만들어진 ABP_, 애니메이션 블루프린트 클래스는 character를 상속받은 player의 animation mode에서 설정을 해주어야 적용됨

8. jump를 설정해주기 위해서 액션 매핑을 해주고 controller에서 이벤트 그래프에서 노드들을 연결해주어야 함
 - 기본적으로 get controlled pawn에서 핀을 끌어다가 어떤 대상에 적용할지를 정해주었는데
 - 언리얼의 기본 상속관계에서 uobject - aactor - pawn - character 순으로 상속이 되기 때문에
 - 우리가 생성한 블루 프린트 클래스가 character를 기반으로 만들었기 때문에
 - pawn이 아닌 character로 down casting을 한번 해주어 jump 함수를 불러주어야 함 (jump는 character의 함수)
 - pressed 중에는 jump이고 released가 되면 stop jumping을 할 수 있게끔 함수가 제공되어 있음

9. 키 입력을 받아 앞, 뒤, 좌, 우로 이동을 해야 할 때 어떤 축을 기준으로 이동을 해야할 지를 생각하면
 - controller의 vector를 기준으로 해야 했고 controller의 forward vector, right vector를 기준으로만 했을 때는 문제가 생김
 - 시점이 위나 아래로 향하게 되었을 때 forward vector가 땅이나 하늘을 향하게 되고 땅을 뚫게 되거나 날 수는 없기에 키 입력이 안 먹게 됨
 - 해결책은 controller의 yaw(Z축)가 얼마나 회전해 있고 그걸 기준으로 forward vector와 right vector를 뽑아내면 문제가 없었음
 - get controll rotation - make rotator - get forward vector순으로 연결
 - make rotator에서 x,y는 0 z축에 controller에서 뽑아온 yaw축을 물려줌
*/