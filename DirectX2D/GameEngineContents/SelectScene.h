#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class EFaceType
{
	NotSelected,
	Selected,
	SelectCheck,
	Max
};

enum class EMoveType
{
	Open,
	Close,
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
	std::shared_ptr<GameEngineSpriteRenderer> Door[4];

	std::pair<float, float> CharcterFace_Location[4];


	float ToggleTimer;
	float MoveTimer;
	int ColorTurn;
	int SelectNum;
	bool MoveDoor[4][2];
	float DoorSpeed[4];

	bool SelectOnce;
	bool SelectRestrict;

public:
	void StartOpenDoor(int _DoorNum);
	void StartCloseDoor(int _DoorNum);
	void DoorUpdate(float _Delta);
	void InputUpdate();

	void ToggleLamp();
	void TurnOnImages();
	void TurnOffImages();

	void SelectAllow();
};

