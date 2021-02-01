#ifndef ___TUTORIALSCENE
#define ___TUTORIALSCENE

#include "GameState.h"

class TutorialScene : public App::Scene
{
private:

public:
	TutorialScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif