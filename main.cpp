#include"commonFunc.h"
#include"image.h"
#include"button.h"
#include"Khudat.h"
#include"NhaPho.h"
#include"NhaSanVuon.h"
#include"Chung.h"
#include"thanhfind.h"
SDL_Window* g_windows = NULL;
SDL_Surface* gScreenSurface = NULL;
image g_background;
image g;
int Khudat::demmm = 2;
int Khudat::kdat[2] = { 49,48 };
int NhaPho::npho[2] = { 49,48 };
int NhaPho::dem = 2;
int NhaSanVuon::nsvuon[2] = { 49,48 };
int NhaSanVuon::demm = 3;
Find box;
button a[5];
button a1[2];
button a2[2];
button a3[3];
button a4[4];
button a5[4];
vector<Khudat>kd;
vector<NhaPho>np;
vector<NhaSanVuon>nsv;
int cmn = 0;
int cmadd = 0;
int cmview = 0;
int cmfix = 0;
int cmfind = 0;
int cmxoa = 0;
bool running = false;
void xoanhasanvuon();
void xoanhapho();
void xoakhudat();
bool findnp();
bool findkd();
void inmenufixnhasanvuon();
void inmenufixkhudat();
void inmenufixnhapho();
void indulieunhap(string x);
NhaSanVuon nhapnsv();
NhaPho nhapnp();
bool fixnsv()
{
    int chiso = 0;
    int dem = 0;
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap ID Nha San Vuon-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        switch (dem) {
        case 0: indulieunhap("-Nhap ID Nha San Vuon-"); break;
        case 1: indulieunhap("-Nhap Dia Diem-"); break;
        case 2: indulieunhap("-Nhap Gia Ban-"); break;
        case 3: indulieunhap("-Nhap Dien Tich Xay Dung-"); break;
        case 4: indulieunhap("-Nhap Dien Tich San Vuon-"); break;
        }
        if (a == 1)
        {
            SDL_RenderPresent(g_screen);
            a--;
        }
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (dem) {
                case 0:
                    for (int i = 0; i < nsv.size(); i++)
                    {
                        if (!strcmp(input.c_str(), nsv[i].takeid()))
                        {
                            dem = cmfix;
                            cmfix = 0;
                            cmn = 0;
                            chiso = i;
                        }
                    }
                    a = 1;

                    break;
                case 1:
                    nsv[chiso].fixdiadiem(input);
                    TTF_CloseFont(font);
                    cout << 123;
                    return TRUE;
                    break;

                case 2:
                    nsv[chiso].fixgiaban(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                case 3:
                    nsv[chiso].fixdientich(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                case 4:
                    nsv[chiso].fixdtsv(atoi(input.c_str()));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                }

                input.clear();

            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);

                }
            }
        }

    }
}
bool fixnp()
{
    int chiso = 0;
    int dem = 0;
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap ID Nha Pho-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        switch (dem) {
        case 0: indulieunhap("-Nhap ID Nha Pho-"); break;
        case 1: indulieunhap("-Nhap Dia Diem-"); break;
        case 2: indulieunhap("-Nhap Gia Ban-"); break;
        case 3: indulieunhap("-Nhap Dien Tich-"); break;

        }
        if (a == 1)
        {
            SDL_RenderPresent(g_screen);
            a--;
        }
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (dem) {
                case 0:
                    for (int i = 0; i < np.size(); i++)
                    {
                        if (!strcmp(input.c_str(), np[i].takeid()))
                        {
                            dem = cmfix;
                            cmfix = 0;
                            cmn = 0;
                            chiso = i;
                        }
                    }
                    a = 1;

                    break;
                case 1:
                    np[chiso].fixdiadiem(input);
                    TTF_CloseFont(font);
                    return TRUE;
                    break;

                case 2:
                    np[chiso].fixgiaban(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                case 3:
                    np[chiso].fixdientich(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                case 4:
                    np[chiso].fixsotang(atoi(input.c_str()));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                }

                input.clear();

            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);

                }
            }
        }

    }
}
bool fixkd()
{
    int chiso=0;
    int dem = 0;
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap ID Khu Dat-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        switch(dem){
        case 0: indulieunhap("-Nhap ID Khu Dat-"); break;
        case 1: indulieunhap("-Nhap Dia Diem-"); break;
        case 2: indulieunhap("-Nhap Gia Ban-"); break;
        case 3: indulieunhap("-Nhap Dien Tich-"); break;
         
        }
        if (a == 1)
        {
            SDL_RenderPresent(g_screen);
            a--;
        }
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (dem) {
                case 0:
                    for (int i = 0; i < kd.size(); i++)
                    {
                        if (!strcmp(input.c_str(),kd[i].takeid()))
                        { 
                            dem = cmfix;
                            cmfix = 0;
                            cmn = 0;
                            chiso = i;
                        }
                    }
                    a = 1;
                  
                    break;
                case 1:
                    kd[chiso].fixdiadiem(input);
                    TTF_CloseFont(font);
                    cout << 123; 
                    return TRUE; 
                    break;
                    
                case 2:
                    kd[chiso].fixgiaban(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                case 3:
                    kd[chiso].fixdientich(stod(input));
                    TTF_CloseFont(font);
                    return TRUE;
                    break;
                }

                input.clear();
            
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);

                }
            }
        }
    
    }
}
Khudat nhapkd()
{
    
    int dem = 0;
    Khudat kdn;
    kdn.capid();
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap Dia Diem-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    
    while (running) {
            SDL_PollEvent(&event);
            SDL_RenderClear(g_screen);
           
            g_background.render(g_screen, NULL);
            box.draw(g_screen);
           
            switch (dem) {
            case 0: indulieunhap("-Nhap Dia Diem-"); break;
            case 1: indulieunhap("-Nhap Gia Ban-"); break;
            case 2: indulieunhap("-Nhap Dien Tich-"); break;
            case 3:TTF_CloseFont(font); cmn = 0; return kdn;
            }
            
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_TEXTINPUT) {
                // Append the input to our input string 
                input += event.text.text; 
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                
                
                SDL_RenderCopy(g_screen, text, NULL, &recttt);
                SDL_RenderPresent(g_screen);
                SDL_DestroyTexture(text);
                SDL_FreeSurface(textSurface);


            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RETURN){
                    SDL_RenderClear(g_screen);
                    switch (dem) {
                    case 0:
                        kdn.fixdiadiem(input); 
                        g_background.render(g_screen, NULL);
                        box.draw(g_screen);
                        indulieunhap("-Nhap Gia Ban-");
                        SDL_RenderPresent(g_screen);
                        break;
                    case 1: 
                        kdn.fixgiaban(stod(input));
                        g_background.render(g_screen, NULL);
                        box.draw(g_screen); 
                        indulieunhap("-Nhap Dien Tich-");
                        SDL_RenderPresent(g_screen);
                        break;
                    case 2:  
                        kdn.fixdientich(stod(input));
                        g_background.render(g_screen, NULL);
                        indulieunhap("-Ban Da Nhap Thanh Cong-");
                        SDL_RenderPresent(g_screen);
                        SDL_Delay(3000);
                        break;
                    case 3:TTF_CloseFont(font); return kdn;
                   
                    }
                   
                    input.clear();
                    dem++;
                }
                else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if(input[0]!=NULL)
                      input.pop_back();
                    if (input[0] != NULL)
                    { 
                        SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                        SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                        SDL_Rect recttt{ 445,357- textSurface->h/2,textSurface->w,textSurface->h };
                        SDL_RenderCopy(g_screen, text, NULL, &recttt);
                        SDL_RenderPresent(g_screen);
                        SDL_DestroyTexture(text);
                        SDL_FreeSurface(textSurface);

                    }
                    else  
                    {
                        SDL_RenderPresent(g_screen);

                    }
                } 
            
           




            }




    }

    
   
    
}
void inmenuview2();
void inmenuview();
void Nhapdl()
{
    ifstream infile;
    infile.open("D:/Code/dohoapbl/KhuDat.txt");
    for (int i = 0;; i++)
    {
       
        Khudat a;
       infile >> a.diadiem;
       if (a.diadiem == "end")
       {
           break;
       }
       infile >> a.giaban;
       infile >> a.dientich;
       a.capid();
     
       
       kd.push_back(a);
    }
    infile.close();
    ifstream innfile;
    innfile.open("D:/Code/dohoapbl/NhaPho.txt");
    for (int i = 0;; i++)
    {
        NhaPho a;
        innfile >> a.diadiem;
        if (a.diadiem == "end")
        {
            break;
        }
        innfile >> a.giaban;
        innfile >> a.dientich;
        innfile >> a.sotang;
        a.capid();
        np.push_back(a);
    }
    innfile.close();
    ifstream innnfile;
    innnfile.open("D:/Code/dohoapbl/NhaSanVuon.txt");
    for (int i = 0; ; i++)
    {
        NhaSanVuon a;
        innnfile >> a.diadiem;
        if (a.diadiem == "end")
        {
            break;
        }
        innnfile >> a.giaban;
        innnfile >> a.dientich;
        innnfile >> a.dientichsanvuon;
        a.capid();
  
        nsv.push_back(a);
    }
    if (kd[1].takegb() != NULL && np[1].takegb() != NULL && nsv[1].takegb() != NULL)
        cout << 1;
    innnfile.close();
}
bool InitData()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0 &&  TTF_Init()>=0)
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        g_windows = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1280, 720, SDL_WINDOW_SHOWN);
        if (g_windows == NULL)
        {
            success = false;
        } 
        else
        {
            g_screen = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
            if (g_screen == NULL)
            {
                success = false;
            }
            else
            {
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) && imgFlags))
                    success = false;
            }
               
            
        }
        

    }
   
    return success;
}
void vebangkd(SDL_Renderer* renderer,int sohang ,int socot) {

  
   
        SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
        SDL_RenderClear(renderer);
        g_background.render(g_screen, NULL);
        if (sohang >= 9) sohang = 9;
        SDL_Rect rect = { 150+98, 100,196, 50 };
        SDL_Rect rectt = { 243,95,196 * 4 + 10,sohang * 50 + 10  };
        SDL_RenderDrawRect(renderer, &rectt);
        SDL_RenderPresent(renderer);
       
        for (int j = 0; j < sohang; j++)
        {
            rect.y += 50 * j;
            for (int i = 0; i < socot; i++)
            {
                rect.x += 196 * i;
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderPresent(renderer);
                rect.x -= 196 * i;
            }
            rect.y -= 50 * j;
        }
        
}
void vebangnp(SDL_Renderer* renderer, int sohang, int socot,int n) {



    SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
    SDL_RenderClear(renderer);
    g_background.render(g_screen, NULL);
    SDL_Rect rect = { 150, 100,196, 50 };
    if (n == 0)
    {   
        if (np.size() < 8)
        {
            SDL_Rect rectt = { 145,95,196 * 5 + 10,np.size() * 50 + 10 + 50 };
            SDL_RenderDrawRect(renderer, &rectt);
        }
        else
        {
            SDL_Rect rectt = { 145,95,196 * 5 + 10,8 * 50 + 10 + 50 };
            SDL_RenderDrawRect(renderer, &rectt);
        }
    }
    else
    {
         if (nsv.size() < 8)
         {
            SDL_Rect rectt = { 145,95,196 * 5 + 10,nsv.size() * 50 + 10 + 50 };
            SDL_RenderDrawRect(renderer, &rectt);
         }
         else
         {
             SDL_Rect rectt = { 145,95,196 * 5 + 10,8 * 50 + 10 + 50 };
             SDL_RenderDrawRect(renderer, &rectt);
         }
    }
    SDL_RenderPresent(renderer);
    if (sohang <= 8)
    {
        for (int j = 0; j < sohang; j++)
        {
            rect.y += 50 * j;
            for (int i = 0; i < socot; i++)
            {
                rect.x += 196 * i;
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderPresent(renderer);
                rect.x -= 196 * i;
            }
            rect.y -= 50 * j;
        }
    }
    else {
        for (int j = 0; j < 9; j++)
        {
            rect.y += 50 * j;
            for (int i = 0; i < socot; i++)
            {
                rect.x += 196 * i;
                SDL_RenderDrawRect(renderer, &rect);
                SDL_RenderPresent(renderer);
                rect.x -= 196 * i;
            }
            rect.y -= 50 * j;
        }
    }

}
void Bangnsv(SDL_Renderer* renderer,vector<NhaSanVuon> n)
{

    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 20); // Thay "arial.ttf" bằng đường dẫn tới font của bạn
    int a = 0; int b = 8;
    const char text[5][12] = { "ID","Diadiem","GiaBan","DienTichXD","DienTichSV" };
    int m = n.size() - 7;
    int x = 400 / m;
    SDL_Rect recttt = { 1160 , 150,15,x };
    while (1)
    {
        SDL_RenderClear(g_screen);
        vebangnp(renderer, n.size() + 1, 5, 0);
        SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
        SDL_Rect rectt = { 1160 , 150,15, 400 };
        SDL_RenderFillRect(g_screen, &rectt);
        SDL_RenderPresent(g_screen);
        SDL_SetRenderDrawColor(g_screen, 255, 255, 150, 255);
        SDL_RenderFillRect(g_screen, &recttt);
        SDL_RenderPresent(g_screen);
      

        for (int i = 0; i < 5; i++)
        {
            SDL_Color textColor = { 255,255, 150, 255 };
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, text[i], textColor);

            // Tạo texture từ surface
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            int x = 248 - textSurface->w / 2;
            x += i * 196;
            int y = 125 - textSurface->h / 2;
            // Vẽ texture lên màn hình
            SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

            // Hiển thị trên màn hình
            SDL_RenderPresent(renderer);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
        for (int i = a; i < b; i++)
        {


            for (int j = 0; j < 5; j++) {
                char n1[20];
                SDL_Color textColor = { 250,250, 250, 250 };
                if (j == 0)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, nsv[i].takeid(), textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 1)
                {
                    string g = n[i].takedd();
                    strcpy(n1, g.c_str());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);

                }
                else if (j == 2)
                {
                    sprintf(n1, "%.2fl tr", n[i].takegb());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 3)
                {
                    sprintf(n1, "%.2fl m3", n[i].takedt());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 4)
                {
                    sprintf(n1, "%.2lf m3", n[i].takedtsv());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);

                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }



            }

        }

        SDL_Event event;
        while (1) {
            SDL_PollEvent(&event);
            int y = event.wheel.y;
            if (event.type == SDL_MOUSEWHEEL) {
                if (y < 0) {
                    if (recttt.y + x <= 350 + 195)
                    {
                        recttt.y += x;
                        a++;
                        b++;
                        break;
                    }
                }
                else if (y > 0)
                {
                    if (recttt.y > 150)
                    {
                        recttt.y -= x;
                        a--; b--;
                        break;
                    }
                }

            }
            else if (event.type == SDL_KEYDOWN) {

                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    cmn = 0;
                    TTF_CloseFont(font);
                    return;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                exit(1);
            }
        }
    }
    TTF_CloseFont(font);

}
void thanhtruot(SDL_Rect& recttt, int z)
{
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    SDL_Rect rectt = { 1160 , 200,15, 350 };
    SDL_RenderFillRect(g_screen, &rectt);
    SDL_RenderPresent(g_screen);
    SDL_SetRenderDrawColor(g_screen, 255, 255, 150, 255);
    SDL_RenderFillRect(g_screen, &recttt);
    SDL_RenderPresent(g_screen);
    while (1)
    {
        while (SDL_PollEvent(&g_event) != 0) {
            int y = g_event.wheel.y;
            if (g_event.type == SDL_MOUSEWHEEL) {
                if (y < 0) {
                    if (recttt.y + z <= 350 + 195)
                    {
                        recttt.y += z;
                    }
                }
                else if (y > 0)
                {
                    if (recttt.y > 200)
                    {
                        recttt.y -= z;
                    }
                }
                return;
            }

        }
    }
}
void Bangnp(SDL_Renderer* renderer, vector<NhaPho> n)
{
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 17); // Thay "arial.ttf" bằng đường dẫn tới font của bạn
    int a = 0;
    int b = 8;
    const char text[5][12] = { "ID","Diadiem","GiaBan","DienTichXD","SoTang" };
    int m = n.size() - 7;
    int x = 400 / m; 
    SDL_Rect recttt = { 1160 , 150,15,x };
    while (1)
    {
        SDL_RenderClear(g_screen);
        vebangnp(renderer, n.size() + 1, 5, 0);
        SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
        SDL_Rect rectt = { 1160 , 150,15, 400 };
        SDL_RenderFillRect(g_screen, &rectt);
        SDL_RenderPresent(g_screen);
        SDL_SetRenderDrawColor(g_screen, 255, 255, 150, 255);
        SDL_RenderFillRect(g_screen, &recttt);
        SDL_RenderPresent(g_screen);

        for (int i = 0; i < 5; i++)
        {

            SDL_Color textColor = { 255,255, 150, 255 };
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, text[i], textColor);

            // Tạo texture từ surface
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            int x = 248 - textSurface->w / 2;
            x += i * 196;
            int y = 125 - textSurface->h / 2;
            // Vẽ texture lên màn hình
            SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

            // Hiển thị trên màn hình
            SDL_RenderPresent(renderer);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }

        for (int i = a; i < b; i++)
        {


            for (int j = 0; j < 5; j++) {
                char n1[20];
                SDL_Color textColor = { 250,250, 250, 250 };
                if (j == 0)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, np[i].takeid(), textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i + 1-a) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 1)
                {
                    string g = n[i].takedd();
                    strcpy(n1, g.c_str());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i- a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);

                }
                else if (j == 2)
                {
                    sprintf(n1, "%.2fl tr", n[i].takegb());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i- a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 3)
                {
                    sprintf(n1, "%.2fl m3", n[i].takedt());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i- a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);
                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }
                else if (j == 4)
                {
                    sprintf(n1, "%i", np[i].takest());
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                    int x = 248 - textSurface->w / 2;
                    x += j * 196;
                    int y = 125 - textSurface->h / 2;
                    y += (i-a + 1) * 50;
                    // Vẽ texture lên màn hình
                    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                    SDL_RenderPresent(renderer);

                    SDL_FreeSurface(textSurface);
                    SDL_DestroyTexture(textTexture);
                }



            }

        }
        SDL_Event event;

        while (1) {
            SDL_PollEvent(&event);
            int y = event.wheel.y;
            if (event.type == SDL_MOUSEWHEEL) {
                if (y < 0) {
                    if (recttt.y + x <= 350 + 195)
                    {
                        recttt.y += x;
                        a++;
                        b++;
                        break;
                    }
                }
                else if (y > 0)
                {
                    if (recttt.y > 150)
                    {
                        recttt.y -= x;
                        a--; b--;
                        break;
                    }
                }

            }
            else if (event.type == SDL_KEYDOWN) {

                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    cmn = 0;
                    TTF_CloseFont(font);
                    return;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                exit(1);
            }
        }

    }

}
void Bangkd(SDL_Renderer* renderer, vector<Khudat> n)
{
        TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 20); // Thay "arial.ttf" bằng đường dẫn tới font của bạn
        int a = 0;
        int b = 8;
        const char text[4][12] = { "ID","Diadiem","GiaBan","DienTich" };
        SDL_Color textColor = { 255,255, 150, 255 };
        int m = n.size() - 7;
        int x = 400 / m;
        SDL_Rect recttt = { 1060 , 150,15,x };
        while (1)
        {   
           
            SDL_RenderClear(g_screen);
            vebangkd(renderer, n.size() + 1, 4);
            SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
            SDL_Rect rectt = { 1060 , 150,15, 400 };
            SDL_RenderFillRect(g_screen, &rectt);
            SDL_RenderPresent(g_screen);
            SDL_SetRenderDrawColor(g_screen, 255, 255, 150, 255);
            SDL_RenderFillRect(g_screen, &recttt);
            SDL_RenderPresent(g_screen);
             
            // in cac tieu de
            for (int i = 0; i < 4; i++)
            {


                SDL_Surface* textSurface = TTF_RenderText_Solid(font, text[i], textColor);

                // Tạo texture từ surface
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                int x = 248 + 98 - textSurface->w / 2;
                x += i * 196;
                int y = 125 - textSurface->h / 2;
                // Vẽ texture lên màn hình
                SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };
                SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                // Hiển thị trên màn hình
                SDL_RenderPresent(renderer);
                SDL_FreeSurface(textSurface);
                SDL_DestroyTexture(textTexture);
            }

            for (int i = a; i < b; i++)
            {
                SDL_Color textColor = { 250,250, 250, 250 };

                for (int j = 0; j < 4; j++) {
                    char n1[20];
                    SDL_Color textColor = { 250,250, 250, 250 };
                    if (j == 0)
                    {
                        SDL_Surface* textSurface = TTF_RenderText_Solid(font, kd[i].takeid(), textColor);
                        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                        int x = 248 + 98 - textSurface->w / 2;
                        x += j * 196;
                        int y = 125 - textSurface->h / 2;
                        y += (i + 1-a) * 50;
                        // Vẽ texture lên màn hình
                        SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                        SDL_RenderPresent(renderer);
                        SDL_FreeSurface(textSurface);
                        SDL_DestroyTexture(textTexture);
                    }
                    else if (j == 1)
                    {
                        string g = n[i].takedd();
                        strcpy(n1, g.c_str());
                        SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                        int x = 248 + 98 - textSurface->w / 2;
                        x += j * 196;
                        int y = 125 - textSurface->h / 2;
                        y += (i + 1-a) * 50;
                        // Vẽ texture lên màn hình
                        SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                        SDL_RenderPresent(renderer);
                        SDL_FreeSurface(textSurface);
                        SDL_DestroyTexture(textTexture);

                    }
                    else if (j == 2)
                    {
                        sprintf(n1, "%.2fl tr", n[i].takegb());
                        SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                        int x = 248 + 98 - textSurface->w / 2;
                        x += j * 196;
                        int y = 125 - textSurface->h / 2;
                        y += (i + 1-a) * 50;
                        // Vẽ texture lên màn hình
                        SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                        SDL_RenderPresent(renderer);
                        SDL_FreeSurface(textSurface);
                        SDL_DestroyTexture(textTexture);
                    }
                    else if (j == 3)
                    {
                        sprintf(n1, "%.2fl m3", n[i].takedt());
                        SDL_Surface* textSurface = TTF_RenderText_Solid(font, n1, textColor);
                        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                        int x = 248 + 98 - textSurface->w / 2;
                        x += j * 196;
                        int y = 125 - textSurface->h / 2;
                        y += (i + 1-a) * 50;
                        // Vẽ texture lên màn hình
                        SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

                        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
                        SDL_RenderPresent(renderer);
                        SDL_FreeSurface(textSurface);
                        SDL_DestroyTexture(textTexture);
                    }



                }

            }

            SDL_Event event;

            while (1) {
                SDL_PollEvent(&event);
                int y = event.wheel.y;
                if (event.type == SDL_MOUSEWHEEL) {
                    if (y < 0) {
                        if (recttt.y + x <= 350 + 195)
                        {
                            recttt.y += x;
                            a++;
                            b++;
                            break;
                        }
                    }
                    else if (y > 0)
                    {
                        if (recttt.y > 150)
                        {
                            recttt.y -= x;
                            a--; b--;
                            break;
                        }
                    }

                }
                else if (event.type == SDL_KEYDOWN) {

                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        cmn = 0;
                        TTF_CloseFont(font);
                        return;
                    }
                }
                else if (event.type == SDL_QUIT)
                {
                    exit(1);
                }
            }
        }

}
void inmenumain();
bool LoadBackGround()
{
    bool ret = g_background.LoadImg("br1.png",g_screen);
    bool rett = g.LoadImg("b.png", g_screen);
    if (ret == false)
        return false;
    return true;
}
void close()
{
    g_background.free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_windows);
    g_window = NULL;
    TTF_Quit();
    SDL_Quit();

}
void inbutton(button* c, int n)
{
    
    for (int i = 0; i < n; i++)
    {
       
        c[i].update(n);
        c[i].draw(g_screen);
    }
   
    
}
bool loadbutton2(button* x, int n, string path)
{

    for (int i = 0; i < n; i++)
    {
        bool b = x[i].Loadbt(path.c_str(), g_screen);
        if (b == false)
            return -1;

        x[i].fixtoado2(i);
    }
}
bool loadbutton(button *x,int n, string path)
{
    int c = 4;
    for (int i = 0; i < n; i++)
    {
        bool b = x[i].Loadbt(path.c_str(),g_screen);
        if (b == false)
            return -1;
        if (n == 5)
            x[i].fixtoado(i);
        else if (n == 3)
            x[i].fixtoado3(i);
        else if (n == 4 && c >= 1)
        {
            x[i].fixtoado4(i);
            c--;
        }
        else if (n == 4)
        {
            x[i].fixtoado5(i);
        }
     
            
    }
    
    return true;

}
bool loadbutton3(button* x, int n, string path)
{
    int c = 4;
    for (int i = 0; i < n; i++)
    {
        bool b = x[i].Loadbt(path.c_str(), g_screen);
        if (b == false)
            return -1;
        
        if (n == 4)
        {
            x[i].fixtoado5(i);
        }


    }

    return true;

}
int main(int argc, char* argv[])
{
    Nhapdl();
    if (InitData() == false)
        return -2;
    if (LoadBackGround() == false)
        return-1;
    loadbutton(a,5, "button.png");
    loadbutton2(a1,2, "buttonview.png");
    loadbutton2(a2,2, "buttonview2.png");
    loadbutton(a3,3, "fixkhudat.png");
    loadbutton(a4,4, "fixnhapho.png");
    loadbutton3(a5,4, "fixnhasanvuon.png");
    box.Loadbt("box.png", g_screen);
      while (!running)
     {
          SDL_RenderClear(g_screen);
         if (cmxoa ==1 && cmn==5)
         {
             xoanhasanvuon();
             cmn = 0;
             cmxoa = 0;
         }
         else if (cmxoa == 1 && cmn == 4)
         {
             xoanhapho();
             cmn = 0;
             cmxoa = 0;
         }
         else if(cmxoa ==1&&cmn==3)
         {
             
             xoakhudat();
             cmn = 0;
             cmxoa = 0;
           
         }
         else if (cmfind != 5 && cmfind != 0 && cmn == 4)
         {
             findnp();
         }
         else if (cmfind != 5 && cmfind != 0 && cmn == 3)
         {
             findkd();
         }
         if (cmfix != 5 && cmfix != 0 && cmn == 5)
         {
             fixnsv();
         }
         else if (cmfix != 5 && cmfix != 0 && cmn == 4)
         {
             fixnp();
         }
         else if ((cmfind == 5 && cmn == 5)||(cmfix == 5 && cmn == 5))
         {
             inmenufixnhasanvuon();
         }
         else if ((cmfind == 5 && cmn == 4) || (cmfix == 5 && cmn == 4))
         {
             inmenufixnhapho();
         }
         else if ((cmfind == 5 && cmn == 3) || (cmfix == 5 && cmn == 3))
         {
            
             inmenufixkhudat();
             
         }
         else if (cmfix != 5 && cmfix != 0 && cmn == 3)
         {
             fixkd();
         }
         else if (cmn == 5 && cmadd == 1)
         {
             cmadd = 0;
             cmn = 0;
             nsv.push_back(nhapnsv());
         }
         else if (cmadd == 1 && cmn == 4)
         {
             cmadd = 0;
             cmn = 0;
             np.push_back(nhapnp());
         }
         else if (cmadd == 1&& cmn == 3)
         {
             cmadd = 0;
             cmn = 0;
             kd.push_back(nhapkd());
         }
         else if (cmn == 0)
         {
          inmenumain();
          SDL_RenderClear(g_screen);

         }
         else if (cmn == 1)
         {
          inmenuview();
         }
         else if (cmn == 2)
         {
           inmenuview2();
         }
         else if (cmn == 3&& cmview==1)
         {
              cmview = 0;
              cmn = 0;
          Bangkd(g_screen,kd);
         }
         else if (cmn == 4&&cmview==1)
         {
              cmview = 0;
              cmn = 0;
          Bangnp(g_screen,np);
         }
         else if (cmn == 5&&cmview==1)
         {
              cmview = 0;
              cmn = 0;
          Bangnsv(g_screen,nsv);
         }
      }
    close();
    return 0;
}
bool findnp()
{

    vector<NhaPho> n;
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    switch (cmfind) {
    case 1: indulieunhap("-Nhap Dia Diem Muon Tim-"); break;
    case 2: indulieunhap("-Nhap Gia Ban Muon Tim-"); break;
    case 3: indulieunhap("-Nhap Dien Tich Xay Dung Muon Tim-"); break;
    case 4: indulieunhap("-Nhap So Tang Muon Tim-"); break;
    }
    box.draw(g_screen);
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        switch (cmfind) {
        case 1: indulieunhap("-Nhap Dia Diem Muon Tim-"); break;
        case 2: indulieunhap("-Nhap Gia Ban Muon Tim-"); break;
        case 3: indulieunhap("-Nhap Dien Tich Muon Tim-"); break;
        case 4: indulieunhap("-Nhap So Tang Muon Tim-"); break;
        }
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (cmfind) {
                case 1:
                    for (int i = 0; i < np.size(); i++)
                    {
                        if (input == np[i].takedd())
                        {
                            n.push_back(np[i]);
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < np.size(); i++)
                    {
                        if (stod(input) == np[i].takegb())
                        {
                            n.push_back(np[i]);
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < np.size(); i++)
                    {
                        if (stod(input) == np[i].takedt())
                        {
                            n.push_back(np[i]);
                        }
                    }
                    break;
                case 4:
                    for (int i = 0; i < np.size(); i++)
                    {
                        if (atoi(input.c_str()) == np[i].takest())
                        {
                            n.push_back(np[i]);
                        }
                    }
                    
                    break;
                }
                input.clear();
                cmfind = 0;
                cmn = 0;

                vebangnp(g_screen, n.size(), 5,0);
                Bangnp(g_screen, n);
                return true;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);

                }
            }
        }

    }
}
bool findkd()
{
    int chiso = 0;
    vector<Khudat> n;
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    switch (cmfind) {
    case 0: indulieunhap("-Nhap ID Khu Dat Muon Tim-"); break;
    case 1: indulieunhap("-Nhap Dia Diem Muon Tim-"); break;
    case 2: indulieunhap("-Nhap Gia Ban Muon Tim-"); break;
    case 3: indulieunhap("-Nhap Dien Tich Muon Tim-"); break;
    }
    box.draw(g_screen);
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    cout << 123;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        switch (cmfind) {
        case 1: indulieunhap("-Nhap Dia Diem Muon Tim-"); break;
        case 2: indulieunhap("-Nhap Gia Ban Muon Tim-"); break;
        case 3: indulieunhap("-Nhap Dien Tich Muon Tim-"); break;
        }
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (cmfind) {
                case 1:
                    for (int i = 0; i < kd.size(); i++)
                    {
                        if (input == kd[i].takedd())
                        {
                            n.push_back(kd[i]);
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < kd.size(); i++)
                    {
                        if (stod(input) == kd[i].takegb())
                        {
                            n.push_back(kd[i]);
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < kd.size(); i++)
                    {
                        if (stod(input) == kd[i].takedt())
                        {
                            n.push_back(kd[i]);
                        }
                    }
                    break;
                }
                cmfind = 0;
                cmn = 0;

                vebangkd(g_screen, n.size(), 4);
                Bangkd(g_screen, n);
                return true;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);

                }
            }
        }

    }
}

