#include "Goal.h"

Goal::Goal(std::mt19937 & rng, Board & brd, snake & snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 & rng, Board & brd, snake & snek)
{
	std::uniform_int_distribution<int> xDist(brd.Get_beg_width(), brd.Get_width() - 1);
	std::uniform_int_distribution<int> yDist(brd.Get_beg_height(), brd.Get_height() - 1);
	
	Location new_loc;
	do
	{
		new_loc.x = xDist(rng);
		new_loc.y = yDist(rng);
	} while (snek.has_eaten_self(new_loc));
	loc = new_loc;
}

void Goal::Draw(Board & brd)
{
	brd.Draw_cell(loc, c);
}

const Location & Goal::get_loc()
{
	return loc;
}
