#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"


using namespace sf;

enum button_state {
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE,
};

class CButton
{
public:
	CButton(float x, float y, 
		float width, float height, 
		Font* font, string text, 
		Color idleColor, Color hoverColor, Color activeColor);

	virtual ~CButton();

private:

	short unsigned buttonstate;

	RectangleShape shape;
	Font* font{ nullptr };
	Text text;

	Color idleColor;
	Color hoverColor;
	Color activeColor;

	

public:

	//Accessors
	const bool isPressd() const;

	void Update(const Vector2f& mousePos);
	void Render(RenderTarget* target);

};

#endif // !BUTTON_H