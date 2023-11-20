#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ReverseActorInfo
{
public:
	float Time;
	float4 Pos;
};

// �߰��� �������� �����ǰ� 
class ReverseRendererInfo 
{
public:
	float Time;
	// ���� ���° �������� 
	int RendererIndex = -1;
	std::string_view SpriteName;
	int Frame;
};

// ���� :
class ReverseActor : public GameEngineActor
{
	// �ð��� �˸��� �ʴٸ� ���Ͻ��ѹ����ų�.
	// static float ReverseTime = 0.05f;

public:
	// constrcuter destructer
	ReverseActor();
	~ReverseActor();

	// delete Function
	ReverseActor(const ReverseActor& _Other) = delete;
	ReverseActor(ReverseActor&& _Other) noexcept = delete;
	ReverseActor& operator=(const ReverseActor& _Other) = delete;
	ReverseActor& operator=(ReverseActor&& _Other) noexcept = delete;

protected:
	void Reverse();
	void ReverseUpdate(float _DeltaTime);

private:
	// �̰� true�� 
	bool IsReverse = false;
	std::vector<std::shared_ptr<GameEngineSpriteRenderer>> Renderers;

	std::list<ReverseActorInfo> ActorInfo;
	std::list<ReverseRendererInfo> RendererInfo;
};

