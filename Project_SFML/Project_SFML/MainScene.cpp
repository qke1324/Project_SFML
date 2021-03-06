#include "framework.h"
#include "MainScene.h"

MainScene::MainScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}

MainScene::MainScene(RenderWindow* window, stack<Scene*>* scenes, SoundSystem* soundSys, ParticleSystem* particleSys)
	: Scene(window, scenes, soundSys, particleSys)
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
	particleSys->Update(deltaTime);
	for (auto& obj : objects)
	{
		obj.second->Update(deltaTime);
	}

	// rotate with angle
	float rotation = Math::RotateAxis(objects["Object"]->getPosition(), objects["Player"]->getPosition(), 90.f);
	objects["Player"]->setRotation(rotation);

	// move dir
	objects["Player"]->move(Math::Normalize(objects["Object"]->getPosition(), objects["Player"]->getPosition()));
	
	//collide check
	if (objects["Object"]->getGlobalBounds().intersects(objects["Player"]->getGlobalBounds()))
	{
		soundSys->EffectPlay("hit");
		particleSys->ParticleOn(objects["Object"]->getPosition());
		objects["Object"]->setPosition(Math::RandomFloat(), Math::RandomFloat());
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
		particleSys->Render(target);
	}
}
