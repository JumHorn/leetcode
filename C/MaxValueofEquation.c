#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findMaxValueOfEquation(int **points, int pointsSize, int *pointsColSize, int k)
{
	int res = INT_MIN, N = pointsSize;
	//front stores data and rear not
	int size = N, deque[size], front = 0, rear = 0;
	deque[rear] = 0;
	rear = (rear - 1 + size) % size; //push back
	for (int i = 1; i < N; ++i)
	{
		while (front != rear && points[i][0] - points[deque[front]][0] > k)
			front = (front - 1 + size) % size; //pop front
		if (front != rear)
			res = max(res, points[deque[front]][1] + points[i][1] + points[i][0] - points[deque[front]][0]);
		while (front != rear && points[i][1] - points[i][0] >= points[deque[(rear + 1) % size]][1] - points[deque[(rear + 1) % size]][0])
			rear = (rear + 1) % size; //pop back
		deque[rear] = i;
		rear = (rear - 1 + size) % size; //push back
	}
	return res;
}