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
	int firstScore;
	int secondScore;
	int thirdScore;

	// 各順位のスコア用変数に代入する
	void SetFirstScore	(int arg) noexcept { firstScore = arg; }
	void SetSecondScore	(int arg) noexcept { secondScore = arg; }
	void SetThirdScore	(int arg) noexcept { thirdScore = arg; }

	// 各順位のスコアを取得する
	int GetFirstScore()		const noexcept { return firstScore; }
	int GetSecondScore()	const noexcept { return secondScore; }
	int GetThirdScore()		const noexcept { return thirdScore; }

public:
	RankingScene(const InitData& init);

	~RankingScene();

	void draw() const override;
	void update() override;
};

#endif