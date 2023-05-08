#pragma once
/*
	1. GameInstance는 프로젝트&세팅 -> 맵&모드에서 세팅해서 사용
	- GetGameInstance를 통해 얻어오고(캐스팅 필요하니 형변환을 해놓은 함수를 만들어서 return해서 쓰면 편함)
	- GameInstance는 싱글턴으로서 존재하는 걸 개인이 쓰기 나름(데이터 보관용도 나쁘진 않아보임)

	2. HP Bar를 만들기 위해 WBP를 만들고 Canvas 패널 지워주고 SizeBox를 추가해줌(SizeBox는 자식을 하나만 가질 수 있다고 하심)
	- Canvas 패널은 화면 전체, SizeBox는 일정 크기를 가지는 패널(w : 125, h : 25)
	- Border 자식으로 추가
	- Border에 패딩이 2종류가 있는데 부모인 SizeBox에 대한 패딩일지 Border 내부 content에 대한 패딩일지(우리는 content에 대해 전체 5 줌)
	- border의 색상은 회색 줌(r,g,b 0.25씩)
	- ProgressBar도 자식에 추가

	3. SizeBox - Border - ProgressBar 순으로 사용
	- ProgressBar는 0 ~ 1 사이의 비율(Percent 옵션)로 부모에 대해 공간을 얼마나 차지할 지 정하는 듯
	- LeftToRight, RightToLeft 등 어디서부터 게이지를 채워서 보여줄 지 정할 수 있음(Bar Fill Type)
*/