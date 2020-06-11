#pragma once
#include "Bullet.h"
class PlayerBulletSpread : public Bullet {
public:
	PlayerBulletSpread(float x, float y, float velX, float velY);
	void Update() override;
	void Render() override;

	float posX; 
	float posY;

	float velX;
	float velY;
};