#pragma once
#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996)

#define MAX 100

int N = 0;
float final_distance = 2000000.0;

typedef struct LOCATION {
	int index;
	int x;
	int y;
}LOCATION;

LOCATION data[MAX] = { 0 };
int result[MAX] = { 0 }, temp[MAX] = { 0 };

void find_distance(int k, double distance);

void print();

void input();

void analysis(double distance);

void swap(int cur, int i);

float cal_distance(int x1, int y1, int x2, int y2);



