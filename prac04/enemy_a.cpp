#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(){

    posX =30;
    posY = 50;

    speed = 300;
}
void EnemyA::Update() 
{

}
void EnemyA::Render() 
{
    TextureElement* enemy = textureManager.GetTexture(GAME_PLAYER_BODY);
    enemy->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 16;
    srcRect.bottom = 16;

    D3DXVECTOR3 pos(posX - 8, posY - 8, 0);
   
    enemy->Sprite->Draw(enemy->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    enemy->Sprite->End();
}