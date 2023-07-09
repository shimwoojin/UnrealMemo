#pragma once
/*
	1. 멀티캐스트 델리게이트를 만드는 방법
	- TMultiCastDelegate<void(int)> a;
	혹은
	- DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiTriggerType, int32, FLinearColor)

	2. UBT와 UHT는 전처리보다 더 먼저 진행되는 언리얼만의 빌드 방식임
	- UBT : Unreal Build Tool
	- UHT : Unreal Header Tool

	- UHT가 먼저 UCLASS(), UFUNCTION()같은 키워드들을 읽고 먼저 처리를 하기 때문에 ClassName.generated.h가 전처리로 파일에 포함되는 과정에서 문제가 없었던 것임
	- 출력을 확인해보면 위 내용을 확인할 수 있으며 <출력>이 주는 정보가 생각보다 많음

	3. public을 위로 올리는 건 습관화
	- 보기 편하기 위해

	4. 컴포넌트를 일반 배열로 만들고 UPROPERTY()로 리플랙션으로 노출시키려고 하면 첫 번째 인자를 제외하곤 적용받지 못함
	- TArray<> 사용하자
	- 혹은 컴포넌트는 배열로 만들지 말자

	5. 머티리얼을 받는 자료형 중에 UMaterialInterface가 있음
	- 동적 머티리얼은 UMaterialInstanceDynamic임
	- 머티리얼의 변수와 상호작용을 하기 위해선 UMaterialInstanceDynamic 자료형이어야 함(Cast)
	- 머티리얼 변수를 통제할 땐 실제 머티리얼에 있는 변수 이름이여야 하며 문자열로 넘겨주는 것이 단점

	6. FString과 FName이 암시적으로 변환될 수 있는 것 같으나
	- 생성자에선 explicit인지 확인 필요

	7. meshes[i]가 문자열로 그대로 읽히는 현상에 대해 ADDDYNAMIC, BINDDYNAMIC 쪽 참조
*/