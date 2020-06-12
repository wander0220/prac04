#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(){
    enemyX = 16;
    enemyY = 16;
}
void EnemyA::Update() 
{

}
void EnemyA::Render() 
{
    TextureElement* enemy = textureManager.GetTexture(GAME_PLAYER_BULLET);
    enemy->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 16;
    srcRect.bottom = 16;

    enemyX = rand() % 120;

    D3DXVECTOR3 pos(rand() % 120,  0, 0);

    enemy->Sprite->Draw(enemy->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    enemy->Sprite->End();
}