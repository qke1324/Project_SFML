#include "GameState.h"

CGameState::CGameState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	: CState(window, supportedKeys,states)
{
	this->InitKeybinds();
}

CGameState::~CGameState()
{
}

void CGameState::InitKeybinds()
{
	ifstream in("Config/gamestate_keybinds.ini");

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


void CGameState::UpdateInput(const float& deltatime)
{
	

	//Update Player input
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.Move(deltatime, -1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.Move(deltatime, 1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.Move(deltatime, 0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.Move(deltatime, 0.f, 1.f);
	
	if (Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->EndState();
}

void CGameState::Update(const float& deltatime)
{
	this->UpdateMousePositions();
	this->UpdateInput(deltatime);

	this->player.Update(deltatime);
}

void CGameState::Render(RenderTarget* target)
{
	if (target) 
	{
		this->player.Render(target);
	}
	else
	{
		this->player.Render(this->window);
	}
}
