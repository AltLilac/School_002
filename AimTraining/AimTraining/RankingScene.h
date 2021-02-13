#ifndef ___RANKINGSCENE
#define ___RANKINGSCENE

#include "GameState.h"

class RankingScene : public App::Scene
{
private:
	Rect*		backMenuButton;			// ���C�����j���[�ɖ߂�{�^��
	Transition* backMenuTransition;		// �{�^���̃g�����V�W����

	TextReader	readSaveData;			// �Z�[�u�f�[�^�t�@�C���̓ǂݍ���

	// �e���ʂ̃X�R�A
	String firstScore;
	String secondScore;
	String thirdScore;

	// �e���ʂ̃X�R�A�p�ϐ��� set ����
	void SetFirstScore	(String arg) noexcept { firstScore = arg; }
	void SetSecondScore	(String arg) noexcept { secondScore = arg; }
	void SetThirdScore	(String arg) noexcept { thirdScore = arg; }

	// �e���ʂ̃X�R�A�� get ����
	String GetFirstScore()	const noexcept { return firstScore; }
	String GetSecondScore()	const noexcept { return secondScore; }
	String GetThirdScore()	const noexcept { return thirdScore; }

public:
	RankingScene(const InitData& init);

	~RankingScene();

	void draw() const override;
	void update() override;
};

#endif