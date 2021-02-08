#ifndef ___RESULTSCENE
#define ___RESULTSCENE

#include "GameState.h"
#include "MainGameScene.h"

class ResultScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// ���C�����j���[�ɖ߂�{�^��
	Transition* backMenuTransition;		// �{�^���ɓK�p����g�����W�V����

public:
	ResultScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif