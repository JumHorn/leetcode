#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int kSimilarity(string A, string B)
	{
		queue<pair<string, int>> q; //{current swapped string A,already matched index}
		unordered_set<string> seen;
		q.push({A, 0});
		int res = -1, N = A.length();
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				string str = q.front().first;
				int start = q.front().second;
				q.pop();
				while (start < N && str[start] == B[start])
					++start;
				if (start == N)
					return res;
				for (int i = start + 1; i < N; ++i)
				{
					if (B[start] == str[i] && B[i] != str[i])
					{
						swap(str[start], str[i]);
						if (seen.find(str) == seen.end())
						{
							seen.insert(str);
							q.push({str, start + 1});
						}
						swap(str[start], str[i]);
					}
				}
			}
		}
		return -1;
	}
};