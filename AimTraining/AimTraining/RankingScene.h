#ifndef ___RANKINGSCENE
#define ___RANKINGSCENE

#include "GameState.h"

class RankingScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// メインメニューに戻るボタン

	Transition* backMenuTransition;		// ボタンのトランシジョン

public:
	RankingScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif