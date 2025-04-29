
#include "Blaster.h"
#include "GameObject.h"

void Blaster::Update(const GameTime & gameTime)
{
	if (m_cooldown > 0) m_cooldown -= gameTime.GetElapsedTime();
}

void Blaster::Fire(TriggerType triggerType)
{
	if (!IsActive()) return;
	if (!CanFire()) return;
	if (!triggerType.Contains(GetTriggerType())) return;

	if (triggerType == TriggerType::Primary)
	{
		FireSingleShot();
	}
	else if (triggerType == TriggerType::Secondary )
	{
		FireSpreadShot();
	}
	else if (triggerType == TriggerType::Special)
	{
		FireMoab();
	}

}

void Blaster::FireSingleShot()
{
	Projectile* pProjectile = GetProjectile();
	if (!pProjectile) return;

	pProjectile->Activate(GetPosition(), IsAttachedToPlayer());

	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	m_cooldown = m_cooldownSeconds / 2;
	
}

void Blaster::FireSpreadShot()
{
	for (int i = -1; i <= 1; ++i) // Fire 3 projectiles in a spread
	{
		Projectile* pProjectile = GetProjectile();
		if (!pProjectile) return;

		Vector2 offset = Vector2::UNIT_X * i * 25; // Adjust spread angle
		pProjectile->Activate(GetPosition() + offset, IsAttachedToPlayer());
	}

	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	m_cooldown = m_cooldownSeconds;
}

void Blaster::FireMoab()
{
	for (int i = 0; i < 3; ++i) // Fire 3 projectiles in quick succession
	{
		Projectile* pProjectile = GetProjectile();
		if (!pProjectile) return;

		pProjectile->Activate(GetPosition(), IsAttachedToPlayer());
	}

	AudioSample* pAudio = GetFireSound();
	if (pAudio) pAudio->Play();

	m_cooldown = m_cooldownSeconds * 10 ;

}
