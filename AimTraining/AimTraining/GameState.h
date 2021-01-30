#ifndef ___GAMESTATE
#define ___GAMESTATE

#include <Siv3D.hpp>

// ƒQ[ƒ€‚Ìó‘Ô
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