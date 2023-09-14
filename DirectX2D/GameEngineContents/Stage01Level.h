#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class Stage01Level : public GameEngineLevel
{
public:
	// constrcuter destructer
	Stage01Level();
	~Stage01Level();

	// delete Function
	Stage01Level(const Stage01Level& _Other) = delete;
	Stage01Level(Stage01Level&& _Other) noexcept = delete;
	Stage01Level& operator=(const Stage01Level& _Other) = delete;
	Stage01Level& operator=(Stage01Level&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	GameEngineSoundPlayer MainBGM;

	std::shared_ptr<class Stage01BackGround> BackGround;
	std::shared_ptr<class Stage01Map> MainMap;
};

