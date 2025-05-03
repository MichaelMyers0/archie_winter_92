#ifndef FTP_H
#define FTP_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <list>
#include <string.h>
#include <sys/types.h>
#include <memory>
#include <vector>
class ftp
{
	enum {length = 255};
	DIR* dirp;
	typedef char name_t[length];
	struct entry
	{
		name_t f_name;
	};
	std::shared_ptr<std::list<entry>> list_of_files;
	char start[length];
	void open_dir(DIR*& dirp, const char* path=".");
	void close_dir(DIR* dirp);
public:
	ftp();
	ftp(const char* path_start);
	void build();
	void get_files(std::vector<const char*>& vec);
	~ftp() = default;
};
#endif
