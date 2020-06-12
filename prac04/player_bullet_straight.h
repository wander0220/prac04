#pragma once
#include "Bullet.h"
class PlayerBulletSpread : public Bullet {
public:
	PlayerBulletSpread(float x, float y);
	void Update() override;
	void Render() override;

	float posX;
	float posY;
};