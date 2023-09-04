#pragma once
#include <GameEngineCore/GameEngineActor.h>


class TitleScene : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleScene();
	~TitleScene();

	// delete Function
	TitleScene(const TitleScene& _Other) = delete;
	TitleScene(TitleScene&& _Other) noexcept = delete;
	TitleScene& operator=(const TitleScene& _Other) = delete;
	TitleScene& operator=(TitleScene&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> TitleRenderer;
	std::shared_ptr<GameEngineSpriteRenderer> InsertCoin;

	float ToggleTimer;
};

