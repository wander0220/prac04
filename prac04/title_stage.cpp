#include "title_stage.h"
#include "global.h"

TitleStage::TitleStage() {

}
void TitleStage::Update()
{
    //if (//inputManager.prevKeyBuffer[VK_LBUTTON] == 1
    //    //&& 
    //    inputManager.keyBuffer[VK_LBUTTON] == 1) 
    //{
    //    stageManager.MakeGameStage();
    //}
    if (inputManager.keyBuffer[VK_LBUTTON] == 1) {
        if (WINDOW_WIDTH * 0.6 < iMouseX && WINDOW_WIDTH * 0.6 + 118 > iMouseX
            && iMouseY > WINDOW_HEIGHT * 0.6- 41  && iMouseY < WINDOW_HEIGHT * 0.6  ) {
            int a = 10;
            stageManager.MakeGameStage();
        }
    }

}
void TitleStage::Render()
{
	TextureElement* element = textureManager.GetTexture(TEX_TITLE_SCREEN);
	element->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 1024;
    srcRect.bottom = 480;

    D3DXVECTOR3 pos(0, 0, 0);

    element->Sprite->Draw(element->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));
    element->Sprite->End(); 

    TextureElement* element2 = textureManager.GetTexture(TITLE_BUTTON);
    element2->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect2;
    srcRect2.left = 0;
    srcRect2.top = 0;
    srcRect2.right = 118;
    srcRect2.bottom = 41;

    D3DXVECTOR3 pos2(WINDOW_WIDTH*0.6, WINDOW_HEIGHT*0.6, 0);

    element2->Sprite->Draw(element2->Texture, &srcRect2, nullptr, &pos2
        , D3DCOLOR_XRGB(255, 255, 255));
    element2->Sprite->End();
}