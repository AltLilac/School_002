#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init)
	: IScene(init)
	, readSaveData	(U"Saved/SaveData.txt")	// �Z�[�u�f�[�^�̑��΃p�X
{

}

void TitleScene::draw() const
{
	// �w�i�F�̎w��
	Scene::SetBackground(Palette::Cyan);

	// �V�[����ɕ\������e�L�X�g UI
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(405, 153, ColorF(0.0, 0.7));		// �����̉e
	FontAsset(U"TitleFont")(U"Aim Training").drawAt(400, 150);
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(405, 462, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"PressKeyFont")(U"Press Enter Key").drawAt(400, 460);
}

void TitleScene::update()
{
	// �Z�[�u�f�[�^�����݂��Ȃ�������
	if (!readSaveData)
	{
		// �V�K�쐬
		TextWriter writeSaveData(U"Saved/SaveData.txt");

		// ��̃f�[�^���쐬�i���v���C�̍ۂ� RankingScene ��K�ꂽ���ɁA1st : 0, 2nd : 0, 3rd : 0 �̏�Ԃɂ��Ă����j
		// RankingScene �� ���ʕ\���Ŏg�p���� String �ϐ��� 0 �ŏ���������ƃA�N�Z�X�ᔽ�œ{�����
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