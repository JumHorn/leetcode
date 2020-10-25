#include <stdbool.h>

bool canReach(int* arr, int arrSize, int start)
{
	if (start < 0 || start >= arrSize || arr[start] < 0)
		return false;
	if (arr[start] == 0)
		return true;
	arr[start] = -arr[start];
	return canReach(arr, arrSize, start + arr[start]) || canReach(arr, arrSize, start - arr[start]);
}
