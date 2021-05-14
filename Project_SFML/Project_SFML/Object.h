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
	Vector2f moveDir{ 0.f, 0.f };
	float moveSpeed = 10.f;
	float deltaTime = 0.f;

public:

	void MoveUpdate(const Vector2f& direction);
	virtual void Update(const float& deltaTime);
	
};

