#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int mostFrequentPrime(vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size();
		unordered_map<int, int> m; //{prime,count}
		vector<vector<int>> D = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
		int res = -1, f = 0;
		auto check = [&](int i, int j)
		{
			// eight direction
			for (auto &d : D)
			{
				int val = mat[i][j];
				if (val > 10 && isPrimer(val))
				{
					int count = ++m[val];
					if (count > f)
					{
						res = val;
						f = count;
					}
					else if (count == f && res < val)
						res = val;
				}

				int dx = d[0], dy = d[1];
				for (int k = 1; k <= 6; ++k)
				{
					int x = i + dx * k, y = j + dy * k;
					if (x < 0 || x >= M || y < 0 || y >= N)
						break;
					val = val * 10 + mat[x][y];
					if (val > 10 && isPrimer(val))
					{
						int count = ++m[val];
						if (count > f)
						{
							res = val;
							f = count;
						}
						else if (count == f && res < val)
							res = val;
					}
				}
			}
		};

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				check(i, j);
			}
		}
		return res;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (long long i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};