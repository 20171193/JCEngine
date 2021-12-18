#include "TextureManager.h"

TextureManager& TextureManager::getInstance()
{
	static TextureManager instance;
	return instance;
}

bool TextureManager::LoadImage(
	const string file,
	const string id
	)
{
	SDL_Surface* tempSurface = IMG_Load(file.c_str());
	//SDL_Surface* tempSurface = SDL_LoadBMP(file.c_str());

	if (tempSurface == nullptr)
	{
		cout << "Surface 생성 실패!" << endl;
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(src_renderer, tempSurface);
	// surface 해제
	SDL_FreeSurface(tempSurface);
	if (texture != nullptr)
	{
		// 텍스쳐 등록
		textureMap[id] = texture;
		return true;
	}
	cout << "이미지 등록 실패!" << endl;
	return false;
}


void TextureManager::DrawImage(
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