#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
	, readSaveData	(U"Saved/SaveData.txt")	// セーブデータの相対パス
{

}

void TitleScene::draw() const
{
	// 背景色の指定
	Scene::SetBackground(Palette::Cyan);

	// シーン上に表示するテキスト UI
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 153, ColorF(0.0, 0.7));		// 文字の影
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 150);
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(405, 462, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(400, 460);
}

void TitleScene::update()
{
	// セーブデータが存在しなかったら
	if (!readSaveData)
	{
		// 新規作成
		TextWriter writeSaveData(U"Saved/SaveData.txt");
	}

	if (KeyEnter.down())
		changeScene(State::MainMenu);
}