#include "RankingScene.h"

RankingScene::RankingScene(const InitData& init)
	: IScene(init)

	// ボタンを表示させる位置
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// ボタンのトランシジョン
	, backMenuTransition(new Transition(0.4s, 0.2s))
{

}

void RankingScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	// シーン上に表示するテキスト UI
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(405, 82, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"MenuTitleFont")(U"Ranking").drawAt(400, 80);

	// 順位
	FontAsset(U"ResultFont")(U"1st : ").drawAt(200, 230, ColorF(0.25));
	FontAsset(U"ResultFont")(U"2nd : ").drawAt(200, 300, ColorF(0.25));
	FontAsset(U"ResultFont")(U"3rd : ").drawAt(200, 370, ColorF(0.25));

	// ボタンの描画
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// ボタンのテキスト
	FontAsset(U"MenuFont")(U"メニューへ戻る").drawAt(backMenuButton->center(), ColorF(0.25));
}

void RankingScene::update()
{
	// トランジションの更新
	backMenuTransition->update(backMenuButton->mouseOver());

	// ボタンにカーソルを合わせたら、マウスカーソルのスタイルを変更
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}