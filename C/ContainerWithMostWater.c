
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int *height, int heightSize)
{
	int res = 0;
	for (int i = 0, j = heightSize - 1; i < j;)
	{
		res = max(res, (j - i) * min(height[i], height[j]));
		height[i] < height[j] ? ++i : --j;
	}
	return res;
}