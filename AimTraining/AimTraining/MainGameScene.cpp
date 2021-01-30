#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
{

}

void MainGameScene::draw() const
{
	Scene::SetBackground(Palette::Orange);
}

void MainGameScene::update()
{
	srand((unsigned)time(NULL));

	if (MouseL.down())
		Circle((50 + rand() % 750), (50 + rand() % 550), 30).draw(Palette::Darkblue);
}