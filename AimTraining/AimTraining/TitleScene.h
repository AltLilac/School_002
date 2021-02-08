#ifndef ___TITLESCENE
#define ___TITLESCENE

#include "GameState.h"

class TitleScene : public App::Scene
{
private:
	TextReader readSaveData;	// セーブデータファイルの読み込み

public:
	TitleScene(const InitData& init);

	void draw()   const override;
	void update() override;
};

#endif