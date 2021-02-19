#ifndef ___MAINGAMESCENE
#define ___MAINGAMESCENE

#include "GameState.h"

class MainGameScene : public App::Scene
{
private:
	const int		timeLimit;			// ��������
	int				currentTime;		// ���݂̐�������

	int				totalScore;			// �X�R�A

	Circle*			target;				// �I�̕`��

	Stopwatch		timeLimitSW;		// �������ԗp�X�g�b�v�E�H�b�`
	Stopwatch		delaySW;			// �x�������p�X�g�b�v�E�H�b�`
	Stopwatch		coolTimeSW;			// �I�̃X�|�[���Ԋu�p�X�g�b�v�E�H�b�`
	Stopwatch		visibleDurationSW;	// �I��\���������鎞�Ԃ𐧌䂷��X�g�b�v�E�H�b�`

	const int		delayTime;			// �x�������ɂ����鎞��

	bool			visibleTarget;		// �I�̕\���A��\���𐧌䂷��t���O
	bool			prepareTarget;		// �I�̍��W����������t���O

	static int		scoreContainer;		// ���̃V�[���Ŋl�������X�R�A��ۑ����Ă���

public:
	MainGameScene(const InitData& init);

	~MainGameScene();

	void draw()   const override;
	void update() override;

	// �V�[�����ׂ��ŃX�R�A���擾����
	[[nodiscard]] static int GetScore() noexcept { return scoreContainer; }
};

#endif