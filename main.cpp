#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#define LINKER_SORCE

#include <SFML\Graphics.hpp> // load this fucker first
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "resource.h"

#include <windows.h> // for the save window
#include <commdlg.h> // for the save window

#include "v_moniter.h"
#include "text_box.h"
#include "sfml_zoom.h"
#include "loader2.h"
#include "icon.h"
#include "window.h"

#include "DemosticToolsSet.h"
#include "CommnadsHighLights.h"


//god fucking dammet i being hyberject with fuckkers
//  this can't handle more then 10 000  boxes 

//TODO: make auto IDmaker function insted of just a varible
//box lim as one varible (ex 50)

// attention TODO and new show path to varible
// wtf event going on here jezes it's fucking meess

/// user options
bool line_hight_light_1 = 0;
bool line_hight_light_2 = 0;
bool debug = 0;

bool load_succss = 1;
bool ones_saved = 0;

std::string about =
"Alt to Create\nRight click to Select\nLeft click to Delete\nShift + Select to link\nCtrl + Select to Remove a link\nScroll/Arrow to Zoom\nCtrl + S to Save\nTAB to select ground\nF1 for Neons F2 for Statics\nF12 to run Commands\n#printgrid#X#Y#Gap# #printgrid2#X#Y#Gap#\n#fullscreenNextTime# #saveAs#File_name#";

// custom theme

//use thes varibles for every act if needed
#include "ColorPalette.h"

std::string file_path_loaction = "";

#define window (*MAIN_WINDOW)
#define events (*MAIN_EVENTS)

std::shared_ptr<sf::RenderWindow> MAIN_WINDOW; // (sf::VideoMode(600, 600), "Linker", sf::Style::Default, sf::ContextSettings(4, 24, 8, 8, 1, 0, 1)); // 
std::shared_ptr<sf::Event> MAIN_EVENTS;

sf::Font font;

DESKTOP_ DESKTOP;

std::vector<WINDOW_> WINDOW;
std::vector<LINES_> LINES;

DESKTOP_ SDESKTOP;

std::vector<WINDOW_> SWINDOW;
std::vector<LINES_> SLINES;

float out_line = 3;

std::vector<Window> win;   // T_4
v2f mouse = v2f(0, 0);	   // T4_1
int select_window_id = -1; // T4_3
int select_window_array = -1;
int IDmaker = 0;				 // T4_3
int dragin_window_in_array = -1; // R_7 // T6_1

Static_v_moniter vm;

v2f center; // R_13
v2f old_center;

v2f defalt_box_limit = v2f(50, 50);

v2f box_limit = v2f(50, 50); // R_14 // T8
float font_size = 23;

int mouse_weel = -1;

struct Links // T5
{
	int WID1, WID2;
	Links()
	{
		WID1 = -1;
		WID2 = -1;
	};
	Links(int WID1, int WID2)
	{
		this->WID1 = WID1;
		this->WID2 = WID2;
	};
	void operator()(int WID1, int WID2)
	{
		this->WID1 = WID1;
		this->WID2 = WID2;
	};
};
std::vector<Links> ln;

bool LSpressing = 0; // T5_1
int SWID1 = -1;		 // T5_1
int SWID2 = -1;		 // T5_1
bool lock = 0;		 // T5_1

bool LCpressing = 0; // T5_3
int SWID1D = -1;	 // T5_3
int SWID2D = -1;	 // T5_3 // select window id 2 to delete
bool lock_1 = 0;	 // T5_3

bool groud_select = 1; // T6_1
bool MLpresing = 0;
v2f mouse_press_point = v2f(0, 0);
v2f distance = v2f(0, 0);

int FPS = 1;

float corrent_scale = 1;
v2f senstivity(10,1);

// controlls
// over simpfly

