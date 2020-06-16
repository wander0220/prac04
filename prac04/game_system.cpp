#include "game_system.h"
#include "global.h"
#include "player_bullet_spread.h"
#include "enemy.h"
#include "enemy_a.h"
GameSystem::GameSystem() {
	enemyATime = 0;
}
void GameSystem::Update() {

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update();
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Update();
	}
}
void GameSystem::Render() {


	enemyATime += deltaTime;

	if (rand() % 100 < 5)
	{
		if (enemyATime > 0.1f)
		{
			GenerateEnemyA();
			enemyATime = 0;
		}
	}

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Render();
	}
	GenerateEnemyA();

}
void GameSystem::GeneratePlayerBulletSpread(int x, int y)
{
	float speed = 4;

	/*
	PlayerBulletSpread* a = new PlayerBulletSpread(x,y,-speed,-speed);
	PlayerBulletSpread* b = new PlayerBulletSpread(x,y, 0, -speed);
	PlayerBulletSpread* c = new PlayerBulletSpread(x,y,speed,-speed);

	bullets.push_back(a);
	bullets.push_back(b);
	bullets.push_back(c);
	*/

	for (int i = 0; i <= 5; i++) {
		float deltaAngle = (i * 8 + 70) * 3.141592f / 180.0f;

		float vx = cos(deltaAngle) * speed;
		float vy = -sin(deltaAngle) * speed;

		PlayerBulletSpread* a = new PlayerBulletSpread(x, y, vx, vy);
		bullets.push_back(a);
	}

}

void GameSystem::GenerateEnemyA() {
	for (int i = 0; i <= 10; i++) {
		float posX = (i + 1) * 30;
		Enemy* enemyA = new EnemyA(posX);
		enemies.push_back(enemyA);
	}
}