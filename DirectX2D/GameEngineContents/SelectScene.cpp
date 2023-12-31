#include "PreCompile.h"
#include "SelectScene.h"

SelectScene::SelectScene()
	: ToggleTimer(0.f)
	, MoveTimer(0.f)
	, ColorTurn(0)
	, SelectNum(0)
	, SelectOnce(false)
	, DoorSpeed{0, }
	, SelectRestrict(true)
	, MoveDoor{false, }
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::Start()
{
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();

	{
		std::shared_ptr<GameEngineSpriteRenderer> Black = CreateComponent<GameEngineSpriteRenderer>(0);
		Black->SetSprite("Black.png");
		Black->SetImageScale(WindowScale);
	}

	BackGroundRender = CreateComponent<GameEngineSpriteRenderer>(2);
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

	CharcterFace_Location[0] = { -430.f, -64.f };
	CharcterFace_Location[1] = { -141.f, -64.f };
	CharcterFace_Location[2] = { 143.f, -64.f };
	CharcterFace_Location[3] = { 430.f, -64.f };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SelectCheck[i][j] = CreateComponent<GameEngineSpriteRenderer>(3);
			SelectCheck[i][j]->SetSprite(SelectCheck_Name[i][j].data());
			SelectCheck[i][j]->Transform.SetLocalPosition({ SelectCheck_Location[j].first, SelectCheck_Location[j].second});
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
			CharacterFace[i][j]->Transform.SetLocalPosition({ CharcterFace_Location[i].first, CharcterFace_Location[i].second });
			CharacterFace[i][j]->SetImageScale({ 270.f, 385.f });
			CharacterFace[i][j]->Off();
		}
	}

	DoorCloseEffect = CreateComponent<GameEngineSpriteRenderer>(3);
	DoorCloseEffect->CreateAnimation("DoorEffect", "DoorCloseEffect", 0.1f, -1, -1, false);
	DoorCloseEffect->ChangeAnimation("DoorEffect");
	DoorCloseEffect->Transform.SetLocalPosition({ -430.f, -260.f });
	DoorCloseEffect->SetImageScale({ 330.f, 100.f });
	DoorCloseEffect->AnimationPauseOn();


	for (int i = 0; i < 4; i++)
	{
		Door[i] = CreateComponent<GameEngineSpriteRenderer>(1);
		Door[i]->SetSprite("DoorClosed1.png");
		Door[i]->Transform.SetLocalPosition({ CharcterFace_Location[i].first, CharcterFace_Location[i].second });
		Door[i]->SetImageScale({ 270.f, 430.f });
	}
}

void SelectScene::Update(float _Delta)
{
	ToggleTimer += _Delta;

	if (MoveTimer <= 0.3f) MoveTimer += _Delta;

	TurnOffImages();

	ToggleLamp();

	DoorUpdate(_Delta);

	InputUpdate();

	TurnOnImages();
}

void SelectScene::StartOpenDoor(int _DoorNum)
{
	MoveDoor[_DoorNum][static_cast<int>(EMoveType::Open)] = true;

	Door[_DoorNum]->SetSprite("DoorClosed1.png");
	Door[_DoorNum]->SetImageScale({ 270.f, 430.f });

	DoorSpeed[_DoorNum] = -250.f;
}

void SelectScene::StartCloseDoor(int _DoorNum)
{
	MoveDoor[_DoorNum][static_cast<int>(EMoveType::Close)] = true;

	Door[_DoorNum]->SetSprite("DoorClosed2.png");
	Door[_DoorNum]->SetImageScale({ 270.f, 430.f });

	DoorSpeed[_DoorNum] = 0.f;
}

void SelectScene::DoorUpdate(float _Delta)
{
	for (int i = 0; i < 4; i++)
	{
		if (true == MoveDoor[i][static_cast<int>(EMoveType::Open)])
		{
			float Loc = Door[i]->Transform.GetWorldPosition().Y;

			if (DoorSpeed[i] < 500.f)
			{
				DoorSpeed[i] += 35.f;
			}

			if (Loc < 350.f)
			{
				Door[i]->Transform.AddLocalPosition(float4::UP * _Delta * DoorSpeed[i]);
			}
			else
			{
				MoveDoor[i][static_cast<int>(EMoveType::Open)] = false;
			}
		}

		if (true == MoveDoor[i][static_cast<int>(EMoveType::Close)])
		{
			float Loc = Door[i]->Transform.GetWorldPosition().Y;

			if (DoorSpeed[i] < 500.f)
			{
				DoorSpeed[i] += 50.f;
			}

			if (Loc > CharcterFace_Location[i].second)
			{
				Door[i]->Transform.AddLocalPosition(float4::DOWN * _Delta * DoorSpeed[i]);
			}
			else
			{
				float4 DoorCloseEffectPos = DoorCloseEffect->Transform.GetWorldPosition();
				MoveDoor[i][static_cast<int>(EMoveType::Close)] = false;

				DoorCloseEffectPos.X = CharcterFace_Location[i].first;

				DoorCloseEffect->Transform.SetLocalPosition(DoorCloseEffectPos);
				DoorCloseEffect->AnimationPauseOff();
			}
		}
	}
}

void SelectScene::InputUpdate()
{
	if (false == SelectRestrict)
	{
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

 		if (GameEngineInput::IsPress(VK_SPACE))
		{
			SelectOnce = true;
			SelectRestrict = true;

 			StartCloseDoor(SelectNum);
		}
	}

}

void SelectScene::ToggleLamp()
{
	if (ToggleTimer > 0.5f)
	{
		ToggleTimer -= 0.5f;
		ColorTurn = (ColorTurn == 0) ? 1 : 0;
	}
}

void SelectScene::TurnOnImages()
{
	int FaceType;
	
	SelectCheck[ColorTurn][SelectNum]->On();

	for (int i = 0; i < 4; i++)
	{
		FaceType = static_cast<int>((SelectOnce == true) ? EFaceType::SelectCheck : EFaceType::Selected);

		if (SelectNum == i)
		{
			CharacterFace[i][FaceType]->On();
		}
		else
		{
			CharacterFace[i][static_cast<int>(EFaceType::NotSelected)]->On();
		}
	}
}

void SelectScene::TurnOffImages()
{
	for (int i = 0; i < 4; i++) SelectCheck[ColorTurn][i]->Off();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CharacterFace[i][j]->Off();
		}
	}
}

void SelectScene::SelectAllow()
{
	SelectRestrict = false;
	SelectOnce = false;
}
