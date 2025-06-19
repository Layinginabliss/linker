#pragma once


#ifndef LINKER_SORCE
#include "main.cpp"
#endif // !LINKER_SORCE


#ifndef CMFU 
#define CMFU


void PaintGrid(v2 size, sf::Vector2f position, int Gap,bool slit = 0)
{

	float gap = Gap * box_limit.x / defalt_box_limit.x;

	loop2(size.y, y, size.x, x)
	{

		v2f ps;
		if (slit)
			ps = v2f((x * (gap)) + (y * gap / 2) + position.x, position.y + (y * gap));
		else
			ps = v2f(x * (gap)+position.x, position.y + (y * gap));

		win.push_back(
			Window(
				window,
				events,
				font,
				IDmaker,
				box_limit,
				font_size,
				out_line,
				"",
				ps));

		win[win.size()-1].select = 0; // wtf dude

		IDmaker++;
	}

	select_window_id = -1;
	select_window_array = -1;
	groud_select = 1;
}

#endif