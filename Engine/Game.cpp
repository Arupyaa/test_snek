/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	//rng(std::random_device()()),
	//color_distr(0,255),
	brd(gfx),
	snek(start_loc),
	goal(rng,brd,snek)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	for (int x = 0; x < brd.Get_width(); ++x)
	{
		for (int y = 0; y < brd.Get_height(); ++y)
		{
			Location loc = { x,y };
			Color c = Colors::Black;
			brd.Draw_cell(loc, c);
		}
	}
	if (!is_game_over)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			velocity = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			velocity = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			velocity = { 1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			velocity = { -1,0 };
		}
		Location next(snek.Get_next_location(velocity));
		if (!brd.IsInsideScreen(next)||
			snek.has_eaten_self(next))
		{
			is_game_over = true;
		}
		else
		{
			++snake_move_counter;
			if (snake_move_counter >= snake_move_period)
			{
				snake_move_counter = 0;
			
				bool eating = next == goal.get_loc();
				if (eating)
				{
					snek.Grow(brd, velocity);
				}
				
				snek.MoveBy(velocity);
				if (eating)
				{
				goal.Respawn(rng,brd,snek);
				}
			
			
			
			
			
			}

			
		}
	}
	
}




void Game::ComposeFrame()
{
	brd.draw_border();
	snek.Draw(brd);
	goal.Draw(brd);

	if (is_game_over)
	{
		SpriteCodex::DrawGameOver(200, 200, gfx);
	}
}
