#include "PreCompile.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "PlayMap.h"
#include "Monster.h"
#include "ContentsEnum.h"

Player::Player() 
{
	
}

Player::~Player() 
{
}

void Player::Start()
{
	{
		// 부모로 바꿔줘야 
		MainSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
		MainSpriteRenderer->SetImageScale({ 256.0f, 256.0f });
		MainSpriteRenderer->CreateAnimation("Run", "HoHoYee_AttackABC", 0.1f, -1, -1, true);
		MainSpriteRenderer->ChangeAnimation("Run");
		MainSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 0.0f, 0.0f });
		MainSpriteRenderer->AutoSpriteSizeOn();

		MainSpriteRenderer->SetEndEvent("Run", std::bind(&Player::TestEvent, this, std::placeholders::_1));
	}

	{
		Col = CreateComponent<GameEngineCollision>(ContentsCollisionType::Player);
		Col->Transform.SetLocalScale({ -100.0f, 100.0f, 1.0f });
	}

	float4 HalfWindowScale = GameEngineCore::MainWindow.GetScale().Half();
	Transform.SetLocalPosition({ HalfWindowScale.X, -HalfWindowScale.Y, -500.0f });

}

void Player::TestEvent(GameEngineRenderer* _Renderer)
{
}

void Player::Update(float _Delta)
{
	// GameEngineDebug::DrawBox2D(MainSpriteRenderer->Transform);

	float Speed = 100.0f;

	if (GameEngineInput::IsDown('A'))
	{
		MainSpriteRenderer->AnimationPauseSwitch();
	}

	if (GameEngineInput::IsPress('A'))
	{
		Transform.SetLocalScale({-1,1.0f, 1.0f});
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
		Transform.SetLocalScale({ 1,1.0f, 1.0f });
		Transform.AddLocalPosition(float4::RIGHT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('W'))
	{
		Transform.AddLocalPosition(float4::UP * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('S'))
	{
		Transform.AddLocalPosition(float4::DOWN * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('Q'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, 360.0f * _Delta });
	}

	if (GameEngineInput::IsPress('E'))
	{
		Transform.AddLocalRotation({ 0.0f, 0.0f, -360.0f * _Delta });
	}

	GetLevel()->GetMainCamera()->Transform.SetLocalPosition(Transform.GetWorldPosition());
	// 
	float4 WorldMousePos = GetLevel()->GetMainCamera()->GetWorldMousePos2D();
	OutputDebugStringA(WorldMousePos.ToString("\n").c_str());

	// OutputDebugStringA(GameEngineCore::MainWindow.GetMousePos().ToString("\n").c_str());

	//GameEngineColor Color = PlayMap::MainMap->GetColor(Transform.GetWorldPosition(), GameEngineColor::RED);

	//if (GameEngineColor::RED != Color)
	//{
	//	GrivityForce.Y -= _Delta * 100.0f;
	//	Transform.AddLocalPosition(GrivityForce * _Delta);
	//}
	//else 
	//{
	//	GrivityForce = 0.0f;
	//}
	// 땅에 딱붙게하고 싶다면 while돌려서 올려주세요.


	// float4 Color = GetColor(Transform.GetWorldPosition());
}