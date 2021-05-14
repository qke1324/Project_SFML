#include "framework.h"
#include "MainScene.h"

MainScene::MainScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}

void MainScene::Init()
{
	txBackGround.loadFromFile("Texture/background.png");
	spBackGround.setTexture(txBackGround);

	Object* player = new Player();
	objects.insert({ "Player", player });
	Object* obj = new Object("Texture/player.png", Vector2f(200.f, 200.f));
	objects.insert({ "Object", obj });
}

void MainScene::KeyBoardInput(Event* keyEvent)
{
	auto input = keyEvent->text.unicode;

	if (input == Keyboard::Escape)
	{
		EndScene();
	}

	if (input == Keyboard::W)
	{
		objects["Player"]->move(0.f, -1.f);
	}
	if (input == Keyboard::A)
	{
		objects["Player"]->move(-1.f, 0.f);
	}
	if (input == Keyboard::S)
	{
		objects["Player"]->move(0.f, 1.f);
	}
	if (input == Keyboard::D)
	{
		objects["Player"]->move(1.f, 0.f);
	}
	if (input == Keyboard::Space)
	{
	}
}

void MainScene::Update(const float& deltaTime)
{
	MouseUpdate();
	for (auto& obj : objects)
	{
		obj.second->Update(deltaTime);
	}
	objects["Player"]->rotate(1.f);

	if (objects["Object"]->getGlobalBounds().intersects(objects["Player"]->getGlobalBounds()))
	{
		// collide
	}
}

void MainScene::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(spBackGround);
		for (auto& obj : objects)
		{
			target->draw(*obj.second);
		}
	}
}
