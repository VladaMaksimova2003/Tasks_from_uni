#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Boolean21");
	int  number, last;
	bool flag = true;
	pt >> number;
	last = number % 10;
	number /= 10;
	while (number != 0) {
		if (last <= (number % 10)) {
			flag = false;
		}

		last = number % 10;
		number /= 10;
	}


	pt << flag;

}