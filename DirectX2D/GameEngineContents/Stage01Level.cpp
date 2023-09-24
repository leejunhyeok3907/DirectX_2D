#include "PreCompile.h"
#include "Stage01Level.h"
#include "Stage01BackGround.h"
#include "Stage01Map.h"
#include "PlayerCharacter.h"

Stage01Level::Stage01Level()
{
}

Stage01Level::~Stage01Level()
{
}

void Stage01Level::Start()
{
	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({ 0, 0, 0, 1 });

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		Dir.MoveChild("Stage01");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateSingle("Stage01Background.png");
		GameEngineSprite::CreateSingle("Stage01Map.png");
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		Dir.MoveChild("PlayerCharacter");
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];
			std::vector<GameEngineDirectory> InnerDirectorys = Dir.GetAllDirectory();

			for (size_t i = 0; i < InnerDirectorys.size(); i++)
			{
				std::string str = InnerDirectorys[i].GetStringPath();

				GameEngineSprite::CreateFolder(str);
			}
		}
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y / 2, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	{
		//BackGround = CreateActor<Stage01BackGround>(ContentsObjectType::BackGround);

		MainMap = CreateActor<Stage01Map>(ContentsObjectType::BackGround);
		MainMap->Transform.SetLocalPosition({ 0.f, -250.f });
	}

	{
		std::shared_ptr<PlayerCharacter> Object = CreateActor<PlayerCharacter>(ContentsObjectType::BackGround);
		Object->Transform.SetLocalPosition({ 500.f, -250.f });
	}
}

void Stage01Level::Update(float _Delta)
{
	//if (GameEngineInput::IsPress('A'))
	//{
	//	GetMainCamera()->Transform.AddLocalPosition(float4::LEFT * _Delta * 1000.f);
	//}

	//if (GameEngineInput::IsPress('D'))
	//{
	//	GetMainCamera()->Transform.AddLocalPosition(float4::RIGHT * _Delta * 1000.f);
	//}

	//if (GameEngineInput::IsPress('W'))
	//{
	//	GetMainCamera()->Transform.AddLocalPosition(float4::UP * _Delta * 500.f);
	//}

	//if (GameEngineInput::IsPress('S'))
	//{
	//	GetMainCamera()->Transform.AddLocalPosition(float4::DOWN * _Delta * 500.f);
	//}
}

void Stage01Level::LevelStart(GameEngineLevel* _PrevLevel)
{
	//MainBGM= GameEngineSound::SoundPlay("SelectBgm.mp3");
}

void Stage01Level::LevelEnd(GameEngineLevel* _NextLevel)
{
}
