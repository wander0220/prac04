#pragma once
#include <vector>

using namespace std;

class Bullet;
class GameSystem {
public:
	vector<Bullet*> bullets;

	void Update();
	void Render();
	void GeneratePlayerBulletSpread(int x, int y);
};