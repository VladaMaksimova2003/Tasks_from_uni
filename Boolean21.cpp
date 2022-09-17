#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Boolean21");
	int n, number;
	bool r = false;
	pt >> number;
	n = number % 10;
	number /= 10;
	while (number != 0) {
		if (n > number % 10) {
			n = number % 10;
			number /= 10;

		}
	}
	if (number == 0)r = true;

	pt << r;
}