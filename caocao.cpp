#include <assert.h>
#include "mymap.hpp"
#include "caocao.hpp"

bool caocao::try_move(int dir, mymap *m)
{
	switch (dir)
	{
		case 1:
			if (pos_y + 2 >= MAP_H)
				return false;
			if (m->map_block[pos_x][pos_y + 2])
				return false;
			if (m->map_block[pos_x + 1][pos_y + 2])
				return false;
			pos_y += 1;
			break;
		case 2:
			if (pos_y == 0)
				return false;
			if (m->map_block[pos_x][pos_y - 1])
				return false;
			if (m->map_block[pos_x + 1][pos_y - 1])
				return false;
			pos_y -= 1;			
			break;
		case 3:
			if (pos_x == 0)
				return false;
			if (m->map_block[pos_x - 1][pos_y])
				return false;
			if (m->map_block[pos_x - 1][pos_y + 1])
				return false;
			pos_x -= 1;			
			break;
		case 4:
			if (pos_x + 2 >= MAP_W)
				return false;
			if (m->map_block[pos_x + 2][pos_y])
				return false;
			if (m->map_block[pos_x + 2][pos_y + 1])
				return false;
			pos_x += 1;						
			break;
		default:
			assert(0);
	}
	return true;
}
bool caocao::at_pos(int x, int y)
{
	return false;
}
int  caocao::get_num()
{
	return 100 + pos_x * 10 + pos_y;
}
