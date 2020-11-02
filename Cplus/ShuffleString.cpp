#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string restoreString(string s, vector<int> &indices)
	{
		int N = indices.size();
		for (int i = 0; i < N; ++i)
		{
			while (indices[i] != i)
			{
				swap(s[i], s[indices[i]]);
				swap(indices[i], indices[indices[i]]);
			}
		}
		return s;
	}
};