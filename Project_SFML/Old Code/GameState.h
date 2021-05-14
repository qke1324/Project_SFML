#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.h"
class CGameState : public CState
{
public:
	CGameState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states);
	virtual ~CGameState();

private:
	CEntity player;

	void InitKeybinds();
public:

	void UpdateInput(const float& deltatime);
	void Update(const float& deltatime);
	void Render(RenderTarget* target = NULL);

};

#endif // !GAMESTATE_H