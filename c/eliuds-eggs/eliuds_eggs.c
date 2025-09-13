#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int layout)
{
	unsigned int eggs;

	eggs = 0;
	while (layout)
	{
		if (layout & 1)
			eggs += 1;
		layout >>= 1;
	}
	return (eggs);
}
