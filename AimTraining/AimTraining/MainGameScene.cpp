#include "MainGameScene.h"

MainGameScene::MainGameScene(const InitData& init)
	: IScene(init)
	, timeLimit		(100)					// ��������
	, totalScore	(0)						// �X�R�A�̍��v
	, timeLimitSW	(true)					// �������ԗp�X�g�b�v�E�H�b�`
	, delaySW		(false)					// �x�������p�X�g�b�v�E�H�b�`
	, delayTime		(3)						// �x�������ɂ����鎞��
{

}

void MainGameScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	Rect(0, 0, 800, 60).draw(ColorF(0.25));

	// ��������
	FontAsset(U"MainGameFont")(U"Time : ", timeLimit - timeLimitSW.s()).drawAt(110, 30);
	// �X�R�A
	FontAsset(U"MainGameFont")(U"Score : ", totalScore).drawAt(670, 30);
}

void MainGameScene::update()
{
	srand((unsigned)time(NULL));

	// �������ԗp�X�g�b�v�E�H�b�`���ғ����Ă�����
	if (timeLimitSW.isRunning())
	{
		// x = 40, y = 100 �������Ƃ����A�� 720 ���� 460 �̃v���C�G���A�͈͓��ɓI�������_���ɐ���
		// �I�̑傫���͍ő唼�a 30 �ŏ����a 10 �Ő��������
		target = new Circle(40 + rand() % 720, 100 + rand() % 460, 10 + rand() % 30);
		target->draw();

		if (target->leftClicked())
		{
			totalScore += 10;
			delete target;
		}
	}

	// �������Ԃ� 0 �ɂȂ�����
	if (timeLimit < 0)
	{
		timeLimitSW.pause();
		delaySW.start();

		// delaySW �� �o�ߎ��Ԃ� delayTime �𒴂�����
		if (delaySW.s() > delayTime)
		{
			changeScene(State::Result);
		}
	}
}