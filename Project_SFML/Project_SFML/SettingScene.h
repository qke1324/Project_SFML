#pragma once
#include "Scene.h"
class SettingScene : public Scene
{
public:
	SettingScene() = default;
	SettingScene(RenderWindow* window, stack<Scene*>* scenes);
	SettingScene(const SettingScene&) = delete;
	SettingScene& operator=(const SettingScene&) = delete;
	virtual ~SettingScene() = default;

protected:

	map<string, Button*> buttons;

private:

	virtual void Init() override;

public:

	virtual void Input(Event* keyEvent) override;
	virtual void Update(const float& deltaTime) override;
	virtual void Render(RenderTarget* target) override;
};

