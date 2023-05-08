#pragma once
/*
1. 과제 풀이 중에 get unscaled box extent와 get scaled box extent의 차이는
 - unscaled는 커진 scale이 안 곱해진걸로 ..?

2. 블프 클래스의 뷰포트에서 카메라 리셋 버튼이 있음
 - 카메라 관점이 너무 멀어지면 사용할만 함

3. 월드라이너에서 배치한 액터들에 대해 shift + 클릭 혹은 ctrl + 클릭 등으로 다수 선택 가능
 - 다수 선택 후 트랜스폼에 대해서 일괄 적용 가능

4. 화면에 문자열 출력 하는 함수는 print string이였고 문자열에 대해 append 함수를 사용해 문자열 추가 가능

5. actor overlap과 component overlap의 차이는
 - actor overlap : actor가 가진 어떤 컴포넌트라도 겹쳤을 때 이벤트 발생하고
 - component overlap은 특정 컴포넌트가 닿았다 라는 출력 핀도 뽑아낼 수 있고
 괄호에 해당하는, 즉 component overlap 이벤트를 부르는 component에 대한 겹침이였던 것임

6. cube의 simulate physics 옵션을 키게 되면 중력 적용 및 type object가 바뀜

7. BP_Hit에서 프리셋을 Block All로 바꾸고 Generate Hit event옵션도 켜주었기 때문에 Hit된 actor
가 있으면 Hit event 발생

8. 레벨의 플레이 버튼 옆 화살표에서 현재 카메라 위치에서 시작하는 옵션도 있음

9. object type이 world static이라고 움직이지 못하는 액터가 아님
 - 그저 콜리전 반응을 어떻게 적용할지에 대한 열거형일 뿐임

10. 콜리전 반응과 simulation generates hit events / simulation generates overlap events는
별개로 옵션 만져줘야 함

11. hit은 한쪽만 켜줘있어도 뜨는데 overlap은 양쪽다 켜져있어야 뜸 (event)

12. 프로젝트 세팅 - 콜리전에서 새로운 object type 등록 가능(이름, 콜리전 반응)하고 프리셋도 등록 가능
 - 과제에서 spring arm에 대해 새로운 object type 등록하고 통과시킬 object type 들에 대해선 콜리전 반응을 무시로 바꿨었음
*/