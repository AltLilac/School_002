#include "ResultScene.h"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)
{

}

void ResultScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);
}

void ResultScene::update()
{

}