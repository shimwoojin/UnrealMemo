#pragma once
/*
	1. 텔레포트 만들고 나서 마지막 수정은 일정거리 이상일 때 데칼이 안 보이는 것인데 
	- Decal의 FadeScreenSize를 0으로 바꿔줌(default 0.01)
	- 화면의 몇 퍼센트 밑으로 크기가 작아지면 화면에서 안 보이게 하는 옵션(default 1%)

	2. 새로운 스킬 FireStrom을 만들어보자
	- BP_Skill 상속받고
	- ParticleSystem 추가하고
	- ParticleSystem의 AutoActivate끄고
	- collision 추가해주고 크기 맞춰주고(z위치300 캡슐크기 높이 : 500, 반지름 : 200)
	- 캡슐의 overlapevents 꺼주고

	3. 다단히트로 구현하기 위해
	- beginoverlap되면 배열에 넣고 endoverlap되면 배열에서 빼고
	- 배열에 들어있는 애들에 대해 0.몇초마다 데미지를 넣는 방식

	4. 주변을 도는 화염 기둥을 구현하기 위해 스킬 발동하면 캐릭터의 전방 vector를 기준 벡터로 잡고 각도를 0으로 초기화해줌(EndAction, 몽타주의 노티파이)
	- particle은 activate해주고 capsule의 overlap은 켜줌

	5. 오버라이드 가능한 이벤트들은 왼쪽탭에서 우클릭 후 함수로 변환 가능(local변수가 필요하다면? 써볼만한)

	6. tick에서는 particle이 active라면 불기둥이 돌아가는 처리를 해주어야 하는데 2가지 방법이 있음
	- 어려운 방법은 삼각함수의 cos, sin을 이옹해서 actor위치 기준으로 각을 계산해서 setactorlocation 해주는 것

	7. tick에서 각도에 대해 +1 씩 해주는 방법은 문제가 있음
	- 컴퓨터 사양에 따라 tick호출 횟수가 달라서 사양이 좋으면 스킬이 빠르고 안좋은면 느려짐
	- AngularSpeed * DeltaSeconds를 Angle에 tick마다 더해주면 사양에 상관없는 같은 결과를 얻을 수 있음

	8. 0.125초마다 배열의 담긴 액터들한테(불기둥안에 들어온) 데미지를 주기 위해 간단한 구현은
	- Tick에서 Delay로 처리하는게 간단한 방법(Retriggable은 여기서 쓰면 안됨)
	- Deligate를 써서 해결해보자

	9. SetTimerByEvent로 CustomEvent(DamageEvent만들어서 할당해주고 .125초마다 발동하게 끔 처리
	- CustomEvent(DamageEvent에 대해 처리해주는 것

	10. 5초 뒤에 스킬을 꺼주기 위해
	- SetTimerByEvent에서 Event핀에 EventDispatcher에서 생성해서 스킬을 끄는 함수를 물려줌(OnTimeOver)
	- 함수를 이벤트로서 timer에 바인딩해주는 느낌
	- OnTimeOver는 particle을 deactivate하고 capsule의 overlapevents를 꺼주는 함수
	

*/