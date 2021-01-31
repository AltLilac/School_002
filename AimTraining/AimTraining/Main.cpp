#define TEST 1
#if TEST == 1

#include "Scenes.h"

void Main()
{
	//const Circle circle(Scene::Center(), 100);
	//int32 count = 0;

	// フォントアセットの登録
	FontAsset::Register(U"TitleFont", 90, Typeface::Medium);
	FontAsset::Register(U"PressKeyFont", 50, Typeface::Medium);

	// シーンマネージャー
	App manager;
	manager
		.add<TitleScene>(State::Title);
		//.add<MainGameScene>(State::MainGame);

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