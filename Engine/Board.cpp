#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::Draw_cell(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension + padding, loc.y*dimension + padding, dimension- padding, dimension - padding, c);
}
void Board::Draw_cell_border(Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension , loc.y*dimension , dimension , dimension, c);
}

int Board::Get_height()
{
	return height;
}

int Board::Get_width()
{
	return width;
}

int Board::Get_beg_height()
{
	return beg_height;
}

int Board::Get_beg_width()
{
	return beg_width;
}

bool Board::IsInsideScreen(const Location & loc)
{
	return loc.x >= beg_width && loc.x < width&&
		loc.y >= beg_height && loc.y < height ;
}

void Board::draw_border()
{
	
	for (int i = 2; i < or_width - 3; ++i)
	{
		Location bord_loc{ i, 2 };
		Draw_cell_border(bord_loc,bord_c);
	}
	for (int i = 2; i < or_height - 3; ++i)
	{
		Location bord_loc{ 2, i };
		Draw_cell_border(bord_loc, bord_c);
	}
	for (int i = 2; i < or_width - 3; ++i)
	{
		Location bord_loc{ i, or_height-3 };
		Draw_cell_border(bord_loc, bord_c);
	}
	for (int i = 2; i < or_height - 2; ++i)
	{
		Location bord_loc{ or_width - 3, i };
		Draw_cell_border(bord_loc, bord_c);
	}
}
