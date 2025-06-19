#include <SFML\Graphics.hpp>
#include "vectors.h"
#include <string>
#include"CommnadsHighLights.h"

#ifndef V_MONITOR
#define V_MONITOR

class Text_box // old sfml support text box . h
{

	sf::RenderWindow *window;
	sf::Event *event;
	sf::RectangleShape cover;

public:
	bool empty; // for R_1
	float character_size; // for none failing 
	std::string msg;
	sf::Text text;
	bool cover_;

	Text_box(){};

	void setup(sf::RenderWindow &window,sf::Event &event,sf::Font &font,float character_size = 18,std::string msg = "")
	{
		cover_ = 0;

		this->window = &window;
		this->event = &event;
		text.setFont(font);
		text.setCharacterSize(character_size);
		this->character_size = character_size;
		if(msg == "")empty = 1;
		else empty = 0;
		this->msg = msg;

		text.setString(msg);
		text.setFillColor(sf::Color(250,250,250));// defalt
//		text.setPosition(100,100);

		cover.setFillColor(sf::Color::Transparent);
		cover.setOutlineColor(sf::Color::Red);
		cover.setOutlineThickness(1);
		
	}

	sf::Color get() // Text box v0.1
	{

		if (!((event->text.unicode == sf::Keyboard::Escape) || (event->text.unicode == 27)))
		{
			if (event->text.unicode == sf::Keyboard::BackSpace || event->text.unicode == 8) // it's 8 for some reason in back space // T_1_1
			{
				if (msg.size() != 0) msg.erase(msg.size() - 1, 1);
			}
			else if (event->text.unicode == 13) //13 is enter T_1_2 
			{
				//				if(empty) msg.clear();
				msg += '\n';
				empty = 0;
			}
			else // + T_1_R_1
			{
				if (empty)
				{
					msg.clear();
					msg += event->text.unicode;
					empty = 0;
				}
				else msg += event->text.unicode;
			}
			if (msg.size() == 0)
			{
				msg = "+";
				empty = 1;
				text.setString("");
			}
			else text.setString(msg);
		}

		return find_commands(text.getString());

		// seek the end of brackets
	}
	void set_character_Size()
	{
		text.setCharacterSize(character_size);
	}

	void draw()
	{
		text.setCharacterSize(character_size);

		if(cover_)
		{
			cover.setSize(sf::Vector2f(text.getGlobalBounds().width,text.getGlobalBounds().height));
			cover.setPosition(text.getPosition());
		}
		
		window->draw(text);
		if(cover_) window->draw(cover);
	};

};
#endif