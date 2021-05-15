#pragma once
#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene() = default;
	MainScene(RenderWindow* window, stack<Scene*>* scenes);
	MainScene(const MainScene&) = delete;
	MainScene& operator=(const MainScene&) = delete;
	virtual ~MainScene();

private:

	Sprite spBackGround;
	Texture txBackGround;

	map<string, Object*> objects;

private:

	virtual void Init() override;

public:

	virtual void Input(Event* keyEvent) override;
	virtual void Update(const float& deltaTime) override;
	virtual void Render(RenderTarget* target) override;
};

