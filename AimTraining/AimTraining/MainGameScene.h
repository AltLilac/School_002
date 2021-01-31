#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
			int				timeLimit;		// 制限時間
			int				totalScore;		// スコア
	mutable Circle*			target;			// 的の描画
	const   Rect*			playArea;		// プレイエリア
			Array<Vec2>		points;			

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;
};

#endif

