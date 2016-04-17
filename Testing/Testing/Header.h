#include <iostream>


int   setTestCases() {
	int test[64][3],j;
	int fillc[3] = { 1,2,3 },
		fillb[3] = { 2,4,5 },
		filla[3] = { 5,6,7 };


	for (int i = 0; i < 64; i++) {
		test[i][2] = fillc[j];
		test[i][0] = filla[j];
		j++;
		if (j > 3) {
			j = 0;
		}
	}
	j = 0;
	for (int i = 0; i < 64; i++) {
		for (int k = i; k < i + 4; k++) {
			test[k][1] = fillb[j];

		}

		j++;
		if (j > 3) {
			j = 0;
		}
		j = 0;
	}
	return test;
}
