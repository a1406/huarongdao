#ifndef BASE_H
#define BASE_H
class mymap;
class base
{
public:
	int type;  //1: 曹操4格子  2:关羽横格子  3:张飞竖格子  4: 小兵一格子  0:空格
	int pos_x;
	int pos_y;
	void do_move(int dir);	
	virtual bool try_move(int dir, mymap *m) = 0;  //能否移动, 1:上 2:下 3:左 4:右
	virtual bool at_pos(int x, int y) = 0;  //是否占据了对应的格子
	virtual int  get_num() = 0;
};

#endif /* BASE_H */
