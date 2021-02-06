#include "TutorialScene.h"

TutorialScene::TutorialScene(const InitData& init)
	: IScene(init)
{

}

void TutorialScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	FontAsset(U"MenuTitleFont")(U"Tutorial").drawAt(405, 83, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"MenuTitleFont")(U"Tutorial").drawAt(400, 80);

	FontAsset(U"TutorialFont")(U"画面に出てくる的を制限時間内に\n出来るだけたくさん壊してください。").drawAt(350, 200, ColorF(0.25));
	FontAsset(U"TutorialFont")(U"的にマウスカーソルを合わせて左クリックで\n的を壊すことができます。").drawAt(400, 330, ColorF(0.25));

	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(405, 522, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(400, 520);
}

void TutorialScene::update()
{
	if (KeyEnter.down())
		changeScene(State::MainGame);
}