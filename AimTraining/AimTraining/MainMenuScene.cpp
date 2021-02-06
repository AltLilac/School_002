#include "MainMenuScene.h"

MainMenuScene::MainMenuScene(const InitData& init)
	: IScene(init)

	// �e�{�^����\��������ʒu
	, playButton		(new Rect(Arg::center = Scene::Center().movedBy(0, -100), 300, 60))
	, rankingButton		(new Rect(Arg::center = Scene::Center().movedBy(0,  -10), 300, 60))
	, backTitleButton	(new Rect(Arg::center = Scene::Center().movedBy(0,	 80), 300, 60))
	, exitButton		(new Rect(Arg::center = Scene::Center().movedBy(0,  170), 300, 60))

	// �e�{�^���ɓK�p����g�����W�V����
	, playTransition		(new Transition(0.4s, 0.2s))
	, rankingTransition		(new Transition(0.4s, 0.2s))
	, backTitleTransition	(new Transition(0.4s, 0.2s))
	, exitTransition		(new Transition(0.4s, 0.2s))

	, tutorialSkip(false)	// �`���[�g���A�����X�L�b�v���邩
{

}

void MainMenuScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// �e�{�^���̕`��
	playButton		->draw(ColorF(1.0, playTransition		->value())).drawFrame(2);
	rankingButton	->draw(ColorF(1.0, rankingTransition	->value())).drawFrame(2);
	backTitleButton	->draw(ColorF(1.0, backTitleTransition	->value())).drawFrame(2);
	exitButton		->draw(ColorF(1.0, exitTransition		->value())).drawFrame(2);

	FontAsset(U"MenuTitleFont")(U"Aim Training").drawAt(405, 82, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Aim Training").drawAt(400, 80);

	// �{�^���̃e�L�X�g
	FontAsset(U"MenuFont")(U"�v���C")		.drawAt(playButton		->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"�����L���O")	.drawAt(rankingButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"�^�C�g���ɖ߂�")	.drawAt(backTitleButton	->center(), ColorF(0.25));
	FontAsset(U"MenuFont")(U"�Q�[�����I��")	.drawAt(exitButton		->center(), ColorF(0.25));

	// �`���[�g���A���X�L�b�v�̃`�F�b�N�{�b�N�X
	SimpleGUI::CheckBox(tutorialSkip, U"�`���[�g���A�����X�L�b�v", Vec2(485, 540));
}

void MainMenuScene::update()
{
	// �g�����W�V�����̍X�V
	playTransition		->update(playButton		->mouseOver());
	rankingTransition	->update(rankingButton	->mouseOver());
	backTitleTransition	->update(backTitleButton->mouseOver());
	exitTransition		->update(exitButton		->mouseOver());

	// �{�^���ɃJ�[�\�������킹����A�}�E�X�J�[�\���̃X�^�C����ύX
	if (playButton->mouseOver() || rankingButton->mouseOver() || backTitleButton->mouseOver() || exitButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	// ���j���[�{�^�����N���b�N�������̏���
	if (playButton->leftClicked())
		changeScene(State::Tutorial);		// �`���[�g���A���V�[���ɑJ��

	if (playButton->leftClicked() && tutorialSkip)
		changeScene(State::MainGame);		// �`���[�g���A�����X�L�b�v���Ă�����A���C���̃Q�[���v���C�V�[���ɑJ��

	if (rankingButton->leftClicked())
		changeScene(State::Ranking);		// �����L���O�{���V�[���ɑJ��

	if (backTitleButton->leftClicked())
		changeScene(State::Title);			// �^�C�g����ʂɖ߂�

	if (exitButton->leftClicked())
		System::Exit();						// �Q�[�����I��
}