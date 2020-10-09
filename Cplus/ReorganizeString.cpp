#include <algorithm>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
	string reorganizeString(string S)
	{
		vector<int> hash(26);
		for (auto c : S)
			++hash[c - 'a'];
		int N = S.length();
		int mostletter = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (hash[mostletter] < hash[i])
				mostletter = i;
		}
		if (hash[mostletter] > (N + 1) / 2)
			return "";
		string res(N, '\0');
		int index = 0;
		while (--hash[mostletter] >= 0)
		{
			res[index] = 'a' + mostletter;
			index += 2;
		}
		for (int i = 0; i < 26; ++i)
		{
			while (--hash[i] >= 0)
			{
				if (index >= N)
					index = 1;
				res[index] = 'a' + i;
				index += 2;
			}
		}
		return res;
	}
};