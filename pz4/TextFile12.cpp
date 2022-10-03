#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("TextFile12");

    int N, K, num = 1, res = 0;
    pt >> N >> K;
    for (int i = 0; i < K; i++)
        num *= 10;
    res = num;
    ofstream fout("d.dat");
    if (!fout.is_open()) {
        pt << "do not open";
    }
    else {
        do {
            fout << res << "\n";
            if ((res / num) % 10 == 0) {

                for (int i = 0; i < 9 && res < N; ++i) {
                    res += 1;
                    fout << res << "\n";
                }
                res -= 9;
            }

            res += num;

        } while (res < N);


    }
    fout.close();
}