#include <assert.h>
#include "base.hpp"

void base::do_move(int dir)
{
	switch (dir)
	{
		case 1:
			pos_y += 1;
			break;
		case 2:
			pos_y -= 1;
			break;
		case 3:
			pos_x -= 1;
			break;
		case 4:
			pos_x += 1;
			break;
		default:
			assert(0);
	}
}

void base::rollback_move(int dir)
{
	switch (dir)
	{
		case 1:
			pos_y -= 1;
			break;
		case 2:
			pos_y += 1;
			break;
		case 3:
			pos_x += 1;
			break;
		case 4:
			pos_x -= 1;
			break;
		default:
			assert(0);
	}
}
