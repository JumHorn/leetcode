#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDeletionSize(vector<string> &A)
	{
		int M = A.size(), N = A[0].length(), res = 0;
		vector<pair<int, int>> equal; //{index,previous equal index}
		for (int i = 0; i < M - 1; ++i)
			equal.push_back({i, i + 1});
		for (int j = 0; j < N && !equal.empty(); ++j)
		{
			bool flag = false;
			vector<pair<int, int>> nextequal;
			for (auto &index : equal)
			{
				if (A[index.second][j] < A[index.first][j])
				{
					flag = true;
					break;
				}
				if (A[index.first][j] == A[index.second][j])
					nextequal.push_back(index);
			}
			if (flag)
				++res;
			else
				equal.swap(nextequal);
		}
		return res;
	}
};