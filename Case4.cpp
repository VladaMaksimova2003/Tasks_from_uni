#include "pt4.h"
using namespace std;

void Solve()
{
	Task("Case4");
	int n = 0;
	pt >> n;
	switch (n) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		n = 31;
		pt << n;
		break;
	case 2:
		n = 28;
		pt << n;
		break;
	case 4: case 6: case 9: case 11:
		n = 30;
		pt << n;
		break;


	}
}