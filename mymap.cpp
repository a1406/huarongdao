#include <assert.h>
#include "mymap.hpp"

void mymap::init_map(int player[PLAYER_NUM])
{
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		int type = player[i] / 100;
		int x = player[i] % 100 / 10;
		int y = player[i] % 10;
		assert(x < MAP_W);
		assert(y < MAP_H);		
		switch (type)
		{
			case 1:
				m_player[i] = new caocao();
				break;
			case 2:
				m_player[i] = new guanyu();				
				break;
			case 3:
				m_player[i] = new zhangfei();								
				break;
			case 4:
				m_player[i] = new xiaobing();												
				break;
			default:
				assert(0);
		}
		m_player[i]->pos_x = x;
		m_player[i]->pos_y = y;
	}
	m_vec.push_back(player);
	m_map[player] = 0;
}


