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

ftp::ftp()
{
	list_of_files = std::make_shared<std::list<entry>>();
	if (!list_of_files)
	{
		fprintf(stderr, "ERROR: fpt::ftp() failed to create a list\n");
		exit(4);
	}
}

ftp::ftp(const char* path_start) : ftp()
{
	size_t len;
	len = strlen(path_start);
	if (!path_start || len >= length)
	{
		fprintf(stderr, "ERROR: Provided path is too long\n");
		exit(5);
	}
	strcpy(start, path_start);
	*(start + len) = 0;
}

void ftp::build()
{
	struct dirent* ent;
	entry e;
	open_dir(dirp, start);
	while ((ent = readdir(dirp)))
	{
		if (0 == strcmp(ent->d_name, ".") || 0 == strcmp(ent->d_name, ".."))
			continue;
		if (ent->d_type == DT_REG)
		{	
			auto len = strlen(ent->d_name);
			strcpy(e.f_name, ent->d_name);
			*(e.f_name + len) = 0;
			list_of_files->push_back(e);
		}
	}
	close_dir(dirp);
}

void ftp::get_files(std::vector<const char*>& vec)
{
	auto iter2 = list_of_files->cbegin();
	while (iter2 != list_of_files->cend())
	{
		vec.push_back(iter2->f_name);	
		iter2++;
	}
}
