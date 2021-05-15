#include "framework.h"
#include "SettingScene.h"

SettingScene::SettingScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}
SettingScene::SettingScene(RenderWindow* window, stack<Scene*>* scenes, SoundSystem* soundSys)
	:Scene(window, scenes, soundSys)
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
		Color::Green, Color::Blue, Color::Yellow);

	buttons["SoundOFF"] = new Button(
		{ 167.f, 246.f }, { 100.f, 100.f },
		"Fonts/Dosis-Light.ttf", "SoundOFF",
		Color::Cyan, Color::Blue, Color::Yellow);

	buttons["SoundON"] = new Button(
		{ 296.f, 246.f }, { 100.f, 100.f },
		"Fonts/Dosis-Light.ttf", "SoundON",
		Color::Blue, Color::Blue, Color::Yellow);

	buttons["SoundPause"] = new Button(
		{ 450.f, 246.f }, { 100.f, 100.f },
		"Fonts/Dosis-Light.ttf", "SoundPause",
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
	MouseUpdate();

	for (auto& button : buttons)
	{
		button.second->Update(mousePositionView);
	}

	if (buttons["Volume+"]->isPressd())
	{
		soundSys->VolumeUp();
	}
	if (buttons["Volume-"]->isPressd())
	{
		soundSys->VolumeDown();
	}
	if (buttons["SoundOFF"]->isPressd())
	{
		soundSys->Stop();
	}
	if (buttons["SoundON"]->isPressd())
	{
		soundSys->Play();
	}
	if (buttons["SoundPause"]->isPressd())
	{
		soundSys->Pause();
	}

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
