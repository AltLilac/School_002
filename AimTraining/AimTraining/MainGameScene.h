#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	Stopwatch timeLimit;
	// ���v�X�R�A
	// �I

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;
};

#endif

