#include "Image.h"
#include <SDL.h>
#include <cstdio>
#include <iostream>
#include <SDL_image.h>
#include "RenderWindow.h"

using namespace std;

Image::Image(const char* path, RenderWindow& window) : 
texture{window.loadTexture(path)},
success{texture != nullptr},
x{},
y{},
width{100},
height{100} { }