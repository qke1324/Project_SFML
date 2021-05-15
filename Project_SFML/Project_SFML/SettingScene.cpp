#include "framework.h"
#include "SettingScene.h"

SettingScene::SettingScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}
SettingScene::~SettingScene()
{
	if (!buttons.empty())
	{
		for (auto& button : buttons)
		{
			SAFE_DELETE(button.second);
		}
		buttons.clear();
	}
}
void SettingScene::Init()
{
	/*
	167 / 136
	296 / 135
	167 / 246
	325 / 255
	*/
	buttons["Volume+"] = new Button(
		{ 167.f, 136.f }, { 100.f, 100.f },
		"Fonts/Dosis-Light.ttf", "Volume+", 
		Color::Magenta, Color::Blue, Color::Yellow);

	buttons["Volume-"] = new Button(
		{ 296.f, 135.f }, { 100.f, 100.f },
		"Fonts/Dosis-Light.ttf", "Volume-",
		Color::Yellow, Color::Blue, Color::Yellow);
}

void SettingScene::Input(Event* keyEvent)
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		EndScene();
	}
}

void SettingScene::Update(const float& deltaTime)
{

}

void SettingScene::Render(RenderTarget* target)
{
	if (target)
	{
		for (auto& button : buttons)
		{
			target->draw(*button.second);
			target->draw(*button.second->GetText());
		}
	}
}
