#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	int lengthLongestPath(string input)
	{
		stack<int> s;
		int index = 0, res = 0, len = input.size();
		while (index < len)
		{
			int t = 0;
			while (input[index] == '\t')
			{
				++t;
				++index;
			}
			while (!s.empty() && t < (int)s.size())
				s.pop();
			int count = 0;
			bool flag = false;
			while (index < len && input[index] != '\n')
			{
				if (input[index] == '.')
					flag = true;
				++count;
				++index;
			}
			++index;
			if (flag)
				res = max(res, (s.empty() ? 0 : s.top()) + count);
			else
				s.push(count + (s.empty() ? 0 : s.top()) + 1);
		}
		return res;
	}
};