#include "main.h"

void main() {
	input();

	find_distance(0,0);

	print();

	getchar();
	getchar();
}

void find_distance(int k) {
	if (k == N-1) {
		
		return;
	}

	for (int i = k; i < N; i++) {
		swap(k, i);
		find_distance(k+=1);
		swap(k, i);
	}
}

void print() {
	for (int i = 0; i < N; i++) {
		printf("%d  ", result[i]);
	}
	printf("\nÃÖ¼Ò°ª : %lf", final_distance);
}

void input() {
	FILE *fp = fopen("data.txt", "r");

	fscanf(fp, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf(fp, "%d %d", &data[i].x, &data[i].y);
		data[i].index = i;
	}

	fclose(fp);
}

void analysis(double distance) {
	for (int i = 0; i < N; i++) {

	}
	
}

void swap(int k, int i) {
	int temp = 0;

	temp = data[k].x;
	data[k].x = data[i].x;
	data[i].x = temp;

	temp = data[k].y;
	data[k].y = data[i].y;
	data[i].y = temp;
}

double cal_distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}