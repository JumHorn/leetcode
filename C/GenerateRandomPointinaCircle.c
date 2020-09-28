#include <math.h>
#include <stdlib.h>

typedef struct
{
	double pi;
	double x;
	double y;
	double radius;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center)
{
	Solution* res = (Solution*)malloc(sizeof(Solution));
	res->radius = radius;
	res->x = x_center;
	res->y = y_center;
	res->pi = 3.141592653;
	return res;
}

double* solutionRandPoint(Solution* obj, int* retSize)
{
	*retSize = 2;
	double* res = (double*)malloc(sizeof(double) * (*retSize));
	double angle = rand() % 10000 / 10000.0;
	double r = sqrt(rand() % 10000 / 10000.0);
	res[0] = obj->radius * r * cos(angle * obj->pi * 2) + obj->x;
	res[1] = obj->radius * r * sin(angle * obj->pi * 2) + obj->y;
	return res;
}

void solutionFree(Solution* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(radius, x_center, y_center);
 * double* param_1 = solutionRandPoint(obj, retSize);
 
 * solutionFree(obj);
*/
