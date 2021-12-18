#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <iostream>
#include <string>
#include <map>

#include "SDL.h"
#include "SDL_image.h"

class TextureManager
{
// singleton 
private:
	TextureManager() {}
	TextureManager(const TextureManager& other);
	~TextureManager() {}

public:
	static TextureManager& getInstance();
// singleton end

public:
	bool Loadimage(
		const std::string file,
		const std::string id
		);

	void Drawimage(
		const std::string img_file,
		const std::string id,
		int x_pos,
		int y_pos,
		int x_scale,
		int y_scale
	);

	void getRenderer(SDL_Renderer* _renderer)
	{
		src_renderer = _renderer;
	}
private:
	SDL_Renderer* src_renderer;

	std::map<std::string, SDL_Texture*> textureMap;
};

#endif