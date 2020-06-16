#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(){

    posX =30;
    posY = 50;

    speed = 300;
}
void EnemyA::Update() 
{
    posY += deltaTime * 300;

}
void EnemyA::Render() 
{
    TextureElement* enemy = textureManager.GetTexture(GAME_ENEMY_BODY);
    enemy->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 64;
    srcRect.bottom = 64;

    D3DXVECTOR3 pos(posX - 32, posY - 32, 0);
   
    enemy->Sprite->Draw(enemy->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    enemy->Sprite->End();
}