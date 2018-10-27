#ifndef MYMAP_H__
#define MYMAP_H__

#include <vector>
#include <map>
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
	int map_block[MAP_W][MAP_H];
	base *m_player[PLAYER_NUM];

	vector<int>  m_result;      //三位数字,第一个表示方向,,第二个表示x, 第三个表示y
	vector<vector<int> > m_vec;
	map<vector<int>, int> m_map;
};

#endif /* MAP_H */
