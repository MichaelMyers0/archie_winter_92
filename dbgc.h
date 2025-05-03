#ifndef DBGC_H
#define DBGC_H
#include "ftp.h"
#include <initializer_list>
#include <vector>
#include <string>
class dbgc
{
	std::shared_ptr<std::vector<ftp>> list_of_ftp_servers;
	std::shared_ptr<std::vector<std::vector<const char*>>> db;
	void init_servers(const std::initializer_list<const char*>& servers);
public:	
	dbgc();
	void gather_files(const std::initializer_list<const char*>& list);
	~dbgc() = default;
};
#endif
