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
	BackGroundRender = CreateComponent<GameEngineSpriteRenderer>(0);
	BackGroundRender->SetSprite("SelectBackground.png");

	std::string_view Temp_Name[2][4] = {
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

	std::pair<float, float> Temp_Location[4] = {
		{-430.f, 180.f},
		{-140.f, 180.f},
		{140.f, 180.f},
		{430.f, 180.f},
	};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SelectCheck[i][j] = CreateComponent<GameEngineSpriteRenderer>(1);
			SelectCheck[i][j]->SetSprite(Temp_Name[i][j].data());
			SelectCheck[i][j]->Transform.SetLocalPosition({ Temp_Location[j].first, Temp_Location[j].second, 0.f, 0.f });
			SelectCheck[i][j]->Off();
		}
	}
}

void SelectScene::Update(float _Delta)
{
	ToggleTimer += _Delta;

	if (MoveTimer <= 0.3f) MoveTimer += _Delta;

	for (int i = 0; i < 4; i++) SelectCheck[ColorTurn][i]->Off();

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
}