void T4_1() 
{
	if (events.type == sf::Event::MouseMoved)
		mouse.set(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

	if (events.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (out_line < 1)
				win.push_back(Window(window, events, font, IDmaker, box_limit, font_size, 1)); // T4_3 // R_14 // R_17
			else // T4_3 // R_14 // R_5
				win.push_back(Window(window, events, font, IDmaker, box_limit, font_size, int(out_line),"")); // "" ?

			win[win.size() - 1].text_cover.x1 = mouse.x - (win[win.size() - 1].text_cover.x2 / 2);													
			win[win.size() - 1].text_cover.y1 = mouse.y - (win[win.size() - 1].text_cover.y2 / 2);
			IDmaker++; // T4_3
		}
	}
}

// selction
void T4_3()
{
	for (int w = 0; w < win.size(); w++) // T4_3
	{
		if (win[w].select)
		{
			select_window_id = win[w].ID;
			win[w].select = 0;
			select_window_array = w;
			break; // R_6
		}
	}
}

void delete_a_fucking_box(int win_ar)
{
	bool start_over = 1;
	while (start_over) // clean all kin lines
	{
		start_over = 0;
		for (int l = 0; l < ln.size(); l++) // T5_4
			if (win[win_ar].ID == ln[l].WID1 || win[win_ar].ID == ln[l].WID2)
			{
				ln.erase(ln.begin() + l);
				start_over = 1;
			}
	}

	win.erase(win.begin() + win_ar);
	select_window_array = -1; // R_9
	select_window_id = -1;
}

// the deletion of a box
void T4_5() 
{
	for (int w = 0; w < win.size(); w++) // T4_5 // TO DO: if you see a bug while deleteing it fix it
	{
		if (win[w].T4_5())
		{
			bool start_over = 1;
			while (start_over)
			{
				start_over = 0;
				for (int l = 0; l < ln.size(); l++) // T5_4
					if (win[w].ID == ln[l].WID1 || win[w].ID == ln[l].WID2)
					{
						ln.erase(ln.begin() + l);
						start_over = 1;
					}
			}

			win.erase(win.begin() + w);
			select_window_array = -1; // R_9
			select_window_id = -1;

			break; // R_6
		}
	}
}

 // the event were the 2 box link , that sounded weird
void T5_1()
{
	// T5_1_1 selecting
	if (events.type == sf::Event::KeyPressed)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			LSpressing = 1;

	if (LSpressing)
	{
		if (!lock)
			for (int w = 0; w < win.size(); w++)
			{
				if (win[w].T5_1_1() && win[w].ID != SWID2)
				{
					SWID1 = win[w].ID;
					lock = 1;
				}
				else if (select_window_id != -1 && select_window_id != SWID2)
				{
					SWID1 = select_window_id;
					lock = 1;
				}
			}
		else
			for (int w = 0; w < win.size(); w++)
				if (win[w].T5_1_1() && win[w].ID != SWID1)
				{
					SWID2 = win[w].ID;
					lock = 0;
				}
	}
	else
	{
		SWID1 = -1;
		SWID2 = -1;
	}
	if (events.type == sf::Event::KeyReleased)
	{
		LSpressing = 0;
		lock = 0;
	}
	// T5_1_2
	if (SWID1 != -1 && SWID2 != -1)
	{
		bool exsist = 0;
		for (int l = 0; l < ln.size(); l++)
			if ((SWID1 == ln[l].WID1 || SWID1 == ln[l].WID2) && (SWID2 == ln[l].WID1 || SWID2 == ln[l].WID2))
			{
				exsist = 1;
				break;
			}
		if (!exsist)
			ln.push_back(Links(SWID1, SWID2));
	}
}

// T5_2 // all about line drawing
void T5_2() 
{
	for (int l = 0; l < ln.size(); l++) // T5_2
	{
		sf::Vertex line[2];
	//	sf::Vertex arrow[3];

		for (int w = 0; w < win.size(); w++)
		{

			line[0].color = main_text_color;
			line[1].color = main_text_color;

			if (line_hight_light_1) // R_10
			{

				line[1].color = sf::Color::Magenta;
				line[0].color = back_ground_color;
				

				//if (ln[l].WID1 == select_window_id)
				//	if (LCpressing || LSpressing)
				//		line[0].color = window_selet_Ctrl_outline_color;
				//	else
				//		line[0].color = window_select_outline_color;
				//if (ln[l].WID2 == select_window_id)
				//	if (LCpressing || LSpressing)
				//		line[1].color = window_selet_Ctrl_outline_color;
				//	else
				//		line[1].color = window_select_outline_color;
			}

			if (ln[l].WID1 == win[w].ID)
				line[0].position = sf::Vector2f(win[w].text_cover.x1 + (win[w].text_cover.x2 / 2),
					win[w].text_cover.y1 + (win[w].text_cover.y2 / 2));
			if (ln[l].WID2 == win[w].ID)
				line[1].position = sf::Vector2f(win[w].text_cover.x1 + (win[w].text_cover.x2 / 2),
					win[w].text_cover.y1 + (win[w].text_cover.y2 / 2));

		}

		window.draw(line, 2, sf::Lines);

	}
}

// T5_3 // remove of two box's link
void T5_3() 
{
	if (events.type == sf::Event::KeyPressed)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			LCpressing = 1;
	if (LCpressing)
	{
		if (!lock_1)
			for (int w = 0; w < win.size(); w++)
			{
				if (win[w].T5_1_1() && win[w].ID != SWID2D)
				{
					SWID1D = win[w].ID;
					lock_1 = 1;
				}
				else if (select_window_id != -1 && select_window_id != SWID2D)
				{
					SWID1D = select_window_id;
					lock_1 = 1;
				}
			}

		else
			for (int w = 0; w < win.size(); w++)
				if (win[w].T5_1_1() && win[w].ID != SWID1D)
				{
					SWID2D = win[w].ID;
					lock_1 = 0;
				}
	}
	else
	{
		SWID1D = -1;
		SWID2D = -1;
	}
	if (events.type == sf::Event::KeyReleased)
	{
		LCpressing = 0;
		lock_1 = 0;
	}
	// T5_3_2
	if (SWID1D != -1 && SWID2D != -1)
		for (int l = 0; l < ln.size(); l++)
			if ((ln[l].WID1 == SWID1D || ln[l].WID2 == SWID1D) && (ln[l].WID1 == SWID2D || ln[l].WID2 == SWID2D))
			{
				ln.erase(ln.begin() + l);
				break;
			}
}

// T6 // moving part ?
void T6() 
{
	if (events.type == sf::Event::MouseButtonPressed)
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (!MLpresing))
		{
			if (dragin_window_in_array != -1)
				groud_select = 0;
			else
				groud_select = 1;
			MLpresing = 1;
			mouse_press_point = v2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			for (int w = 0; w < win.size(); w++) // T6_2
				win[w].window_old_position = v2f(win[w].text_cover.x1, win[w].text_cover.y1);
			old_center = center;
		}

	if (groud_select)
	{
		select_window_array = -1; // R_11
		select_window_id = -1;
		if (MLpresing)
		{
			distance = v2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) - mouse_press_point; // T6_1
			for (int w = 0; w < win.size(); w++)																	// T6_2
			{
				win[w].text_cover.x1 = win[w].window_old_position.x + distance.x;
				win[w].text_cover.y1 = win[w].window_old_position.y + distance.y;
			}
			center = old_center + distance; // R_13
		}
	}

	if (events.type == sf::Event::MouseButtonReleased)
	{
		MLpresing = 0;
		distance = 0;
		mouse_press_point = 0;
	}
}

