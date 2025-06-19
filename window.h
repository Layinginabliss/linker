#pragma once

#include <SFML/Graphics.hpp>
#include "vector"
#include "text_box.h"
#include "v_moniter.h"
#include "ColorPalette.h"

#ifndef WINDOW_BOX_H
#define WINDOW_BOX_H

class Window
{
	sf::RenderWindow *window; // T_3
	sf::Event *event;

	bool button(v4f button, v2f mouse) // T_2
	{
		if (button.x1 < mouse.x && button.y1 < mouse.y && button.x2 + button.x1 > mouse.x && button.y2 + button.y1 > mouse.y)
		{
			return 1;
		}
		else
			return 0;
	}
	v2f mouse_position;
	v2f clicked_position;
	v2f box_old_position;
	bool lock;

	bool R_pressing; // T4_5

public:

	sf::Color command;
	v2f box_limit;			  // T_1_R_3
	Text_box text;			  // T_1 task 1
	v4f text_cover;			  // T_1 task 2 // T_4 common root one
	sf::RectangleShape cover; // T_1_R_2  // T_3
	bool select;			  // T4_1
	int ID;					  // T4_1
	v2f window_old_position;  // T6_2
	v2f distance_to_center;	  // T7_2 // T7_3

	Window(sf::RenderWindow &window, sf::Event &event, sf::Font &font, int ID, v2f box_limit, float font_size, float out_line,std::string tmsg = "",v2f position = v2f(0,0)) // T4_1 // R_14  .3
	{

//		command = outline_color; // <<

		command = main_text_color;

		this->ID = ID;

		this->window = &window;
		this->event = &event;
		text.setup(window, event, font, font_size, tmsg);

		cover.setFillColor(window_cover_color); // defalt 

		this->box_limit = box_limit; // dfalt //T_1

		text_cover.set(position.x,position.y, box_limit.x, box_limit.y); // defalt  // needing value for T_2
		cover.setOutlineThickness(out_line);			// R_10
		cover.setOutlineColor(window_outline_color);	// R_10  // ?
		cover.setPosition(text_cover.x1, text_cover.y1);
		cover.setSize(sf::Vector2f(text_cover.x2, text_cover.y2));
		mouse_position = 0;
		box_old_position = 0;
		clicked_position = 0;
		lock = 0;

		select = 1; // 1 // T4_2 // change it
		R_pressing = 0;
		distance_to_center = 0;
	};

	// box preparation ?
	void T_1(bool set_only_cover = 0) // get to a box //T7_R..
	{
		// T_1 task 1

		if (!set_only_cover) //
		{
			if (event->type == sf::Event::TextEntered)
			{
				sf::Color colorsr = text.get();
				if (colorsr != sf::Color::Transparent)
					command = colorsr;
				else command = main_text_color;
			}
		}
		// T_1 task 2

		if (text.text.getGlobalBounds().width + (text.character_size / 3 * 4) > box_limit.x) // T_1_R_3
		{
			text_cover.x2 = text.text.getGlobalBounds().width + (text.character_size / 3 * 4); // T_1_R_2
		}
		else
			text_cover.x2 = box_limit.x;
		if (text.text.getGlobalBounds().height + (text.character_size / 3 * 4) > box_limit.y)
		{
			text_cover.y2 = text.text.getGlobalBounds().height + (text.character_size / 3 * 4); // T_1_R_2
		}
		else
			text_cover.y2 = box_limit.y;

		//		vm.v_moniter("cover",text_cover);
		//		cover.setPosition(text_cover.x1,text_cover.y1); //X1
	};

	bool T_2() // move a box // T4_5
	{
		if (event->type == sf::Event::MouseMoved) // common .. T_2 T_3 T4_5
		{
			mouse_position.set(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
		}

		if (event->type == sf::Event::MouseButtonPressed)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !lock)
			{
				if (button(text_cover, mouse_position))
				{
					lock = 1;
					clicked_position = mouse_position;
					box_old_position.set(text_cover.x1, text_cover.y1);
					select = 1; // T4_3
				}
			}

		if (event->type == sf::Event::MouseButtonPressed)
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) // T4_5
				R_pressing = 1;
		if (lock)
		{

			text_cover.x1 = mouse_position.x + (box_old_position.x - clicked_position.x);
			text_cover.y1 = mouse_position.y + (box_old_position.y - clicked_position.y);

			//			cover.setPosition(text_cover.x1,text_cover.y1); // X2
		}
		if (event->type == sf::Event::MouseButtonReleased) // common ... T4_5
		{
			lock = 0;
			//			mouse_position = 0;
			R_pressing = 0;
		}

		if (lock)
			return 1;
		else
			return 0;
	}

	bool T4_5()
	{
		if (R_pressing)
		{
			if (button(text_cover, mouse_position))
			{
				return true;
			}
			else
				return 0;
		}
		else
			return 0;
	}

	bool T5_1_1()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (button(text_cover, mouse_position))
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}

	void pre_draw_set() // some bug fix the map on line error and drawing
	{
		text.set_character_Size(); // T7_R ...
		this->T_1(1);

		text.text.setPosition(text_cover.x1 + (text.character_size / 2), text_cover.y1 + (text.character_size / 2)); // T_3 joing T_1 & T_2
		cover.setPosition(text_cover.x1, text_cover.y1);															 // T4_2
		cover.setSize(sf::Vector2f(text_cover.x2, text_cover.y2));													 // T7
	}
	void draw(float out_line)
	{
		text.text.setFillColor(command);

		if (cover.getOutlineThickness() > 1)
			cover.setOutlineThickness(out_line);
		else
			cover.setOutlineThickness(1);
		window->draw(cover);
		text.draw();
	};
};

#endif