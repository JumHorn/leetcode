

int mctFromLeafValues(int* arr, int arrSize)
{
	int res = 0, top = -1;
	for (int i = 0; i < arrSize; i++)
	{
		if (top == -1)
			arr[++top] = arr[i];
		else if (top == 0)
		{
			if (arr[i] >= arr[top])
			{
				res += arr[i] * arr[top];
				arr[top] = arr[i];
			}
			else
				arr[++top] = arr[i];
		}
		else
		{
			if (arr[i] < arr[top])
				arr[++top] = arr[i];
			else
			{
				if (arr[i] >= arr[top - 1])
				{
					res += arr[top] * arr[top - 1];
					--top;
					--i;
				}
				else
				{
					res += arr[top] * arr[i];
					arr[top] = arr[i];
				}
			}
		}
	}
	for (int i = top; i > 0; i--)
		res += arr[i] * arr[i - 1];
	return res;
}

