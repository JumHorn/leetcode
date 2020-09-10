#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution() : cache(50, vector<int>(10, -1))
	{
	}

	double getProbability(vector<int> &balls)
	{
		int sum = accumulate(balls.begin(), balls.end(), 0);
		int N = balls.size();
		vector<int> aBox(N), bBox(N);
		double all = permutation(balls, sum);
		double possible = dfs(balls, 0, sum, aBox, bBox);
		return possible * 1.0 / all;
	}

	double dfs(vector<int> &ball, int index, int sum, vector<int> &aBox, vector<int> &bBox)
	{
		int suma = accumulate(aBox.begin(), aBox.end(), 0);
		int sumb = accumulate(bBox.begin(), bBox.end(), 0);
		// invalid split because either `a` or `b` takes up more than half of the balls.
		if (suma * 2 > sum || sumb * 2 > sum)
			return 0;
		int N = ball.size();
		if (index >= N)
		{
			int colorABox = 0, colorBBox = 0;
			for (int i = 0; i < N; ++i)
			{
				colorABox += aBox[i] > 0 ? 1 : 0;
				colorBBox += bBox[i] > 0 ? 1 : 0;
			}
			// invalid split because `a` and `b` don't have the same number of distinct colors.
			if (colorABox != colorBBox)
				return 0;
			return permutation(aBox, sum / 2) * permutation(bBox, sum / 2);
		}

		// try different splits at the `i`-th element, i.e. a[i] + b[i] = A[i]
		double res = 0;
		for (int i = 0; i <= ball[index]; ++i)
		{
			int a = aBox[index], b = bBox[index];
			aBox[index] = i;
			bBox[index] = ball[index] - i;
			res += dfs(ball, index + 1, sum, aBox, bBox);
			aBox[index] = a;
			bBox[index] = b;
		}
		return res;
	}

	double permutation(vector<int> &arr, int sum)
	{
		double res = 1;
		for (int i = 0; i < (int)arr.size(); ++i)
		{
			res *= C(sum, arr[i]);
			sum -= arr[i];
		}
		return res;
	}

	int C(int n, int m) //combination C(n,m)=C(n-1,m)+C(n-1,m-1)
	{
		if (cache[n][m] != -1)
			return cache[n][m];
		if (n == m || m == 0)
			return 1;
		if (m == 1)
			return n;
		return cache[n][m] = C(n - 1, m) + C(n - 1, m - 1);
	}

private:
	vector<vector<int>> cache;
};