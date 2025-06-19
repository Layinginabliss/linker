
#include <SFML\Graphics.hpp>
#include "vectors.h"
#include <string>

#ifndef V_MONITOR_H
#define V_MONITOR_H

//TODO: add the V_moniter macro or Static after finishing the static class for not repeting

class Static_v_moniter // static // variable_moniter
{
	sf::RenderWindow *window;
	sf::Text text;
	std::string msg;

public:

	Static_v_moniter(){};

	void setup (sf::RenderWindow &window,sf::Font &font,float character_size = 18,sf::Vector2f poistion = sf::Vector2f(0,0))//defalt
	{
		this->window = &window;
		text.setFont(font);
		
		text.setCharacterSize(character_size);
		text.setPosition(poistion);
	};


	void operator () (std::string name,int value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value);
		msg += '\n';
		
		text.setString(msg);
	};
	void operator () (std::string name,bool value)
	{
		msg += name;
		msg += " = ";
		if(value) msg += "true";
		else msg += "false";
		msg += '\n';
		
		text.setString(msg);
	};
	void operator () (std::string name,float value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value);
		msg += '\n';
		
		text.setString(msg);
	};
	
	void operator () (std::string name,v2 value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x);
		msg += " : ";
		msg += std::to_string(value.y);
		msg += '\n';
		
		text.setString(msg);
	};
	void operator () (std::string name,v2f value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x);
		msg += " : ";
		msg += std::to_string(value.y);
		msg += '\n';
		
		text.setString(msg);
	};

	void operator () (std::string name,v3 value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x);
		msg += " : ";
		msg += std::to_string(value.y);
		msg += " : ";
		msg += std::to_string(value.z);
		msg += '\n';
		
		text.setString(msg);
	};
	void operator () (std::string name,v3f value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x);
		msg += " : ";
		msg += std::to_string(value.y);
		msg += " : ";
		msg += std::to_string(value.z);
		msg += '\n';
		
		text.setString(msg);
	};

	void operator () (std::string name,v4 value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x1);
		msg += " : ";
		msg += std::to_string(value.y1);
		msg += " : ";
		msg += std::to_string(value.x2);
		msg += " : ";
		msg += std::to_string(value.y2);
		msg += '\n';
		
		text.setString(msg);
	};
	void operator () (std::string name,v4f value)
	{
		msg += name;
		msg += " = ";
		msg += std::to_string(value.x1);
		msg += " : ";
		msg += std::to_string(value.y1);
		msg += " : ";
		msg += std::to_string(value.x2);
		msg += " : ";
		msg += std::to_string(value.y2);
		msg += '\n';
		
		text.setString(msg);
	};

	void draw()
	{
		window->draw(text);
		msg.clear();
	}

};

#endif