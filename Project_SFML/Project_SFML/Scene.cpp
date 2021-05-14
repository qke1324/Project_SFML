#include "framework.h"
#include "Scene.h"

Scene::Scene(RenderWindow* window, stack<Scene*>* scenes)
{
	this->window = window;
	this->scenes = scenes;
}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	this->quit = true;
}

void Scene::MouseUpdate()
{
	this->mousePositionScreen = Mouse::getPosition();
	this->mousePositionWindow = Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}
