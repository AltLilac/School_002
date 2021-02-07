#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	mutable	int				timeLimit;		// 制限時間
	mutable	int				totalScore;		// スコア

	Circle*					target;			// 的の描画

	Stopwatch				timeLimitSW;	// 制限時間用ストップウォッチ
	Stopwatch				delaySW;		// 遅延処理用ストップウォッチ

	const	int				delayTime;		// 遅延処理にかける時間

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;

	int GetScore() const { return totalScore; }
};

#endif

