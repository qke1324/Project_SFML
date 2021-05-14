#pragma once

typedef struct WINDOW_INFO
{
	const char* windowName = "window name";
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	int framerateLimit = 120;
	bool verticalSync = false;

}WINDOW_INFO;

class Scene;

class Engine final
{
public:

	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	~Engine() = default;

private:

	RenderWindow* window = nullptr;
	WINDOW_INFO win_info;

	Event event;

	Clock timer;
	float deltaTime = 0.f;

	stack<Scene*> scenes;

public:

	void Init();
	void Destroy();
	
private:

	void KeyboardInput();
	void EventUpdate();
	void SceneUpdate();

public:

	void Update();
	bool Render();

};

