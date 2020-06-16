#pragma once
#include "enemy.h"
class EnemyA : public Enemy 
{
public:
	EnemyA(float);
	void Update() override;
	void Render() override;

	int speed;
	float posX;
	float posY;
};
