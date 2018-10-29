#include <assert.h>
#include <string.h>
#include "mymap.hpp"

void mymap::reset_player()
{
	vector<int> t;
	t = m_vec.back();
	
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		int type = t[i] / 100;
		int x = t[i] % 100 / 10;
		int y = t[i] % 10;
		assert(x < MAP_W);
		assert(y < MAP_H);

		assert(type == m_player[i]->type);
		
		// delete m_player[i];
		// switch (type)
		// {
		// 	case 1:
		// 		m_player[i] = new caocao();
		// 		break;
		// 	case 2:
		// 		m_player[i] = new guanyu();				
		// 		break;
		// 	case 3:
		// 		m_player[i] = new zhangfei();								
		// 		break;
		// 	case 4:
		// 		m_player[i] = new xiaobing();												
		// 		break;
		// 	default:
		// 		assert(0);
		// }
		// m_player[i]->type = type;		
		m_player[i]->pos_x = x;
		m_player[i]->pos_y = y;
	}
	refresh_block();
}

void mymap::init_map(int player[PLAYER_NUM])
{
	vector<int> t;
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
		m_player[i]->type = type;		
		m_player[i]->pos_x = x;
		m_player[i]->pos_y = y;
		t.push_back(player[i]);
	}
	refresh_block();
	m_vec.push_back(t);
	m_map.insert(t);
}

void mymap::set_block(int x, int y)
{
	assert(x < MAP_W);
	assert(y < MAP_H);
	assert(map_block[x][y] == 0);	
	map_block[x][y] = 1;
}

void mymap::refresh_block()
{
	memset(&map_block, 0, sizeof(map_block));
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		int x = m_player[i]->pos_x;
		int y = m_player[i]->pos_y;
		set_block(x, y);
		switch (m_player[i]->type)
		{
			case 1:
				set_block(x + 1, y);
				set_block(x, y + 1);
				set_block(x + 1, y + 1);		
				break;
			case 2:
				set_block(x + 1, y);
				break;
			case 3:
				set_block(x, y + 1);
				break;
			case 4:
				break;
			default:
				assert(0);
		}
	}
}

bool mymap::is_win()
{
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		if (m_player[i]->type != 1)
			continue;
		if (m_player[i]->pos_x == 1 && m_player[i]->pos_y == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	assert(0);
}

bool mymap::run_step()
{
	for (int i = 0; i < PLAYER_NUM; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (!m_player[i]->try_move(j, this))
				continue;
			m_player[i]->do_move(j);			
			vector<int> t;
			for (int ii = 0; ii < PLAYER_NUM; ++ii)
			{
				t.push_back(m_player[ii]->get_num());
			}
			if (m_map.find(t) != m_map.end())
			{
				m_player[i]->rollback_move(j);
				continue;
			}
			if (m_failed.find(t) != m_failed.end())
			{
				m_player[i]->rollback_move(j);				
				continue;
			}


			
			refresh_block();
			m_vec.push_back(t);
//			int n = m_map.size();
			m_map.insert(t);
			return true;
		}
	}
	return false;
}

void mymap::add_to_win_map()
{
	assert(win_map.empty());
	win_vec = m_vec;
	int i = 0;
	for (vector<vector<int> >::iterator ite = win_vec.begin(); ite != win_vec.end(); ++ite)
	{
		vector<int> t = *ite;
		win_map[t] = ++i;
	}
}

bool mymap::run()
{
	for (;;)
	{
		bool ret = run_step();
		if (ret == false)
		{
//			return false;
//			print_result();
//			printf("=================end=================\n\n\n");
			
			assert(m_vec.size() == m_map.size());

			int left = m_vec.size();
			
//			if (m_vec.empty())
			if (left <= 1)
				return false;
			vector<int> t;
			t = m_vec.back();
			m_vec.pop_back();
			m_failed.insert(t);
			m_map.erase(t);

			reset_player();
		}
		else
		{
			if (is_win())
			{
				add_to_win_map();
				return true;
			}
		}
	}
	assert(0);
}

void mymap::print_block()
{
	for (int i = MAP_H - 1; i >= 0; --i)
	{
		for (int j = 0; j < MAP_W; ++j)
		{
			int bk = map_block[j][i];
			printf("%d ", bk);
		}
		printf("\n");
	}
}

void mymap::print_result()
{
	static const char *char_map[] = {
		"  ",
		"曹",
		"操",
		"关",
		"羽",
		"张",
		"飞",
		"兵",

		"0 ",
		"1 ",
		"2 ",
		"3 ",
		"4 ",
		"5 ",
		"6 ",
		"7 ",
		"8 ",
		"9 ",				
	};
	
	int i = 0;
	for (vector<vector<int> >::iterator ite = m_vec.begin(); ite != m_vec.end(); ++ite)
	{
		++i;
		vector<int> t1 = *ite;
		int        result[MAP_W][MAP_H] = {0};

		int j = 0;
		for (vector<int>::iterator ite2 = t1.begin(); ite2 != t1.end(); ++ite2)
		{
			++j;
			int t2 = *ite2;
			int type = t2 / 100;
			int x	 = t2 % 100 / 10;
			int y	 = t2 % 10;
			assert(x < MAP_W);
			assert(y < MAP_H);			
			
			switch (type)
			{
				case 1:
				{
					result[x][y] = 1;
					result[x+1][y] = 2;
					result[x][y+1] = 1;
					result[x+1][y+1] = 2;
					assert(x + 1 < MAP_W);
					assert(y + 1 < MAP_H);

					// result[x+1][y] = j + 7;
					// result[x][y+1] = j + 7;
					// result[x+1][y+1] = j + 7;
				}
				break;
				case 2:
				{
					result[x][y]   = 3;
					result[x+1][y] = 4;
					assert(x + 1 < MAP_W);

//					result[x+1][y] = j + 7;					
				}
				break;
				case 3:
				{
					result[x][y]   = 6;
					result[x][y+1] = 5;
					assert(y + 1 < MAP_H);

//					result[x][y+1] = j + 7;					
				}
				break;
				case 4:
				{
					result[x][y] = 7;

//					result[x][y] = j + 7;					
				}
				break;
				default:
					assert(0);
			}
		}
		for (int i = MAP_H - 1; i >= 0; --i)
		{
			for (int j = 0; j < MAP_W; ++j)
			{
				int id = result[j][i];
//				assert(id < 8 && id >= 0);
				printf("%s ", char_map[id]);
			}
			printf("\n");
		}
		printf("=================step %d=================\n", i);
	}

}
