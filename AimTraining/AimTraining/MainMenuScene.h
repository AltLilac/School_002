#ifndef ___MAINMENUSCENE
#define ___MAINMENUSCENE

#include "GameState.h"

class MainMenuScene : public App::Scene
{
private:
	Rect*		playButton;				// ���C���̃Q�[���v���C�V�[���ɑJ�ڂ���{�^��
	Rect*		rankingButton;			// �����L���O�{���̃V�[���ɑJ�ڂ���{�^��
	Rect*		backTitleButton;		// �^�C�g����ʂɖ߂�{�^��
	Rect*		exitButton;				// �Q�[�����I������{�^��

	// �e�{�^���ɓK�p����g�����W�V����
	Transition* playTransition;
	Transition* rankingTransition;
	Transition* backTitleTransition;
	Transition* exitTransition;

public:
	MainMenuScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif