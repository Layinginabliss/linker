#pragma once

#ifndef LINKER_SORCE
#include "main.cpp"
#endif // !LINKER_SORCE


#ifndef STATS 
#define STATS
void Stats()
{
	vm("select win iarray", select_window_array);
	vm("select win ID", select_window_id);
	vm("win count", int(win.size()));
	vm("ln count", int(ln.size()));
//	vm("select ID for new line", v2(SWID1, SWID2));
//	vm("delete ID for line", v2(SWID1D, SWID2D));
	int LS = 0, LC = 0;
	if (LSpressing)
		LS = 1;
	if (LCpressing)
		LC = 1;
	vm("Shift / Ctr", v2(LS, LC));
	vm("drag win in array", dragin_window_in_array);
	vm("ground select", groud_select);
	vm("mouse", mouse);
	vm("distance", distance);
//	vm("out line", out_line);
//	vm("font size", font_size);
	vm("box limit", box_limit);
	vm("center", center);
	vm("line high light", line_hight_light_1);
	vm("ID maker", IDmaker);
	vm("scale ratio", defalt_box_limit / box_limit);
	vm("FPS > ", FPS);
	if (select_window_array != -1)
	{
		vm("v4f win " + std::to_string(select_window_id), win[select_window_array].text_cover);
		vm("distance to center win " + std::to_string(select_window_id), win[select_window_array].distance_to_center);
		vm("text empty", win[select_window_array].text.empty);
		vm(win[select_window_array].text.text.getString(), int(std::string(win[select_window_array].text.text.getString()).size()));
	}
}

#endif 
