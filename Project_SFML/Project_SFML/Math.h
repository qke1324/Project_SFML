#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
using namespace sf;

constexpr float PI = 3.14159265f;

namespace Math
{
	inline const float Length(const float& posX, const float& posY)
	{
		return sqrt((posX * posX) + (posY * posY));
	}

	inline const Vector2f Normalize(const Vector2f& vec1, const Vector2f& vec2)
	{
		float dirX = vec1.x - vec2.x;
		float dirY = vec1.y - vec2.y;

		float length = Length(dirX, dirY);
		
		return { dirX / length, dirY / length };
	}

	inline const float RotateAxis(const Vector2f& vec1, const Vector2f& vec2, const float& angle)
	{
		Vector2f normal = Normalize(vec1, vec2);
		return ((atan2(normal.y, normal.x) * 180.f / PI)) + angle;
		
	}
}