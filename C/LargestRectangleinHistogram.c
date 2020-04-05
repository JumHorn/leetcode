/*
current rectangle left extend and right extend most to get highest area
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int largestRectangleArea(int *heights, int heightsSize)
{
	int stack[heightsSize + 1], top = 0, res = 0;
	stack[0] = -1;
	for (int i = 0; i < heightsSize; i++)
	{
		while (top != 0 && heights[i] <= heights[stack[top]])
		{
			res = max(res, heights[stack[top]] * (i - stack[top - 1] - 1));
			--top;
		}
		stack[++top] = i;
	}
	int right = stack[top] + 1;
	while (top != 0)
	{
		res = max(res, heights[stack[top]] * (right - stack[top - 1] - 1));
		--top;
	}
	return res;
}