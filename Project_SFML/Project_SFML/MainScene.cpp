#include "framework.h"
#include "MainScene.h"

MainScene::MainScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}

MainScene::~MainScene()
{
	if (!objects.empty())
	{
		for (auto& object : objects)
		{
			SAFE_DELETE(object.second);
		}
		objects.clear();
	}
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

	float dirX = mousePositionView.x - objects["Player"]->getPosition().x;
	float dirY = mousePositionView.y - objects["Player"]->getPosition().y;

	// sprite texture 
	// dir top = 90;
	float rotation = ((atan2(dirY, dirX)) * 180.f / PI) + 90.f;
	objects["Player"]->setRotation(rotation);

	// move dir
	float length = sqrt((dirX * dirX) + (dirY * dirY));
	objects["Player"]->move(dirX / length, dirY / length);

	//collide check
	if (objects["Object"]->getGlobalBounds().intersects(objects["Player"]->getGlobalBounds()))
	{
		objects["Object"]->SetActive(false);
	}
}

void MainScene::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(spBackGround);
		for (auto& obj : objects)
		{
			if (obj.second->isActive())
			{
				target->draw(*obj.second);
			}
		}
	}
}
