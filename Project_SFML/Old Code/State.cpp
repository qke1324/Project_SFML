#include "State.h"

CState::CState(RenderWindow* window, map<string, int>* supportedKeys, stack<CState*>* states)
	:window(window), supportedKeys(supportedKeys), states(states)
{

}

CState::~CState()
{
}

const bool& CState::getQuit() const
{
	return this->quit;
}


void CState::EndState()
{
	this->quit = true;
}

void CState::UpdateMousePositions()
{
	this->mousePosScreen = Mouse::getPosition();
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
}
