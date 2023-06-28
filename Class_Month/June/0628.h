#pragma once
/*
	1. LineTrace에서 디버그 모드를 켜면 선이 보이고 선에 닿으면 점이 찍히는 헤더를 사용해 봄
	- #include "DrawDebugHelpers.h"
	- DrawDebugSolidbox, DrawDebugPoint, DrawDebugSphere, DrawDebugCircle, DrawDebugLine, DrawDebugCapsule, DrawDebugDirectionalArrow
	- FBox라는 구조체는 양 끝 모서리의 위치를 넘겨주면 생성 가능
	- DrawDebugPoint는 ScreenSpace로 찍히게 됨
	- DrawDebugCircle은 얼마나 잘게 쪼개지는지에 따라 더 정확한 원이 됨(인자로 넘김)
	- DrawDebugCapsule은 FQuat을 받게 되는데 FRotator를 주로 사용하는 입장에서 FQuat로의 변환은 1) FRotator().Quaternion() 2) FQuat(FRotator())
	- FQuat::Identity -> 쿼터니언의 기본 값 정도 되는 듯, 벡터로 따지면 제로 벡터

	2. Cpp 델리게이트를 다루기 이전에 블프에서 사용하던 이벤트 디스패처(멀티캐스트 델리게이트)를 좀 알아보면
	- 호출, 바인드, 언바인드, 모두 언바인드, 이벤트, 할당 정도가 있는데
	- 할당은 이벤트 디스패처가 받을 인자 목록에 맞춰 커스텀 이벤트를 만들어 줌
	
	- 델리게이트의 강력함을 간단하게 설명하면 우리는 그저 선언된 델리게이트를 원하는 곳에서 호출하기만 하면 됨
	호출에 앞서 누구의 이벤트(혹은 함수)를 바인드 해줄지는 유연함(동적 바인딩)

	3. 이벤트 디스패처에 바인딩을 하는 과정에서 내 이벤트 디스패처 변수는 private으로 보호하고 input값으로 이벤트를 받고 싶을 경우가 있을 수 있는데
	- 정식 지원을 하는 방법은 아니라 우회를 해야 함
	
	- 이벤트를 input으로 받는 노드(예를 들면 이벤트 바인딩 노드)에서 핀을 뽑아 함수의 input으로 주고 함수의 input을 통해 함수의 output으로까지 전달 가능
	꽤나 우회해서 함수의 input 혹은 output으로 이벤트를 받거나 보낼 수 있음

	- 함수 -> 이벤트로 전환은 <이벤트 생성> 노드를 이용
*/