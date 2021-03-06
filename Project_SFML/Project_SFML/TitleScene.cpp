#include "framework.h"
#include "TitleScene.h"
#include "MainScene.h"
#include "SettingScene.h"
#include "ParticleSystem.h"

TitleScene::TitleScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}
TitleScene::~TitleScene()
{
	SAFE_DELETE(particleSys);

	if (!buttons.empty())
	{
		for (auto& button : buttons)
		{
			SAFE_DELETE(button.second);
		}
		buttons.clear();
	}

	SAFE_DELETE(soundSys);

}
void TitleScene::Init()
{
	buttons["START"] = new Button(
		{ 200.f, 300.f }, { 100.f, 50.f }, 
		"Fonts/Dosis-Light.ttf", "START", 
		Color::Magenta, Color::Blue, Color::Yellow);

	buttons["QUIT"] = new Button(
		{ 200.f, 400.f }, { 100.f, 50.f },
		"Fonts/Dosis-Light.ttf", "QUIT",
		Color::Magenta, Color::Blue, Color::Yellow);

	buttons["Setting"] = new Button(
		{ 200.f, 500.f }, { 100.f, 50.f },
		"Fonts/Dosis-Light.ttf", "Setting",
		Color::Magenta, Color::Blue, Color::Yellow);

	particleSys = new ParticleSystem(100);
	soundSys = new SoundSystem("Sound/NooMA-Mauve.wav", true);
	soundSys->AddEffectSound("Sound/swing.wav", "swing");
	soundSys->AddEffectSound("Sound/hit.wav", "hit");
	soundSys->Play();
}

void TitleScene::Input(Event* keyEvent)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		particleSys->ParticleOn(mousePositionView);
	}
}

void TitleScene::Update(const float& deltaTime)
{
	MouseUpdate();

	for (auto& button : buttons)
	{
		button.second->Update(mousePositionView);
	}

	if (buttons["START"]->isPressd())
	{
		scenes->push(new MainScene(window, scenes, soundSys, particleSys));
	}
	if (buttons["QUIT"]->isPressd())
	{
		EndScene();
	}
	if (buttons["Setting"]->isPressd())
	{
		scenes->push(new SettingScene(window, scenes, soundSys));
	}

	particleSys->Update(deltaTime);
}

void TitleScene::Render(RenderTarget* target)
{
	if (target)
	{
		for (auto& button : buttons)
		{
			target->draw(*button.second);
			target->draw(*button.second->GetText());
		}
		particleSys->Render(target);
	}
}
