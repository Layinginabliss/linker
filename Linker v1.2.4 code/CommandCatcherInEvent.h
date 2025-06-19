#pragma once
#include "DemosticToolsSet.h"
#include "CommandCatchersTools.h"

// in event
// can use a swich but it's the same plus no brekings

if (found("#printgrid#"))
{

	//std::string command1 = command;
	//command1.erase(command1.begin(), command1.begin() + std::string("#printgrid#").size());

	PrepeareCC("#printgird#",CC); // carbon copy

	GrabFromStart(CC, "#", X);
	GrabFromStart(CC, "#", Y);
	GrabFromStart(CC, "#", Gap);

	if (Gap == "")Gap = "200";

	if (!(X == "" || Y == ""))
	{
		PaintGrid(v2(std::stoi(X), std::stoi(Y)), win[w].cover.getPosition(), std::stoi(Gap));

		//		delete_a_fucking_box(w);
		//		w = -1;
	}

}

if (found("#printgrid2#"))
{
	// extaction of need varibles

	//std::string command2 = command;
	//command2.erase(command2.begin(), command2.begin() + std::string("#printgrid2#").size());

	PrepeareCC("#printgrid2#",CC);

	GrabFromStart(CC, "#", X);
	GrabFromStart(CC, "#", Y);
	GrabFromStart(CC, "#", Gap);

	if (Gap == "") Gap = "200";

	if (!(X == "" || Y == ""))
	{

	// inplamet the varible to need function

		PaintGrid(v2(std::stoi(X), std::stoi(Y)), win[w].cover.getPosition(), std::stoi(Gap), 1);
		//	delete_a_fucking_box(w);
	}
}


if (found("#saveAs#"))
{
	PrepeareCC("#saveAs#", CC); // command rest with out "" as CC
	GrabFromStart(CC,"#",fl);

	file_path_loaction = fl;
	if(fl != "")title = fl;

}

if (found("R~"))
{
	//space between time t1 and t2

}

if (found("@")) // @j#13
{
	PrepareCC("@", CC);
	GrabFromStart(CC, "#", Record);
	GrabFromStart(CC, "#", ID);
}

if (found("#showReactorToT1#"))
{

}

if (found("#printRecord#"))
{
	PrepareCC("#printRecord#", CC);
	GrabFromStart(CC,"#",Record);
}

if found("#cleanArea#")
{

}
//

if (found("#selectRun#"))
{

}

if (found("#CLEAN#"))
{

}
