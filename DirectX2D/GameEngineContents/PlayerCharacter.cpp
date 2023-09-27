#include "PreCompile.h"
#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
{
}

PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Start()
{
	UpperSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(30);
	UnderSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(29);

	CreateAnimations();

	UpperSpriteRenderer->ChangeAnimation("Walk");
	UpperSpriteRenderer->AutoSpriteSizeOn();
	UpperSpriteRenderer->SetAutoScaleRatio(3.f);
	UpperSpriteRenderer->SetPivotType(PivotType::Center);
	UpperSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 45.0f, 0.0f });

	UnderSpriteRenderer->ChangeAnimation("Walk");
	UnderSpriteRenderer->AutoSpriteSizeOn();
	UnderSpriteRenderer->SetAutoScaleRatio(3.f);
	UnderSpriteRenderer->SetPivotType(PivotType::Center);
	UnderSpriteRenderer->Transform.SetLocalPosition({ -15.0f, 0.0f, 0.0f });
}

void PlayerCharacter::Update(float _Delta)
{
	float Speed = 200.f;

	if (GameEngineInput::IsPress('A'))
	{
		Transform.AddLocalPosition(float4::LEFT * _Delta * Speed);
	}

	if (GameEngineInput::IsPress('D'))
	{
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
}

void PlayerCharacter::CreateAnimations()
{
	{
		UpperSpriteRenderer->CreateAnimation("Idle", "IdleUpper", 0.1f, -1, -1, true);
		UpperSpriteRenderer->CreateAnimation("Walk", "WalkUpper", 0.1f, -1, -1, true);
		UpperSpriteRenderer->CreateAnimation("Fire", "FireUpper", 0.1f, -1, -1, true);
		UpperSpriteRenderer->CreateAnimation("JumpIdle", "JumpIdleUpper", 0.1f, -1, -1, true);
	}

	{
		UnderSpriteRenderer->CreateAnimation("Idle", "IdleUnder", 0.1f, -1, -1, true);
		UnderSpriteRenderer->CreateAnimation("Walk", "WalkUnder", 0.1f, -1, -1, true);
		UnderSpriteRenderer->CreateAnimation("JumpIdle", "JumpIdleUnder", 0.1f, -1, -1, true);
	}
}
