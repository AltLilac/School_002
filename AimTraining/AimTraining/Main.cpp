#define TEST 1
#if TEST == 1

#include "Scenes.h"

void Main()
{
	//const Circle circle(Scene::Center(), 100);
	//int32 count = 0;

	// フォントアセットの登録
	FontAsset::Register(U"TitleFont",		90, Typeface::Medium);
	FontAsset::Register(U"PressKeyFont",	50, Typeface::Medium);
	FontAsset::Register(U"MenuTitleFont",	70, Typeface::Medium);
	FontAsset::Register(U"MenuFont",		30, Typeface::Regular);
	FontAsset::Register(U"TutorialFont",	35, Typeface::Regular);
	FontAsset::Register(U"MainGameFont",	30, Typeface::Regular);
	FontAsset::Register(U"GameOverFont",	50, Typeface::Regular);
	FontAsset::Register(U"ResultFont",		40, Typeface::Regular);

	// シーンマネージャー
	App manager;
	manager
		.add<TitleScene>	(State::Title)
		.add<MainMenuScene>	(State::MainMenu)
		.add<RankingScene>	(State::Ranking)
		.add<TutorialScene>	(State::Tutorial)
		.add<MainGameScene>	(State::MainGame)
		.add<ResultScene>	(State::Result);

	while (System::Update())
	{
		if (!manager.update())
			break;

		//ClearPrint();
		//Print << U"Score : " << count;

		// 円が左クリックされたら
		//if (circle.leftClicked())
			//count += 10;

		//circle.draw(Palette::Gray);
	}
}

#endif