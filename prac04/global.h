#pragma once
#include <d3dx9.h>
#include "texture_manager.h"
#include "stage_manager.h"
#include "input_manager.h"
#include "game_system.h"

#define BANANA_IMG 500

extern LPDIRECT3D9             g_pD3D;
extern LPDIRECT3DDEVICE9       g_pd3dDevice;
extern TextureManager    textureManager;
extern InputManager inputManager;
extern StageManager stageManager;
extern GameSystem gameSystem;

extern float deltaTime;

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 480

#define TEX_TITLE_SCREEN 2020
#define TEX_FRIST_STAGE_SCREEN 2002
#define GAME_PLAYER_BODY 2001
#define GAME_PLAYER_BULLET 2010

