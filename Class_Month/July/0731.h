#pragma once
/*
	1. 애님 인스턴스는 프리뷰에 적용된 인스턴스가 있기 때문에 2개처럼 보일 수가 있음
	- Try Get Pawn Owner가 유효한지 체크하면 우리꺼만 체크 가능

	2. 본 트랜스폼(변경), 2 본 IK 는 컴포넌트 공간에서 변환해야 함
	- 기본 로컬 공간에서 애니메이션을 만들게 되는데 위 2노드를 사용하려면 로컬 <-> 컴포넌트, 컴포넌트 <-> 로컬 변환이 필요함

	- 로컬은 스켈레톤 에디터에서 볼 수 있는 공간(각 뼈마다 부모에 상대적인)이고 컴포넌트는 스켈레탈 메쉬 컴포넌트를 의미함(스켈레탈 메쉬의 트랜스폼이 반영된)

	3. 가상 본을 본 트랜스폼으로 옮겨놓고 옮겨진 가상본을 2본IK에 적용해 줄 것임

	4. 본 트랜스폼(변경)의 속성
	- Translation Mode : Ignore, Replace Existing, Add to Existing
	- Translation Space : World Space, Component Space, Parent Bone Space, Bone Space

	- Add to Existing, World Space를 골랐는데 각각 이유는 기존 값에서 더해진 값을 쓰는 것이고 Bone Space로 처리할 수도 있었으나 뼈가 만들어지길 축이 통일되지 않게 만들어져서
	어쩔수 없이 World Space를 사용

*/