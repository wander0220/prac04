#include "title_stage.h"
#include "global.h"

TitleStage::TitleStage() {

}
void TitleStage::Update()
{

}
void TitleStage::Render()
{
	TextureElement* element = textureManager.GetTexture(TEX_TITLE_SCREEN);
	element->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    element->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.top = 0;
    srcRect.left = 0;
    srcRect.bottom = 640;
    srcRect.right = 480;

    D3DXVECTOR3 pos(0, 0, 0);

    element->Sprite->Draw(element->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));
    element->Sprite->End(); 
}