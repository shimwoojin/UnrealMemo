#pragma once
/*
	1. class UParkourComponent : public UActorComponent {} 생성

	2. enum 복습
	- enum class에 지정자 BlueprintType이 붙게 되면 : uint8 이 강제 됨 -> 저 키워드 없이 UENUM()만 한다면 타입 상관 없음
	- namespace로 감싼 enum은 : uint8 같은 문법 불가능 -> enum class만 가능한 듯
	- namespace로 감싼 enum이 TEnumAsByte<>로 강제되는 경우가 있는데 그 경우는 Member Variable인 경우

	3. <namespace로 감싼 enum> vs <enum class>
	- 취향 차이 혹은 사용처가 갈린다라고 할 수 있음 -> enum class의 경우 정수형으로 auto cast가 안 되기 때문에 이런 상황
	- enum은 수치를 보기 좋게 포장한 느낌 / enum class는 <고르시오> 같은 느낌

	4. 리플랙션에 노출되지 않은 코드를 리플랙션에 노출된 코드에서 사용할 경우 에러날 수 있음
	- typedef 

	5. 구조체를 데이터 테이블로 활용하기 위해선 : public FTableRowBase 를 상속
	- #include "Engine/DataTable.h"
	- 상속이기 때문에 부모의 헤더 필요
	- 실제 데이터 테이블을 물려 주기 위해선 class UDataTable* DataTable; 에 담아줘야 함

	6. 데이터 테이블값 TArray에 얻어오기
	- TArray<FParkourData const*> Rows;
	DataTable->GetAllRows("", Rows)
	- Rows에 데이터 테이블의 값을 인자로 넘겨 받아오는 건데
	 ""를 넘기는 건 모든 rows를 얻어오겠다는 뜻 -> "" 안에 이름에 포함된 문자열이 있다면 그 녀석들만 얻어오게 됨

	 7. static 멤버 변수는 UPROEPRTY 키워드 쓰면 안 됨(static을 타입명으로 읽어서 컴파일 시 오류)
	 - 우회하는 방법은 static 멤버변수를 반환하는 Getter를 블프에 노출해주면 됨

	 8. 마찬가지로 다중 컨테이너(map에서 key로 배열을 가지는 등)가 블프에선 사용이 안되지만
	 - 우회 : 구조체에 배열 멤버를 가지고 그 구조체를 key로 가지는 map 정의 -> 실사용은 하지 말자
*/