#include "PreCompile.h"
#include "Stage01BackGround.h"

Stage01BackGround::Stage01BackGround()
{
}

Stage01BackGround::~Stage01BackGround()
{
}

void Stage01BackGround::Start()
{
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();

	BackGroundRenderer = CreateComponent<GameEngineSpriteRenderer>(0);
	BackGroundRenderer->SetSprite("Stage01Background.png");
	BackGroundRenderer->SetPivotType(PivotType::Left);
	BackGroundRenderer->SetImageScale({ 12405, 1440 });
}

void Stage01BackGround::Update(float _Delta)
{
}
