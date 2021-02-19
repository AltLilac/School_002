#include "ResultScene.h"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)

	// ボタンを表示させる位置
	, backMenuButton	(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))
	, saveScoreButton	(new Rect(Arg::center = Scene::Center().movedBy(0,  80), 300, 60))

	// ボタンに適用するトランジション
	, backMenuTransition	(new Transition(0.4s, 0.2s))
	, saveScoreTransition	(new Transition(0.4s, 0.2s))

	// セーブデータの相対パス
	, readSaveData(U"Saved/SaveDate.txt")

	// 書き込むファイルの指定（同名のファイルが存在しなければ新規に作成）
	, writeSaveData(U"Saved/SaveData.txt", OpenMode::Append)
{
	
}

void ResultScene::draw() const
{
	// 背景色の指定
	Scene::SetBackground(Palette::Cyan);

	// シーン上に表示するテキスト UI
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(405, 82, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(400, 80);

	FontAsset(U"ResultFont")(U"Your Score : ", MainGameScene::GetScore()).drawAt(200, 250, ColorF(0.25));

	// ボタンの描画
	backMenuButton	->draw(ColorF(1.0, backMenuTransition	->value())).drawFrame(2);
	saveScoreButton	->draw(ColorF(1.0, saveScoreTransition	->value())).drawFrame(2);

	// ボタンのテキスト
	FontAsset(U"MenuFont")(U"終了")			.drawAt(backMenuButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"セーブして終了")	.drawAt(saveScoreButton	->center(), ColorF(0.25));
}

void ResultScene::update()
{
	// トランジションの更新
	backMenuTransition	->update(backMenuButton	->mouseOver());
	saveScoreTransition	->update(saveScoreButton->mouseOver());

	// セーブデータのオープンに失敗したら
	if (!writeSaveData)
	{
		throw Error(U"Failed to load savedata");
	}

	// ボタンにカーソルを合わせたら、マウスカーソルのスタイルを変更
	if (backMenuButton->mouseOver() || saveScoreButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	// ボタンを左クリックで獲得したスコアを保存し、メインメニューへ戻る
	if (saveScoreButton->leftClicked())
	{
		writeSaveData.writeln(MainGameScene::GetScore());
		changeScene(State::MainMenu);
	}

	// ボタンを左クリックでメインメニューへ戻る
	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}

ResultScene::~ResultScene()
{
	delete
		backMenuButton,		saveScoreButton,
		backMenuTransition, saveScoreTransition;
}