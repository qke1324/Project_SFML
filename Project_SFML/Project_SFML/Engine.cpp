#include "framework.h"
#include "Engine.h"
#include "MainScene.h"
#include "TitleScene.h"

Engine::Engine()
{
	Init();
}

void Engine::Init()
{
	this->window = new RenderWindow(VideoMode(win_info.WINDOW_WIDTH, win_info.WINDOW_HEIGHT), win_info.windowName);
	this->window->setFramerateLimit(win_info.framerateLimit);
	this->window->setVerticalSyncEnabled(win_info.verticalSync);
	this->window->setMouseCursorVisible(win_info.mouseCursor);
	scenes.push(new TitleScene(this->window, &this->scenes));
}

void Engine::Destroy()
{
	SAFE_DELETE(window);
}

void Engine::Input()
{
	if (!scenes.empty())
	{
		scenes.top()->Input(&this->event);
		return;
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}
}

void Engine::EventUpdate()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case Event::Closed:
		{
			this->window->close();
			break;
		}
		case Event::MouseButtonPressed:
		case Event::KeyPressed:
		{
			this->Input();
			break;
		}
		default:
			break;
		}
	}
}

void Engine::SceneUpdate()
{
	if (!scenes.empty())
	{
		this->scenes.top()->Update(deltaTime);

		if (this->scenes.top()->GetQuit())
		{
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
}

void Engine::Update()
{
	deltaTime = this->timer.restart().asSeconds();
	EventUpdate();
	SceneUpdate();
}

bool Engine::Render()
{
	if (window->isOpen())
	{
		this->window->clear();
		this->Update();

		//Render Scene
		if (!scenes.empty())
		{
			this->scenes.top()->Render(this->window);
			window->draw(this->scenes.top()->GetCursor());
		}
		else
		{
			return false;
		}

		this->window->display();
		return true;
	}
	else
	{
		return false;
	}

	return false;
}
