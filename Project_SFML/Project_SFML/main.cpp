#include "framework.h"
#include "Engine.h"

int main()
{
	Engine engine;
	
	while (engine.Render());

	engine.Destroy();

	cout << "Game End\n";
}