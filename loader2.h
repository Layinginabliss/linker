#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "vectors.h"
#include "DemosticToolsSet.h"


#ifndef LOADER_2_H 
#define LOADER_2_H

#define SHOW_ 0

bool exceptinal_full_screen = 0; // loading predifined varibles

struct DESKTOP_
{

	v2 win_size;
	v2 win_position;
	v2f center;
	float out_line; 
	float font_size;
	v2f box_limit;
	int IDmaker;
	
	int line_hight_light;
	int debug;

};
struct WINDOW_ // T8
{
	WINDOW_ () {}; 

	WINDOW_ 
	(
	   std::string &text,
	   v2f position,
	   int ID
	) 
	
	{
		this->text = text;
		this->position = position;
		this->ID = ID;
	};
	
	int ID;
	v2f position;
	std::string text;
};
struct LINES_ // T8
{
	LINES_ () {};

	LINES_ (int ID1,int ID2) {this->winID1 = ID1; this->winID2 = ID2;};

	int winID1;
	int winID2;
};

void save_(std::ofstream & output,char * data)
{
//	output.write(data,sizeof(data));
	output.write(reinterpret_cast<const char*>(data), sizeof(int));
}

bool save(DESKTOP_ &dss,std::vector<WINDOW_> &window_s,std::vector <LINES_> &line_s,std::string output_file_location)
{

	std::ofstream output (output_file_location,std::ios::binary | std::ios::out);
	if(output.is_open())
	{
	save_(output,(char *) &dss.win_size.x); // int
	save_(output,(char *) &dss.win_size.y); // int 

	save_(output,(char *) &dss.win_position.x); // int
	save_(output,(char *) &dss.win_position.y); // int 

	save_(output,(char *) &dss.center.x); // float
	save_(output,(char *) &dss.center.y); // float

	save_(output,(char *) &dss.out_line); // float
	save_(output,(char *) &dss.font_size); // float

	save_(output,(char *) &dss.box_limit.x);  //float
	save_(output,(char *) &dss.box_limit.y); // float

	save_(output,(char *) &dss.IDmaker); // int

	save_(output,(char *) &dss.line_hight_light); // int

	save_(output,(char *) &dss.debug); // int

	int window_s_amount = window_s.size() ;
	save_(output,(char *) &window_s_amount);

	int line_s_amount = line_s.size();
	save_(output,(char *) &line_s_amount);

	for (int w = 0; w < window_s_amount; w++)
	{
		save_(output,(char*) &window_s[w].ID);
		save_(output,(char*) &window_s[w].position.x);
		save_(output,(char*) &window_s[w].position.y);
		int text_size = window_s[w].text.size();
		save_(output,(char*) &text_size);
		output.write(window_s[w].text.c_str(),text_size);
	}

	for (int l = 0; l < line_s_amount; l++)
	{
		save_(output,(char*) &line_s[l].winID1);
		save_(output,(char*) &line_s[l].winID2);
	}

	output.close();
	return true;
	}else return false;
}
bool load(DESKTOP_ &dsl,std::vector<WINDOW_> &window_l,std::vector <LINES_> &line_l,std::string input_file_location)
{
	std::ifstream input (input_file_location,std::ios::binary | std::ios::in);
	if(input.is_open())
	{
	input.read((char*)&dsl.win_size.x,sizeof(int));
	input.read((char*)&dsl.win_size.y,sizeof(int));

	input.read((char*)&dsl.win_position.x,sizeof(int));
	input.read((char*)&dsl.win_position.y,sizeof(int));

	input.read((char*)&dsl.center.x,sizeof(float));
	input.read((char*)&dsl.center.y,sizeof(float));

	input.read((char*)&dsl.out_line,sizeof(float));
	input.read((char*)&dsl.font_size,sizeof(float));

	input.read((char*)&dsl.box_limit.x,sizeof(float));
	input.read((char*)&dsl.box_limit.y,sizeof(float));

	input.read((char*)&dsl.IDmaker,sizeof(int));

	input.read((char*)&dsl.line_hight_light,sizeof(int));

	input.read((char*)&dsl.debug,sizeof(int));


#if(SHOW_)
	std::cout<<"win_s "<<dsl.win_size.x<<","<< dsl.win_size.y <<std::endl;
	std::cout<<"center "<<dsl.center.x<<","<< dsl.center.y <<std::endl;
	std::cout<<"outline"<<dsl.out_line <<std::endl;
	std::cout<<"fontsize "<<dsl.font_size <<std::endl;
	std::cout<<"boxsize "<<dsl.box_limit.x<<"-"<< dsl.box_limit.y <<std::endl;
#endif


	int window_amount;
	input.read((char*)&window_amount,sizeof(int));

	int line_amount;
	input.read((char*)&line_amount,sizeof(int));

#if(SHOW_)
	std::cout<<"window_a"<<window_amount<<std::endl;
	std::cout<<"line_a"<<line_amount<<std::endl;
#endif
	for (int w = 0; w < window_amount; w++)
	{
		window_l.push_back(WINDOW_());
		input.read((char*)&window_l[w].ID,sizeof(int));
		input.read((char*)&window_l[w].position.x,sizeof(int));
		input.read((char*)&window_l[w].position.y,sizeof(int));
		int text_size = 0;
		input.read((char*)&text_size,sizeof(int));
		for (int ts = 0; ts < text_size; ts++)
		{
			char c;
			input.read(&c,sizeof(char));
			window_l[w].text.push_back(c);
		}

		std::string command = window_l[w].text;

#include"CommandCatcherInLoading.h"

#if(SHOW_)
		std::cout<<"win "<<w<< " id - "<<window_l[w].ID<<std::endl;
		std::cout<<"win "<<w<< " pos - "<<window_l[w].position.x<<","<< window_l[w].position.y <<std::endl;
		std::cout<<"win "<<w<< " text size - "<<window_l[w].text.size()<<std::endl;
		std::cout<<"win "<<w<< " text - "<<window_l[w].text<<std::endl;
#endif		
	}

	for (int l = 0; l < line_amount; l++)
	{
		line_l.push_back(LINES_());
	
		input.read((char*)&line_l[l].winID1,sizeof(int));
		input.read((char*)&line_l[l].winID2,sizeof(int));

#if(SHOW_)
		std::cout<<"l "<<l<<" "<<line_l[l].winID1<<","<<line_l[l].winID2<<std::endl;
#endif

	}
	input.close();
	return true;
	}else return false;
}

#endif