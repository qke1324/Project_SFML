#pragma once
class ParticleSystem : public Drawable, public Transformable
{
public:

	ParticleSystem() = default;
	ParticleSystem(const unsigned int& count);
	ParticleSystem(const ParticleSystem&) = delete;
	ParticleSystem& operator=(const ParticleSystem&) = delete;
	~ParticleSystem() = default;

private:

	struct Particle
	{
		Vector2f velocity{ 0.f, 0.f };
		float lifeTime = 0.f;
	};

	vector<Particle> particles;
	VertexArray vertices;
	float lifeTime = 3.f;
	Vector2f emitter{ 0.f, 0.f };
	bool isActive = true;

private:

	void ResetParticle(const size_t& index);

public:
	void Init();
	void SetEmitter(const Vector2f& position);
	void Update(const float& deltaTime);

	virtual void draw(RenderTarget& target, RenderStates states) const;
};

