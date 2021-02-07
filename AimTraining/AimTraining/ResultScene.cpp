#include "ResultScene.h"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)

	// �{�^����\��������ʒu
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// �{�^���ɓK�p����g�����W�V����
	, backMenuTransition(new Transition(0.4s, 0.2s))
{

}

void ResultScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(405, 82, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(400, 80);

	FontAsset(U"ResultFont")(U"Your Score : ").drawAt(200, 250, ColorF(0.25));

	// �{�^���̕`��
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// �{�^���̃e�L�X�g
	FontAsset(U"MenuFont")(U"���j���[�ɖ߂�").drawAt(backMenuButton->center(), ColorF(0.25));
}

void ResultScene::update()
{
	// �g�����W�V�����̍X�V
	backMenuTransition->update(backMenuButton->mouseOver());

	// �{�^���ɃJ�[�\�������킹����A�}�E�X�J�[�\���̃X�^�C����ύX
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}