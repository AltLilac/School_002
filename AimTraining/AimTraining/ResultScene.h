#ifndef ___RESULTSCENE
#define ___RESULTSCENE

#include "GameState.h"
#include "MainGameScene.h"

class ResultScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// ���C�����j���[�ɖ߂�{�^��
	Rect*		saveScoreButton;		// �v���C���ʂ�ۑ����ďI������{�^��

	// �e�{�^���ɓK�p����g�����W�V����
	Transition* backMenuTransition;
	Transition* saveScoreTransition;

	TextReader	readSaveData;			// �Z�[�u�f�[�^�̓ǂݍ���
	TextWriter  writeSaveData;			// �Z�[�u�f�[�^�̏�������

public:
	ResultScene(const InitData& init);

	void draw() const override;
	void update() override;
};

#endif