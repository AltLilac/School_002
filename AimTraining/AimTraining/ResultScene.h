#ifndef ___RESULTSCENE
#define ___RESULTSCENE

#include "GameState.h"

class ResultScene : public App::Scene
{
private:

public:
	ResultScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif