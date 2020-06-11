#pragma once
#include "Bullet.h"
class PlayerBulletSpread : public Bullet {
public:
	PlayerBulletSpread(int x, int y, float velX, float velY);
	void Update() override;
	void Render() override;

	int posX; 
	int posY;

	float velX;
	float velY;
};