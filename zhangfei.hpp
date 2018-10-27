#ifndef ZHANGFEI_H
#define ZHANGFEI_H
#include "base.hpp"

class zhangfei: public base
{
public:
	virtual bool can_move(int dir);
	virtual bool at_pos(int x, int y);
	
};

#endif /* ZHANGFEI_H */
