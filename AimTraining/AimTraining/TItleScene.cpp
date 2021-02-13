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

		// 空のデータを作成（未プレイの際に RankingScene を訪れた時に、1st : 0, 2nd : 0, 3rd : 0 の状態にしておく）
		// RankingScene の 順位表示で使用する String 変数を 0 で初期化するとアクセス違反で怒られる為
		int count = 0;

		while (count < 3)
		{
			writeSaveData.writeln(U"0");
			count++;
		}
	}

	if (KeyEnter.down())
		changeScene(State::MainMenu);
}