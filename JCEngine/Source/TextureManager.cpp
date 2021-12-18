#include "TextureManager.h"

using namespace std;

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

bool TextureManager::Loadimage(
	const string file,
	const string id
	)
{
	SDL_Surface* tempSurface = IMG_Load(file.c_str());
	//SDL_Surface* tempSurface = SDL_LoadBMP(file.c_str());

	if (tempSurface == nullptr)
	{
		cout << "Surface ���� ����!" << endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(src_renderer, tempSurface);
	// surface ����
	SDL_FreeSurface(tempSurface);
	if (texture != nullptr)
	{
		// �ؽ��� ���
		textureMap[id] = texture;
		return true;
	}
	cout << "�̹��� ��� ����!" << endl;
	return false;
}


void TextureManager::Drawimage(
	const string file,
	const string id,
	int x_pos,
	int y_pos,
	int x_scale,
	int y_scale
	)
{
	SDL_Rect src_Rect;
	SDL_Rect dst_Rect;

	src_Rect.x = 0;
	src_Rect.y = 0;
	src_Rect.w = dst_Rect.w = x_scale;
	src_Rect.h = dst_Rect.h = y_scale;
	dst_Rect.x = x_pos;
	dst_Rect.y = y_pos;

	SDL_RenderCopy(
		src_renderer,
		textureMap[id],
		&src_Rect,
		&dst_Rect
	);
}