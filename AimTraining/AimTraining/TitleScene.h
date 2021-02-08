#ifndef ___TITLESCENE
#define ___TITLESCENE

#include "GameState.h"

class TitleScene : public App::Scene
{
private:
	TextWriter readSaveData;	// �Z�[�u�f�[�^�t�@�C���̓ǂݍ���

public:
	TitleScene(const InitData& init);

	void draw()   const override;
	void update() override;

	void drawTitleUI() const;
};

#endif