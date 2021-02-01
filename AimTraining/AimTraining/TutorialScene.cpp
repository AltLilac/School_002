#include "TutorialScene.h"

TutorialScene::TutorialScene(const InitData& init)
	: IScene(init)
{

}

void TutorialScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(405, 465, ColorF(0.0, 0.7));	// •¶Žš‚Ì‰e
	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(400, 460);
}

void TutorialScene::update()
{
	if (KeyEnter.down())
		changeScene(State::MainGame);
}