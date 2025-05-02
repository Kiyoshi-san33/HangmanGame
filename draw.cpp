#include "file/draw.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

void DRAW::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
}

void DRAW::setAngle(double angle) {
    this->angle = angle - floor(angle / 360) * 360;
}

void DRAW::setColor(SDL_Color color) {
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void DRAW::clearWithBgColor(SDL_Color bgColor) {
    SDL_Color Color_ = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(Color_);
}

SDL_Texture* DRAW::loadTexture(string filepath) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());
    if (loadedSurface == NULL)
        cout << "Unable to load image " << filepath << " SDL_image Error: " << IMG_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << filepath << " SDL Error: " << SDL_GetError() << endl;
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

SDL_Texture* DRAW::loadImage(string filepath, SDL_Rect* srcRect, SDL_Rect* desRect, double _x, double _y) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());
    if (loadedSurface == NULL)
        cout << "Unable to load image " << filepath << " SDL_image Error: " << IMG_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << filepath << " SDL Error: " << SDL_GetError() << endl;
        SDL_FreeSurface(loadedSurface);
    }

    Uint32 format;
    SDL_QueryTexture(newTexture, &format, NULL, &srcRect->w, &srcRect->h);
    srcRect->x = 0;
    srcRect->y = 0;
    desRect->x = _x;
    desRect->y = _y;
    desRect->w = srcRect->w;
    desRect->h = srcRect->h;
    return newTexture;
}

SDL_Texture* DRAW::textTexture(string text, SDL_Rect* srcRect, SDL_Rect* desRect, double _x, double _y) {
    SDL_Color a = {140, 160, 45};
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), a);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    TTF_SizeText(font, text.c_str(), &srcRect->w, &srcRect->h);
    srcRect->x = 0;
    srcRect->y = 0;
    desRect->x = _x;
    desRect->y = _y;
    desRect->w = srcRect->w;
    desRect->h = srcRect->h;
    return texture;
}

bool DRAW::createImage(SDL_Texture* texture) {
    if (texture == NULL) return false;
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    return true;
}

DRAW::DRAW(SDL_Window* window = nullptr, SDL_Renderer* renderer_ = nullptr, TTF_Font* font_ = nullptr) : renderer(renderer_), font(font_) {
    if (window == nullptr) return;
    SDL_RenderGetLogicalSize(renderer, &width, &height);
    if (width == 0 && height == 0)
        SDL_GetWindowSize(window, &width, &height);
    
    setPosition(width / 2, height / 2);
    setAngle(0);
    setColor({255, 255, 255});
    clearWithBgColor({255, 255, 255});
}

void DRAW::getRandomColor() {
    Uint8 r = rand() % 256;
    Uint8 g = rand() % 256;
    Uint8 b = rand() % 256;
    SDL_Color color = {r, g, b};
    setColor(color);
}
