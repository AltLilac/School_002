#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit			(30)				// 制限時間の初期設定
	, currentTime		(timeLimit)			// 現在の制限時間
	, totalScore		(0)					// スコアの合計

	, timeLimitSW		(true)				// 制限時間用ストップウォッチ
	, delaySW			(false)				// 遅延処理用ストップウォッチ
	, coolTimeSW		(false)				// 的のスポーン間隔用ストップウォッチ
	, visibleDurationSW	(false)				// 的を表示し続ける時間を制御するストップウォッチ

	, delayTime			(4)					// 遅延処理にかける時間

	, visibleTarget		(false)				// 的の表示、非表示を制御するフラグ
	, prepareTarget		(true)				// 的の座標を準備するフラグ
{
	srand((unsigned)time(NULL));
}

int MainGameScene::scoreContainer = 0;		// スコア保存用変数の初期化

void MainGameScene::draw() const
{
	// 背景色の指定
	Scene::SetBackground(Palette::Cyan);

	// 上部の UI 表示用エリア
	Rect(0, 0, 800, 60).draw(ColorF(0.25));

	// 制限時間
	FontAsset(U"MainGameFont")(U"Time : ", currentTime).drawAt(110, 30);
	// スコア
	FontAsset(U"MainGameFont")(U"Score : ", totalScore).drawAt(670, 30);

	// 遅延処理が発生している時に
	if (delaySW.isRunning())
	{
		// 時間切れの旨を示す UI
		FontAsset(U"GameOverFont")(U"Time Over !").drawAt(Scene::Center(), ColorF(0.25));
	}
}

void MainGameScene::update()
{
	// 制限時間（ 初期制限時間 - ストップウォッチの経過時間 ）
	currentTime = timeLimit - timeLimitSW.s();

	// 制限時間用ストップウォッチが稼働していたら
	if (timeLimitSW.isRunning())
	{
		// 的の座標を準備できる状態なら
		if (prepareTarget)
		{
			// 新しく的の座標とサイズを準備
			target = new Circle(40 + rand() % 720, 100 + rand() % 460, 10 + rand() % 30);

			// 的の表示を有効化
			visibleTarget = true;
		}

		// 的の表示を管理するフラグが true なら
		if (visibleTarget)
		{
			// 的の座標を新しく生成しないようにする
			prepareTarget = false;

			target->draw();

			// 的の表示制限時間のカウントを開始
			visibleDurationSW.start();

			// 的を左クリックしたら
			if (target->leftClicked())
			{
				// スコアの加算
				totalScore += 10;

				// 表示制限時間のカウントをリセット
				visibleDurationSW.reset();

				// 的の座標を再び準備できる状態に戻す
				prepareTarget = true;

				// 的の表示を無効化
				visibleTarget = false;
			}

			// 的の表示制限時間を超えたら
			if (visibleDurationSW.sF() > 1.0)
			{
				// 表示制限時間のカウントをリセット
				visibleDurationSW.reset();

				// 的の座標を再び準備できる状態に戻す
				prepareTarget = true;

				// 的の表示を無効化
				visibleTarget = false;
			}
		}
	}

	// 制限時間が 0 になったら
	if (currentTime < 0)
	{
		// 一瞬だけスコアの表記が -1 になるので 0 を入れる
		currentTime = 0;

		// 制限時間時間の進行をストップ
		timeLimitSW.pause();

		// 遅延処理開始
		delaySW.start();

		// スコアを保存
		scoreContainer = totalScore;

		// 遅延処理にかけたい時間を超えたら
		if (delaySW.s() > delayTime)
		{
			// 遅延処理をストップ
			delaySW.pause();

			// リザルトシーンへ遷移
			changeScene(State::Result);
		}
	}
}