#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int shortestSubarray(int *A, int ASize, int K)
{
	int res = INT_MAX, prefixsum[ASize + 1];
	int N = ASize + 1, deque[N], front = 0, rear = 0;
	prefixsum[0] = 0;
	for (int i = 0; i < ASize; ++i)
		prefixsum[i + 1] = prefixsum[i] + A[i];
	deque[rear] = 0;
	rear = (rear + N - 1) % N; //push back
	for (int i = 1; i <= ASize; ++i)
	{
		while (front != rear && prefixsum[i] - K >= prefixsum[deque[front]])
		{
			res = min(res, i - deque[front]);
			front = (front + N - 1) % N; //pop front
		}
		while (front != rear && prefixsum[deque[(rear + 1) % N]] >= prefixsum[i])
			rear = (rear + 1) % N; //pop back
		deque[rear] = i;
		rear = (rear + N - 1) % N; //push back
	}
	return res == INT_MAX ? -1 : res;
}