#pragma once
/*
	1. FString은 TCHAR형으로 형변환(정확히는 형변환은 아님)해서 사용하기 위해 2가지 방법이 있음(TEXT()의 경우 TCHAR를 요구함)
	- 1) Data.GetCharArray().GetData() 2) *Data
	- 2번 방법은 *에 대해 연산자 오버로딩이 된 것

	2. FVector, FRotator 등엔 ToString()이라는 알아서 FString으로 반환해주는 함수가 있음

	3. UObject는 각각 FName을 가지고 FName은 ToString으로 변환해서 사용 가능

	4. Rotator는 받는 인자가 pitch, yaw, roll 순
	- 주석을 달 때 매개변수마다 주석을 다르게 달아줄 수 있는데
	- @param <매개변수 이름> <주석 내용>

	5. 블프의 PrintString처럼 화면에 띄우기 위한 함수는(log가 아닌)
	- GEngine->AddOnScreenDebugMessage(); 매개변수는 아래서 설명
	- key, 띄울 시간, 색, 메시지 등은 필수로 넘겨주야 하고 디폴트 매개변수로 잡혀있는 값이 있음
	- key는 각 메시지에 대해 Channel임 -> 띄워질 위치가 정해진다는 뜻
	- key의 기본값 -1은 Channel 없이 다른 Channel이 적혀있건 관계없이 쭉 밀어 냄
	- 디폴트 인자 중에 bNewerOnTop이 있는데 쌓이는 순서에 대해 toggle하는 것
	- 크기에 대해서도 디폴트 인자임

	6. FPS장르를 다룰 때 상대는 내 전신이 보이고 플레이어는 본인의 손과 무기 정도만 보이면 되는데
	- 이 때 플레이어에게 SkeletalMesh를 두개 주고 1) 상대에게 보이는 용도 2) 플레이어에게 보여질 용도로 나눈 뒤
	- <디폴트 - 렌더링> 에서 OwnerNoSee, OnlyOwnerSee 등의 값을 조정하여 사용하는 기법도 있다고 함

	7. 5번 얘기를 이어하자면 화면에 띄울 메시지를 제외하고 key, 띄울 시간, 색에 대해선 디폴트 매개변수를 주고자 하는데
	- 여러 함수에 같은 값을 주어 초기화를 하는 내용이기 때문에 1) static const 변수 2) 매크로 를 활용하여 이 내용의 유지보수성을 올릴 수 있는데
	
	- 상수성에 대해 define을 하는 방법이 구식 방법이라 첫 시도엔 static const를 사용함

	- 클래스 내의 static을 사용함에 있어 클래스 내에 변수를 static 키워드를 적어 붙여주고(초기화는 하지 않음)
	cpp에 가서 static 키워드는 빼고 변수 이름 앞에 네임스페이스를 붙여 초기화를 해주면 됨(int같은 정수형이나 char형에 대해선 cpp가 아닌 클래스 내부에서도 초기화가 가능하다곤 함)

	- 위 방법의 안 좋은 점은 함수에 마우스를 갖다 대어 기본값이 뭘로 설정되었나 확인하고자 할 때 한 눈에 확인이 어렵다는 점이 있음

	- 위 방법에 대해선 매크로가 더 유리해보임(매크로는 함수에 마우스 갖다 대면 어떤 값인지 치환되서 볼 수 있음)

	8. 대문자 변환 : ctrl shift u, 소문자 변환 : ctrl u
	- 대문자 변환은 잘 안 쓰던 기능인데 매크로를 자주 코딩하게 되면 유용할 듯

	9. 헤더의 끝에서 #undef 을 통해 그 매크로의 해제를 할 수 있으나 보통은 지양하는 게 좋음

	10. FString::FromInt()로 int를 FString으로 바꿀 수 있었다면
	- FString::SanitizeFloat()은 float을 FString으로 바꿀 수 있음(Sanitize는 '살균하다'의 의미 -> 쓸데없는 0을 떼줌, 굉장히 청결한 float인 듯 ㅋㅋ)

	11. Logger::Print()를 정의함에 있어 GEngine->AddOnScreenDebugMessage()를 호출하며 오버로딩하는 형식으로 정의하였는데
	- 이런 경우 GEngine->AddOnScreentDebugMessage()에 대해 한 단계 래핑하여 함수로서 관리해주는 것이 좋음(Internal 함수)

	12. UKismetSystemLiberary::PrintString()은 우리가 알던 블프의 printstring임(#include "Kismet/KismetSystemLibrary.h"
	- 우리가 Logger를 새로 정의한 이유는 log와 screen에 따로 쓸 함수를 분리함도 있으며
	- 화면에 띄울 경우 key를 주어 가시성을 높여줌에 있음
*/