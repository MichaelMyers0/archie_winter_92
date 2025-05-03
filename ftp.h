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
#if 0	
	ftp(const ftp& fpt_s) = delete;
	ftp& operator=(const ftp& ftp_s) = delete;
#endif	
public:
	ftp();
	ftp(const char* path_start);
	void build();
	~ftp() = default;
};
#endif
