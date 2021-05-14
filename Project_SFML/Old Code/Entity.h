#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <memory>

using namespace std;

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;

class CEntity
{
public:
	CEntity();
	virtual ~CEntity();

private:
	

protected:
	Texture* texture{ nullptr };
	Sprite* sprite{ nullptr };

	float moveSpeed{ 100.f };

public:

	//Component Functions
	void CreateSprite(Texture* texture);

	virtual void Move(const float& deltatime, const float x, const float y);

	virtual void Update(const float& deltatime);
	virtual void Render(RenderTarget* target);
};

#endif // !ENTITY_H