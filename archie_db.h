#ifndef ARCHIE_DB_H
#define ARCHIE_DB_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
class archie_db
{
	std::vector<std::vector<const char*>> v;
public:
	void init_db(const std::vector<std::vector<const char*>>& vv);	
};
#endif
