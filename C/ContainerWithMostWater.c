
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int* height, int heightSize)
{
	int i = 0, j = heightSize - 1;
	int res = 0;
	while (i < j)
	{
		res = max(res, (j - i) * min(height[i], height[j]));
		height[i] < height[j] ? ++i : --j;
	}
	return res;
}
