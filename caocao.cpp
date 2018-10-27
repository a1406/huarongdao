#include <assert.h>
#include "caocao.hpp"

bool caocao::try_move(int dir, mymap *m)
{
	switch (dir)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			assert(0);
	}
	return false;
}
bool caocao::at_pos(int x, int y)
{
	return false;
}
int  caocao::get_num()
{
	return 100 + pos_x * 10 + pos_y;
}
