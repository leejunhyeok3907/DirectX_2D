#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Stage01Map : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage01Map();
	~Stage01Map();

	// delete Function
	Stage01Map(const Stage01Map& _Other) = delete;
	Stage01Map(Stage01Map&& _Other) noexcept = delete;
	Stage01Map& operator=(const Stage01Map& _Other) = delete;
	Stage01Map& operator=(Stage01Map&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> StageMapRenderer;
};

