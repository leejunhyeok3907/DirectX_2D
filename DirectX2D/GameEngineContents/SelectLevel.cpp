#include "PreCompile.h"
#include "SelectLevel.h"
#include "SelectScene.h"

SelectLevel::SelectLevel()
	: timer(0)
	, DoOnce(false)
	, IsOpen{false, }
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

		std::vector<GameEngineDirectory> Directorys = Dir.GetAllDirectory();

		for (size_t i = 0; i < Directorys.size(); i++)
		{
			GameEngineDirectory& Dir = Directorys[i];

			GameEngineSprite::CreateFolder(Dir.GetStringPath());
		}

		GameEngineSprite::CreateSingle("SelectBackground.png");
		GameEngineSprite::CreateSingle("DoorClosed1.png");
		GameEngineSprite::CreateSingle("DoorClosed2.png");
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
		GameEngineSprite::CreateSingle("Black.png");
	}

	GetMainCamera()->Transform.SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	GetMainCamera()->SetProjectionType(EPROJECTIONTYPE::Orthographic);

	SelectSceneObject = CreateActor<SelectScene>(ContentsObjectType::BackGround);
}

void SelectLevel::Update(float _Delta)
{
	if (timer < 10.f) timer += _Delta;

	if (false == IsEveryDoorOpen()) DoorOpen();

	if (false == DoOnce)
	{
		if (timer > 3.f)
		{
			DoOnce = true;
			SelectSceneObject->SelectAllow();
		}
	}

}

void SelectLevel::LevelStart(GameEngineLevel* _PrevLevel)
{
	SelectBGM=GameEngineSound::SoundPlay("SelectBgm.mp3");
}

void SelectLevel::LevelEnd(GameEngineLevel* _NextLevel)
{
	SelectBGM.Stop();
}

void SelectLevel::DoorOpen()
{
	float Door1OpenTiming = 1.5f;
	float Door2OpenTiming = 1.0f;
	float Door3OpenTiming = 1.3f;
	float Door4OpenTiming = 1.1f;

	if (false == IsOpen[0])
	{
		if (timer > Door1OpenTiming)
		{
			IsOpen[0] = true;
			SelectSceneObject->StartOpenDoor(0);
		}
	}

	if (false == IsOpen[1])
	{
		if (timer > Door2OpenTiming)
		{
			IsOpen[1] = true;
			SelectSceneObject->StartOpenDoor(1);
		}
	}

	if (false == IsOpen[2])
	{
		if (timer > Door3OpenTiming)
		{
			IsOpen[2] = true;
			SelectSceneObject->StartOpenDoor(2);
		}
	}

	if (false == IsOpen[3])
	{
		if (timer > Door4OpenTiming)
		{
			IsOpen[3] = true;
			SelectSceneObject->StartOpenDoor(3);
		}
	}
}

bool SelectLevel::IsEveryDoorOpen()
{
	return IsOpen[0] && IsOpen[1] && IsOpen[2] && IsOpen[3];
}
