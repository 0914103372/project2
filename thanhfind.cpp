#include "thanhfind.h"
bool Find::Loadbt(std::string path, SDL_Renderer* screen)
{

	SDL_Texture* new_texture = IMG_LoadTexture(screen, path.c_str());
	if (!new_texture)
	{
		cout << "khong load dc anh button" << endl;
	}
	p_button = new_texture;
	return p_button != NULL;
}
void Find::draw(SDL_Renderer* screen)
{
	SDL_RenderCopy(screen, p_button, &recttt, &rectt);
}