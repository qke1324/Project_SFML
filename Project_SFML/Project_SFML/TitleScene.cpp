#include "framework.h"
#include "TitleScene.h"
#include "MainScene.h"

TitleScene::TitleScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}

void TitleScene::Init()
{
	buttons["START"] = new Button(
		{ 200.f, 300.f }, { 100.f, 50.f }, 
		"Fonts/Dosis-Light.ttf", "START", 
		Color::Magenta, Color::Blue, Color::Yellow);

}

void TitleScene::Input(Event* keyEvent)
{

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
		scenes->push(new MainScene(window, scenes));
	}

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
	}
}
