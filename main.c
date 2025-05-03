#include "ftp.h"
#include "dbgc.c"
int main()
{
	ftp ftp_server(".");
	ftp_server.build();
	dbgc c;
	std::initializer_list<const char*> list{"."};
	c.gather_files(list);
	exit(0);
}
