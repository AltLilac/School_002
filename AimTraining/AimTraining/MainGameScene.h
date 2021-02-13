#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	const int	timeLimit;		// 制限時間
	int			currentTime;	// 現在の制限時間

	mutable	int	totalScore;		// スコア

	Circle*		target;			// 的の描画

	Stopwatch	timeLimitSW;	// 制限時間用ストップウォッチ
	Stopwatch	delaySW;		// 遅延処理用ストップウォッチ

	const int	delayTime;		// 遅延処理にかける時間

	static int	scoreContainer;	// このシーンで獲得したスコアを保存しておく

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;

	static int GetScore() noexcept { return scoreContainer; }
};

#endif