//senstivity // litaral zooming all in function with some exception for the visual aids and font errors
void T7(int command = 0) // T7_2 // T3_R.. 
{
	if ((mouse_weel != -1) || command == 1 || command == 2)
	{
		if (((mouse_weel == 1) || (command == 1)) && (font_size < 150))
		{
			//			if(!fixing)zoom++;

			zoom_raw_size_value(font_size, senstivity, ZOOM_IN);									  // R_15 // R_14
			zoom_raw_size_value(out_line, senstivity, ZOOM_IN);										  // R_15 // R_14
			zoom_raw_size_value(box_limit.x, senstivity, ZOOM_IN);									  // R_15 // R_14
			zoom_raw_size_value(box_limit.y, senstivity, ZOOM_IN);									  // R_15
			for (int w = 0; w < win.size(); w++)													  // R_16
				win[w].distance_to_center = v2f(win[w].text_cover.x1, win[w].text_cover.y1) - center; // R_16
			zoom_raw_possition_value(center, mouse, senstivity, ZOOM_IN);							  // R_13

			for (int w = 0; w < win.size(); w++)
			{
				win[w].text_cover.x1 = center.x + win[w].distance_to_center.x; // R_16
				win[w].text_cover.y1 = center.y + win[w].distance_to_center.y;

				sf::RectangleShape edit; // R_15
				edit.setPosition(win[w].text_cover.x1, win[w].text_cover.y1);
				edit.setSize(sf::Vector2f(win[w].text_cover.x2, win[w].text_cover.y2));

				zoom_rectangle(edit, center, senstivity, ZOOM_IN); // R_15

				win[w].text_cover.x1 = edit.getPosition().x;
				win[w].text_cover.y1 = edit.getPosition().y;

				win[w].text.character_size = font_size;
				if (!(out_line <= 1))
					win[w].cover.setOutlineThickness(int(out_line)); // R_17
				win[w].box_limit = box_limit;
			}

			  corrent_scale = corrent_scale + (corrent_scale / senstivity.x * senstivity.y);

		}

		if (((mouse_weel == 0) || (command == 2)) && (font_size > 0.3))
		{
			//			if(!fixing)zoom--;

			zoom_raw_size_value(font_size, senstivity, ZOOM_OUT);	// R_15 // R_14
			zoom_raw_size_value(out_line, senstivity, ZOOM_OUT);	// R_15 // R_14
			zoom_raw_size_value(box_limit.x, senstivity, ZOOM_OUT); // R_15 // R_14
			zoom_raw_size_value(box_limit.y, senstivity, ZOOM_OUT); // R_15
			for (int w = 0; w < win.size(); w++)					// R_16
				win[w].distance_to_center = v2f(win[w].text_cover.x1, win[w].text_cover.y1) - center;
			zoom_raw_possition_value(center, mouse, senstivity, ZOOM_OUT); // R_13

			for (int w = 0; w < win.size(); w++)
			{
				win[w].text_cover.x1 = center.x + win[w].distance_to_center.x; // R_16
				win[w].text_cover.y1 = center.y + win[w].distance_to_center.y;

				sf::RectangleShape edit; // R_15
				edit.setPosition(win[w].text_cover.x1, win[w].text_cover.y1);
				edit.setSize(sf::Vector2f(win[w].text_cover.x2, win[w].text_cover.y2));

				zoom_rectangle(edit, center, senstivity, ZOOM_OUT); // R_15

				win[w].text_cover.x1 = edit.getPosition().x;
				win[w].text_cover.y1 = edit.getPosition().y;

				win[w].text.character_size = font_size;
				if (!(out_line <= 1))
					win[w].cover.setOutlineThickness(int(out_line)); // // R_17
				win[w].box_limit = box_limit;
			}

			corrent_scale = corrent_scale - (corrent_scale / senstivity.x * senstivity.y);
		}

		mouse_weel = -1; // T7_2
	}
}

