#include "global.h"
#include "game_first_stage.h"

GameFirstStage::GameFirstStage() {
    backgroundY = 0;
}

void GameFirstStage::Update() {
    backgroundY += 0.1f;
}
void GameFirstStage::Render() {
    TextureElement* background = textureManager.GetTexture(TEX_FRIST_STAGE_SCREEN);
    background->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    background->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 640;
    srcRect.bottom = 480;

    D3DXVECTOR3 pos(0, backgroundY, 0);

    background->Sprite->Draw(background->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));
    background->Sprite->End();
}