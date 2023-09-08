#include "PreCompile.h"
#include "SelectScene.h"

SelectScene::SelectScene()
	: ToggleTimer(0.f)
	, MoveTimer(0.f)
	, ColorTurn(0)
	, SelectNum(0)
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::Start()
{
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();

	BackGroundRender = CreateComponent<GameEngineSpriteRenderer>(0);
	BackGroundRender->SetSprite("SelectBackground.png");
	BackGroundRender->SetImageScale(WindowScale);

	std::string_view SelectCheck_Name[2][4] = {
		{
			"Select1R.png",
			"Select2R.png",
			"Select3R.png",
			"Select4R.png",
		},
		{
			"Select1Y.png",
			"Select2Y.png",
			"Select3Y.png",
			"Select4Y.png",
		}
	};

	std::pair<float, float> SelectCheck_Location[4] = {
		{-430.f, 177.f},
		{-142.f, 177.f},
		{140.f, 177.f},
		{430.f, 177.f},
	};

	std::string_view CharacterFace_Name[4][3] = {
		{
			"Marco1.png",
			"Marco2.png",
			"Marco3.png"
		},
		{
			"Eri1.png",
			"Eri2.png",
			"Eri3.png",
		},
		{
			"Tarma1.png",
			"Tarma2.png",
			"Tarma3.png",
		},
		{
			"Pio1.png",
			"Pio2.png",
			"Pio3.png",
		}
	};

	std::pair<float, float> CharcterFace_Location[4] = {
		{-430.f, -64.f},
		{-141.f, -64.f},
		{143.f, -64.f},
		{430.f, -64.f},
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SelectCheck[i][j] = CreateComponent<GameEngineSpriteRenderer>(1);
			SelectCheck[i][j]->SetSprite(SelectCheck_Name[i][j].data());
			SelectCheck[i][j]->Transform.SetLocalPosition({ SelectCheck_Location[j].first, SelectCheck_Location[j].second, 0.f, 0.f });
			SelectCheck[i][j]->SetImageScale({ 270.f, 95.f });
			SelectCheck[i][j]->Off();
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CharacterFace[i][j] = CreateComponent<GameEngineSpriteRenderer>(1);
			CharacterFace[i][j]->SetSprite(CharacterFace_Name[i][j].data());
			CharacterFace[i][j]->Transform.SetLocalPosition({ CharcterFace_Location[i].first, CharcterFace_Location[i].second, 0.f, 0.f });
			CharacterFace[i][j]->SetImageScale({ 270.f, 385.f, 0.f, 0.f });
			CharacterFace[i][j]->Off();
		}
	}

	DoorCloseEffect = CreateComponent<GameEngineSpriteRenderer>(1);
	DoorCloseEffect->CreateAnimation("DoorEffect", "DoorCloseEffect", 0.1f, -1, -1, true);
	DoorCloseEffect->ChangeAnimation("DoorEffect");
	DoorCloseEffect->Transform.SetLocalPosition({ -430.f, -260.f });
	DoorCloseEffect->SetImageScale({ 330.f, 100.f });
	//DoorCloseEffect->AnimationPauseOn();
}

void SelectScene::Update(float _Delta)
{
	ToggleTimer += _Delta;

	if (MoveTimer <= 0.3f) MoveTimer += _Delta;

	for (int i = 0; i < 4; i++) SelectCheck[ColorTurn][i]->Off();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CharacterFace[i][j]->Off();
		}
	}

	if (ToggleTimer > 0.5f)
	{
		ToggleTimer -= 0.5f;
		ColorTurn = (ColorTurn == 0) ? 1 : 0;
	}

	if (MoveTimer >= 0.3f)
	{
		if (GameEngineInput::IsPress(VK_LEFT) || GameEngineInput::IsPress('A'))
		{
			MoveTimer -= 0.3f;
			SelectNum--;

			if (SelectNum <= -1) SelectNum += 4;
		}

		if (GameEngineInput::IsPress(VK_RIGHT) || GameEngineInput::IsPress('D'))
		{
			MoveTimer -= 0.3f;
			SelectNum++;

			if (SelectNum >= 4) SelectNum -= 4;
		}
	}

	SelectCheck[ColorTurn][SelectNum]->On();

	for (int i = 0; i < 4; i++)
	{
		if (SelectNum == i)
		{
			CharacterFace[i][static_cast<int>(EFaceType::Selected)]->On();
		}
		else
		{
			CharacterFace[i][static_cast<int>(EFaceType::NotSelected)]->On();
		}
	}
}
