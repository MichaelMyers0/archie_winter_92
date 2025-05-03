#include "ftp.h"
#include "dbgc.c"
#include "archie_db.h"
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "ERROR: Provide ftp server name\n");
		exit(1);
	}
	std::vector<const char*> vec;
	ftp ftp_server(*(argv + 1));
	ftp_server.build();
	ftp_server.get_files(vec);
	dbgc c;
	std::initializer_list<const char*> list{*(argv + 1)};
	c.gather_files(list);
	std::vector<std::vector<const char*>> v = c.dump_db();
	archie_db a_db;
	a_db.init_db(v);
	exit(0);
}
