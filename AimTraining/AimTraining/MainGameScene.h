#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
			int				timeLimit;		// ��������
			int				totalScore;		// �X�R�A
	mutable Circle*			target;			// �I�̕`��
	const   Rect*			playArea;		// �v���C�G���A
			Array<Vec2>		points;			

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;
};

#endif

