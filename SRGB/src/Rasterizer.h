#pragma once

#include <iostream>

#include "Vector3.h"
#include "Matrix4.h"
#include "Buffer.h"
#include "SDL.h"
#include "Model.h"


//Static method class. 
class Rasterizer {

public:
		

	static void drawLine(int x0, int y0, int x1, int y1, Buffer<uint32_t> *px_buff, uint32_t colour);

	//verts are Vec3f verts[3] and must be in viewport coordinates
	static void drawWireFrame(const Vec3f *verts, Buffer<uint32_t> *px_buff, uint32_t colour);

	
	static void drawTriangle(const Vec3f *verts, Buffer<uint32_t> *px_buff, uint32_t colour);//colour should later be like shader or something and maybe needs zbuffer

	//Simple version of drawTriangle()
	static void simpleRasterizeTri(const Vec3f *verts, const Vec2f *uvVerts, const Texture *texture, Buffer<uint32_t> *px_buff,  Buffer<float> *z_buff, float intensity);

private:

	Rasterizer();
	
	//Traingle rasterizing help functions

	//TODO
	static void setTriBBox(Vec2i &min, Vec2i &max, const Vec3f *verts, int vp_width, int vp_height);
	
	static float edgeFunct(const Vec3f &v0, const Vec3f &v1, const Vec3f p);


	//SDL surface pixel formats
	static const uint32_t PX_FORMAT = SDL_PIXELFORMAT_RGB888;
	static const SDL_PixelFormat *px_format;

	//Colours
	static const uint32_t red;
	static const uint32_t green;
	static const uint32_t blue; 
	static const uint32_t white;


};

