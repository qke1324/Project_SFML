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
	RectangleShape* startbutton = new RectangleShape(Vector2f(100.f, 100.f));
	startbutton->setFillColor(Color::Red);
	buttons.insert({ "Start", startbutton });

	Font* startfont = new Font();
	startfont->loadFromFile("Fonts/Dosis-Light.ttf");
	
	fonts.insert({ "Start", startfont });
	
	Text* starttext = new Text();
	starttext->setFont(*startfont);
	starttext->setString("Start");
	starttext->setFillColor(Color::White);
	starttext->setPosition(startbutton->getPosition().x, startbutton->getPosition().y);
	texts.insert({ "Start", starttext });

}

void TitleScene::Input(Event* keyEvent)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		scenes->push(new MainScene(window, scenes));
	}
}

void TitleScene::Update(const float& deltaTime)
{
	MouseUpdate();
}

void TitleScene::Render(RenderTarget* target)
{
	if (target)
	{
		for (auto& button : buttons)
		{
			target->draw(*button.second);
		}
		for (auto& text : texts)
		{
			target->draw(*text.second);
		}
	}
}
