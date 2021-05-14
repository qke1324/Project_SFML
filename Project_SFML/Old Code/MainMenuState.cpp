#include "MainMenuState.h"

CMainMenuState::CMainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	: CState(window, supportedKeys, states)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFonts();
	this->InitKeybinds();
	this->InitButtons();


	this->background.setSize(Vector2f(window->getSize()));
	this->background.setFillColor(Color::Magenta);
}

CMainMenuState::~CMainMenuState()
{
	auto it = this->buttons.begin();

	for (; it != this->buttons.end(); ++it) {
		delete it->second;
	}
}


void CMainMenuState::InitVariables()
{

}

void CMainMenuState::InitBackground()
{
	this->background.setSize(
		Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	if (!this->backgroundTexture.loadFromFile("Images/mainmenu_background.png")) {
		throw("ERROR : MAIN_MENU_STATE - FILE NOT LOAD");
	}
	this->background.setTexture(&this->backgroundTexture);
}

void CMainMenuState::InitFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR : MAINMENUSTATE - FONT NOT LOAD");
	}

}

void CMainMenuState::InitKeybinds()
{
	ifstream in("Config/mainmenustate_keybinds.ini");

	if (in.is_open()) {
		string key{};
		string key2{};
		while (in >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	in.close();
}

void CMainMenuState::InitButtons()
{
	this->buttons["GAME_STATE"] = new CButton(280, 328, 250, 50,
		&this->font, "New Game",
		Color::Magenta, Color::Blue, Color::Yellow);

	this->buttons["SETTINGS"] = new CButton(280, 447, 250, 50,
		&this->font, "Settings",
		Color::Magenta, Color::Blue, Color::Yellow);

	this->buttons["EXIT_STATE"] = new CButton(280, 647, 250, 50,
		&this->font, "Quit",
		Color::Magenta, Color::Blue, Color::Yellow);
}

void CMainMenuState::UpdateInput(const float& deltatime)
{

}

void CMainMenuState::UpdateButtons()
{
	
	for (const auto& it : this->buttons) {
		it.second->Update(this->mousePosView);
	}

	//New Game
	if (this->buttons["GAME_STATE"]->isPressd()) {
		this->states->push(new CGameState(this->window, this->supportedKeys, this->states));
	}
	
	//Quit Game
	if (this->buttons["EXIT_STATE"]->isPressd()) {
		this->EndState();
	}

}

void CMainMenuState::Update(const float& deltatime)
{
	this->UpdateMousePositions();
	this->UpdateInput(deltatime);

	this->UpdateButtons();
}

void CMainMenuState::RenderButtons(RenderTarget* target)
{
	for (const auto& it : this->buttons) {
		it.second->Render(target);
	}
}


void CMainMenuState::Render(RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->RenderButtons(target);

	//
	Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(20);
	stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);
}
