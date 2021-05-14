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

void MainScene::Input(Event* keyEvent)
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

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		cout << mousePositionView.x << " / " << mousePositionView.y << endl;
	}

}

void MainScene::Update(const float& deltaTime)
{
	MouseUpdate();
	
	for (auto& obj : objects)
	{
		obj.second->Update(deltaTime);
	}
	float rotX = mousePositionView.x - objects["Player"]->getPosition().x;
	float rotY = mousePositionView.y - objects["Player"]->getPosition().y;
	
	float rotation = (atan2(rotY, rotX)) * 180 / PI;

	objects["Player"]->setRotation(rotation);

	float dirX = mousePositionView.x - objects["Player"]->getPosition().x;
	float dirY = mousePositionView.y - objects["Player"]->getPosition().y;
	float length = sqrt(
		(mousePositionView.x - objects["Player"]->getPosition().x) * (mousePositionView.x - objects["Player"]->getPosition().x) +
		(mousePositionView.y - objects["Player"]->getPosition().y) * (mousePositionView.y - objects["Player"]->getPosition().y));
	dirX /= length;
	dirY /= length;

	objects["Player"]->move(dirX, dirY);

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
