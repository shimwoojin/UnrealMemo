#pragma once
/*
	1. 배그 우클릭 길게 -> 견착, 우클릭 짧게 -> 스코프 같은 구현
	- Timer를 안 쓰고 구현 하는 방법에 대해 질문함
	- Sequence, Gate를 응용 -> Gate 내부 내용 빈 매크로에 복붙 후 Output에 Gate가 실행되지 않았을 때 Pin을 결과로 쓸 수도 있음

	2. Spline Component의 함수 중 GetLocationAtSplinePoint의 Local과 World의 차이는 World는 실제 배치 된 위치(World의 0,0,0 기준)인 거고 Local은 World상에 배치된 Actor의 Gizmo를 기준으로 함
	- World로 바꿔줌

	3. BTT_Patrol을 구성하기 위해 Controlled Pawn에서 GetComponentByClass로 BP_PatrolComponent를 훔쳐오는데 인터페이스를 구성하는 것이 더 좋음
	- GetComponentByClass는 남발하면 안됨 -> 위험한 함수
	- 인터페이스가 아닌 형변환으로도 처리가 가능하나 기획의도랑 맞아야 함(cast하는 대상부터 자식으로 patrol 기능을 가진다거나 하는?)

	4. MoveToLocation이라는 함수로 이동시키려는 대상에 대해 Location을 주면 이동함(이 함수는 MoveTo같은 다른 이동 함수가 아니라면 명령을 끝까지 수행함)
	- Return Value로 Failed, AlreadyAtGoal, RequestSuccessful이 나오는데 이걸 switch로 활용하여 execute 실패, 다음 이동 장소 정하고 execute 성공, execute 성공 등의 처리를 함

	5. BTT_Patrol내부에서 적의 BP_PatrolComponent가 필요한데 이 변수를 얻어오는 과정을 처음 한 번만 수행하게끔 하도록 바꾼 방법은
	- BP_PatrolComponent유형의 변수를 만들어서 Valid 검사를 하고 InValid일 때만 Setting해주면 최초 시도에만 값 세팅하게 됨
	- 최초 시도 시 Component에 값 세팅해주고 나서도 valid검사를 하는데 이때 Invalid라면 실패 처리

	6. IsAtLocation 데코레이터에 잡혀있는 taget이나 MoveTo에 잡혀있는 Target이 Invalid라면 실패로 처리되는 듯
	- MoveTo의 Target이 유효해서 명령이 시작되고 나면 중간에 Target이 Invalid로 바뀌더라도 계속 따라옴 -> Target이 Invalid되면 MoveTo 실행 안 하게 하려면
	Target에 대해 위에서 데코레이터(블랙보드)로 관찰자에 대해 설정해줘야 함

	7. 강사님이 생각하시길 Task 기본 MoveTo는 Success 혹은 Fail에 도착해야 FinishExecute로 그때서야 풀어주는 거라고 하심
	- AIMoveTo에서 그냥 1) 그냥 실행 핀 2) Success 3) Fail이 있는데 아마 기본 Task인 MoveTo는 그냥 실행핀에 연결이 없는 듯
	- AIMoveTo는 그냥 실행 핀으로 빼서 FinishExecute 주면 흐름을 바로 뺄 수 있음

	8. 기존 BP_Patrol에서 Tick에서 처리하던 MoveToLocation은 사실 상 Tick 발동이 안함
	- MoveToLocation의 반환 값 3종류에서 모두 FinishExecute 해버리기 때문
	- ExecuteAI로 내용 모두 이사

	9. 공격 중 피격 당하면 다음 공격이 안되는 버그를 고치는 과제 피드백에서
	- 일단 과제의 핵심 Key는 AttackEnalbed가 맞고 OnCompleted로 흐름이 가지 못하기 때문임
	- 그래서 간단하게 생각했을 때 Montage의 OnInterrupted에서 처리하려는 생각이 잘못된 이유는
	- OnInterrupted라는 건 다른 몽타주가 재생되는 상황에도 발생되는 핀이기 때문에
	- 콤보 공격에서 다음 몽타주가 이 몽타주의 OnInterrupted를 발생시킴

	- 콤보 공격의 흐름을 정리하면
	1타 공격 발생 -> 다음 콤보로 이어질 수 있으면 BlendOut에서 다음 몽타주를 재생하라고 명령 -> 다음 몽타주 재생은 기존 몽타주에게는 OnInterrupted로 작용 및 OnCompleted로는 흐름이 가지 않음

	- 기존 몽타주 입장에서 자신이 실행중에 방해받은 것으로 처리되기 때문에 기존 몽타주가 다음 몽타주에 BlendOut이 되는 것이 아니라 다음 몽타주가 기존의 몽타주를 BlendIn하는 방식으로 처리하는 것

	10. BlendOut 관련 옵션 중에 애니메이션 시퀀스 쪽에서 <실제 BlendOut을 수행하는 시간>과 <BlendOut으로서 인지하게끔 Trigger> 시키는 시간을 다르게 줄 수 있는 옵션이 있음
	- BlendOutTriggerTime은 Default가 -1인데 BlendOutTime과 같은 값을 가지겠다는 의미임
*/