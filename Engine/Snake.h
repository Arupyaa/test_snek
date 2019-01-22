#pragma once
#include "location.h"
#include "Board.h"
#include <assert.h>
#include "Keyboard.h"
class snake
{
public:
	snake(const Location loc);
	void Draw( Board& brd);
	void MoveBy(const Location& delta_loc);
	void Grow(Board& brd, const Location& delta_loc);
	void update(const Location starting_loc, Board& brd,Keyboard& kbd );
	Location Get_velocity();
	Location Get_next_location(const Location& velocity);
	bool has_eaten_self(const Location& target);
	
	
private:
	class Segment  {
	public:
		void init_head(const Location& init_loc);
		void init_body(int& color_counter);
		void follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw( Board& brd);
		Location get_location();
	private:
		Location loc;
		Color c;
		//Color c1 = (255, 50, 0);
		//Color c2 = (100, 0, 150);
		//Color c3 = (50, 0, 200);
		

	};
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	Location velocity = { 0,0 };
	static constexpr Color head_color = Colors::Green;
	
	bool was_eaten = false;
	int color_counter = 0;
};