#ifndef ZHANGFEI_H
#define ZHANGFEI_H
#include "base.hpp"

class zhangfei: public base
{
public:
	virtual bool try_move(int dir, mymap *m);
	virtual bool at_pos(int x, int y);
	virtual int  get_num();		
};

#endif /* ZHANGFEI_H */
