//
//  surface.h
//  sdl_1
//
//  Created by Casuneanu Andrei on 20/05/14.
//  Copyright (c) 2014 Casuneanu Andrei. All rights reserved.
//

#ifndef sdl_1_surface_h
#define sdl_1_surface_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cstring>
#include <fstream>
using namespace std;

class surface
{
	public:
	~surface();
	bool read(string);
	void set_xy(int a, int b) {x=a; y=b;}
	void set_misc(int a, int b) {mx=a; my=b;}
	void set_sec(int x) {sec=x;}
	void set_wh(int width,int height) {wu=width; hu=height;}
	//de ce sunt definite aici? pentru ca se fac automat inline si asa economisesc mult timp :D
	bool render();
	void load_from_text(string, SDL_Color);
	void free();
	//void handle_e(SDL_Event&);//referinta
	//getpixel
	//setpixel
	
	private:
	SDL_Surface* sur;
	SDL_Texture* tex;
	SDL_Rect poz;
	//SDL_Rect* clip;
	int x, y;
	int w, h;
	int last_tick;
	int inceput;
	int wu, hu;//width utilizator, height utilizator
	int mx, my;//miscarea pe x/y intr-o sec
	int sec;//numarul de secunde, -1 pentru infinit
	//callback function
	bool repeat_x, repeat_y;
};


class frames_per_second
{
	public:
	double get_fps();
	void record();
	
	private:
	double fps;
	int last, now;
	int frames;
};

extern frames_per_second FPS;


/*class sprite_sheet
{
	public:
	
	private:
	
};*/

#endif
