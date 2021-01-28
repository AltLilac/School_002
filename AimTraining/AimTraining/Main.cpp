#define TEST 0
#if TEST == 1

# include <Siv3D.hpp>

void Main()
{
	Scene::SetBackground(Palette::White);

	const Circle circle(Scene::Center(), 100);

	int32 count = 0, missCount = 0;

	while (System::Update())
	{
		ClearPrint();
		Print << U"Score : " << count;

		// ‰~‚ª¶ƒNƒŠƒbƒN‚³‚ê‚½‚ç
		if (circle.leftClicked())
			count += 10;

		circle.draw(Palette::Gray);
	}
}

#endif