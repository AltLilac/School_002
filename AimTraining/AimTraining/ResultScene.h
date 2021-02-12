#ifndef ___RESULTSCENE
#define ___RESULTSCENE

#include "GameState.h"
#include "MainGameScene.h"

class ResultScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// メインメニューに戻るボタン
	Rect*		saveScoreButton;		// プレイ結果を保存して終了するボタン

	// 各ボタンに適用するトランジション
	Transition* backMenuTransition;
	Transition* saveScoreTransition;

	TextReader	readSaveData;			// セーブデータの読み込み
	TextWriter  writeSaveData;			// セーブデータの書き込み

public:
	ResultScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif