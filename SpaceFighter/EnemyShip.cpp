
#include "EnemyShip.h"
#include "Level.h"



EnemyShip::EnemyShip()
	
{

	SetMaxHitPoints(1);
	SetCollisionRadius(20);
	GetWeapon("Enemy Blaster");
}




void EnemyShip::Update(const GameTime& gameTime)
{
	if (m_delaySeconds > 0)
	{
		m_delaySeconds -= gameTime.GetElapsedTime();

		if (m_delaySeconds <= 0)
		{
			GameObject::Activate();
		}
	}

	if (IsActive())
	{
		m_activationSeconds += gameTime.GetElapsedTime();
		if (m_activationSeconds > 2 && !IsOnScreen()) Deactivate();
	}

	Ship::Update(gameTime);
}


void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
{
	
	//setup enemy ship
	Blaster* pBlasterEnemy = new Blaster("Enemy Blaster");
	pBlasterEnemy->SetProjectilePool(&m_enemyprojectiles);
	AttachItem(pBlasterEnemy, Vector2::UNIT_Y * -20);
	
	
	SetPosition(position);
	m_delaySeconds = delaySeconds;

	Ship::Initialize();
}


void EnemyShip::Hit(const float damage)
{
	Ship::Hit(damage);
}

void EnemyShip::Fire(TriggerType type)  
{  
Ship::FireWeapons(type);  
}

void EnemyShip::AttachItem(IAttachment* item, Vector2 position)
{
	Ship::AttachItem(item, position);
}