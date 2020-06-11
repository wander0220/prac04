#pragma once
#include "Stage.h"
#include "game_background.h"
#include "player.h"

class GameFirstStage : public Stage {
public:
	GameFirstStage();

	void Update() override;
	void Render() override;

	GameBackground background;
	Player player;

	float backgroundY;

};