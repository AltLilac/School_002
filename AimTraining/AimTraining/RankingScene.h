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
	int firstScore;
	int secondScore;
	int thirdScore;

	// �e���ʂ̃X�R�A�p�ϐ��ɑ������
	void SetFirstScore	(int arg) noexcept { firstScore = arg; }
	void SetSecondScore	(int arg) noexcept { secondScore = arg; }
	void SetThirdScore	(int arg) noexcept { thirdScore = arg; }

	// �e���ʂ̃X�R�A���擾����
	int GetFirstScore()		const noexcept { return firstScore; }
	int GetSecondScore()	const noexcept { return secondScore; }
	int GetThirdScore()		const noexcept { return thirdScore; }

public:
	RankingScene(const InitData& init);

	~RankingScene();

	void draw() const override;
	void update() override;
};

#endif