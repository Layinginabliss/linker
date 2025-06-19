#pragma once

#ifndef CMCT
#define CMCT

#define found(what) command.find(what) != std::string::npos

#define PrepeareCC(what,named) std::string named = command; \
named.erase(named.begin(),named.begin() + std::string(what).size()) 

#endif