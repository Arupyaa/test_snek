#pragma once
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, Board& brd, snake& snek);
	void Respawn(std::mt19937& rng, Board& brd, snake& snek);
	void Draw(Board& brd);
	const Location& get_loc();
private:
	Location loc;
	static constexpr Color c = Colors::Magenta;
};