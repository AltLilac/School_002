#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit		(10)					// 制限時間の初期設定
	, currentTime	(timeLimit)				// 現在の制限時間
	, totalScore	(0)						// スコアの合計
	, timeLimitSW	(true)					// 制限時間用ストップウォッチ
	, delaySW		(false)					// 遅延処理用ストップウォッチ
	, delayTime		(4)						// 遅延処理にかける時間
{
	
}

int MainGameScene::scoreContainer = 0;

void MainGameScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	Rect(0, 0, 800, 60).draw(ColorF(0.25));

	// 制限時間
	FontAsset(U"MainGameFont")(U"Time : ", currentTime).drawAt(110, 30);
	// スコア
	FontAsset(U"MainGameFont")(U"Score : ", totalScore).drawAt(670, 30);

	// 制限時間が 0 になったら
	if (currentTime == 0 && delaySW.isRunning())
	{
		FontAsset(U"GameOverFont")(U"Time Over !").drawAt(Scene::Center(), ColorF(0.25));
	}
}

void MainGameScene::update()
{
	srand((unsigned)time(NULL));

	currentTime = timeLimit - timeLimitSW.s();

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
	if (currentTime < 0)
	{
		currentTime = 0;
		timeLimitSW.pause();
		delaySW.start();

		scoreContainer = totalScore;	// スコアを保存

		// delaySW の 経過時間が delayTime を超えたら
		if (delaySW.s() > delayTime)
		{
			delaySW.pause();
			changeScene(State::Result);
		}
	}
}