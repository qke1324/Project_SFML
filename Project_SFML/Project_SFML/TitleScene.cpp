#include "framework.h"
#include "TitleScene.h"

TitleScene::TitleScene(RenderWindow* window, stack<Scene*>* scenes)
	:Scene(window, scenes)
{
	Init();
}

void TitleScene::Init()
{
	//RectangleShape* startbutton = new RectangleShape(Vector2f(100.f, 100.f));

}

void TitleScene::KeyBoardInput(Event* keyEvent)
{

}

void TitleScene::Update(const float& deltaTime)
{
	MouseUpdate();
}

void TitleScene::Render(RenderTarget* target)
{
}
