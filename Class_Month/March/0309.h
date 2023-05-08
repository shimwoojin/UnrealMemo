#pragma once
/*
1. controller가 나, <player controller>
 - 클래스 디폴트에서 find camrera component when view target옵션을 켜서 player가 뷰타겟이 됐을 때 카메라 컴포넌트를 찾고
 player camera manager class에서 찾은 camera component를 사용, 이 때 auto manager active camera target 옵션도 체크가 돼 있어야 함

2. Blend Space 1D에서 스켈레톤에 들어오게 되면 캐릭터 - 본 그리기 모든 계층구조를 눌러 뼈대가 어떻게 생긴 지 확인 가능
 - 좌측에 root를 기준으로 상대위치들이 잡혀있음(단순한 transform matrix라고 함)

3. 스켈레톤의 트랜스폼을 조정하는게 애니메이션의 기본 원리

4. 애니메이션에서 빨간 라인을 우측 끝으로 밀어 몇초짜리 애니메이션인지 확인 가능
 - 프레임도 몇개로 이루어져있는지 확인 가능

5. 3D 애니메이션의 기초 : key frame animation
 - 특징적인 몇 지점을 찝어서 그 사이의 이동은 선형보간을 통해 자연스럽게 보이게 함
 - (1-r)x + ry 의 식이 선형 보간 ( 0 <= r <= 1 )
 - Idle, Walk, Run의 애니메이션 조합도 speed값을 기준으로 선형보간 된 것
 - (1 - speed / 300)(Idle) + (speed / 300)(Walk) 이런 식
 - bone과 bone에 대한 선형보간 , animation과 animation에 대한 선형 보간

6. 점프 애니메이션 구현
 - ABP_Characer에의 AnimGraph에서 State machine 만듬
 - state machine을 더블클릭해서 들어오게 되면 entry, 진입점 노드가 있음
 - 이전에 만들어두었던 BS_Unarmed 연결, BS_Unarmed를 기준으로 jump의 시작을 하고 jump가 끝나면 다시 이 상태로 돌아와야 함

7. jump인지를 어떻게 구분하느냐 ?
 - getowner에서 getmovementcomponent를 하고 isfalling을 하면 jump인지 알 수 있음
 - 점프라는 것은 우리가 중력을 이겨내고 올라가는 것이기에 점프를 하는 순간부터 isfalling의 return값은 true(true라는 것은 jump 시작)
 - isfalling의 return값은 이벤트 그래프에서 매 프레임 받아와서 bFalling인 bool변수에 담아둠
 - 이 값을 활용해 점프 중인지 점프가 끝났는지 판단 가능

8. jump시작과 끝은 bFalling변수에 의해 알수 있고 jump_loop는 jump_start의 애니메이션이 얼마나 남았는지를 기준으로 판단
 - time remaining(ratio) - jump_start를 끌어와서 0 ~ 1사이의 값으로 대수 비교

9. 양방향 화살표는 다음 노드를 연결한 선에 있는 표시를 누르고 나면 디테일에서 옵션 조절 가능

10. 이렇게만 하고 나면 jump 중 로켓처럼 탁 튀어오르게 되는데 그 이유는 jump_start랑 jump_end의 animation_loop를 풀어주어야 함
 - state machine에서 애니메이션 클릭 후 ~~재생 탭에서 옵션 설정 가능

11. 캐릭터가 달리던 도중 키를 떼게되면 너무 탁 멈추게 되는데 character의 movement component에 마찰계수 적용하는 옵션 있음
 - general settings에 use separate braking fiction

12. BP_BoxCollision 블프 액터를 만들었고 Box가 root, text를 자식으로 달아줌
 - 이 클래스를 상속시켜 collision이 일어났을 때 다양한 이벤트를 하는 용도, text는 자기 클래스의 이름을 나타내게 됨
 - 기본적으로 월드상에 배치될 때 세팅이 이루어져야 하기 때문에 contruction script에서 세팅을 만져줌

13. text의 위치를 box extent의 z축 위 30으로 잡아주기 위해 set relative location을 통해 text render의 위치를 잡아줌
 - get scaled box extent의 z값에 30을 더해 text의 z location에 달아줌

14. text에 띄울 text를 클래스 본인의 이름으로 하려고 하는데 이 때 C++에서의 키워드 this가 아닌 self 였고
 - getclass -> getdisplayname -> totext(string)을 통해 text에 달아줌
 - string에서 text로 형변환했는데 자료형 차이는 나중에..

15. 과제로 box의 scale에 영향을 받지 않는 text를 구현해야 했음
*/