#pragma once
#include <d3dx9.h>
#include "texture_manager.h"
#include "stage_manager.h"

#define BANANA_IMG 500

extern LPDIRECT3D9             g_pD3D;
extern LPDIRECT3DDEVICE9       g_pd3dDevice;
extern TextureManager    textureManager;
extern StageManager stageManager;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define TEX_TITLE_SCREEN 2020