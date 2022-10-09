#include <cstdio>
using namespace std;

char news[51][51];

int main() {
	int r, c, zr, zc;
	scanf("%d%d%d%d", &r, &c, &zr, &zc);
	for (int i = 0; i < r; i++) scanf("%s", news[i]);

	// Solution 1 - simulation
	for (int i = 0; i < r; i++) {
		for (int ii = 0; ii < zr; ii++) {
			for (int j = 0; j < c; j++) {
				for (int jj = 0; jj < zc; jj++) {
					printf("%c", news[i][j]);
				}
			}
			printf("\n");
		}
	}

	//Solution 2 - a bit of math
	/*
	for (int i = 0; i < r*zr; i++) {
		for (int j = 0; j < c*zc; j++)
			printf("%c", news[i/zr][j/zc]);
		printf("\n");
	}
	*/

	return 0;
}