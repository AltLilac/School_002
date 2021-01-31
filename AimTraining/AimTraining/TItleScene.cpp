#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
{

}

void TitleScene::drawTitleUI() const
{
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 155, ColorF(0.0, 0.7));
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 150);
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(405, 465, ColorF(0.0, 0.7));
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(400, 460);
}

void TitleScene::draw() const
{
	drawTitleUI();
}

void TitleScene::update()
{
	if (KeyEnter.down())
		changeScene(State::MainMenu);
}