#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(const InitData& init)
	: IScene(init)

	// 各ボタンを表示させる位置
	, playButton		(new Rect(Arg::center = Scene::Center().movedBy(0, -70), 300, 60))
	, rankingButton		(new Rect(Arg::center = Scene::Center().movedBy(0,  30), 300, 60))
	, backTitleButton	(new Rect(Arg::center = Scene::Center().movedBy(0, 130), 300, 60))
	, exitButton		(new Rect(Arg::center = Scene::Center().movedBy(0, 230), 300, 60))

	// 各ボタンに適用するトランジション
	, playTransition		(new Transition(0.4s, 0.2s))
	, rankingTransition		(new Transition(0.4s, 0.2s))
	, backTitleTransition	(new Transition(0.4s, 0.2s))
	, exitTransition		(new Transition(0.4s, 0.2s))
{

}

void MainMenuScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// 各ボタンの描画
	playButton		->draw(ColorF(1.0, playTransition		->value())).drawFrame(2);
	rankingButton	->draw(ColorF(1.0, rankingTransition	->value())).drawFrame(2);
	backTitleButton	->draw(ColorF(1.0, backTitleTransition	->value())).drawFrame(2);
	exitButton		->draw(ColorF(1.0, exitTransition		->value())).drawFrame(2);

	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 97.5, ColorF(0.0, 0.7));		// 文字の影
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 92.5);

	FontAsset(U"MenuFont")(U"プレイ")		.drawAt(playButton		->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"ランキング")	.drawAt(rankingButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"タイトルに戻る")	.drawAt(backTitleButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"ゲームを終了")	.drawAt(exitButton		->center(), ColorF(0.25));
}

void MainMenuScene::update()
{
	// トランジションの更新
	playTransition		->update(playButton		->mouseOver());
	rankingTransition	->update(rankingButton	->mouseOver());
	backTitleTransition	->update(backTitleButton->mouseOver());
	exitTransition		->update(exitButton		->mouseOver());

	// ボタンにカーソルを合わせたら、マウスカーソルのスタイルを変更
	if (playButton->mouseOver() || rankingButton->mouseOver() || backTitleButton->mouseOver() || exitButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	// メニューボタンをクリックした時の処理
	if (playButton->leftClicked())
		changeScene(State::Tutorial);		// メインのゲームプレイシーンに遷移

	if (rankingButton->leftClicked())
		changeScene(State::Ranking);		// ランキング閲覧シーンに遷移

	if (backTitleButton->leftClicked())
		changeScene(State::Title);			// タイトル画面に戻る

	if (exitButton->leftClicked())
		System::Exit();						// ゲームを終了
}