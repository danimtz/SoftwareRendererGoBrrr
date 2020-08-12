#include "Scene.h"


Scene::Scene()
{
	//TEMPORARY MODEL CREATION LATER WILL BE DONE TRHOUGH READING A FILE OR SOMETHING. 
	//CAM PROPERTIES SHOULD BE SPECIFIED IN FILE AS WELL AND PUT INTO A STRUCT LIKE CAM_PROPERTIES

	Mat4f rot,sc,trs,transf;
	Model *model;
	

	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(0.4, 0.4, 0.4));
	trs = Mat4f::createTranslation(Vec3f(1, 0, 0));
	transf = trs*rot*sc;
	model = new Model("assets\\head.obj","assets\\african_head_diffuse.tga", transf);
	m_models_in_scene.push_back(model);


	
	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(4, 4, 4));
	trs = Mat4f::createTranslation(Vec3f(-1, -0.5, 0));
	transf = trs * rot * sc;
	model = new Model("assets\\bunnyHD.obj", transf);
	m_models_in_scene.push_back(model);
	


	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(0.2, 0.2, 0.2));
	trs = Mat4f::createTranslation(Vec3f(0, 0, 0));
	transf = trs * rot * sc;
    model = new Model("assets\\survival_guitar\\source\\guitar.obj", "assets\\survival_guitar\\source\\1001_albedo.jpg", transf);
	//model = new Model("assets\\survival_guitar\\source\\guitar.obj", transf);

	m_models_in_scene.push_back(model);
	












	m_camera = new Camera(Vec3f(0, 0, 1), 0.0f, -90.0f);


	//Lights

	//1 light only for now
	Light *light = new Light(Vec3f(0.3, 0.8, 1));
	
	m_lights_in_scene.push_back(light);


	std::cout<< "Finished scene setup."<<std::endl;

}

Scene::~Scene()
{
	// Deallocate models in vector
	for (int i = 0; i < m_models_in_scene.size(); ++i)
	{
		delete m_models_in_scene[i]; 
	}

	// Deallocate lights in vector
	for (int i = 0; i < m_lights_in_scene.size(); ++i)
	{
		delete m_lights_in_scene[i];
	}

	delete m_camera;
}


std::queue<Model*>* Scene::createRenderQueue()//Put models to be rendered from scene in queue.
{
	//CURRENLY JUST PLACES ALL MODELS IN SCENE IN THE QUEUE. CHANGE THIS LATER


	for (int i = 0; i < m_models_in_scene.size(); i++)
	{
		
		m_render_queue.push(m_models_in_scene[i]);
	}

	return &m_render_queue;
}

std::vector<Light*>& Scene::getLights()
{
	return m_lights_in_scene;
}

Camera* Scene::getCam() const
{
	return m_camera;
}