
//using stack to store the index of the height
//keep the stack decreasing
int trap(int *height, int heightSize)
{
	if (heightSize == 0)
		return 0;
	int stack[heightSize], top = -1, res = 0; //simulate stack using array
	for (int i = 0; i < heightSize; i++)
	{
		if (top == -1 || height[i] < height[stack[top]]) //stack is empty
			stack[++top] = i;
		else
		{
			while (top != -1 && height[i] >= height[stack[top]])
			{
				res -= height[stack[top]];
				--top;
			}
			if (top == -1)
				res += height[stack[0]] * (i - stack[0]);
			stack[++top] = i;
		}
	}
	while (--top >= 0)
		res += height[stack[top + 1]] * (stack[top + 1] - stack[top] - 1);
	return res;
}