#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "MainMenuState.h"

class CGame
{
public:
	CGame();
	virtual ~CGame();

private:

	//Variables
	RenderWindow* window;
	Event sfevent;
	vector<VideoMode> videoModes;
	ContextSettings windowSettings;
	bool fullscreen{ false };
	Clock deltaClock;
	float deltatime{ 0.f };

	stack<CState*> states;

	map<string, int> supportedKeys;

	//Initalization
	void InitVariables();
	void InitWindow();
	void InitKeys();
	void InitStates();

public:

	//Reguler
	void EndApplication();

	//Update
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();

	//Render
	void Render();
	
	//Core
	void Run();
};

#endif