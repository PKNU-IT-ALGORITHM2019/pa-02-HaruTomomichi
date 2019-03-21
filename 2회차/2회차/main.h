#pragma once
#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996)

#define MAX 100

int x[MAX], y[MAX], n = 0;
double result = 0;

void input();

double cal_distance(int x1, int y1, int x2, int y2);

void start();

double find_distance(int cur, double distance);



