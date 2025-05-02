#include "ftp.h"

void ftp::open_dir(DIR*& dirp, const char* path)
{
	errno = 0;
	dirp = opendir(path);
	if (!dirp)
	{
		perror("void fpt::open_dir(DIR*& dirp, const char* path)\n");
		exit(1);
	}
}

void ftp::read_dir()
{
}

void ftp::close_dir(DIR* dirp)
{
	int res;
	errno = 0;
	res = closedir(dirp);
	if (res == -1)
	{
		perror("void fpt::close_dir()\n");
		exit(3);
	}
}

ftp::ftp(const char* path_start)
{
	size_t len;
	len = strlen(path_start);
	if (!path_start || len >= length)
	{
		fprintf(stderr, "ERROR: Provided path is too long\n");
		exit(1);
	}
	strcpy(start, path_start);
	*(start + len) = 0;
}

void ftp::build()
{
	open_dir(dirp, start);
	close_dir(dirp);
}
