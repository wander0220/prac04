#include "game_system.h"
#include "global.h"
#include "player_bullet_spread.h"

void GameSystem::Update() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update();
	}
}
void GameSystem::Render() {
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Render();
	}
}
void GameSystem::GeneratePlayerBulletSpread(int x, int y)
{
	float speed = 1;
	PlayerBulletSpread* a = new PlayerBulletSpread(x,y,-speed,-speed);
	PlayerBulletSpread* b = new PlayerBulletSpread(x,y, 0, -speed);
	PlayerBulletSpread* c = new PlayerBulletSpread(x,y,speed,-speed);

	bullets.push_back(a);
	bullets.push_back(b);
	bullets.push_back(c);

}
