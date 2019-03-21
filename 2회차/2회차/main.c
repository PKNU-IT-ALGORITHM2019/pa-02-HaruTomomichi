#include "main.h"

void main() {
	input();

	start();

	getchar();
	getchar();
}

void input() {
	FILE *fp = fopen("data.txt", "r");

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d", &x[i], &y[i]);
	}

	fclose(fp);
}

double cal_distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void start() {
	for (int i = 0; i < n; i++) {
		int cur = 0;


	}
}

double find_distance(, int cur, double distance, ) {
	if (result < distance) {
		return false; // 꽝일 경우에 코드이다. 수정이 필요
	}

	if (cur == 0 && result != 0) {
		printf("%d %d\n", x2, y2);
		return true; // 당첨일 경우에 코드이다. 수정이 필요
	}

	cur++;
	result += cal_distance(x1, y1, x2, y2);



	return (, cur, result, )
}