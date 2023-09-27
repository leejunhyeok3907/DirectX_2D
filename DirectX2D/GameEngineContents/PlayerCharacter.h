#pragma once
#include <GameEngineCore/GameEngineActor.h>

enum class E_Acton
{
	UP,
	Donw,
	Max
};

class PlayerCharacter : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerCharacter();
	~PlayerCharacter();

	// delete Function
	PlayerCharacter(const PlayerCharacter& _Other) = delete;
	PlayerCharacter(PlayerCharacter&& _Other) noexcept = delete;
	PlayerCharacter& operator=(const PlayerCharacter& _Other) = delete;
	PlayerCharacter& operator=(PlayerCharacter&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> UpperSpriteRenderer;
	std::shared_ptr<class GameEngineSpriteRenderer> UnderSpriteRenderer;


	float4 GrivityForce = { 0.0f, 0.0f, 0.0f, 1.0f };

	std::shared_ptr<GameEngineCollision> Collision;

private:
	void CreateAnimations();
};

