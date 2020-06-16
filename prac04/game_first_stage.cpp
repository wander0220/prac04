#include "game_first_stage.h"
#include "global.h"

GameFirstStage::GameFirstStage() {
    gameSystem.ClearAll();
}

void GameFirstStage::Update() {
    background.Update();
    player.Update();
    gameSystem.Update();

}
void GameFirstStage::Render() {
    background.Render();
    player.Render();
    gameSystem.Render();

}