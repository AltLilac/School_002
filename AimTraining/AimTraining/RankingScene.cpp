#include "RankingScene.h"

RankingScene::RankingScene(const InitData& init)
	: IScene(init)
{

}

void RankingScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);
}

void RankingScene::update()
{

}