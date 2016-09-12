#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

double getRandouble(const double min, const double max) {
	double temp = ((double)rand()) / (double)RAND_MAX;
	temp = min + (max - min)*temp;
	return temp;
}
bool isinsideCircle(const double x, const double y, const double x_c = 0.5, const double y_c = 0.5, const double r_c = 0.5) {
	return (x - x_c)*(x - x_c) + (y - y_c)* (y - y_c) <= r_c*r_c;
}
bool isinsideRectangle(const double x, const double y, const double x_r = 1.5, const double y_r = 0.5, const double w_r = 3.0, const double h_r = 0.5) {
	return (x<x_r+0.5*w_r && x>x_r - 0.5*w_r)&& (y<y_r + 0.5*h_r && y>y_r - 0.5*h_r);
}
int main() {
	FILE* of = fopen("dumbbel.csv", "w");
	srand((unsigned int)time(NULL));

	register double x, y;
	for (int i = 0; i < 10000; i++) {
		x = getRandouble(0, 3.0);
		y = getRandouble(0, 1.0);
		if (isinsideCircle(x, y)|| isinsideCircle(x, y,2.5)||isinsideRectangle(x,y))
			fprintf(of, "%f, %f\n", x, y);
	}

	return 0;
}