#include "Stage.h"
#include "stage_manager.h"
#include "title_stage.h"


void StageManager::MakeTitleScreen()
{
	if (currentStage != nullptr)
	{
		delete currentStage;
	}

	TitleStage* stage = new TitleStage();
	currentStage = stage;
}
void StageManager::Update() 
{
	if (currentStage != nullptr) {
		currentStage->Update();
	}
}
void StageManager::Render() 
{
	if (currentStage != nullptr) {
		currentStage->Render();
	}
}

