#pragma once
/*
	1. 함수 타입에 auto가 읽히려면 갖다쓰려는 곳보다 먼저 적혀야 함
	
	2. 지역 변수는 선언과 동시에 초기화해야 오류 안남

	3. if문 안에서 초기화는 =과 ==이 헷갈릴 수 있어서 막아놓은 듯
	- 선언과 동시에 초기화하는 것은 가능하나 선언 후 따로 초기화를 막아놓은 듯

	4. UInputComponent::BinxAction() 사용 중에 EInputEvent::IE_Pressed 같은 인자를 받는 것이 있음
	- 눌렀을 때나 뗐을 떄 등 어떤 키 입력인지를 정하는 열거자

	5. actor는 component들의 중개자
	- 외부에서 어떤 기능에 대해 처리할 때 component들을 직접 가져다가 처리하기 보단 component들을 활용하여 구성된 actor의 함수를 구성하여 처리하는 것이 옳은 방법

	- 우리 Character의 void Parkour() 함수가 ParkourComponent의 void BeginParkour()를 대신 불러주는 것과 같은 설계가 위와 같음

	6. 애니메이션에 root motion이 걸려있을 때 애님 블프에 몽타주에 대한 슬롯 설정이 없었어도 그 애니메이션이 재생된다면 root motion에 대한 움직임은 발생했어야 함

	7. 디버그 시 bool 지역변수가 최적화 변수라서 값 확인이 불가능한 경우가 있었음
	- 우리 VS 빌드 모드가 <development editor>였기 때문일까
	- <debug editor>였다면 bool 지역변수도 값을 찍어줬을 것임

	- development editor가 어느 정도의 최적화와 디버그를 겸한 모드로 알고 있음
	- development vs development editor의 차이는 .exe를 만드느냐와 dll을 만드느냐의 차이

	- .exe를 만들어도 사용할 수 없음 -> 실행에 필요한 다른 파일들이 그 경로에 준비되어 있지 않음

	8. 파쿠르 로직 중 크게 2가지 정도 문제가 있음
	- 1) dot에 대해 모서리의 normal과 처리할 시 문제
	- 2) 물체의 extent.z에 대해서만 처리를 했는데 z가 충족해야 파쿠르를 하는 물체도 있지만 x 혹은 y가 충족해야 하는 물체도 있음

	9. 위 2번에 대한 문제는 우리가 처리할 obastcle의 extent를 float이 아닌 FVector로 받아 0이 아닌 각 요소에 대해서 처리하는 방식으로 로직 구성할 예정

	10. 데이터 테이블 .csv 연동
	- .csv 파일의 경로 설정 후 리임포트

	11. float& FVector::Component(int32 Index)
	- index로 FVector의 x,y,z에 접근할 수 있는 함수
	- return (&X)[Index); 와 같은 로직인데
	- 벡터의 X 주소를 뽑아서 index로 포인터 연산으로 다시 접근하는 것
*/