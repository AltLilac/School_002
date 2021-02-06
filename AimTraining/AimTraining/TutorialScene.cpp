#include "TutorialScene.h"

TutorialScene::TutorialScene(const InitData& init)
	: IScene(init)
{

}

void TutorialScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	FontAsset(U"MenuTitleFont")(U"Tutorial").drawAt(405, 83, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Tutorial").drawAt(400, 80);

	FontAsset(U"TutorialFont")(U"��ʂɏo�Ă���I�𐧌����ԓ���\n�o���邾����������󂵂Ă��������B").drawAt(350, 200, ColorF(0.25));
	FontAsset(U"TutorialFont")(U"�I�Ƀ}�E�X�J�[�\�������킹�č��N���b�N��\n�I���󂷂��Ƃ��ł��܂��B").drawAt(400, 330, ColorF(0.25));

	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(405, 522, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"PressKeyFont")(U"Press Enter Key to Continue...").drawAt(400, 520);
}

void TutorialScene::update()
{
	if (KeyEnter.down())
		changeScene(State::MainGame);
}