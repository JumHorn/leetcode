
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size)
{
	int res = 0, coeff[] = {1, -1};
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			int smallest = coeff[i] * arr1[0] + coeff[j] * arr2[0] + 0;
			for (int k = 1; k < arr1Size; ++k)
			{
				int cur = coeff[i] * arr1[k] + coeff[j] * arr2[k] + k;
				res = max(res, cur - smallest);
				smallest = min(smallest, cur);
			}
		}
	}
	return res;
}
