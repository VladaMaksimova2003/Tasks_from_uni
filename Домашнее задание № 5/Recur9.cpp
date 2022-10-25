#include <iostream>
using namespace std;
//Recur9.Описать рекурсивную функцию GCD(A, B) целого типа, находящую наибольший общий делитель
//(НОД, greatest common divisor) двух целых положительных чисел A и B, используя алгоритм Евклида :
//НОД(A, B) = НОД(B, A mod B), B ≠ 0;        НОД(A, 0) = A,
//где «mod» обозначает операцию взятия остатка от деления.С помощью этой функции найти 
//НОД(A, B), НОД(A, C), НОД(A, D), если даны числа A, B, C, D.
int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
int main() {
    setlocale(LC_ALL, "ru");
    int a, b, c, d, result;
    cout << "Введите  4 целых положительных числа" << endl;
    cin >> a >> b >> c >> d;
    cout << "НОД чисел: " << endl;
    result = gcd(a, b);
    cout << result << endl;
    result = gcd(a, c);
    cout << result << endl;
    result = gcd(a, d);
    cout << result << endl;

}