#pragma once
#include "Graphics.h"
#include "location.h"

class Board {
public:
	Board(Graphics& gfx);
	void Draw_cell(Location& loc, Color c);
	void Draw_cell_border(Location& loc, Color c);
	int Get_height();
	int Get_width();
	int Get_beg_height();
	int Get_beg_width();
	bool IsInsideScreen(const Location& loc);
	void draw_border();
private:
	int dimension = 20;
	int or_height = 30;
	int or_width = 40;

	int beg_height = 3;
	int beg_width = 3;
	int height = 30-3;
	int width = 40-3;

	int padding = 2;
	static constexpr Color bord_c = Colors::White;

	Graphics& gfx;
};