
#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	int min_ch = 1;
	cin >> a;
	while (a != 0) {

		if (a % 2 == 0 && a < min_ch)
			min_ch = a;

		if (min_ch == 1 || a % 2 != 0) {
			cout << "NO";
		}
		else cout << min_ch;
		cin >> a;
	}

	return 0;
}