#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
	, readSaveData	(U"Saved/SaveDate.txt")	// �Z�[�u�f�[�^�̑��΃p�X
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
	if (!readSaveData)
	{
		// �V�K�쐬
		TextWriter writeSaveData(U"Saved/SaveData.txt");
	}

	if (KeyEnter.down())
		changeScene(State::MainMenu);
}