#ifndef ___GAMESTATE
#define ___GAMESTATE

#include <Siv3D.hpp>

// �Q�[���̏��
enum class State
{
	Title,
	MainMenu,
	Ranking,
	Tutorial,
	MainGame,
	Result
};

using App = SceneManager<State>;

#endif