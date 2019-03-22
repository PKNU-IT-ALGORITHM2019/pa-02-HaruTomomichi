#include "main.h"

void main() {
	input();

	find_distance(0,0,0);

	print();

	getchar();
	getchar();
}

void find_distance(int level,int k, double distance) {
	if (level > 0) {
		distance += cal_distance(data[level].x, data[level].y, data[level-1].x, data[level-1].y);
	}

	if (distance > final_distance) {
		level--;
		return;
	}
	
	if (level == N-1) {
		result[level] = data[k].index;
		distance += cal_distance(data[result[0]].x, data[result[0]].y, data[k].x, data[k].y);
		analysis(distance);
		level--;
		return;
	}

	for (int i = k; i < N; i++) {
		swap(k, i);
		result[k] = data[i].index;
		find_distance(++level,k+1,distance);
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
	if (distance < final_distance) {
		final_distance = distance;
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