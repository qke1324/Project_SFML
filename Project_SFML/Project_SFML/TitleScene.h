#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:

	TitleScene() = default;
	TitleScene(RenderWindow* window, stack<Scene*>* scenes);
	TitleScene(const TitleScene&) = delete;
	TitleScene& operator=(const TitleScene&) = delete;
	virtual ~TitleScene() = default;

private:

	map<string, RectangleShape*> buttons;

private:

	virtual void Init();

public:

	virtual void KeyBoardInput(Event* keyEvent);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderTarget* target);

};

