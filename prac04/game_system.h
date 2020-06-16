#pragma once
#include <vector>
#include "enemy_a.h"

using namespace std;

class Bullet;
class GameSystem {
public:
	vector<Bullet*> bullets;
	EnemyA enemyA;

	void Update();
	void Render();
	void GeneratePlayerBulletSpread(int x, int y);
};