#ifndef XIAOBING_H
#define XIAOBING_H
#include "base.hpp"

class xiaobing: public base
{
public:
	virtual bool can_move(int dir);
	virtual bool at_pos(int x, int y);
	
};

#endif /* CAOCAO_H */
