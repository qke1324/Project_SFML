#include "framework.h"
#include "Button.h"

Button::Button(const Vector2f& position, const Vector2f& scale, 
	const char* fontPath, const string& textString, 
	Color idleColor, Color hoverColor, Color activeColor)
	:idleColor(idleColor), hoverColor(hoverColor), activeColor(activeColor)
{
	setPosition(position);
	setSize(scale);
	setOrigin(getSize().x / 2.f, getSize().y / 2.f);

	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setString(textString);
	text.setFillColor(Color::White);
	text.setCharacterSize(25);
	text.setOrigin(getSize().x / 2.f, getSize().y / 2.f);
	text.setPosition(getPosition().x, getPosition().y);
	setFillColor(idleColor);
}

const bool Button::isPressd() const
{
	if (buttonState == BTN_ACTIVE)
	{
		return true;
	}

	return false;
}

void Button::Update(const Vector2f& mousePos)
{
	// idle
	buttonState = BTN_IDLE;

	// hover
	if (getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;

		// active
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	// state color
	switch (buttonState)
	{
	case BTN_IDLE:
	{
		setFillColor(idleColor);
		break;
	}
	case BTN_HOVER:
	{
		setFillColor(hoverColor);
		break;
	}
	case BTN_ACTIVE:
	{
		setFillColor(activeColor);
		break;
	}
	}
}

const Text* Button::GetText() const
{
	return &text;
}
