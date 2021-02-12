#include "RankingScene.h"

RankingScene::RankingScene(const InitData& init)
	: IScene(init)

	// �{�^����\��������ʒu
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// �{�^���̃g�����V�W����
	, backMenuTransition(new Transition(0.4s, 0.2s))
{

}

void RankingScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// �V�[����ɕ\������e�L�X�g UI
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(405, 82, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(400, 80);

	// ����
	FontAsset(U"ResultFont")(U"1st : ").drawAt(200, 230, ColorF(0.25));
	FontAsset(U"ResultFont")(U"2nd : ").drawAt(200, 300, ColorF(0.25));
	FontAsset(U"ResultFont")(U"3rd : ").drawAt(200, 370, ColorF(0.25));

	// �{�^���̕`��
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// �{�^���̃e�L�X�g
	FontAsset(U"MenuFont")(U"���j���[�֖߂�").drawAt(backMenuButton->center(), ColorF(0.25));
}

void RankingScene::update()
{
	// �g�����W�V�����̍X�V
	backMenuTransition->update(backMenuButton->mouseOver());

	// �{�^���ɃJ�[�\�������킹����A�}�E�X�J�[�\���̃X�^�C����ύX
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}