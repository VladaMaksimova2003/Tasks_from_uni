#include "fraction_division.h"
int Nod(int a, int b) {
	int c;
	while (b != 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}
void Sokr(int& a, int& b) {
	int temp = Nod(a, b);
	a /= temp;
	b /= temp;
}
void Mult(int &a, int &b, int &c, int &d) {
	a *= d;
	b *= c;
}
float Div(int a, int b, int c, int d, int k, int m) {
	Mult(a, b, c, d);
	Sokr(a, b);
	Mult(a, b, k, m);
	Sokr(a, b);
	float temp = float(a) / float(b);
	return temp;
}