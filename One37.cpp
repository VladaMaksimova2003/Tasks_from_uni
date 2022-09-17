#include "pt4.h"
using namespace std;
#define N 10000
#define S 100000
void Solve()
{
    Task("One37");
    int number = 0, even = 1, odd = 1, n = 0;
    pt >> number;
    if (number >= N && number < S) {
        while (number != 0) {
            n = number % 10;
            if (n % 2 == 0) {
                even *= n;
            }
            else odd *= n;
            number = number / 10;
        }
        pt << float(even) / float(odd);
    }
}
