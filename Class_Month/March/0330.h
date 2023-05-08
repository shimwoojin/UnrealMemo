#pragma once
/*
	1. Hit처리를 하기로 함
	- 애니메이션을 처리해줘야 하고
	- 체력 관리
	- 체력이 0보다 작은지 큰지에 따른 hit, die 분기

	2. 데미지가 들어가고 체력이 깎이는 부분에서 방어력이나 뭐 기타 요소들이랑 계산할 공식이 필요하다면
	- mathexp 노드 사용

	3. sequnce를 사용해서 then0에서는 공격 받고 난 이후의 체력애 대해 0보다 큰지 아닌지 검사해서 상태를 변경해주고
	- then1에서는 현재 상태를 얻어와 현재 상태에 맞는 몽타주를 재생
		- DamagedData랑 DiedData는 각각 데이터에셋을 만들어서 0번 배열만 채워줬음
		- 인덱스는 0을 주면 됨(인덱스를 정하는 로직이 없어도 됨, 다양하게 맞거나 죽는다면 여기서 처리)

	4. LifeNow는 Beginplay에서 LifeMa를 set해줌

	5. 몽타주가 이유없이 재생하지 않는다면 대부부 슬롯 문제

	6. 체력에 따라서 애니메이션은 잘 나오지만 추가적인 처리가 필요함
	- 죽었는데 다시 맞을 수 있음
		- 상태를 Died로 바꾼 직후 GenerateOverlapEvent(capsule) 꺼줌
	- 죽었는데 안 사라짐
		- GenerateOverlapEvent(capsule) 끈 직후에 DestroyActor로 처리(바로 사라지게 하면 안됨)
		- Delay 사용 가능
		- SetLifeSpan으로 더 좋은 처리 가능
		- 더 좋은 처리는 몽타주 재생 노드의 BlendOut핀에서 Died 상태 인지 체크한 후 DestroyActor해주면 됨 (BlendOut의 BlendTime 기본값 0.25, 끝에 0.25초는 재생안함)
		- 위 방법이 깔끔한 것 같지만 Died애니메이션을 끝까지 다 보고 싶은 경우
			- Died_Montage에 가서 BlendOut의 BlendTime을 0으로 바꾸고 Completed에서 Died인 경우 DestroyActor해주면 됨, Died가 아닌 경우 SetState(Idle)
	- 죽었는데 벌떡 일어남
		- 위 처리를 했다면 이런 문제가 발생 안할거지만 관련 된 옵션은 BlendOut

	7. 몽타주를 재생하다가 다른 몽타주가 재생되버린다면? (이전 몽타주가 끊긴다면)
	- 이후 몽타주의 BlendIn만 적용된다고 함

	8. 맞을 때 flash를 줌(피격 대상의 색을 변하게)
	- Material의 색을 바꿔주는 방식으로
	- Runtime에는 Material이 변화 불가능
	- Beginplay에서 Material을 DynamicMaterial로 바꾸고 시작해야 함
	- Mesh - GetMaterials(MaterialInterface, Material의 최상위 클래스) - ForEachLoop - CreateDynamicMaterialInstance
		- 버전이 2개가 있는데 만들고 다시 Set을 해야 하는 버전이 있고
		- 만들자마자 덮어써주는 버전이 있음 (핀 하나 더 있는게 이 버전, primitive component)

	9. 동적 material로 바꾸고 나면 AnyDamage에서 이 Material들에 대해 MaterialInstanceDyanmic에 형변환해서 사용 ( 색을 주는 변수 형식은 LinearColor)
	- SetVectorParamaterValue 노드를 통해 Material이 들고 있는 BodyColor를 바꾸는 방식으로 처리해봤는데 이 방식은 너무 빨갛고 부자연스럽기 때문에
	- 은은하게 보일 수 있게 EmissiveColor라는 parameter를 만들어서 색을 정해서 넘겨주면
	- Material쪽에선 기존 색과 받은 EmissiveColor를 섞어서 색을 정함
	- 근데 이 방식도 색이 진한 부분과는 더 진하게 섞이고 색이 연한 부분과는 연하게 섞이는 등 문제가 있음

	- Material에 우클릭 후 인스턴스로 하나 만들어 준다음 BodyColor탭에 체크 후 색을 0 0 0 0으로 바꿔줌
	- 모든 머티리얼에 다 이렇게 해주고
	- BP_Enemy에 이걸 적용해줌 (일단 이렇게 마무리, 아마 추가 작업 있을 듯)

	10. 맞을 때 반작용이 생기는 처리도 해줌
	- AnyDamage의 Instigator - GetControlledPawn - SetCustomDilation(0.01) - Delay(0.1) - SetCustomDilation(1)
	- 이렇게 하면 문제점이 원거리 공격에도 반작용이 생김

	- 무기로 옮겨서 처리해주는데(Overlap 이벤트에 시퀀스 새로 만들어서)
	- GetInstigator - SetCustomDilation(0.01) - Delay(0.1) - SetCustomDilation(1)로 처리해 줌
*/