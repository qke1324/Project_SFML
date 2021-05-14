#include "framework.h"
#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(const unsigned int& count)
	:vertices(Points, count), particles(count)
{

}

void ParticleSystem::ResetParticle(const size_t& index)
{
	float angle = (rand() % 360) * PI / 180.f;
	float speed = (rand() % 50) + 50.f;

	particles[index].velocity = Vector2f(cos(angle) * speed, sin(angle) * speed);
	particles[index].lifeTime = rand() % 5;

	vertices[index].position = emitter;
}

void ParticleSystem::Init()
{
    // TODO : 파티클 초기화 혹은 그리기 false
}

void ParticleSystem::SetEmitter(const Vector2f& position)
{
	emitter = position;
}

void ParticleSystem::Update(const float& deltaTime)
{
    for (std::size_t i = 0; i < particles.size(); ++i)
    {
        Particle& p = particles[i];
        p.lifeTime -= deltaTime;

        if (p.lifeTime <= 0.f)
        {
            ResetParticle(i);  
        }

        vertices[i].position += p.velocity * deltaTime;

        float ratio =  lifeTime / p.lifeTime ;
        vertices[i].color.r = static_cast<sf::Uint8>(ratio * 255);
        vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}

void ParticleSystem::draw(RenderTarget& target, RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    if (isActive)
    {
        target.draw(vertices, states);
    }
}
