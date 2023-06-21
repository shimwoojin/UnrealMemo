#pragma once
/*
	1. UFUNCTION 지정자 중 BlueprintNativeEvent를 사용할 때 <함수이름_Implementation> 이라는 이름의 함수를 새로 정의해주어야 하는데
	- BlueprintNativeEvent 키워드가 붙게 된 함수는 문서이름.gen.cpp에 기본 구현을 갖게 됨
	- 그 구현의 내용은 C++ 버전으로 호출할 땐 <함수이름_Implementation>을 호출하고
	블루프린트에 오버라이딩 된 구현이 있다면 그 내용을 호출한다는 뜻

	- 하여 우리는 BlueprintNativeEvent를 사용하여 C++에 기본 구현을 갖고 블루프린트로 오버라이드하여 사용하고자 하는 경우가 있다면
	
	기본 함수는 구현을 비워두고 ( gen.cpp에서 이미 <함수이름_Implementation>을 부르기로 약속돼있음 )
	<함수이름_Implementation>을 정의부와 구현부를 마련해두어야 함

	이 때 <함수이름_Implementation>에는 어떠한 지정자도 사실 의미가 없는 것이(어떤 것은 있을수도) 블프에서 오버라이드 안 할 시 이 함수를
	부르게 되는데 블프 관점에서 노출된 함수는 <함수이름> 이기 때문 -> <함수이름>이 내부적으로 <함수이름_Implementation>을 부르는 것

	하여 리플랙션 기능을 이용하고 싶다면 블프에 노출될 함수인 <함수이름>을 통하는 것이 의도와 맞을 듯

	2. 
*/