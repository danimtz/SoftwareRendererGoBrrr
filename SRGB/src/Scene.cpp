#include "Scene.h"


Scene::Scene()
{
	//Create materials
	m_material_list.push_back(new Material());


	//TEMPORARY MODEL CREATION LATER WILL BE DONE TRHOUGH READING A FILE OR SOMETHING. 
	//CAM PROPERTIES SHOULD BE SPECIFIED IN FILE AS WELL AND PUT INTO A STRUCT LIKE CAM_PROPERTIES
	Mat4f rot,sc,trs,transf;
	Model *model;
	


	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(0.4, 0.4, 0.4));
	trs = Mat4f::createTranslation(Vec3f(1, 0, 0));
	transf = trs*rot*sc;
	model = new Model("assets\\head.obj","assets\\african_head_diffuse.tga", m_material_list[0], transf);
	m_models_in_scene.push_back(model);


	
	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(4, 4, 4));
	trs = Mat4f::createTranslation(Vec3f(-1, -0.5, 0));
	transf = trs * rot * sc;
	model = new Model("assets\\bunnyHD.obj", m_material_list[0], transf);
	m_models_in_scene.push_back(model);
	


	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(0.2, 0.2, 0.2));
	trs = Mat4f::createTranslation(Vec3f(0, 0, 0));
	transf = trs * rot * sc;
    model = new Model("assets\\survival_guitar\\source\\guitar.obj", "assets\\survival_guitar\\source\\1001_albedo.jpg", m_material_list[0], transf);
	m_models_in_scene.push_back(model);
	


	rot = Mat4f::createRotAxis(Vec3f(0, 0, 0));
	sc = Mat4f::createScale(Vec3f(10, 0.5, 10));
	trs = Mat4f::createTranslation(Vec3f(0, -0.5, 0));
	transf = trs * rot * sc;
	model = new Model("assets\\cube.obj", m_material_list[0], transf);
	//m_models_in_scene.push_back(model);



	m_camera = new Camera(Vec3f(0, 0, 1), 0.0f, -90.0f);


	//Lights

	//POTENTIAL MEMORY LEAK IF NOT ADDED TO VECTOR
	//new Light(Vec3f(0, 0, -1), Vec3f(0,0,0), Vec3f(0.2, 0.8, 0.9)); //BLUEISH LIGHT


	m_lights_in_scene.push_back(new Light(Vec3f(0.7, 0.8, 1), Vec3f(0, 0, 0), Vec3f(0.7, 0.4, 0.15))); //Sun colouredish


	
	m_lights_in_scene.push_back(new Light(Vec3f(0, 0.3, -1), Vec3f(0, 0, 0), Vec3f(0.4, 0.5, 0.9)) ); //BACK


	m_lights_in_scene.push_back(new Light(Vec3f(0, 0.5, 1), Vec3f(0, 0, 0), Vec3f(0.9, 0.9, 0.9)) ); //FRONT




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

	// Deallocate materials in vector
	for (int i = 0; i < m_material_list.size(); ++i)
	{
		delete m_material_list[i];
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