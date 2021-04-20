#pragma once
#include "SDL.h"
#include "Camera.h"
#include "Renderer.h"
#include "Shader.h"

class InputHandler {
public:

	InputHandler(Camera *cam, Renderer* m_renderer);
	~InputHandler();

	void onUpdate(bool &running);

private:

	Camera *m_sceneCam;
	Renderer* m_renderer;
	void handleSDLevent(bool &running, SDL_Event &event);

};

