#ifndef BASE_H
#define BASE_H

class base
{
public:
	int type;  //1: 曹操4格子  2:关羽横格子  3:张飞竖格子  4: 小兵一格子  0:空格
	int pos_x;
	int pos_y;
	
	virtual bool can_move(int dir) = 0;  //能否移动, 1:上 2:下 3:左 4:右
	virtual bool at_pos(int x, int y) = 0;  //是否占据了对应的格子
};

#endif /* BASE_H */
