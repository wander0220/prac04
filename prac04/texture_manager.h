#pragma once
#include <vector>
#include <D3dx9core.h>
#include "global.h"

using namespace std;

class TextureElement 
{
public:
	int id;
	LPDIRECT3DTEXTURE9  Texture;
	ID3DXSprite* Sprite ;
};
class TextureManager {
public:
	vector<TextureElement*> elements;

	void LoadTexture(const TCHAR* name, int id) {
		TextureElement* newElement = new TextureElement();
		newElement->id = id;

		//Create sprite
		D3DXCreateSprite(g_pd3dDevice, &newElement->Sprite);
		//Create Texture
		D3DXCreateTextureFromFile(g_pd3dDevice, name, &newElement->Texture);

		elements.push_back(newElement);
	}
	TextureElement* GetTexture(const int id) {
		for (int i = 0; i < elements.size(); i++) {
			if (id == elements[i]->id) {
				return elements[i];
			}
		}
		return nullptr;
	}

	//void UnloadTexture();

};