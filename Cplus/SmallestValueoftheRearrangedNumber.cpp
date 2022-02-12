#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	long long smallestNumber(long long num)
	{
		if (num == 0)
			return 0;
		if (num > 0)
		{
			string s = to_string(num);
			sort(s.begin(), s.end());
			int N = s.length(), i = 0;
			while (i < N && s[i] == '0')
				++i;
			char c = s[i];
			s.erase(i, 1);
			s.insert(s.begin(), c);
			return stoll(s);
		}
		string s = to_string(-num);
		sort(s.begin(), s.end(), greater<char>());
		return -stoll(s);
	}
};