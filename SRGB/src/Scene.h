#pragma once


#include <iostream>
#include <queue>
#include "Model.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"

struct SceneLights {

	std::vector<PointLight> pointLights;
	std::vector<DirLight>	dirLights;
};


//TODO: Add scene to renderer class?
class Scene {
public:

	Scene();

	std::queue<Model*>* createRenderQueue();//Camera culling etc etc
	
	void onUpdate(float delta_t);

	//LIGHTS
	SceneLights* getLights();

	Camera* getCam();

	//Scene swapping utility: This should be in a separate class such as sceneUtility. 
	void changeScene();
	int m_scene_ID;
	const int max_scenes = 2;

private:
	
	

	std::vector<Model> m_models_in_scene;//owner
	std::queue<Model*> m_render_queue; //This should be in renderer i think
	SceneLights m_lights_in_scene;

	// INSTEAD OF A VECTOR TO STORE THE MATERIALS A MAP OR SOMETHING WITH NAME WOULD BE BETTER
	std::vector<Material> m_material_list;

	Camera m_camera;


};

