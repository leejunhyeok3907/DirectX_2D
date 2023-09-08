#include "PreCompile.h"
#include "SelectLevel.h"
#include "SelectScene.h"

SelectLevel::SelectLevel()
{
}

SelectLevel::~SelectLevel()
{
}

void SelectLevel::Start()
{
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		Dir.MoveChild("SelectTexture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateSingle("SelectBackground.png");
		GameEngineSprite::CreateSingle("DoorClose.png");
		GameEngineSprite::CreateSingle("Select1R.png");
		GameEngineSprite::CreateSingle("Select2R.png");
		GameEngineSprite::CreateSingle("Select3R.png");
		GameEngineSprite::CreateSingle("Select4R.png");
		GameEngineSprite::CreateSingle("Select1Y.png");
		GameEngineSprite::CreateSingle("Select2Y.png");
		GameEngineSprite::CreateSingle("Select3Y.png");
		GameEngineSprite::CreateSingle("Select4Y.png");
		GameEngineSprite::CreateSingle("Marco1.png");
		GameEngineSprite::CreateSingle("Marco2.png");
		GameEngineSprite::CreateSingle("Marco3.png");
		GameEngineSprite::CreateSingle("Eri1.png");
		GameEngineSprite::CreateSingle("Eri2.png");
		GameEngineSprite::CreateSingle("Eri3.png");
		GameEngineSprite::CreateSingle("Tarma1.png");
		GameEngineSprite::CreateSingle("Tarma2.png");
		GameEngineSprite::CreateSingle("Tarma3.png");
		GameEngineSprite::CreateSingle("Pio1.png");
		GameEngineSprite::CreateSingle("Pio2.png");
		GameEngineSprite::CreateSingle("Pio3.png");
	}

	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	std::shared_ptr<SelectScene> Title = CreateActor<SelectScene>(ContentsObjectType::BackGround);
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
