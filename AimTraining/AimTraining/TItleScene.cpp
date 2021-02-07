#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
{

}

// �^�C�g����ʂ̃e�L�X�g
void TitleScene::drawTitleUI() const
{
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 153, ColorF(0.0, 0.7));		// �����̉e
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 150);
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(405, 462, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(400, 460);
}

void TitleScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	drawTitleUI();
}

void TitleScene::update()
{
	// �Z�[�u�f�[�^�����݂��Ȃ�������
	// �V�K�쐬
	// ���Ă���������̃t�@�C����ǂݍ���

	if (KeyEnter.down())
		changeScene(State::MainMenu);
}