#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class DRAW {
    double x;
    double y;
    double angle;
    int width;
    int height;
    SDL_Color color;
    SDL_Renderer* renderer;
    TTF_Font* font;

   public:
    DRAW (SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font);

    void setPosition(double x, double y);
    double getX() const 
    { 
        return x; 
    }
    double getY() const 
    { 
        return y; 
    }

    void setAngle(double angle);
    double getAngle() const 
    { 
        return angle; 
    }

    int getWidth() const 
    { 
        return width; 
    }
    int getHeight() const 
    { 
        return height; 
    }

    void setColor(SDL_Color color);
    SDL_Color getColor() const 
    { 
        return color; 
    }

    SDL_Renderer* getRenderer() const 
    { 
        return renderer; 
    }

    void clearWithBgColor(SDL_Color color);

    void getRandomColor();

    SDL_Texture* loadTexture(std::string filepath);
    SDL_Texture* textTexture(std::string text, SDL_Rect* srcRect, SDL_Rect* desRect, double _x = 0, double _y = 0);
    SDL_Texture* loadImage(std::string text, SDL_Rect* srcRect, SDL_Rect* desRect, double _x = 0, double _y = 0);
    bool createImage(SDL_Texture* texture);
};

#endif