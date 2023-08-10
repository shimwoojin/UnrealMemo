#pragma once
/*
	1. SetupAttachment로 생성자에서 누가 누구의 부모 컴포넌트가 될지를 정하는 경우가 대부분인데 예외가 있음
	- Mesh 계열에서 소켓의 위치로 attach 하려는 경우 SetupAttachment로 불가능함
	- 이 때 사용할 수 있는 함수가 AttachToComponent이고
	- 이 함수의 처리 위치는 OnConstruction으로 잡게 됨

	- 생성자가 아닌 OnConstruction인 이유가 있는데 생성자가 적용되는 시점에서 SkeletalMeshComponent에 SkeletalMesh가 적용이 안 되어 있을 수 있고
	적용이 안 되어 있다면 소켓 네임을 적용시켜줘도 Root에 붙게 될 것임
	- 스켈레탈 메쉬가 무엇인지 모르고 소켓에 attach 해야 하는 특수한 상황 탓에
	- OnConstruction에서 AttachToComponent로 처리하는 것임

	2. 생성 패턴 - 빌더
	- 이 패턴이 적합한 상황은 소비형 아이템에 대해 개별 클래스로 분화하게 되면 수많은 클래스들이 생길 것이고 이 상황은 오히려 관리하기에 악조건이 된다는 것
	
	StudentBuilder& SetName(FString const Name)
	{
		this->Name = Name;
		return * this;
	}

	StudentBuilder& SetID(int32 ID)
	{
		this->ID = ID;
		return * this;
	}

	Student* Build()
	{
		return new Student(ID, Name, Grade, PhoneNumber);
	}

	void Function()
	{
		Student* S = StudentBuilder()
						.SetID(123)
						.SetName("woojin")
						.Build();
	}

	- 핵심은 생성하고자 하는 클래스가 있고 그 클래스를 생성해주는 builder 클래스가 있을 때
	- 그 builder 클래스가 생성하고자 하는 클래스의 속성들에 대해 setting을 하는 것이고
	- setting을 하고 나서 builder 자신을 반환함으로서 연쇄적으로 코드를 작성할 수 있게끔 하는 것
	- 또한 생성할 클래스에 대해 Build라는 함수로 생성까지 담당하는 것까지가 빌더 패턴이라 할 수 있을 것 같다

	- 언뜻 보기엔 생성할 클래스의 생성자에서 인자를 다 받아서 처리해도 되는 것으로 생각할 수도 있으나
	- Builder 패턴을 씀으로서 기본값에 대해선 유지하고 변경할 속성에 대해서만 변경하여 적용시켜 줄 수 있음
	
*/