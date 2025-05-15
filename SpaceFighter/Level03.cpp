

#include "Level03.h"
#include "Boss.h"


void Level03::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	//Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");
	SetNextLevelIndex(1);
	Level::LoadContent(resourceManager);

	const int COUNT = 1;

	double xPositions[COUNT] =
	{
		.5
	};

	double delays[COUNT] =
	{
		0.25
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), 100.0f);

		Boss* pEnemy = new Boss();
		pEnemy->SetTexture(resourceManager.Load<Texture>("Textures\\BioEnemyBoss.png"));
		pEnemy->SetCurrentLevel(this);	
		AddGameObject(pEnemy);
	}

	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground03.png"));

	Level::LoadContent(resourceManager);
}


