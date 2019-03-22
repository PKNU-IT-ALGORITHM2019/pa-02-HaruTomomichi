#include "main.h"

void main() {
	input();

	find_distance(0, 0);

	print();

	getchar();
	getchar();
}

int find_temp(int answer) {
	for (int i = 0; i < N; i++) {
		if (answer == data[i].index) {
			return i;
		}
	}
	return -1;
}

void find_distance(int k, double distance) {

	if (k > 0 && k!= N) {
		distance += cal_distance(data[k].x, data[k].y, data[k - 1].x, data[k - 1].y);
	}

	if (distance > final_distance) {
		return;
	}

	if (k == N) {
		distance += cal_distance(data[0].x, data[0].y, data[k - 1].x, data[k - 1].y);
		for (int i = 0; i < N; i++) {
			printf("%d ", temp[i]);
		}
		printf("%f\n", distance);
		analysis(distance);
		return;
	}

	for (int i = k; i < N; i++) {
		
		if (k < i && k != 0) {
			distance -= cal_distance(data[find_temp(temp[k])].x, data[find_temp(temp[k])].y, data[find_temp(temp[k-1])].x, data[find_temp(temp[k-1])].y);
		}
		temp[k] = data[i].index;
		swap(k, i);
		if (k < i && k != 0) {
			distance += cal_distance(data[k].x, data[k].y, data[k - 1].x, data[k - 1].y);
		}
		find_distance(k+1, distance);
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
	FILE *fp = fopen("input1.txt", "r");

	fscanf(fp, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf(fp, "%d %d", &data[i].x, &data[i].y);
		data[i].index = i;
	}

	fclose(fp);
}

void analysis(double distance) {
	if (distance < final_distance) {
		for (int i = 0; i < N; i++) {
			result[i] = temp[i];
		}

		final_distance = distance;
	}
}

void swap(int k, int i) {
	LOCATION temp;

	temp = data[k];
	data[k] = data[i];
	data[i] = temp;
}
double cal_distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}