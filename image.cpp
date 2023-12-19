#include"image.h"
image::image()
{
	p_image = NULL;
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
}
image::~image()
{}
bool image::LoadImg(std::string path,SDL_Renderer*screen)
{
	SDL_Texture* new_texture = NULL;
	SDL_Surface* load_surface = IMG_Load(path.c_str());
		if (load_surface != NULL)
		{
			new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
			if (new_texture != NULL)
			{
				rect_.w = load_surface->w;
				rect_.h= load_surface->h;
			}
			SDL_FreeSurface(load_surface);
		}
		p_image = new_texture;
		return p_image != NULL;

}
void image::render(SDL_Renderer* des, const SDL_Rect* clip)
{
	SDL_Rect renderquad = { rect_.x,rect_.y,rect_.w,rect_.h };
	SDL_RenderCopy(des, p_image, clip,NULL);
}
void image::free()
{
	if (p_image != NULL)
	{
		SDL_DestroyTexture(p_image);
		p_image = NULL;
		rect_.x = 0;
		rect_.y = 0;
		rect_.w = 0;
		rect_.h = 0;
	}
}