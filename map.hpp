#ifndef MAP_H__
#define MAP_H__

#include "caocao.hpp"
#include "xiaobing.hpp"
#include "guanyu.hpp"
#include "zhangfei.hpp"

#define MAP_W 4
#define MAP_H 5
#define PLAYER_NUM 10

#define OUT_POS_X 1
#define OUT_POS_Y 0

class map
{
public:
	void init_map(int player[PLAYER_NUM]);  //三位数字,第一个表示类型,第二个表示x, 第三个表示y
	int map_block[MAP_W][MAP_H];
	base *m_player[PLAYER_NUM];
};

#endif /* MAP_H */
