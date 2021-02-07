#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit		(100)					// 制限時間
	, totalScore	(0)						// スコアの合計
	, timeLimitSW	(true)					// 制限時間用ストップウォッチ
	, delaySW		(false)					// 遅延処理用ストップウォッチ
	, delayTime		(3)						// 遅延処理にかける時間
{

}

void MainGameScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	Rect(0, 0, 800, 60).draw(ColorF(0.25));

	// 制限時間
	FontAsset(U"MainGameFont")(U"Time : ", timeLimit - timeLimitSW.s()).drawAt(110, 30);
	// スコア
	FontAsset(U"MainGameFont")(U"Score : ", totalScore).drawAt(670, 30);
}

void MainGameScene::update()
{
	srand((unsigned)time(NULL));

	// 制限時間用ストップウォッチが稼働していたら
	if (timeLimitSW.isRunning())
	{
		// x = 40, y = 100 を左上基準とした、幅 720 高さ 460 のプレイエリア範囲内に的をランダムに生成
		// 的の大きさは最大半径 30 最小半径 10 で生成される
		target = new Circle(40 + rand() % 720, 100 + rand() % 460, 10 + rand() % 30);
		target->draw();

		if (target->leftClicked())
		{
			totalScore += 10;
			delete target;
		}
	}

	// 制限時間が 0 になったら
	if (timeLimit < 0)
	{
		timeLimitSW.pause();
		delaySW.start();

		// delaySW の 経過時間が delayTime を超えたら
		if (delaySW.s() > delayTime)
		{
			changeScene(State::Result);
		}
	}
}