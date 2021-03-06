#pragma once

#include "Player.h"
#include "Button.h"
#include "SoundSystem.h"
#include "ParticleSystem.h"

class Scene
{
public:
	Scene() = default;
	Scene(RenderWindow* window, stack<Scene*>* scenes);
	Scene(RenderWindow* window, stack<Scene*>* scenes, SoundSystem* soundSys, ParticleSystem* particleSys);
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene() = default;

protected:

	RenderWindow* window = nullptr;
	stack<Scene*>* scenes = nullptr;
	SoundSystem* soundSys = nullptr;
	ParticleSystem* particleSys = nullptr;
	Vector2i mousePositionScreen	{ 0, 0 };
	Vector2i mousePositionWindow	{ 0, 0 };
	Vector2f mousePositionView		{ 0.f, 0.f };

	Sprite spcursor;
	Texture txcursor;

	bool quit = false;

private:

	virtual void Init() = 0;

protected:

	void MouseUpdate();

public:
	bool GetQuit() const;
	void EndScene();
	const Sprite& GetCursor() const;

	virtual void Input(Event* keyEvent) = 0;
	virtual void Update(const float& deltaTime) = 0;
	virtual void Render(RenderTarget* target) = 0;

};

