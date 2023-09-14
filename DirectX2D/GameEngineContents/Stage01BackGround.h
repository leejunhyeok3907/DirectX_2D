#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Stage01BackGround : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage01BackGround();
	~Stage01BackGround();

	// delete Function
	Stage01BackGround(const Stage01BackGround& _Other) = delete;
	Stage01BackGround(Stage01BackGround&& _Other) noexcept = delete;
	Stage01BackGround& operator=(const Stage01BackGround& _Other) = delete;
	Stage01BackGround& operator=(Stage01BackGround&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> BackGroundRenderer;
};

