#include <unistd.h>
#include <string.h>

int rand()
{
	static int la = -1;

	la++;
	if (la == 0)
		return 8;
	if (la == 2)
		return 7;
	if (la == 1)
		return 8;
	if (la == 3)
		return 9;
	if (la == 5)
		return 74;
	if (la == 4)
		return 23;
	return la * la % 30000;
}
