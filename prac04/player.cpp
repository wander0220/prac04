#include "global.h"
#include "player.h"

#define PLAYER_BODY_WIDTH 64
#define PLAYER_BODY_WIDTH_HALF 32

#define PLAYER_BODY_HEIGHT 64
#define PLAYER_BODY_HEIGHT_HALF 32


Player::Player() {
    playerX = WINDOW_WIDTH / 2;
    playerY = WINDOW_HEIGHT * 0.9f;

    speed = 500;
}
void Player::Update() {
    if (inputManager.keyBuffer[VK_LEFT] == 1) {
        playerX -= speed * deltaTime;
    }
    if (inputManager.keyBuffer[VK_RIGHT] == 1) {
        playerX += speed * deltaTime;
    }
    if (inputManager.keyBuffer[VK_UP] == 1) {
        playerY -= speed * deltaTime;
    }
    if (inputManager.keyBuffer[VK_DOWN] == 1) {
        playerY += speed * deltaTime;
    }

    if (inputManager.prevKeyBuffer['Z'] == 1 && inputManager.keyBuffer['Z'] == 0) 
    {
        soundManager.sndPlayerBullet->Reset();
        soundManager.sndPlayerBullet->Play(0, 0, 1);

        //미사일 발사
        gameSystem.GeneratePlayerBulletSpread(playerX, playerY-30);

    }



    if (playerX < 0) {
        playerX = 0;
    }
    if (playerX > WINDOW_WIDTH) {
        playerX = WINDOW_WIDTH;
    }
    if (playerY < 0) {
        playerY = 0;
    }
    if (playerY > WINDOW_HEIGHT) {
        playerY = WINDOW_HEIGHT;
    }
}
void Player::Render() {

    TextureElement* player = textureManager.GetTexture(GAME_PLAYER_BODY);
    player->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = PLAYER_BODY_WIDTH;
    srcRect.bottom = PLAYER_BODY_HEIGHT;

    D3DXVECTOR3 pos(playerX - PLAYER_BODY_WIDTH_HALF, playerY - PLAYER_BODY_HEIGHT_HALF, 0);

    player->Sprite->Draw(player->Texture, &srcRect, nullptr, &pos
        , D3DCOLOR_XRGB(255, 255, 255));

    player->Sprite->End();
}