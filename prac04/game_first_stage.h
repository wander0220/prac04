#pragma once
# include "Stage.h"

class GameFirstStage : public Stage {
public:
	GameFirstStage();

	void Update() override;
	void Render() override;
};