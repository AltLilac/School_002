#include "ResultScene.h"

ResultScene::ResultScene(const InitData& init)
	: IScene(init)

	// ボタンを表示させる位置
	, backMenuButton(new Rect(Arg::center = Scene::Center().movedBy(0, 170), 300, 60))

	// ボタンに適用するトランジション
	, backMenuTransition(new Transition(0.4s, 0.2s))
{

}

void ResultScene::draw() const
{
	Scene::SetBackground(Palette::Cyan);

	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(405, 82, ColorF(0.0, 0.7));	// 文字の影
	FontAsset(U"MenuTitleFont")(U"Session Ended").drawAt(400, 80);

	FontAsset(U"ResultFont")(U"Your Score : ").drawAt(200, 250, ColorF(0.25));

	// ボタンの描画
	backMenuButton->draw(ColorF(1.0, backMenuTransition->value())).drawFrame(2);

	// ボタンのテキスト
	FontAsset(U"MenuFont")(U"メニューに戻る").drawAt(backMenuButton->center(), ColorF(0.25));
}

void ResultScene::update()
{
	// トランジションの更新
	backMenuTransition->update(backMenuButton->mouseOver());

	// ボタンにカーソルを合わせたら、マウスカーソルのスタイルを変更
	if (backMenuButton->mouseOver())
		Cursor::RequestStyle(CursorStyle::Hand);

	if (backMenuButton->leftClicked())
		changeScene(State::MainMenu);
}