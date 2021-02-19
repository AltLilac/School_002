#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	const int		timeLimit;			// 制限時間
	int				currentTime;		// 現在の制限時間

	int				totalScore;			// スコア

	Circle*			target;				// 的の描画

	Stopwatch		timeLimitSW;		// 制限時間用ストップウォッチ
	Stopwatch		delaySW;			// 遅延処理用ストップウォッチ
	Stopwatch		coolTimeSW;			// 的のスポーン間隔用ストップウォッチ
	Stopwatch		visibleDurationSW;	// 的を表示し続ける時間を制御するストップウォッチ

	const int		delayTime;			// 遅延処理にかける時間

	bool			visibleTarget;		// 的の表示、非表示を制御するフラグ
	bool			prepareTarget;		// 的の座標を準備するフラグ

	static int		scoreContainer;		// このシーンで獲得したスコアを保存しておく

public:
	MainGameScene(const InitData& init);

	~MainGameScene();

	void draw()   const override;
	void update() override;

	// シーンを跨いでスコアを取得する
	[[nodiscard]] static int GetScore() noexcept { return scoreContainer; }
};

#endif