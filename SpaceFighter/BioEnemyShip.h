
#pragma once

#include "EnemyShip.h"
#include "Blaster.h"


/** @brief Represents an enemy ship that is biological in nature. */
class BioEnemyShip : public EnemyShip
{

public:

	/** @brief Creates a new instance of BioEnemyShip. */
	BioEnemyShip();
	virtual ~BioEnemyShip() { }

	/** @brief Sets the texture that will be used to render the enemy ship.
		@param pTexture A pointer to the texture. */
	virtual void SetTexture(Texture *pTexture) { m_pTexture = pTexture; }

	/** @brief Updates the enemy ship.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Draws the enemy ship.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	//fires weapons
	virtual void Fire(TriggerType type);

	//newly added
	virtual void LoadContentEnemyProjectiles(ResourceManager& resourceManager);


private:

	Texture* m_pTexture = nullptr;
	float m_TimeBetweenShots = 2.0f;//time between shots
	float m_TimeSinceLastShot = 0.0f;//time since the last shot was fired
	std::vector<Projectile*> m_projectiles;

	Blaster* pBlaster = nullptr;
	BioEnemyShip* m_pEnemyShip = nullptr;
	
};