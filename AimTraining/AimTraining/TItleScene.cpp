#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
{

}

void TitleScene::draw() const
{
	Scene::SetBackground(Palette::Orange);
}

void TitleScene::update()
{

}