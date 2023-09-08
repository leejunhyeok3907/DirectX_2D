#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class EFaceType
{
	NotSelected,
	Selected,
	SelectCheck,
	Max
};

class SelectScene : public GameEngineActor
{
public:
	// constrcuter destructer
	SelectScene();
	~SelectScene();

	// delete Function
	SelectScene(const SelectScene& _Other) = delete;
	SelectScene(SelectScene&& _Other) noexcept = delete;
	SelectScene& operator=(const SelectScene& _Other) = delete;
	SelectScene& operator=(SelectScene&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<GameEngineSpriteRenderer> BackGroundRender;
	std::shared_ptr<GameEngineSpriteRenderer> SelectCheck[2][4];
	std::shared_ptr<GameEngineSpriteRenderer> CharacterFace[4][3];
	std::shared_ptr<GameEngineSpriteRenderer> DoorCloseEffect;


	float ToggleTimer;
	float MoveTimer;
	int ColorTurn;
	int SelectNum;
};

