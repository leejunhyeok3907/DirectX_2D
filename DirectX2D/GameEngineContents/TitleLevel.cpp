#include "PreCompile.h"
#include "TitleLevel.h"
#include "TitleScene.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Start()
{
	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		Dir.MoveChild("TitleTexture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateSingle("MainTitle.png");
		GameEngineSprite::CreateSingle("InsertCoin.png");
	}

	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	std::shared_ptr<TitleScene> Object = CreateActor<TitleScene>(ContentsObjectType::BackGround);
}


void TitleLevel::Update(float _Delta)
{
	if (GameEngineInput::IsPress(VK_SPACE))
	{
		GameEngineCore::ChangeLevel("SelectLevel");
	}
}


void TitleLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	GameEngineSound::SoundPlay("TitleBgm.mp3");
}

void TitleLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}