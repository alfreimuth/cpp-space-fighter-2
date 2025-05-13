
#include "BioEnemyShip.h"
#include "Level.h"
#include "Projectile.h"





BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
	GetWeapon("Enemy Blaster");

	// create the projectiles newly added
	for (int i = 0; i < 100; i++)
	{
		Projectile* pProjectile = new Projectile();
		m_projectiles.push_back(pProjectile);
		
	}

}




void BioEnemyShip::Update(const GameTime& gameTime)  
{  
   if (IsActive())  
   {  
       float x = sin(gameTime.GetTotalTime() * Math::PI + GetIndex());  
       x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;  
       TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());  

       if (!IsOnScreen()) Deactivate();  
   }  

   m_TimeSinceLastShot += gameTime.GetElapsedTime();  

   

  
   if (m_TimeSinceLastShot > m_TimeBetweenShots)  
   {  
	   Blaster* pBlaster = new Blaster("Enemy Blaster");
	   pBlaster->SetProjectilePool(&m_projectiles);
	   AttachItem(pBlaster, Vector2::UNIT_Y * -20);
       // Fire the weapon and reset the TimeSinceLastShot variable to 0  
       Fire(TriggerType::None);   
	   FireWeapons(TriggerType::None);
       std::cout << "Enemy Ship is Firing! \n";  
       m_TimeSinceLastShot = 0.0f;  
   }  
   //newly added
   m_pEnemyShip = new BioEnemyShip(); // create the bio ship
   
   
   m_pEnemyShip->AttachItem(pBlaster, Vector2::UNIT_Y * -20); // attach the blaster to the bio ship

 

   EnemyShip::Update(gameTime);  
}
//newly added
void BioEnemyShip::LoadContentEnemyProjectiles(ResourceManager& resourceManager)
{

	m_pTexture = resourceManager.Load<Texture>("Textures\\Bullet.png");
	AudioSample* pAudio = resourceManager.Load<AudioSample>("Audio\\Effects\\Laser.wav");
	pAudio->SetVolume(0.5f);
	GetWeapon("Enemy Blaster")->SetFireSound(pAudio);
	SetPosition(Game::GetScreenCenter() + Vector2::UNIT_Y * 300);



}




void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}

void BioEnemyShip::Fire(TriggerType type)
{
	Ship::FireWeapons(type);
}


