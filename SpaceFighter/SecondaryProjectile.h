
#pragma once

#include "Projectile.h"
#include "GameObject.h"

class SecondaryProjectile : public Projectile 
{
public:
	SecondaryProjectile();
	virtual ~SecondaryProjectile() {}

private:

	static Texture* s_pTexture;

	float m_speed = 500; // pixels per second
	float m_damage = 1;

	Vector2 m_direction;

	bool m_wasShotByPlayer = true;
};