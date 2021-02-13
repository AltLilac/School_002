#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	const int	timeLimit;		// ��������
	int			currentTime;	// ���݂̐�������

	mutable	int	totalScore;		// �X�R�A

	Circle*		target;			// �I�̕`��

	Stopwatch	timeLimitSW;	// �������ԗp�X�g�b�v�E�H�b�`
	Stopwatch	delaySW;		// �x�������p�X�g�b�v�E�H�b�`

	const int	delayTime;		// �x�������ɂ����鎞��

	static int	scoreContainer;	// ���̃V�[���Ŋl�������X�R�A��ۑ����Ă���

public:
	MainGameScene(const InitData& init);

	void draw()   const override;
	void update() override;

	static int GetScore() noexcept { return scoreContainer; }
};

#endif

