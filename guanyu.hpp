#ifndef GUANYU_H
#define GUANYU_H
#include "base.hpp"

class guanyu: public base
{
public:
	virtual bool try_move(int dir, mymap *m);
	virtual bool at_pos(int x, int y);
	virtual int  get_num();	
};

#endif /* CAOCAO_H */
