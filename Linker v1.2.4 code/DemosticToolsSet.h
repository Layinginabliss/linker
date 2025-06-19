#pragma once

#ifndef  DOMECSTIC_TOOLSET
#define DOMESTIC_TOOLSET

#define loop(time,i) for(int i = 0;i <time;i++)
#define loop2(time1,x,time2,y) loop(time1,x) loop(time2,y)

// vector out rage proff . grab from start of string to a new sting // new change not tested
#define GrabFromStart(in,till,name) std::string name = "";\
							if (in.find(till) != std::string::npos) \
							{ auto found = in.find(till); name = in.substr(0,found) ;in.erase(in.begin(),in.begin() + found + 1);}


#endif // ! DOMECSTIC_TOOLSET


