#include "PreCompile.h"
#include "Stage01Map.h"

Stage01Map::Stage01Map()
{
}

Stage01Map::~Stage01Map()
{
}

void Stage01Map::Start()
{
	float4 WindowScale = GameEngineCore::MainWindow.GetScale();

	StageMapRenderer = CreateComponent<GameEngineSpriteRenderer>(1);
	StageMapRenderer->SetSprite("Stage01Map.png");
	StageMapRenderer->SetPivotType(PivotType::Left);
	StageMapRenderer->SetImageScale({ 12515, 920 });
}

void Stage01Map::Update(float _Delta)
{
}
