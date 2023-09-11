#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class SelectLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	SelectLevel();
	~SelectLevel();

	// delete Function
	SelectLevel(const SelectLevel& _Other) = delete;
	SelectLevel(SelectLevel&& _Other) noexcept = delete;
	SelectLevel& operator=(const SelectLevel& _Other) = delete;
	SelectLevel& operator=(SelectLevel&& _Other) noexcept = delete;

protected:
	void Start() override;

	void Update(float _Delta) override;

	void LevelStart(GameEngineLevel* _PrevLevel) override;
	void LevelEnd(GameEngineLevel* _NextLevel) override;

private:
	std::shared_ptr<class SelectScene> SelectSceneObject;

	float timer;
	bool IsOpen[4];

private:
	void DoorOpen();
	bool IsEveryDoorOpen();
};

