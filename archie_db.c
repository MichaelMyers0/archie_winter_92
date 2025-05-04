#include "archie_db.h"

void archie_db::init_db(const std::vector<std::vector<const char*>>& vv)
{
	v = vv;
}

void archie_db::find_file(const char* fname)
{
	auto iter = v.cbegin();
	auto flag = 0;
	while (iter != v.cend() && !flag)
	{
		auto vec_iter = iter->cbegin();
		while (vec_iter != iter->cend())
		{
			if (0 == strcmp(*vec_iter, fname))
			{
				printf("We found a file\n");
				flag = 1;
				break;
			}
			vec_iter++;
		}
		iter++;
	}
}
