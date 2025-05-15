
#include "Boss.h"
#include "Level.h"


Boss::Boss()
{
	SetSpeed(150);
	SetMaxHitPoints(10);
	SetCollisionRadius(150);
	GetWeapon("Main Blaster");
}


void Boss::Update(const GameTime& gameTime)
{
	
	if (IsActive())
	{
		float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;
		float y = cos(gameTime.GetTotalTime() * Math::PI * 0.5f + GetIndex());
		y *= 30.0f * gameTime.GetElapsedTime();
		TranslatePosition(x, y);
	}


	Boss::Update(gameTime);

	Vector2 position = GetPosition();

	
	float delta = m_speed * (float)gameTime.GetElapsedTime();
	position.X += delta * m_direction;
	
	float halfWidth = GetHalfDimensions().X / 2.f;
	float screenWidth = (float)Game::GetScreenWidth();

	if (position.X - halfWidth <= 0)
	{
		position.X = halfWidth;
		m_direction = 1;
	}
	else if (position.X + halfWidth >= screenWidth)
	{
		position.X = screenWidth - halfWidth;
		m_direction = -1;
	}

	SetPosition(position);
}


void Boss::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}

}


void Boss::Hit(const float damage)
{
	Ship::Hit(damage);
	std::cout << "OUCH\n";
}

void Boss::Fire() 
{

}
