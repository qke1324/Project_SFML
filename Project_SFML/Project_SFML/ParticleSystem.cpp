#include "framework.h"
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(const unsigned int& count)
	:particles(count)
{
	for (auto& i : particles)
	{
		i = new Particle("Texture/particle.png");
		i->SetMoveDirection(Math::Normalize({ Math::RandomFloat(), Math::RandomFloat() }, { Math::RandomFloat(), Math::RandomFloat() }));
		i->SetMoveSpeed(Math::RandomFloat());
	}
}

ParticleSystem::~ParticleSystem()
{
	if (!particles.empty())
	{
		for (auto& particle : particles)
		{
			SAFE_DELETE(particle);
		}
		particles.clear();
	}
}

void ParticleSystem::ParticleOn(const Vector2f& startPosition)
{
	isOn = true;
	particleLifeTime = 0.f;
	for (auto& i : particles)
	{
		i->SetActive(true);
		i->setPosition(startPosition);
		i->SetMoveDirection(Math::Normalize({ Math::RandomFloat(), Math::RandomFloat() }, { Math::RandomFloat(), Math::RandomFloat() }));
		i->SetMoveSpeed(Math::RandomFloat());
	}
}

void ParticleSystem::ParticleOff()
{
	isOn = false;
	for (auto& i : particles)
	{
		i->SetActive(false);
		i->setPosition(this->offPosition);
	}
}

void ParticleSystem::Update(const float& deltaTime)
{
	particleLifeTime += deltaTime;
	if (particleLifeTime >= .4f)
	{
		ParticleOff();
	}
	if (isOn)
	{
		for (auto& i : particles)
		{
			i->Update(deltaTime);
		}
	}
}

void ParticleSystem::Render(RenderTarget* target)
{
	if (isOn)
	{
		if (target)
		{
			for (auto& i : particles)
			{
				target->draw(*i);
			}
		}
	}
}
