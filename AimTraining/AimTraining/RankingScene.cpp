#include "RankingScene.h"

RankingScene::RankingScene(const InitData& init)
	: IScene(init)

	// ボタンを表示させる位置
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// ボタンのトランシジョン
	, backMenuTransition(new Transition(0.4s, 0.2s))

	, readSaveData(U"Saved/SaveData.txt")	// セーブデータの相対パス
{
	// データを一時的に保持しておく配列
	Array<String> dataArray;

	// 内容を読み込む変数
	String data;

	// セーブデータに記録されているスコアを全て取得
	// 終端に達するまで 1 個ずつ読み込む
	while (readSaveData.readLine(data))
	{
		dataArray << data;	// 1 個ずつ追加
	}

	// データをソートで並べ替え
	std::sort(dataArray.begin(), dataArray.end(), std::greater<String>{});

	// 上位 3 つのセッションリザルトを取得する
	SetFirstScore(dataArray[0]);
	SetSecondScore(dataArray[1]);
	SetThirdScore(dataArray[2]);
}

void RankingScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// シーン上に表示するテキスト UI
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(405, 82, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(400, 80);

	// 順位の表示
	FontAsset(U"ResultFont")(U"1st : ", GetFirstScore()).drawAt(200, 200, ColorF(0.25));
	FontAsset(U"ResultFont")(U"2nd : ", GetSecondScore()).drawAt(200, 280, ColorF(0.25));
	FontAsset(U"ResultFont")(U"3rd : ", GetThirdScore()).drawAt(200, 360, ColorF(0.25));

	// ボタンの描画
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// ボタンのテキスト
	FontAsset(U"MenuFont")(U"メニューへ戻る").drawAt(backMenuButton->center(), ColorF(0.25));
}

void RankingScene::update()
{
	// トランジションの更新
	backMenuTransition->update(backMenuButton->mouseOver());

	// セーブデータが存在しなかったら
	if (!readSaveData)
	{
		throw Error(U"Failed to load savedata");
	}

	// ボタンにカーソルを合わせたら、マウスカーソルのスタイルを変更
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}

RankingScene::~RankingScene()
{
	delete backMenuButton, backMenuTransition;
}