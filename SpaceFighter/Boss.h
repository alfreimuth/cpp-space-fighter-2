
#pragma once

#include "Ship.h"


/** @brief Represents an enemy ship that is biological in nature. */
class Boss : public Ship
{

public:

	/** @brief Creates a new instance of BioEnemyShip. */
	Boss();
	virtual ~Boss() { }

	/** @brief Sets the texture that will be used to render the enemy ship.
		@param pTexture A pointer to the texture. */
	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	/** @brief Updates the enemy ship.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Fires a weapon from the enemy ship. */
	virtual void Fire() { }

	/** @brief Applies damage to the ship.
		@param damage The amount of damage to apply. */
	virtual void Hit(const float damage);

	/** @brief Gets the string representation of the enemy ship.
		@return Returns the string "Enemy Ship". */
	virtual std::string ToString() const { return "BOSS Ship"; }

	/** @brief Gets the collision type of the enemy ship.
		@return Returns the collision type of the enemy ship. */
	virtual CollisionType GetCollisionType() const { return CollisionType::Enemy | CollisionType::Ship; }


	virtual void Draw(SpriteBatch& spriteBatch);

	virtual void Hit(const float damage);

	virtual void Fire() { }



private:

	Texture* m_pTexture = nullptr;

private:

	float m_speed = 100.0f; 
	int m_direction = 1;    	
	

	float m_maxHitPoints = 3;
	float m_hitPoints = m_maxHitPoints;

};

