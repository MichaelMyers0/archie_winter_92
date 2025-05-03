#include "dbgc.h"

dbgc::dbgc()
{
	list_of_ftp_servers = std::make_shared<std::vector<ftp>>();
	if (!list_of_ftp_servers)
	{
		fprintf(stderr, "ERROR: Failed to create a list_of_ftp_servers\n");
		exit(1);
	}
	db = std::make_shared<std::vector<std::vector<const char*>>>();
	if (!db)
	{
		fprintf(stderr, "ERROR: Failed to create a db\n");
		exit(2);
	}
}

void dbgc::init_servers(const std::initializer_list<const char*>& servers)
{
        auto iter = servers.begin();
        while (iter != servers.end())
        {
		ftp f(*iter);
		f.build();
                list_of_ftp_servers->push_back(f);
                iter++;
        }
}

void dbgc::gather_files(const std::initializer_list<const char*>& ftp_server_names)
{
	init_servers(ftp_server_names);
	std::vector<const char*> v;
	auto iter = list_of_ftp_servers->begin();
	while (iter != list_of_ftp_servers->end())
	{
		iter->get_files(v);
		db->push_back(v);
		iter++;
		v.clear();
	}
}

std::vector<std::vector<const char*>> dbgc::dump_db()
{
	return *db;
}
