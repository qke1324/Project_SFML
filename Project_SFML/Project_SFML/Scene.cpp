#include "framework.h"
#include "Scene.h"

Scene::Scene(RenderWindow* window, stack<Scene*>* scenes)
{
	this->window = window;
	this->scenes = scenes;
	txcursor.loadFromFile("Texture/cursor.png");
	spcursor.setTexture(txcursor);
	spcursor.setScale({ 0.1f, 0.1f });
}

Scene::Scene(RenderWindow* window, stack<Scene*>* scenes, SoundSystem* soundSys)
{
	this->window = window;
	this->scenes = scenes;
	this->soundSys = soundSys;
	txcursor.loadFromFile("Texture/cursor.png");
	spcursor.setTexture(txcursor);
	spcursor.setScale({ 0.1f, 0.1f });
}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	this->quit = true;
}

const Sprite& Scene::GetCursor() const
{
	return this->spcursor;
}

void Scene::MouseUpdate()
{
	this->mousePositionScreen = Mouse::getPosition();
	this->mousePositionWindow = Mouse::getPosition(*this->window);
	this->mousePositionView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
	spcursor.setPosition(mousePositionView);
}
