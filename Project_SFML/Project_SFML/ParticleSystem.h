#pragma once
#include "Particle.h"

class ParticleSystem
{
public:

	ParticleSystem() = default;
	ParticleSystem(const unsigned int& count);
	ParticleSystem(const ParticleSystem&) = delete;
	ParticleSystem& operator=(const ParticleSystem&) = delete;
	~ParticleSystem() = default;

private:

	vector<Particle*> particles;

	Vector2f offPosition{ -50.f, -50.f };

	bool isOn = false;

	float particleLifeTime = 0.f;

public:

	void ParticleOn(const Vector2f& startPosition);
	void ParticleOff();
	void Update(const float& deltaTime);
	void Render(RenderTarget* target);

};

