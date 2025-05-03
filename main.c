#include "ftp.h"
#include "dbgc.c"
int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "ERROR: Provide ftp server name\n");
		exit(1);
	}
	ftp ftp_server(".");
	ftp_server.build();
	dbgc c;
	std::initializer_list<const char*> list{*(argv + 1)};
	c.gather_files(list);
	exit(0);
}
