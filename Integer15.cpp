#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Integer15");
    int number = 0, n1, n2, n3, result = 0;
    pt >> number;
    n1 = number % 10;
    n2 = (number / 10) % 10;
    n3 = (number / 100) % 10;
    result = n2 * 100 + n3 * 10 + n1;
    pt << result;

}
