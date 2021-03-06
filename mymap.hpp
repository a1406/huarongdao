#ifndef MYMAP_H__
#define MYMAP_H__

#include <vector>
#include <map>
#include <set>
#include "caocao.hpp"
#include "xiaobing.hpp"
#include "guanyu.hpp"
#include "zhangfei.hpp"

using namespace std;

#define MAP_W 4
#define MAP_H 5
#define PLAYER_NUM 10

#define OUT_POS_X 1
#define OUT_POS_Y 0

class mymap
{
public:
	void init_map(int player[PLAYER_NUM]);  //三位数字,第一个表示类型,第二个表示x, 第三个表示y
	bool run();

	void print_result();
	
	int map_block[MAP_W][MAP_H];
	base *m_player[PLAYER_NUM];

//	vector<int>  m_result;      //三位数字,第一个表示方向,,第二个表示x, 第三个表示y
	vector<vector<int> > m_vec;
	set<vector<int> > m_map;
	set<vector<int> > m_failed;

	vector<vector<int> > win_vec;
	map<vector<int>, int> win_map;	

private:
	bool run_step();  //返回true表示有路走, false表示没路走
	void refresh_block();
	void set_block(int x, int y);
	bool is_win();
	void reset_player();	
	void add_to_win_map();
	void print_block();	
};

#endif /* MAP_H */
