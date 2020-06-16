#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(){

    posX = WINDOW_WIDTH / 2;
    posY = WINDOW_HEIGHT * 0.2f;

    speed = 300;
}
void EnemyA::Update() 
{
    //posX += speed * deltaTime;
    posY += speed * deltaTime;
}
void EnemyA::Render() 
{
    TextureElement* enemy = textureManager.GetTexture(GAME_ENEMY_BODY);
    enemy->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 16;
    srcRect.bottom = 16;


    D3DXVECTOR3 pos(32,  32, 0);

    enemy->Sprite->Draw(enemy->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    enemy->Sprite->End();
}