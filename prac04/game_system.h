#pragma once
#include <vector>


using namespace std;

class Bullet;
class Enemy;
class GameSystem {
public:
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;

	GameSystem();
	void Update();
	void Render();
	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();

	float enemyATime;
};