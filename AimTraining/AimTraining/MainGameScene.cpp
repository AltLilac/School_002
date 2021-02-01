#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit(100)						// 制限時間
	, target(new Circle())					// 的
	, playArea(new Rect(50, 50, 700, 500))	// 左上の x, y 座標を基準とした、幅 700 高さ 500 のプレイエリア
{
	for (size_t i = 0; i < 100; ++i)
		points << RandomVec2(*playArea);
}

void MainGameScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);
}

void MainGameScene::update()
{
	playArea->draw(Palette::Gray);

	if (SimpleGUI::Button(U"Reset", Vec2(20, 20)))
	{
		for (auto& point : points)
			point = RandomVec2(*playArea);
	}

	for (const auto& point : points)
		Circle(point, 3).draw();
}