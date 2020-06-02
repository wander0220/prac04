#include "texture_manager.h"
#include "global.h"

void TextureManager::LoadTexture(const TCHAR* name, int id) {
	TextureElement* newElement = new TextureElement();
	newElement->id = id;

	//Create sprite
	D3DXCreateSprite(g_pd3dDevice, &newElement->Sprite);
	//Create Texture
	D3DXCreateTextureFromFile(g_pd3dDevice, name, &newElement->Texture);

	elements.push_back(newElement);
}
TextureElement* TextureManager::GetTexture(const int id) {
	//O(n) °Ë»ö~~
	for (int i = 0; i < elements.size(); i++) {
		if (id == elements[i]->id) {
			return elements[i];
		}
	}
	return nullptr;
}