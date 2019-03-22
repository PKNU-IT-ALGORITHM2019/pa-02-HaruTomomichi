#include "main.h"

void main() {
	input();

	find_distance(0, 0);

	getchar();
	getchar();
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
		fscanf(fp, "%d %d", &data[i].x,&data[i].y);
		data[i].index = i+1;
	}

	fclose(fp);
}

double cal_distance(int x1,int y1,int x2,int y2) {
	return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

void analysis(double distance) {
	if (distance < final_distance) {
		final_distance = distance;
	}
}

void swap(int cur, int i) {
	int temp = 0;

	temp = data[cur].x;
	data[cur].x = data[i].x;
	data[i].x = temp;

	temp = data[cur].y;
	data[cur].y = data[i].y;
	data[i].y = temp;
}

void find_distance(int cur, double distance) {

	if (distance > final_distance) {
		return;
	}
	
	if (cur == N-1) {
		result[cur] = data[cur].index;
		distance += cal_distance(data[result[0]].x, data[result[0]].y, data[cur].x, data[cur].y);
		analysis(distance);
		return;
	}

	for (int i = cur; i < N; i++) {
		result[cur] = data[cur].index;

		swap(cur, i);
		distance += cal_distance(data[cur].x,data[cur].y,data[cur+1].x,data[cur+1].y);
		find_distance(cur + 1,distance);
		swap(cur, i);
	}
}