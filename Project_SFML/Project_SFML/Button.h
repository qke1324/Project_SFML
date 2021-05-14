#pragma once

enum BUTTON_STATE
{
	BTN_IDLE,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button final : public RectangleShape
{
public:
	Button() = default;
	Button(const Vector2f& position, const Vector2f& scale, 
		const char* fontPath, const string& textString,
		Color idleColor, Color hoverColor, Color activeColor);

	Button(const Button&) = delete;
	Button& operator=(const Button&) = delete;
	~Button() = default;

private:

	Font font;
	Text text;
	Color idleColor;
	Color hoverColor;
	Color activeColor;

	int buttonState = BTN_IDLE;

public:

	const bool isPressd() const;
	void Update(const Vector2f& mousePos);
	const Text* GetText() const;
};

