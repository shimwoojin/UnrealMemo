#pragma once
/*
	1. 그동안 당연하게 Cross를 하고 나면 왼손을 들고 검지가 첫 번째 벡터, 중지가 두 번재 벡터, 엄지가 Cross의 결과로 생각했었으나
	- 이것이 UE가 왼손 좌표계여서 가능했던 것이고
	- 이것은 수학적으로 벡터의 Cross를 하고 나온 결과와는 정반대의 결과인 것
	
	- 오른쪽에 있다라는 판별이 수학적으론 그 결과의 벡터가 z가 마이너스가 나오는데에 비해
	- 오른쪽에 있다라는 판별이 UE에선 벡터의 z가 플러스가 나옴

	2. 추가로 왼손좌표계는 D3D, 언리얼, 유니티에서 쓰고 있으며
	- 오른손 좌표계는 다른 그래픽 라이브러리, OpenGL, 수학의 좌표계 등에서 쓰임

	3. 결론적으로 수학 좌표계와 언리얼 좌표계는 x,y,z축 중 하나가 축이 반전되어 있는 것이고
	이런 점을 고려하여 수식에 적용해주어야 함(예를 들면 DegAtan2로 Rotator를 구하게 된다면 pitch가 마이너스)

	4. 땅의 법선벡터에 대해 DegAtan을 하게 되는 것이고 땅의 법선벡터를 기준으로 땅을 상상하게 됐을 때 
	- Roll은 회전과 DegAtan의 결과 각이 같으나
	- Pitch는 부호가 바꼈다는 것을 결과론적으로는 계산해 볼 수 있음

	5. FInterpTo, RInterpTo의 cpp를 까봤을 때
	- DeltaSeconds, InterpSpeed의 값이 Start -> Target을 갈 때 몇 퍼센트를 향할지를 0 ~ 1 사이 만큼으로 Clamp하고 있었음
	- DeltaSeconds * InterpSpeed 만큼을 0 ~ 1로 Clamp하던데 
	- Deltaseconds를 60hz기준으로 생각하고 interpspeed를 대략적으로 정하게 되면 원하는 움직임을 만들 수 있을 것,, 걍 여러번 테스트하자

	- 이것만 알면 됨 -> interp는 tick 단위로 계산할 경우 부드러운 움직임을 만들기 위해 사용하고
	그 부드러운 움직임은 start -> target 의 차이에서 몇%에 해당하는 비율만큼 계산 한 번 당 줄어드는 거임(처음 빠른 움직임 -> 점점 느려지는 이유)
	start == target이 거의 차이나지 않을 만큼 가까워졌을 경우엔 interp 내부적으로도 return 시키는 로직이 있음
*/