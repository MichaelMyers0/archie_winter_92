#ifndef FTP_H
#define FTP_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <list>
#include <string.h>
#include <sys/types.h>
#include <string>
class ftp
{
	enum {length = 255};
	DIR* dirp;
	typedef char string_t[length];
	std::list<std::string> list_of_files;
	char start[length];
	void open_dir(DIR*& dirp, const char* path);
	void read_dir();
	void close_dir(DIR* dirp);
public:
	ftp() = default;
	ftp(const char* path_start);
	void build();
	~ftp() = default;
};
#endif
