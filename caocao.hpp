#ifndef CAOCAO_H
#define CAOCAO_H
#include "base.hpp"

class caocao: public base
{
public:
	virtual bool can_move(int dir);
	virtual bool at_pos(int x, int y);
	
};

#endif /* CAOCAO_H */
