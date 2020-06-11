#pragma once
#include "global.h"

class Bullet {
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
};