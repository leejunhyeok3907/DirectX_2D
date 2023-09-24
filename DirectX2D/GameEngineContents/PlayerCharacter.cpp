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
	UpperSpriteRenderer->CreateAnimation("Idle_Upper", "IdleUpper", 0.1f, -1, -1, true);
	UpperSpriteRenderer->CreateAnimation("Walk_Upper", "WalkUpper", 0.1f, -1, -1, true);
	UpperSpriteRenderer->ChangeAnimation("Walk_Upper");
	//UpperSpriteRenderer->SetImageScale({ 87.f, 87.f });
	//UpperSpriteRenderer->SetImageScale({ 96.f, 84.f });
	UpperSpriteRenderer->Transform.SetLocalPosition({ 0.0f, 45.0f, 0.0f });

	UnderSpriteRenderer = CreateComponent<GameEngineSpriteRenderer>(29);
	UnderSpriteRenderer->CreateAnimation("Idle_Under", "IdleUnder", 0.1f, -1, -1, true);
	UnderSpriteRenderer->CreateAnimation("Walk_Under", "WalkUnder", 0.1f, -1, -1, true);
	UnderSpriteRenderer->ChangeAnimation("Walk_Under");
	//UnderSpriteRenderer->SetImageScale({ 63.f, 48.f });
	//UnderSpriteRenderer->SetImageScale({ 63.f, 60.f });
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
