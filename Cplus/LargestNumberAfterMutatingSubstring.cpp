#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string maximumNumber(string num, vector<int> &change)
	{
		int N = num.size();
		for (int i = 0; i < N; ++i)
		{
			int val = num[i] - '0';
			if (change[val] > val)
			{
				for (int j = i; j < N && change[num[j] - '0'] >= num[j] - '0'; ++j)
				{
					num[j] = change[num[j] - '0'] + '0';
				}
				break;
			}
		}
		return num;
	}
};