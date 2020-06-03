#pragma once

class Stage;
class StageManager {
public:
	Stage* currentStage;
	
	void Update();
	void Render();
	void MakeGameStage();

	void MakeTitleScreen();
};