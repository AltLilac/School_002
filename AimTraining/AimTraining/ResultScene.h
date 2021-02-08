#ifndef ___RESULTSCENE
#define ___RESULTSCENE

#include "GameState.h"
#include "MainGameScene.h"

class ResultScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// メインメニューに戻るボタン
	Transition* backMenuTransition;		// ボタンに適用するトランジション

public:
	ResultScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif