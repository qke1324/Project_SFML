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
	
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		objects["Player"]->MoveUpdate({ 0.f, -10.f });
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		objects["Player"]->MoveUpdate({ -10.f, 0.f });
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		objects["Player"]->MoveUpdate({ 0.f, 10.f });
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		objects["Player"]->MoveUpdate({ 10.f, 0.f });
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
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
