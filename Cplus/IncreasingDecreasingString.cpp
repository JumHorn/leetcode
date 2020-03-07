#include <string>
using namespace std;

class Solution
{
public:
	string sortString(string s)
	{
		int arr[26] = {0};
		for (auto c : s)
			++arr[c - 'a'];
		int n = s.length();
		string res(n, ' ');
		for (int i = 0; i < n;)
		{
			for (int j = 0; j < 26; j++)
			{
				if (arr[j] > 0)
				{
					res[i++] = j + 'a';
					--arr[j];
				}
			}
			for (int j = 25; j >= 0; j--)
			{
				if (arr[j] > 0)
				{
					res[i++] = j + 'a';
					--arr[j];
				}
			}
		}
		return res;
	}
};
