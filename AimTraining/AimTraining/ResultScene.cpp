#include "ResultScene.h"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)

	// �{�^����\��������ʒu
	, backMenuButton	(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))
	, saveScoreButton	(new Rect(Arg::center = Scene::Center().movedBy(0,  80), 300, 60))

	// �{�^���ɓK�p����g�����W�V����
	, backMenuTransition	(new Transition(0.4s, 0.2s))
	, saveScoreTransition	(new Transition(0.4s, 0.2s))

	// �Z�[�u�f�[�^�̑��΃p�X
	, readSaveData(U"Saved/SaveDate.txt")

	// �������ރt�@�C���̎w��i�����̃t�@�C�������݂��Ȃ���ΐV�K�ɍ쐬�j
	, writeSaveData(U"Saved/SaveData.txt", OpenMode::Append)
{
	
}

void ResultScene::draw() const
{
	// �w�i�F�̎w��
	Scene::SetBackground(Palette::Cyan);

	// �V�[����ɕ\������e�L�X�g UI
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(405, 82, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(400, 80);

	FontAsset(U"ResultFont")(U"Your Score : ", MainGameScene::GetScore()).drawAt(200, 250, ColorF(0.25));

	// �{�^���̕`��
	backMenuButton	->draw(ColorF(1.0, backMenuTransition	->value())).drawFrame(2);
	saveScoreButton	->draw(ColorF(1.0, saveScoreTransition	->value())).drawFrame(2);

	// �{�^���̃e�L�X�g
	FontAsset(U"MenuFont")(U"�I��")			.drawAt(backMenuButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"�Z�[�u���ďI��")	.drawAt(saveScoreButton	->center(), ColorF(0.25));
}

void ResultScene::update()
{
	// �g�����W�V�����̍X�V
	backMenuTransition	->update(backMenuButton	->mouseOver());
	saveScoreTransition	->update(saveScoreButton->mouseOver());

	// �Z�[�u�f�[�^�̃I�[�v���Ɏ��s������
	if (!writeSaveData)
	{
		throw Error(U"Failed to load savedata");
	}

	// �{�^���ɃJ�[�\�������킹����A�}�E�X�J�[�\���̃X�^�C����ύX
	if (backMenuButton->mouseOver() || saveScoreButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	// �{�^�������N���b�N�Ŋl�������X�R�A��ۑ����A���C�����j���[�֖߂�
	if (saveScoreButton->leftClicked())
	{
		writeSaveData.writeln(MainGameScene::GetScore());
		changeScene(State::MainMenu);
	}

	// �{�^�������N���b�N�Ń��C�����j���[�֖߂�
	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}

ResultScene::~ResultScene()
{
	delete
		backMenuButton,		saveScoreButton,
		backMenuTransition, saveScoreTransition;
}