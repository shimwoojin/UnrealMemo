#pragma once
/*
	1. �ɺ��� ���� �θ��� ���� �����ڸ� �� �� ����
	- public : ���� �ϴܿ� �ϰ͵� x, proteced : * , private : �ڹ���� ��� ����
	
	2. Setter, Getter�� ������ �̰ɷ� ����
	- SetRootComponent�� �ص� �θ��� proteced ���� RootComponent�� ���� �ִ� �� �������� SetRootComponent() �Լ��� ���ϸ� �߰����� �۾��� ������

	3. CreateDefaultSubobject, SetupAttachment���� �Լ��� �����ڿ����� �� �� �ִ� Construction �Լ���
	- CretaeDefaultSubobject�� �����ϴ� NonConsturction �Լ��� NewObject ��
	- Actor�� GetWorld()->SpawnActor()

	4. Root = CreateDefaultSubobject<USceneComponent("Root"); �� ���� ��
	- ���ø� �Լ��� ��ȯ ���� Root�� �����Ϳ� ��ȯ �޴� ����
	- ���� ��� USceneComponent�� ����Ͽ����� ���ø� �Լ� �߿� ���ڷ� USceneComponent�� �޴´ٰ� �����ϸ� ���ø� ���� ���̵� Ÿ�� �߷��� ������
	- ���� ���� ���ڷ� �޴� USceneComponent ���ڰ� ���� ������ �츮�� ���ø� ���ڸ� ���� ��������� ��

	5. ��� �ڵ��� �ϱ� ���� ��ũ�θ� �� �Ẹ��
	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<>("#Component")

	- �ϴ� �������� ���� �� �� ���� -> ������ ���ø� ���ڸ� ä����� �ϴµ� ������ �̸����κ��� ���� Ÿ�������� �˾Ƴ��� ��

	- decltype(*Component)���� �ϰ� �Ǹ� Component& ���� ���� �� ���� -> ������ ������ ���� �������� ���� decltype�� ������ �� ���۷����� ���������� �� �𸣰���

	- &�� ����� �ϴ� ��Ȳ��
	
	- <type_traits> ��� �߰����ְ�

	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<std::remove_reference<decltype(*Component)>::type>("#Component")

	- #define CreateDefaultSubObjectAuto(Component)\
	Component = CreateDefaultSubobject<std::remove_reference_t<decltype(*Component)>>("#Component")
	
	- �� ����ü�� ����� ��� ������� �߿� type�̶�� ������ ���۷����� ���� ���� Ÿ���� ���� ������

	6. �͸���ü�� decltype�� ���� ������ �� ����
	- struct
	{
	int i1;
	int i2;
	} ii;

	decltype(ii) ii2;

	7. #define PI 3.14 �� ������ ������ ����(��ó��)�ǰ� ������ �ڵ忡�� 3.14�� �����־ ������ �Ұ�����
	- const ������ Ȱ��

	8. ������ �⺻ ���� �� tick�� ���ִ� �ڵ嵵 �ڵ����� �����µ� �� �ڵ带 �����ְ� �Ǹ� Actor�� tick�� �۵����� ����
	- Actor�� ���� Component�ʹ� ����

	9. ������ ���忡�� tick�� ���� ũ�� 2������ �����ϸ� 1) ���� tick 2) ���� tick
	- ���� tick �� collision�� ���ؼ� �����ϰ� �����ϸ� collision �����ؼ� ������ �������� block�ϰŰ� �������� overlap�ϰŰ� ���س����ſ� ���� �� ������ ������ actor���� �浹�߳� Ȯ���غ���
	�浹������ �� actor�鿡�� '�� �浹����', '�� ������'�� callback���� �����ִ� ����

	10. ������ ���ε����ִ� 4���� ���
	- 1) �������� ���� 2) ����Ʈ ���۷��� 3) ConstructorHelpers::FObjectFinder<����> ������(���) 4) �������� ������(Ȥ�� ������) ������ C++���� ConsturctionScript���� ����
	- �� 4�������� ��� FM�� �����ڿ��� AssetManager�� Ȱ���ϴ� ��(������ ������ ����̴ϱ� ��û ���߿� �غ�����)

	11. ����Ʈ ���۷����� ?
	- ��θ� ���� �ִ� ��
	- �� ������ Ȱ���Ϸ��� �ε��ؼ� �� ������� ���� Ȱ�� ������
	- ���� Ȥ�� �񵿱⸦ �� �� �ִµ�(����� �츮�� ���� �ð��� ���� Ÿ�Ӷ���, �񵿱�� �ٸ� Ÿ�Ӷ���(�ٸ� �������� ��))
	- �񵿱⸦ ����Կ� �־� �ᱹ Completed ���� Ȱ���ؾ� �ϴµ� Completed ������ ������ Ȱ���Ϸ��� None��

	- C++ ������ ǥ���ϰ� �Ǹ� TSoftObjectPtr<>(����Ʈ ������Ʈ ���۷���), TSoftClassPtr<>(����Ʈ Ŭ���� ���۷���)

	12. �𸮾󿡼� ��� ������ ����� ���������� �Ұ�����(Ȥ�� ���ڵ� ���� �̸� ����� �ȵ�)
	- this�� ���̰� �ǹ�����

	13. C++�� ������ ���� Ȱ���Կ� �־ C++�� �����ڴ� ������ �����ص� ���� �о�� �� ����
	- �ּ� ConstructionScript Ȥ�� Beginplay�� �Ǿ�� ��

	14. void OnConstruction(FTransform const& Transform) override;
	- ConstructionScript�� C++ ���� �̸�

	15. Ctrl + . -> ���� ������ �������� ���� ����
	- ���ڸ������� �� �а� ���� �ؾ� �ٷ� �������

	16. Super�� ����ȭ -> �θ��� �Լ��� �����޾Ҵٸ�
	- �� �θ��� �Լ��� ������庸�� �츮 ������ �� ���ư��� �� �����Ѵٸ�,,

	17. ���� �߿� ������ �� �� ���ٸ� ���� ��� -> ctrl + break / ���� : ctrl + shift + b

	18. ���� ConstructorHelpers::FObjectFinder<>�� NonConsturction ������(NonConstruction�̶� ���� �����ڰ� �ƴ� �̶� �� �� ����)
	- UStaticMesh* MyMesh = LoadObject<UStaticMesh>(this, TEXT("StaticMesh'/Game/Cube.Cube'"));
	- UObject* MyMesh2 = StaticLoadObject(UstaticMesh::StaticClass(), this, TEXT("StaticMesh'/Game/Cube.Cube'"));
*/