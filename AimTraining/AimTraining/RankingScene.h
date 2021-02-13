#ifndef ___RANKINGSCENE
#define ___RANKINGSCENE

#include "GameState.h"

class RankingScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// メインメニューに戻るボタン
	Transition* backMenuTransition;		// ボタンのトランシジョン

	TextReader	readSaveData;			// セーブデータファイルの読み込み

	// 各順位のスコア
	String firstScore;
	String secondScore;
	String thirdScore;

	// 各順位のスコア用変数に set する
	void SetFirstScore	(String arg) noexcept { firstScore = arg; }
	void SetSecondScore	(String arg) noexcept { secondScore = arg; }
	void SetThirdScore	(String arg) noexcept { thirdScore = arg; }

	// 各順位のスコアを get する
	String GetFirstScore()	const noexcept { return firstScore; }
	String GetSecondScore()	const noexcept { return secondScore; }
	String GetThirdScore()	const noexcept { return thirdScore; }

public:
	RankingScene(const InitData& init);

	~RankingScene();

	void draw() const override;
	void update() override;
};

#endif