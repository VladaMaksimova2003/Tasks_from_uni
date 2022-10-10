#include <iostream>
#define PI 3.14
float RingS(float R1, float R2) {
	if (R1 > R2) {
		return PI * (R1 * R1 - R2 * R2);
	}
	return 0;
}
int main() {
	float R1, R2;
	for (int i = 0; i < 3; ++i) {
		std::cin >> R1 >> R2;
		std::cout << RingS(R1, R2) << std::endl;
	}
	return 0;
}