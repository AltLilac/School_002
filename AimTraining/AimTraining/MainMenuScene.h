#ifndef ___MAINMENUSCENE
#define ___MAINMENUSCENE

#include "GameState.h"

class MainMenuScene : public App::Scene
{
private:
	Rect*		playButton;				// メインのゲームプレイシーンに遷移するボタン
	Rect*		rankingButton;			// ランキング閲覧のシーンに遷移するボタン
	Rect*		backTitleButton;		// タイトル画面に戻るボタン
	Rect*		exitButton;				// ゲームを終了するボタン

	// 各ボタンに適用するトランジション
	Transition* playTransition;
	Transition* rankingTransition;
	Transition* backTitleTransition;
	Transition* exitTransition;

public:
	MainMenuScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif