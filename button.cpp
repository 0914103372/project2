#include "button.h"

bool button::Loadbt(std::string path, SDL_Renderer* screen)
{
	
    SDL_Texture* new_texture = IMG_LoadTexture(screen, path.c_str());
	if (!new_texture)
	{
		cout << "khong load dc anh button" << endl;
	}
	p_button = new_texture;
	return p_button != NULL;
}

void button::free()
{
	SDL_DestroyTexture(p_button);
}

void button::update(int i)
{
	SDL_Point mouse;
	SDL_GetMouseState(&mouse.x, &mouse.y);
	if (SDL_PointInRect(&mouse, &a) == SDL_TRUE)
	{
		
	    if (b.w == 378)
		{
			b.x = 395;
			
		}
	    else if (b.w == 415)
		{
			b.x = 433;
		}
		else
		{
			b.x = 448;
		}
		isSelected = true;
	}
	else
	{
		isSelected = false;
		b.x = -4;
	}
}

void button::draw(SDL_Renderer* screen)
{
		SDL_RenderCopy(screen, p_button, &b, &a);
}

void button::fixtoado(int i)
{
	
	
	
		if (i == 1)
		{

			b.y += 103;
			a.y += 100;
		}
		else if (i >= 2 && i < 4)
		{
			if (i == 2)
				a.y -= 5;
			else
				a.y += 97;
			a.x = 660;
			b.y += i * 103;
		}
		else if (i == 4)
		{
			b.y += (i - 1) * 103;
			b.y += 100;
			a.y += 2 * 100;
			a.x = 441;
		}
	
	

	
}



void button::fixtoado2(int i)
{
	a.y = 315;
	if (i == 1)
	{
		b.y += 103;
		a.x = 660;
	}

}
void button::fixtoado3(int i)
{
	if (i == 1)
	{
		a.x = 441;
		b.y += 103;
		a.y += 100;
	}
	if (i == 2)
	{
		b.y += 103*2;
		a.x = 660;
	}

}
void button::fixtoado4(int i)
{
	b.w = 378;
	b.h = 78;

	if (i == 1)
	{
		b.y += 88;
		a.y += 100;
	}
	else if (i >= 2 )
	{
		if (i == 2)
		{
			a.y -= 5;
		}
		else
		a.y += 97;
		a.x = 660;
		b.y += i * 90;
	}
	

}
void button::fixtoado5(int i)
{
	//410//82//102//433
	b.w = 415;
	b.h = 82;
	if (i == 1)
	{

		b.y += 102;
		a.y += 100;
	}
	else if (i >= 2 && i < 4)
	{
		if (i == 2)
			a.y -= 5;
		else
			a.y += 97;
		a.x = 660;
		b.y += i * 102;
	}
}