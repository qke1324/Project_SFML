#include "Game.h"

//Static Funtions



//Constructor/Destructor
CGame::CGame() {
	this->InitWindow();
	this->InitKeys();
	this->InitStates();
}

CGame::~CGame() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop(); 
	}

} 

void CGame::InitVariables()
{
	this->window = NULL;
	this->fullscreen = false;
	this->deltatime = 0.f;
}

//Initializer Funtions
void CGame::InitWindow()
{
	/*Create a SFML window using options from a window.ini file.*/

	ifstream in("Config/window.ini");

	this->videoModes = VideoMode::getFullscreenModes();

	string title = "None";
	VideoMode window_bounds =VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertival_sync_enabled = false;
	unsigned antialiasing_level = 0;

	if (in.is_open()) {
		getline(in, title);
		in >> window_bounds.width >> window_bounds.height;
		in >> fullscreen;
		in >> framerate_limit;
		in >> vertival_sync_enabled;
		in >> antialiasing_level;
	}

	in.close();

	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialiasing_level;
	
	if (this->fullscreen)
		this->window = new RenderWindow(window_bounds, title, Style::Fullscreen, windowSettings);
	else
		this->window = new RenderWindow(window_bounds, title, Style::Titlebar | Style::Close, windowSettings);
	
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertival_sync_enabled);

}

void CGame::InitStates()
{
	this->states.push(new CMainMenuState(this->window, &this->supportedKeys, &this->states));
}

void CGame::InitKeys()
{
	ifstream in("Config/supportedkey.ini");

	if (in.is_open()) {
		string key{};
		int key_val{ 0 };
		while (in >> key >> key_val)
		{
			this->supportedKeys[key] = key_val;
		}
	}
	in.close();
}

void CGame::EndApplication()
{
	cout << "end app" << endl;
}

void CGame::UpdateDeltaTime()
{
	/*Update the deltatime variable with the time it takes to update and render one frame*/
	this->deltatime = this->deltaClock.restart().asSeconds();
}

void CGame::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->sfevent))
	{
		if (this->sfevent.type == Event::Closed)
			this->window->close();
	}
}

void CGame::Update()
{
	this->UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->deltatime);

		if (this->states.top()->getQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->EndApplication();
		this->window->close();
	}
}
void CGame::Render()
{

	this->window->clear();

	//Render Items;
	if (!this->states.empty()) {
		this->states.top()->Render(this->window);
	}

	this->window->display();
}

void CGame::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	}
}
