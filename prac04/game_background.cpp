#include "game_background.h"
#include "global.h"

GameBackground::GameBackground() {
    backgroundY = 0;
}
void GameBackground::Update() {
    backgroundY += 0.1f;
}
void GameBackground::Render() {
    TextureElement* background = textureManager.GetTexture(TEX_FRIST_STAGE_SCREEN);
    background->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 1024;
    srcRect.bottom = 480;

    D3DXVECTOR3 pos(0, backgroundY, 0);

    background->Sprite->Draw(background->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    pos = { 0, backgroundY - 480, 0 };
    background->Sprite->Draw(background->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    background->Sprite->End();
}