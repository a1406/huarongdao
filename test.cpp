#include <stdio.h>
#include "mymap.hpp"

int main(int argc, char *argv[])
{
	mymap m, m2;
	int player[PLAYER_NUM] = {404, 403, 402, 401, 113, 210, 211, 212, 331, 333}; //层层设防
	int player2[PLAYER_NUM] = {402, 404, 433, 434, 113, 300, 310, 320, 331, 212}; //兵临曹营
	
	m.init_map(player);
	m2.init_map(player2);

	if (argc == 1)
	{
		bool ret = m.run();
		printf("m run, ret = %s\n", ret ? "true" : "false");
	}
		//	m2.run();

	m.print_result();
	//	m2.print_result();
	return 0;
}
