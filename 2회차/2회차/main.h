#pragma once
#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996)

#define MAX 100

int N = 0;
double final_distance = 2000000.0, temp_distance = 0;

typedef struct LOCATION {
	int index;
	int x;
	int y;
}LOCATION;

LOCATION data[MAX];
int result[MAX];

void print();

void analysis(double distance);

void input();

double cal_distance(int cur, int i);

void swap(int cur, int i);

void find_distance(int cur, double distance);



