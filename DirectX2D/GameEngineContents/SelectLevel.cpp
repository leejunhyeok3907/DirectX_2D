#include "PreCompile.h"
#include "SelectLevel.h"

SelectLevel::SelectLevel()
{
}

SelectLevel::~SelectLevel()
{
}

void SelectLevel::Start()
{
	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);
}

void SelectLevel::Update(float _Delta)
{
}

void SelectLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
}

void SelectLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
}
