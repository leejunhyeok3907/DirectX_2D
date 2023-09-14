#include "PreCompile.h"
#include "ContentsCore.h"

#include <GameEngineCore/GameEngineSampler.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include "PlayLevel.h"
#include "SelectLevel.h"
#include "TitleLevel.h"

ContentsCore::ContentsCore() 
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::Start()
{
	//�⺻������ SpriteRenderer�� ���鶧 �־��� ���÷��� �����մϴ�.
	GameEngineCore::CreateLevel<PlayLevel>("PlayLevel");
	GameEngineCore::CreateLevel<TitleLevel>("TitleLevel");
	GameEngineCore::CreateLevel<SelectLevel>("SelectLevel");
	GameEngineCore::ChangeLevel("TitleLevel");

	SoundContentLoad();

	// �ڱ� �ؽ�ó �ε��ؾ� �Ѵ�.

}

void ContentsCore::Update(float _Delta)
{

}

void ContentsCore::Release()
{
	GameEngineSound::Release();
}

void ContentsCore::SoundContentLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToExistsChild("GameEngineResources");
	Dir.MoveChild("ContentsResources");
	Dir.MoveChild("Sound");
	Dir.MoveChild("Bgm");

	std::vector<GameEngineFile> Files = Dir.GetAllFile();

	for (size_t i = 0; i < Files.size(); i++)
	{
		GameEngineFile& File = Files[i];
		GameEngineSound::SoundLoad(File.GetStringPath());
	}
}
