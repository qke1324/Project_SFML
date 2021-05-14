#pragma once
#include "Scene.h"

class ParticleSystem;

class TitleScene : public Scene
{
public:

	TitleScene() = default;
	TitleScene(RenderWindow* window, stack<Scene*>* scenes);
	TitleScene(const TitleScene&) = delete;
	TitleScene& operator=(const TitleScene&) = delete;
	virtual ~TitleScene() = default;

private:

	map<string, Button*> buttons;
	ParticleSystem* particleSys = nullptr;

private:

	virtual void Init();

public:

	virtual void Input(Event* keyEvent);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderTarget* target);

};

