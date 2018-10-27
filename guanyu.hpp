#ifndef GUANYU_H
#define GUANYU_H
#include "base.hpp"

class guanyu: public base
{
public:
	virtual bool can_move(int dir);
	virtual bool at_pos(int x, int y);
	
};

#endif /* CAOCAO_H */
