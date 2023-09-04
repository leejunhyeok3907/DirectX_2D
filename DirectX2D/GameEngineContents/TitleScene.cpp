#include "PreCompile.h"
#include "TitleScene.h"

TitleScene::TitleScene()
	: ToggleTimer(0.f)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Start()
{
	TitleRenderer = CreateComponent<GameEngineSpriteRenderer>(0);
	TitleRenderer->SetSprite("MainTitle.png");

	float4 Position;
	Position.Y = -225.f;

	InsertCoin = CreateComponent<GameEngineSpriteRenderer>(1);
	InsertCoin->SetSprite("InsertCoin.png");
	InsertCoin->Transform.SetLocalPosition(Position);
}

void TitleScene::Update(float _Delta)
{
	ToggleTimer += _Delta;

	if (ToggleTimer > 3.f)
	{
		ToggleTimer -= 3.f;
	}
}
