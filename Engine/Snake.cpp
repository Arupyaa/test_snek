#include "Snake.h"

snake::snake(const Location loc)
{
	segments[0].init_head(loc);
}

void snake::Draw( Board & brd)
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

void snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].follow(segments[i-1]);
	}
	//if (!skip_delta)
	//{
		segments[0].MoveBy(delta_loc);
	//}
}

void snake::Grow(Board& brd, const Location& delta_loc)
{
	if (nSegments < nSegmentsMax)
	{
		
		segments[nSegments].init_body(color_counter);
		
		if (color_counter + 1 == 3)
		{
			color_counter = 0;
		}


		color_counter = color_counter + 1;

		++nSegments;
		MoveBy(delta_loc);
		
		
		//MoveBy(delta_loc);
		//skip_delta = true;
		
		//skip_delta = false;
	}
}



Location snake::Get_velocity()
{
	return velocity;
}

Location snake::Get_next_location(const Location & velocity)
{
	Location l(segments[0].get_location());
	l.add(velocity);
	return l;
}

bool snake::has_eaten_self(const Location & target)
{
	for (int i = 0; i < nSegments - 1; ++i)
	{
		if (segments[i].get_location() == target)
		{
			was_eaten = true;
		}
	}
	return was_eaten;
}

void snake::Segment::init_head(const Location & init_loc)
{
	loc = init_loc;
	c = head_color;
}

void snake::Segment::init_body(int& color_counter)
{
	if (color_counter == 0)
	{
		c = Colors::LightGray;
	}
	else if (color_counter == 1)
	{
		c = Colors::Red;
	}
	else if (color_counter == 2)
	{
		c = Colors::Gray;
	}
	
	
}

void snake::Segment::follow(const Segment & next)
{
	loc = next.loc;
}

void snake::Segment::MoveBy(const Location & delta_loc)
{
	//assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void snake::Segment::Draw( Board& brd)
{
	brd.Draw_cell(loc, c);
}

Location snake::Segment::get_location()
{
	return loc;
}
