#pragma once

typedef struct WINDOW_INFO
{
	const char* windowName = "window name";
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 600;
	int framerateLimit = 60;
	bool verticalSync = false;
	bool mouseCursor = false;

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

	void Input();
	void EventUpdate();
	void SceneUpdate();

public:

	void Update();
	bool Render();

};

