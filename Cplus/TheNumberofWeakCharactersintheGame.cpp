#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfWeakCharacters(vector<vector<int>> &properties)
	{
		sort(properties.begin(), properties.end());
		int N = properties.size(), res = 0;
		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 0, j = 0; i < N;)
		{
			while (i < N && properties[i][0] == properties[j][0])
				++i;
			int k = i - 1;
			while (!q.empty() && q.top() < properties[k][1])
			{
				q.pop();
				++res;
			}
			for (; j < i; ++j)
				q.push(properties[j][1]);
		}
		return res;
	}
};