void T7_1() 
{
	if (events.type == sf::Event::MouseWheelMoved)
	{
		if (events.mouseWheel.delta > 0)
			mouse_weel = 1;
		if (events.mouseWheel.delta < 0)
			mouse_weel = 0;

		//		T7();  //T7_2
	}
	if ((events.type == sf::Event::MouseWheelMoved) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		mouse_weel = -1;
}

 // the center lines
void R_13()
{

	sf::Vertex line[4]; // R_13
	line[0].position = sf::Vector2f(center.x, 0);
	line[1].position = sf::Vector2f(center.x, window.getSize().y);
	line[2].position = sf::Vector2f(0, center.y);
	line[3].position = sf::Vector2f(window.getSize().x, center.y);
	for (int l = 0; l < 4; l++)
		line[l].color = center_lines_color;
	window.draw(line, 4, sf::Lines);

}

void R_14()
{
	if (!load_succss)
	{
		sf::Text how_to_use;
		how_to_use.setFont(font);
		how_to_use.setStyle(sf::Text::Bold);
		how_to_use.setString(about);
		how_to_use.setCharacterSize(font_size / 2.5);
		how_to_use.setPosition(sf::Vector2f(center.x + font_size / 3, center.y - how_to_use.getLocalBounds().height - font_size / 3));
		how_to_use.setFillColor(how_use_color);
		window.draw(how_to_use);
	}
}

// infor about the program state // and the drawing windows 
void R_15() 
{
	for (int w = 0; w < win.size(); w++) // R_15
		win[w].draw(out_line);

	if ((distance != 0) && debug)
	{
		sf::Vertex line[2];
		line[0] = sf::Vector2f(mouse_press_point.x, mouse_press_point.y);
		line[1] = sf::Vector2f(mouse.x, mouse.y);

		window.draw(line, 2, sf::Lines);
	}
	if (debug)
		vm.draw();
}

void R_10() // outline colore change << // event loop
{
	for (int w = 0; w < win.size(); w++) // R_10 //as a key press event
	{
		if (line_hight_light_1)
			win[w].cover.setOutlineColor(sf::Color::Magenta);
		else
			win[w].cover.setOutlineColor(window_outline_color);
		
		if (win[w].command != main_text_color)
			win[w].cover.setOutlineColor(win[w].command);
	}

//	if(select_window_array != -1)win[select_window_array].cover.setOutlineColor(win[select_window_array].command);

	if (select_window_array != -1 )
	{
		if (win[select_window_array].command == main_text_color)
		{
			if (!groud_select)
				win[select_window_array].cover.setOutlineColor(window_select_outline_color);

			if (LSpressing || LCpressing)
				win[select_window_array].cover.setOutlineColor(window_selet_Ctrl_outline_color);
		}
	}
}

// shorcuts
void T7_2()
{

	if (events.type == sf::Event::KeyPressed) // T7 ..
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			T7(ZOOM_IN);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			T7(ZOOM_OUT);
		//				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		//					T7_3(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
		{
			if (line_hight_light_1 == 0)
				line_hight_light_1 = 1;
			else
				line_hight_light_1 = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
		{
			if (line_hight_light_2 == 0)
				line_hight_light_2 = 1;
			else
				line_hight_light_2 = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
		{
			if (debug == 0)
				debug = 1;
			else
				debug = 0;
		}
		
	}
}


#include "Statics.h"

bool MStimer(sf::Clock &clock, float delay)
{
	sf::Time time = clock.getElapsedTime();
	if (time.asMilliseconds() >= delay)
	{
		clock.restart();
		return 1;
	}
	else
		return 0;
}

std::string OpenFileDialog()
{
	std::string filePath;

	OPENFILENAMEA ofn = {0};
	char szFile[MAX_PATH] = {0};

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Binary Linker files \0*.bln*\0";
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";

	if (GetOpenFileNameA(&ofn) == TRUE)
	{
		filePath = szFile;
	}

	return filePath;
}

int C = 1;
void Save(std::string &file_path)
{

	SDESKTOP.box_limit = box_limit;
	SDESKTOP.center = center;
	SDESKTOP.font_size = font_size;
	SDESKTOP.IDmaker = IDmaker;
	SDESKTOP.out_line = out_line;
	SDESKTOP.win_size(window.getSize().x, window.getSize().y);

	if (line_hight_light_1)
		SDESKTOP.line_hight_light = 1;
	else
		SDESKTOP.line_hight_light= 0;
	if (debug)
		SDESKTOP.debug = 1;
	else
		SDESKTOP.debug = 0;

	SWINDOW.resize(win.size());
	SLINES.resize(ln.size());

	for (int w = 0; w < SWINDOW.size(); w++)
	{
		SWINDOW[w].ID = win[w].ID;
		SWINDOW[w].position(win[w].text_cover.x1, win[w].text_cover.y1);
		SWINDOW[w].text = win[w].text.text.getString();
	}

	for (int l = 0; l < SLINES.size(); l++)
	{
		SLINES[l].winID1 = ln[l].WID1;
		SLINES[l].winID2 = ln[l].WID2;
	}

	auto faild_to_save_msg = L"Faild to save the file.\nCheck the file path\nRun #saveAs#File_name# command to relocate the adress";

	if (win.size() > 0)
	{
		if (load_succss || file_path != "")
		{
			if (!save(SDESKTOP, SWINDOW, SLINES, file_path))
				MessageBoxW(NULL, faild_to_save_msg, L"Faild to save", MB_ICONERROR | MB_OK);
			
		}
		else
		{
			if (!ones_saved)
			{
				while (std::filesystem::exists(std::string("New Linker File (" + std::to_string(C) + ").bln")))
					C++;

				if(!save(SDESKTOP, SWINDOW, SLINES, std::string("New Linker File (" + std::to_string(C) + ").bln")))
					MessageBoxW(NULL, faild_to_save_msg, L"Faild to save", MB_ICONERROR | MB_OK);
			}
			else
				if(!save(SDESKTOP, SWINDOW, SLINES, std::string("New Linker File (" + std::to_string(C) + ").bln")))
					MessageBoxW(NULL,faild_to_save_msg, L"Faild to save", MB_ICONERROR | MB_OK);

		}
	}

}

#include "CommandFunctions.h"


int main()
{
	const char* note = "5/10/2022 - linker 1.2v";

	if (!font.loadFromFile("font.ttf"))
		if (!font.loadFromFile("font.pfb"))
			if (!font.loadFromFile("font.otf"))
				if (!font.loadFromFile("font.otf"))
					if (!font.loadFromFile("font.fnt"))
						MessageBoxW(NULL, L"Font file not found!", L"Error", MB_ICONERROR | MB_OK);
					


	file_path_loaction = OpenFileDialog();

	std::string title = file_path_loaction;
	if (title == "") title = "New File";


	// smart pointers

	//styles


	if (file_path_loaction.find(".bln") == std::string::npos) // loading odder matter 
		load_succss = 0;
	else
	{
//		std::cout << " file valied " << std::endl;
//		std::cout << file_path_loaction << std::endl;
		if (load(DESKTOP, WINDOW, LINES, file_path_loaction)) load_succss = 1;
		else load_succss = 0;
	}

	if (exceptinal_full_screen)
		MAIN_WINDOW = std::make_shared<sf::RenderWindow> (sf::VideoMode::getFullscreenModes()[0], std::string("Linker - " + title),sf::Style::Fullscreen, sf::ContextSettings(4, 24, 8, 8, 1, 0, 1));
	else
		MAIN_WINDOW = std::make_shared<sf::RenderWindow>(sf::VideoMode(600,600), std::string("Linker - " + title), sf::Style::Default, sf::ContextSettings(4, 24, 8, 8, 1, 0, 1));
	
	
	MAIN_EVENTS = std::make_shared<sf::Event>();


	sf::VideoMode win_size;

	if (load_succss && !exceptinal_full_screen) // load window size
	{
		
		win_size = sf::VideoMode(DESKTOP.win_size.x, DESKTOP.win_size.y);
		window.setSize(sf::Vector2u(DESKTOP.win_size.x, DESKTOP.win_size.y));
	}
	else
		win_size = sf::VideoMode(window.getSize().x,window.getSize().y);

	if (load_succss)
		center = DESKTOP.center;
	else
		center = v2f(window.getSize().x / 2, window.getSize().y / 2);

	vm.setup(window, font, 12);

	if (load_succss)
	{
		if(!exceptinal_full_screen) window.setPosition(sf::Vector2i(DESKTOP.win_position.x, DESKTOP.win_position.y));
		out_line = DESKTOP.out_line;
		font_size = DESKTOP.font_size;
		box_limit = DESKTOP.box_limit;
		IDmaker = DESKTOP.IDmaker;

		if (DESKTOP.line_hight_light == 1)
			line_hight_light_1 = 1;
		
		else
			line_hight_light_1 = 0;
		if (DESKTOP.debug == 1)
			debug = 1;
		else
			debug = 0;
	}


	for (int w = 0; w < WINDOW.size(); w++) // loading commands
	{
		win.push_back(Window(window, events, font, WINDOW[w].ID, box_limit, font_size, out_line, WINDOW[w].text));

		sf::Color found_commands = find_commands(WINDOW[w].text); // comman in the text to high light
		if (found_commands != sf::Color::Transparent)
			win[w].command = found_commands;

		win[w].text_cover.x1 = WINDOW[w].position.x;
		win[w].text_cover.y1 = WINDOW[w].position.y;
		win[w].select = 0;
	}



	for (int l = 0; l < LINES.size(); l++)
	{
		ln.push_back(Links(LINES[l].winID1, LINES[l].winID2));
	}

	// end of load

	window.setIcon(icon.width, icon.height, icon.pixel_data);
	sf::Clock FPSclock;

	sf::Clock SavingClock;

	while (window.isOpen()) // insane amount of Big-O's from win's ln's
	{	

		if (debug)
			Stats();

		T4_3(); // see if window is slected or not

		if (!window.hasFocus()) FPS = 5;
		else if (MStimer(FPSclock, 700))FPS = 10;

		while (window.pollEvent(events))
		{
			if (events.type == sf::Event::Closed)
			{
				SDESKTOP.win_position(window.getPosition().x, window.getPosition().y);
				window.close();
			}
			if (events.type == sf::Event::Resized)
				window.setView(sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)));

			if (events.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					Save(file_path_loaction);
					window.setTitle(std::string("Linker - " + title + " - Saved "));
					ones_saved = 1;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
					groud_select = 1;

				int for_bitten_event_ids;


#ifdef NDEBUG
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12))
#endif // NDEBUG
#ifndef NDEBUG 
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
#endif // NDEBUG 
				{
					loop(win.size(),w)
					{
						std::string command = win[w].text.text.getString();

						#include"CommandCatcherInEvent.h"
					}

				}

			}


			T4_1(); // T4_1 // add window
			if (select_window_array != -1)
				win[select_window_array].T_1(); // T4_4

			if (dragin_window_in_array == -1) // R_7
			{	for (int w = 0; w < win.size(); w++)
					if (win[w].T_2())
					{
						dragin_window_in_array = w;
						break;
					} // T4_2 // R_6
			}
			if (dragin_window_in_array != -1)			// R_7
				if (!win[dragin_window_in_array].T_2()) // T4_2
					dragin_window_in_array = -1;

			T5_1(); // T5_1 //add line
			T5_3(); // T5_3 delete line
			T6(); // T6 // ground move
			T7_1(); // T7_1 // zooming
			T7_2(); // zooming part
			R_10(); // out line color changer 
			FPS = 60;
		}
		
		if (SavingClock.getElapsedTime().asSeconds() >= 2)
		{
			window.setTitle(std::string("Linker - " + title));
			SavingClock.restart();
		}

		window.setFramerateLimit(FPS);

		T7(); // T7_2
		T4_5();

		window.clear(back_ground_color);

		R_14();
		R_13();

		for (int w = 0; w < win.size(); w++)
			win[w].pre_draw_set();

		T5_2(); // T5_2 // draw line

		R_15(); // information about the program state

		window.display();
	}

	Save(file_path_loaction);

//	delete MAIN_WINDOW;
//	delete MAIN_EVENTS;

	return 0;

}