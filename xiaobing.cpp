#include <assert.h>
#include "mymap.hpp"
#include "xiaobing.hpp"

bool xiaobing::try_move(int dir, mymap *m)
{
	switch (dir)
	{
		case 1:
			if (pos_y + 1 >= MAP_H)
				return false;
			if (m->map_block[pos_x][pos_y + 1])
				return false;
			break;
		case 2:
			if (pos_y == 0)
				return false;
			if (m->map_block[pos_x][pos_y - 1])
				return false;
			break;
		case 3:
			if (pos_x == 0)
				return false;
			if (m->map_block[pos_x - 1][pos_y])
				return false;
			break;
		case 4:
			if (pos_x + 1 >= MAP_W)
				return false;
			if (m->map_block[pos_x + 1][pos_y])
				return false;
			break;
		default:
			assert(0);
	}
	return true;
}
bool xiaobing::at_pos(int x, int y)
{
	return false;
}
int  xiaobing::get_num()
{
	return 400 + pos_x * 10 + pos_y;
}
