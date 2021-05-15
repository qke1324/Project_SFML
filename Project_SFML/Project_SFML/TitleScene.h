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
	virtual ~TitleScene();

private:

	map<string, Button*> buttons;
	ParticleSystem* particleSys = nullptr;
	SoundSystem* soundSys = nullptr;


private:

	virtual void Init() override;

public:

	virtual void Input(Event* keyEvent) override;
	virtual void Update(const float& deltaTime) override;
	virtual void Render(RenderTarget* target) override;

};