void inmenufixnhasanvuon()
{
    button* b = a5;


    g.render(g_screen, NULL);
    inbutton(b, 4);
    SDL_RenderPresent(g_screen);


    if (SDL_PollEvent(&g_event) == 1)
    {
        switch (g_event.type)
        {
        case SDL_QUIT:

            break;
        case SDL_MOUSEBUTTONUP:
            if (g_event.button.button == SDL_BUTTON_LEFT)
            {
                if (a5[0].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 1;
                    else if (cmfind == 5)
                        cmfind = 1;

                }
                else if (a5[1].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 2;
                    else if (cmfind == 5)
                        cmfind = 2;

                }
                else if (a5[2].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 3;
                    else if (cmfind == 5)
                        cmfind = 3;

                }
                else if (a5[3].isSelected == true)
                {

                    if (cmfix == 5)
                        cmfix = 4;
                    else if (cmfind == 5)
                        cmfind = 4;

                }
                   
                
            }
        }
    }


}
void inmenufixnhapho()
{
    button* b = a4;


    g.render(g_screen, NULL);
    inbutton(b, 4);
    SDL_RenderPresent(g_screen);


    if (SDL_PollEvent(&g_event) == 1)
    {
        switch (g_event.type)
        {
        case SDL_QUIT:

            break;
        case SDL_MOUSEBUTTONUP:
            if (g_event.button.button == SDL_BUTTON_LEFT)
            {
                if (a4[0].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 1;
                    else if (cmfind == 5)
                        cmfind = 1;
                   
                }
                else if (a4[1].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 2;
                    else if (cmfind == 5)
                        cmfind = 2;
                 
                }
                else if (a4[2].isSelected == true)
                {


                    if (cmfix == 5)
                        cmfix = 3;
                    else if (cmfind == 5)
                        cmfind = 3;
                   
                }
                else if (a4[3].isSelected == true)
                {

                    if (cmfix == 5)
                        cmfix = 4;
                    else if (cmfind == 5)
                        cmfind = 4;
                    
                }
               
            }
        }
    }


}
void inmenufixkhudat()
{
    button* b = a3;
  

    g.render(g_screen, NULL);
    inbutton(b, 3);
    SDL_RenderPresent(g_screen);
  
    
        if (SDL_PollEvent(&g_event) == 1)
        {
            switch (g_event.type)
            {
            case SDL_QUIT:
              
                break;
            case SDL_MOUSEBUTTONUP:
                if (g_event.button.button == SDL_BUTTON_LEFT)
                {
                    if (a3[0].isSelected == true)
                    {
                     
                        if (cmfix == 5)
                            cmfix = 1;
                        else if (cmfind == 5)
                            cmfind = 1;
                       
                    }
                    else if (a3[1].isSelected == true)
                    {
                        
                        if (cmfix == 5)
                            cmfix = 2;
                        else if (cmfind == 5)
                            cmfind = 2;
                       
                    }
                    else if (a3[2].isSelected == true)
                    { 
                     
                        if (cmfix == 5)
                            cmfix = 3;
                        else if (cmfind == 5)
                            cmfind = 3;
                    }
                }
            }
        }
        
    
}
void inmenumain()
{
    button* b = a;
    
    g.render(g_screen, NULL);
    inbutton(b,5);
    SDL_RenderPresent(g_screen);
    if (SDL_PollEvent(&g_event) == 1)
    {
        switch (g_event.type)
        {
        case SDL_QUIT:
            running = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (g_event.button.button == SDL_BUTTON_LEFT)
            {
                if (a[0].isSelected == true)
                {
                    
                    cmn = 1; cmview = 1;
                }
                else if (a[1].isSelected == true)
                {
                    cmn = 1; cmadd = 1;
                }
                else if (a[2].isSelected == true)
                {
                    cmn = 1; cmfix = 5;
                }
                else if (a[3].isSelected == true)
                {
                    cmn = 1; cmfind = 5;
                }
                else if (a[4].isSelected == true)
                {
                    cmn = 1; cmxoa = 1;
                }

            }

        }
    }
}
void inmenuview()
{
    
    button* b = a1;
    g.render(g_screen, NULL);
    inbutton(b,2);
    SDL_RenderPresent(g_screen);
    
    if (SDL_PollEvent(&g_event) == 1)
    {
        switch (g_event.type)
        {
        case SDL_KEYDOWN:
            if (g_event.key.keysym.sym == SDLK_ESCAPE) {
                cmn = 0;
            }
            break;
        case SDL_QUIT:
            running = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (g_event.button.button == SDL_BUTTON_LEFT)
            {
                if (a1[0].isSelected == true)
                {
                        cmn = 3;
                }
                else if (a1[1].isSelected == true)
                {
                    cmn = 2;
                }
                

            }

        }
    }
}
void inmenuview2()
{
    button* b = a2;
    g.render(g_screen, NULL);
    inbutton(b, 2);
    SDL_RenderPresent(g_screen);

    if (SDL_PollEvent(&g_event) == 1)
    {
        switch (g_event.type)
        {
        case SDL_KEYDOWN:
            if (g_event.key.keysym.sym == SDLK_ESCAPE) {
                cmn = 1;
            }
            break;
        case SDL_QUIT:
            running = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (g_event.button.button == SDL_BUTTON_LEFT)
            {
                if (a2[0].isSelected == true)
                {
                    cmn = 4; 
                }
                else if (a2[1].isSelected == true)
                {
                    cmn = 5;
                }


            }

        }
    }
}
void indulieunhap(string x);
void xoanhasanvuon()
{
    {
        SDL_RenderClear(g_screen);
        SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        indulieunhap("-Nhap ID Nha San Vuon-");
        SDL_RenderPresent(g_screen);
        TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
        SDL_Color white = { 250, 250, 250, 250 };
        string input;
        bool running = true;
        SDL_Event event;
        int a = 0;
        while (1) {
            SDL_PollEvent(&event);
            SDL_RenderClear(g_screen);
            g_background.render(g_screen, NULL);
            box.draw(g_screen);
            indulieunhap("-Nhap ID Nha San Vuon-");
            if (event.type == SDL_QUIT) {
                exit(1);
            }
            else if (event.type == SDL_TEXTINPUT) {
                // Append the input to our input string 
                input += event.text.text;
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                SDL_RenderCopy(g_screen, text, NULL, &recttt);
                SDL_RenderPresent(g_screen);
                SDL_DestroyTexture(text);
                SDL_FreeSurface(textSurface);
            }
            else if (event.type == SDL_KEYDOWN)
            {
                for (int i = 0; i < nsv.size(); i++)
                {
                    if (!strcmp(input.c_str(), nsv[i].takeid()))
                    {
                        nsv.erase(nsv.begin() + i);
                        return;
                    }
                }

            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {
                    SDL_RenderPresent(g_screen);
                }
            }
        }
    }
}
void xoakhudat()
{
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap ID Khu Dat Muon Xoa-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        indulieunhap("-Nhap ID Khu Dat Muon Xoa-");
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };


            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);


        }
        else if (event.type == SDL_KEYDOWN)
        {
            for (int i = 0; i < kd.size(); i++)
            {
                if (!strcmp(input.c_str(), kd[i].takeid()))
                {
                    kd.erase(kd.begin() + i);
                    return;
                }
            }

        }
        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
            if (input[0] != NULL)
                input.pop_back();
            if (input[0] != NULL)
            {
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                SDL_RenderCopy(g_screen, text, NULL, &recttt);
                SDL_RenderPresent(g_screen);
                SDL_DestroyTexture(text);
                SDL_FreeSurface(textSurface);

            }
            else
            {
                SDL_RenderPresent(g_screen);
            }
        }

    }
}
void xoanhapho()
{
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap ID Nha Pho Muon Xoa-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;
    int a = 0;
    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);
        indulieunhap("-Nhap ID Nha Pho Muon Xoa-");
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            // Append the input to our input string 
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };


            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);


        }
        else if (event.type == SDL_KEYDOWN)
        {
            for (int i = 0; i < np.size(); i++)
            {
                if (!strcmp(input.c_str(), np[i].takeid()))
                {
                    np.erase(np.begin() + i);
                    return;
                }
            }

        }
        else if (event.key.keysym.sym == SDLK_BACKSPACE) {
            if (input[0] != NULL)
                input.pop_back();
            if (input[0] != NULL)
            {
                SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                SDL_RenderCopy(g_screen, text, NULL, &recttt);
                SDL_RenderPresent(g_screen);
                SDL_DestroyTexture(text);
                SDL_FreeSurface(textSurface);

            }
            else
            {
                SDL_RenderPresent(g_screen);
            }
        }

    }
}
void indulieunhap(string x)
{
    SDL_Color white = { 250, 250, 250, 250 };
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, x.c_str(), white);
    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
    SDL_Rect recttt{ 640 - textSurface->w / 2,200,textSurface->w,textSurface->h };
    SDL_RenderCopy(g_screen, text, NULL, &recttt);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(textSurface);
}
NhaSanVuon nhapnsv()
{

    int dem = 0;
    NhaSanVuon nsvn;
    nsvn.capid();
   
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap Dia Diem-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);

        switch (dem) {
        case 0: indulieunhap("-Nhap Dia Diem-"); break;
        case 1: indulieunhap("-Nhap Gia Ban-"); break;
        case 2: indulieunhap("-Nhap Dien Tich Xay Dung-"); break;
        case 3: indulieunhap("-Nhap Dien Tich San Vuon-");  break;
        case 4: SDL_Delay(2000); TTF_CloseFont(font);  return nsvn;
        }

        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (dem) {
                case 0:
                    nsvn.fixdiadiem(input);
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap Gia Ban-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 1:
                    nsvn.fixgiaban(stod(input));
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap Dien Tich Xay Dung-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 2:
                    nsvn.fixdientich(stod(input));
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap Dien Tich San Vuon-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 3:
                    nsvn.fixdtsv(stod(input));
                    g_background.render(g_screen, NULL);
                    indulieunhap("-Ban Da Nhap Thanh Cong-");
                    SDL_RenderPresent(g_screen);
                    break;
                }
                input.clear();
                dem++;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE)
            {
                if (input[0] != NULL)
                {
                    input.pop_back();
                }
                if (input[0] != NULL)
                {
                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);
                }
                else
                {
                    SDL_RenderPresent(g_screen);
                }
            }
        }
    }
}
NhaPho nhapnp()
{
    int dem = 0;
    NhaPho npn;
    npn.capid();
    SDL_RenderClear(g_screen);
    SDL_SetRenderDrawColor(g_screen, 250, 250, 250, 250);
    g_background.render(g_screen, NULL);
    box.draw(g_screen);
    indulieunhap("-Nhap Dia Diem-");
    SDL_RenderPresent(g_screen);
    TTF_Font* font = TTF_OpenFont("C:/font/ArialNovaCond-Bold.ttf", 40);
    SDL_Color white = { 250, 250, 250, 250 };
    string input;
    bool running = true;
    SDL_Event event;

    while (running) {
        SDL_PollEvent(&event);
        SDL_RenderClear(g_screen);
        g_background.render(g_screen, NULL);
        box.draw(g_screen);

        switch (dem) {
        case 0: indulieunhap("-Nhap Dia Diem-"); break; 
        case 1: indulieunhap("-Nhap Gia Ban-"); break;
        case 2: indulieunhap("-Nhap Dien Tich Xay Dung-"); break;
        case 3: indulieunhap("-Nhap So Tang-");  break;
        case 4: SDL_Delay(2000); TTF_CloseFont(font);  return npn;
        }

        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_TEXTINPUT) {
            input += event.text.text;
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
            SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
            SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
            SDL_RenderCopy(g_screen, text, NULL, &recttt);
            SDL_RenderPresent(g_screen);
            SDL_DestroyTexture(text);
            SDL_FreeSurface(textSurface);
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_RETURN) {
                SDL_RenderClear(g_screen);
                switch (dem) {
                case 0:
                    npn.fixdiadiem(input);
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap Gia Ban-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 1:
                    npn.fixgiaban(stod(input));
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap Dien Tich Xay Dung-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 2:
                    npn.fixdientich(stod(input));
                    g_background.render(g_screen, NULL);
                    box.draw(g_screen);
                    indulieunhap("-Nhap So Tang-");
                    SDL_RenderPresent(g_screen);
                    break;
                case 3:
                    npn.fixsotang(atoi(input.c_str()));
                    g_background.render(g_screen, NULL);
                    indulieunhap("-Ban Da Nhap Thanh Cong-");
                    SDL_RenderPresent(g_screen);
                    break;


                }

                input.clear();
                dem++;
            }
            else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                if (input[0] != NULL)
                    input.pop_back();
                if (input[0] != NULL)
                {

                    SDL_Surface* textSurface = TTF_RenderText_Solid(font, input.c_str(), white);
                    SDL_Texture* text = SDL_CreateTextureFromSurface(g_screen, textSurface);
                    SDL_Rect recttt{ 445,357 - textSurface->h / 2,textSurface->w,textSurface->h };
                    SDL_RenderCopy(g_screen, text, NULL, &recttt);
                    SDL_RenderPresent(g_screen);
                    SDL_DestroyTexture(text);
                    SDL_FreeSurface(textSurface);

                }
                else
                {


                    SDL_RenderPresent(g_screen);


                }
            }






        }




    }
}