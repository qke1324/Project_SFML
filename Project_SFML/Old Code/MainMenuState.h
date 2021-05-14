#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

class CMainMenuState : public CState
{
public:
	CMainMenuState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states);
	virtual ~CMainMenuState();

private:
	Texture backgroundTexture;
	RectangleShape background;
	Font font;

	map<string, CButton*> buttons;

	void InitVariables();
	void InitBackground();
	void InitFonts();
	void InitKeybinds();
	void InitButtons();
	

public:

	

	void UpdateInput(const float& deltatime);
	void UpdateButtons();
	void Update(const float& deltatime);
	void RenderButtons(RenderTarget* target = NULL);
	void Render(RenderTarget* target = NULL);
};

#endif // !MAINMENUSTATE_H