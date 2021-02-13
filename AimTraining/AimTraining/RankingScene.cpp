#include "RankingScene.h"

RankingScene::RankingScene(const InitData& init)
	: IScene(init)

	// �{�^����\��������ʒu
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// �{�^���̃g�����V�W����
	, backMenuTransition(new Transition(0.4s, 0.2s))

	, readSaveData(U"Saved/SaveData.txt")	// �Z�[�u�f�[�^�̑��΃p�X
{
	// �f�[�^���ꎞ�I�ɕێ����Ă����z��
	Array<String> dataArray;

	// ���e��ǂݍ��ޕϐ�
	String data;

	// �Z�[�u�f�[�^�ɋL�^����Ă���X�R�A��S�Ď擾
	// �I�[�ɒB����܂� 1 ���ǂݍ���
	while (readSaveData.readLine(data))
	{
		dataArray << data;	// 1 ���ǉ�
	}

	// �f�[�^���\�[�g�ŕ��בւ�
	std::sort(dataArray.begin(), dataArray.end(), std::greater<String>{});

	// ��� 3 �̃Z�b�V�������U���g���擾����
	SetFirstScore(dataArray[0]);
	SetSecondScore(dataArray[1]);
	SetThirdScore(dataArray[2]);
}

void RankingScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// �V�[����ɕ\������e�L�X�g UI
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(405, 82, ColorF(0.0, 0.7));	// �����̉e
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(400, 80);

	// ���ʂ̕\��
	FontAsset(U"ResultFont")(U"1st : ", GetFirstScore()).drawAt(200, 200, ColorF(0.25));
	FontAsset(U"ResultFont")(U"2nd : ", GetSecondScore()).drawAt(200, 280, ColorF(0.25));
	FontAsset(U"ResultFont")(U"3rd : ", GetThirdScore()).drawAt(200, 360, ColorF(0.25));

	// �{�^���̕`��
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// �{�^���̃e�L�X�g
	FontAsset(U"MenuFont")(U"���j���[�֖߂�").drawAt(backMenuButton->center(), ColorF(0.25));
}

void RankingScene::update()
{
	// �g�����W�V�����̍X�V
	backMenuTransition->update(backMenuButton->mouseOver());

	// �Z�[�u�f�[�^�����݂��Ȃ�������
	if (!readSaveData)
	{
		throw Error(U"Failed to load savedata");
	}

	// �{�^���ɃJ�[�\�������킹����A�}�E�X�J�[�\���̃X�^�C����ύX
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}

RankingScene::~RankingScene()
{
	delete backMenuButton, backMenuTransition;
}