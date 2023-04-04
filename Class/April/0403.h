#pragma once
/*
	1. 스킬을 구현하기 위해서 무기에서 했던 것과 같이 character의 beginplay에서 spawnactorfromclasses로 생성하여 가지고 있음
	- 클래스를 담는 배열과 래퍼런스를 담는 배열 구분
	- CurrentSkill 단일 변수를 만들어서 현재 스킬에 대한 것도 관리

	2. 위 작업을 constructionscript가 아닌 beginplay에서 하는 차이점에 대한 질문이 있었는데
	- 일단 첫번째로 저 작업을 beginplay에서 한 이유는 spawnactorfromclasses가 constructionscript에서는 부를 수 없음
	- constructionscript의 주 용도는 이 클래스를 월드에 배치 한 순간 동작하는 것이고
	- 인스턴스별로 뭔가 변화가 생겼을 때도 constructionscript를 실행해주는데
	- 이걸 응용하게 되면 bool변수나 enum변수로 어떤 변수를 주는지에 따라 어떤 component를 가질지를 인스턴스를 월드에 배치한 이후
	정할 수 있음
	- 하지만 또 한계라 한다면 AddComponentByClass같은 함수 사용은 제한되어서 명시적으로 변수의 어떤 값엔 어떤 컴포넌트를 추가하겠다 같은 식의
	선언을 해야 함
	- beginplay나 constructionscript나 생성자나 시작할 때 처리하는 것은 같지만 3개는 미묘하게 다른 부분이 있으니 일단 인지하고 넘어감
	- 추가로 변수 값 변화에 따라서 추가되는 component를 확인해 볼 때 에디터 개인설정 - 콘텐츠 에디터 - 블루프린트 에디터 - 디테일 보기에서 컨스트럭션 스크립트
	숨김 에 대해서 체크를 풀어주고 사용해야 변화된 component확인 가능(default는 constructionscript 숨김)

	3. sequence에서 이미 연결했던 핀을 다른 곳으로 옮겨주는 거 ctrl 누르고 핀 클릭 후 드래그하여 가능(sequence만은 아니고 모든 연결 선에 대해)

	4. 역할별로 comment 박스 만들어줌

	5. skill A,B,C 액션매핑 만들고(z,x,c) 컨트롤러에서 character에 상속한 skillA,B,C인터페이스 콜해줌
	- chracter쪽에서 상속받은 인터페이스 구현만 하면 skillA,B,C에 관한 키 입력 시 호출됨

	6. 키 입력을 길게 누르다가 떼야 작동하는 이벤트에 대해서 2가지 방법 정도 생각해 볼 수 있는데
	- 인터페이스에서 pressed랑 released에 대해 2가지 함수를 만들어서 각각 동작시켜주는 것이랑
	- 인터페이스쪽 함수에서 하나만 만드는데 대신 input값으로 bool변수 하나 받아서 filpflop으로 처리해주는 방법(키 이벤트의 pressed랑 released는 둘다 flipflop
	으로 들어오는 흐름, 누르면 true, 떼면 false 이런 식으로)

	7. Delay와 RetriggableDelay의 차이가 있는데
	- Delay는 Delay중에 다른 Delay가 들어오면 무시하고 본인의 남은 시간을 끝내기만 하는데
	- RetriggableDelay는 Delay중에 다른 RetriggableDelay가 들어오면 다시 그 시점부터 Delay 시작함
	- 적의 피격 색이랑 타격 시 경직에 대해 Delay -> RetriggableDelay로 바꿈

	8. Sequence와 Gate를 활용하여 이단입력에 대해서만 작동하도록 만들 수도 있는데
	- 키 이벤트 - Sequence - Gate 순으로 배치하고
	- Sequence의 Then0는 일단 실행쪽으로 들어가고(Gate가 처음엔 막혀있음)
	- Then1이 Open의 흐름에 들어가서 문을 열어주고
	- Then2는 delay0.25초 뒤에 Gate 문을 다시 닫음

	- 핵심은 Then1과 Then2 사이에서 새로운 키 입력에 대해서 Gate가 열려있기 때문에 Gate를 통과할 수 있게 됨

	9. IsValid로 변수에 대해 null체크를 할 수 있었는데 (혹은 class에 대해 null체크가 가능한 함수도 있음 IsValidClass였나?)
	- 변수 getter에 우클릭해서 변수의 유효성 검사를 통해 IsValid와 같은 일을 할 수 있음


*/