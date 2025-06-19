#pragma once
#include "DemosticToolsSet.h"

#ifndef COMMAND_HIGHLIGHT_H
#define COMMAND_HIGHLIGHT_H

#define IfInReturn(in,what,whattoreturn)\
if (in.find(what) != std::string::npos)\
return whattoreturn 

sf::Color find_commands(std::string text)
{
	IfInReturn(text, "#printgrid#", sf::Color::Magenta);
	IfInReturn(text, "#printgrid2#", sf::Color::Magenta);
	IfInReturn(text, "#fullscreenNextTime#", sf::Color::White);
	IfInReturn(text, "#saveAs#", sf::Color::White);

	return sf::Color::Transparent;
}

#endif // !COMMAND_HIGHLIGHT_H

