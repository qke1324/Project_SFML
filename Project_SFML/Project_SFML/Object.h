#pragma once

class Object : public Sprite
{
public:
	Object() = default;
	Object(const char* texturePath, const Vector2f& position);
	Object(const Object&) = delete;
	Object& operator=(const Object&) = delete;
	virtual ~Object() = default;

protected:

	Texture* texture = nullptr;

public:

	virtual void Update(const float& deltaTime);

};

