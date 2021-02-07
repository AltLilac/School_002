#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
{

}

// タイトル画面のテキスト
void TitleScene::drawTitleUI() const
{
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 153, ColorF(0.0, 0.7));		// 文字の影
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 150);
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(405, 462, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(400, 460);
}

void TitleScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	drawTitleUI();
}

void TitleScene::update()
{
	// セーブデータが存在しなかったら
	// 新規作成
	// していたら既存のファイルを読み込む

	if (KeyEnter.down())
		changeScene(State::MainMenu);
}