#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit			(30)				// �������Ԃ̏����ݒ�
	, currentTime		(timeLimit)			// ���݂̐�������
	, totalScore		(0)					// �X�R�A�̍��v

	, timeLimitSW		(true)				// �������ԗp�X�g�b�v�E�H�b�`
	, delaySW			(false)				// �x�������p�X�g�b�v�E�H�b�`
	, coolTimeSW		(false)				// �I�̃X�|�[���Ԋu�p�X�g�b�v�E�H�b�`
	, visibleDurationSW	(false)				// �I��\���������鎞�Ԃ𐧌䂷��X�g�b�v�E�H�b�`

	, delayTime			(4)					// �x�������ɂ����鎞��

	, visibleTarget		(false)				// �I�̕\���A��\���𐧌䂷��t���O
	, prepareTarget		(true)				// �I�̍��W����������t���O
{
	srand((unsigned)time(NULL));
}

int MainGameScene::scoreContainer = 0;		// �X�R�A�ۑ��p�ϐ��̏�����

void MainGameScene::draw() const
{
	// �w�i�F�̎w��
	Scene::SetBackground(Palette::Cyan);

	// �㕔�� UI �\���p�G���A
	Rect(0, 0, 800, 60).draw(ColorF(0.25));

	// ��������
	FontAsset(U"MainGameFont")(U"Time : ", currentTime).drawAt(110, 30);
	// �X�R�A
	FontAsset(U"MainGameFont")(U"Score : ", totalScore).drawAt(670, 30);

	// �x���������������Ă��鎞��
	if (delaySW.isRunning())
	{
		// ���Ԑ؂�̎|������ UI
		FontAsset(U"GameOverFont")(U"Time Over !").drawAt(Scene::Center(), ColorF(0.25));
	}
}

void MainGameScene::update()
{
	// �������ԁi ������������ - �X�g�b�v�E�H�b�`�̌o�ߎ��� �j
	currentTime = timeLimit - timeLimitSW.s();

	// �������ԗp�X�g�b�v�E�H�b�`���ғ����Ă�����
	if (timeLimitSW.isRunning())
	{
		// �I�̍��W�������ł����ԂȂ�
		if (prepareTarget)
		{
			// �V�����I�̍��W�ƃT�C�Y������
			target = new Circle(40 + rand() % 720, 100 + rand() % 460, 10 + rand() % 30);

			// �I�̕\����L����
			visibleTarget = true;
		}

		// �I�̕\�����Ǘ�����t���O�� true �Ȃ�
		if (visibleTarget)
		{
			// �I�̍��W��V�����������Ȃ��悤�ɂ���
			prepareTarget = false;

			target->draw();

			// �I�̕\���������Ԃ̃J�E���g���J�n
			visibleDurationSW.start();

			// �I�����N���b�N������
			if (target->leftClicked())
			{
				// �X�R�A�̉��Z
				totalScore += 10;

				// �\���������Ԃ̃J�E���g�����Z�b�g
				visibleDurationSW.reset();

				// �I�̍��W���Ăя����ł����Ԃɖ߂�
				prepareTarget = true;

				// �I�̕\���𖳌���
				visibleTarget = false;
			}

			// �I�̕\���������Ԃ𒴂�����
			if (visibleDurationSW.sF() > 1.0)
			{
				// �\���������Ԃ̃J�E���g�����Z�b�g
				visibleDurationSW.reset();

				// �I�̍��W���Ăя����ł����Ԃɖ߂�
				prepareTarget = true;

				// �I�̕\���𖳌���
				visibleTarget = false;
			}
		}
	}

	// �������Ԃ� 0 �ɂȂ�����
	if (currentTime < 0)
	{
		// ��u�����X�R�A�̕\�L�� -1 �ɂȂ�̂� 0 ������
		currentTime = 0;

		// �������Ԏ��Ԃ̐i�s���X�g�b�v
		timeLimitSW.pause();

		// �x�������J�n
		delaySW.start();

		// �X�R�A��ۑ�
		scoreContainer = totalScore;

		// �x�������ɂ����������Ԃ𒴂�����
		if (delaySW.s() > delayTime)
		{
			// �x���������X�g�b�v
			delaySW.pause();

			// ���U���g�V�[���֑J��
			changeScene(State::Result);
		}
	}
}