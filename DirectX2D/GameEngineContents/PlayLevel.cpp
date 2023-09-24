#include "PreCompile.h"
#include "PlayLevel.h"
#include "Player.h"
#include "PlayMap.h"
#include "Monster.h"
#include "TileMap.h"

PlayLevel::PlayLevel() 
{
}

PlayLevel::~PlayLevel() 
{
}

void PlayLevel::Start()
{
	GameEngineCore::GetBackBufferRenderTarget()->SetClearColor({0, 0, 0, 1});


	{
		// 엔진용 쉐이더를 전부다 전부다 로드하는 코드를 친다.
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("Texture");
		std::vector<GameEngineFile> Files = Dir.GetAllFile();

		for (size_t i = 0; i < Files.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineFile& File = Files[i];
			GameEngineTexture::Load(File.GetStringPath());
		}

		GameEngineSprite::CreateCut("TestPlayer.png", 6, 6);
	}

	{
		GameEngineDirectory Dir;
		Dir.MoveParentToExistsChild("GameEngineResources");
		Dir.MoveChild("ContentsResources");
		Dir.MoveChild("FolderTexture");
		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			// 구조적으로 잘 이해하고 있는지를 자신이 명확하게 인지하기 위해서
			GameEngineDirectory& Dir = Directorys[i];

			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}

		GameEngineSprite::CreateCut("TestPlayer.png", 6, 6);
		GameEngineSprite::CreateSingle("TestMap.png");
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();

	GetMainCamera()->Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f});
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);


	{
		std::shared_ptr<Player> Object = CreateActor<Player>(ContentsObjectType::Player);
		PlayerObject = Object;
	}

	{
		//GameEngineRandom NewRanadom;
		//for (size_t i = 0; i < 10; i++)
		//{
		//	std::shared_ptr<Monster> Object = CreateActor<Monster>(ContentsObjectType::Monster);
		//	Object->Transform.SetLocalPosition(NewRanadom.RandomVectorBox2D(0, 1280, 0, -720));
		//}

		//std::shared_ptr<PlayMap> Object0 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object1 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object2 = CreateActor<PlayMap>(ContentsObjectType::Monster);
		//std::shared_ptr<PlayMap> Object3 = CreateActor<PlayMap>(ContentsObjectType::Monster);
	}

	{
		std::shared_ptr<PlayMap> Object = CreateActor<PlayMap>(ContentsObjectType::BackGround);
		Map = Object;
	}

	//{
	//	std::shared_ptr<TileMap> Object = CreateActor<TileMap>(ContentsObjectType::BackGround);

	//	size_t TileX = 300;
	//	size_t TileY = 300;

	//	Object->TileRenderer->CreateTileMap({ TileX, TileY, {32, 32}, "HoHoYee_AttackABC" });
	//	Object->TileRenderer->SetSamplerState(SAMPLER_OBJECT::LINEAR);

	//	for (size_t y = 0; y < TileY; y++)
	//	{
	//		for (size_t x = 0; x < TileX; x++)
	//		{
	//			Object->TileRenderer->SetTileIndex({y, x});
	//		}
	//	}

	//	TileMapObject = Object;
	//}
}

void PlayLevel::Update(float _Delta)
{
}

void PlayLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	int a = 0;
}

void PlayLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	int a = 0;
}
