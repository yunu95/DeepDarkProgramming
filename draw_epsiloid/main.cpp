#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

double getRandouble(const double min, const double max) {
	double temp = ((double)rand()) / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}
bool isinsideEllipsoid(const double x, const double y, const double x_e = 1.0, const double y_e = 0.5, const double a_e = 1.0, const double b_e = 0.5) {
	return b_e*b_e*(x - x_e)*(x - x_e) + a_e*a_e*(y - y_e)* (y - y_e) <= a_e*a_e*b_e*b_e;
}
int main() {
	FILE* of = fopen("ellipsoid.csv", "w");
	srand((unsigned int)time(NULL));

	register double x, y;
	for (int i = 0; i < 10000; i++) {
		x = getRandouble(0, 3.0);
		y = getRandouble(0, 1.0);
		if (isinsideEllipsoid(x, y))
			fprintf(of, "%f, %f\n", x, y);
	}

	return 0;
}