#include "player_bullet_spread.h"
PlayerBulletSpread::PlayerBulletSpread(int x, int y, float vx, float vy) {
	posX = x;
	posY = y;
	velX = vx;
	velY = vy;

}
void PlayerBulletSpread::Update() {

}
void PlayerBulletSpread::Render() {

    TextureElement* bullet = textureManager.GetTexture(GAME_PLAYER_BULLET);
    bullet->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 16;
    srcRect.bottom = 16;

    D3DXVECTOR3 pos(posX-8, posY-8, 0);

    bullet->Sprite->Draw(bullet->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    bullet->Sprite->End();
}