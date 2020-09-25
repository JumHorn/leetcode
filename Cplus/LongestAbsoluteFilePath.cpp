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
		s.push(0); //dummy node
		int index = 0, res = 0, len = input.size();
		while (index < len)
		{
			int tab = 0;
			while (input[index] == '\t')
			{
				++tab;
				++index;
			}
			while (tab + 1 < (int)s.size())
				s.pop();
			int count = 0;
			bool file = false;
			while (index < len && input[index] != '\n')
			{
				if (input[index] == '.')
					file = true;
				++count;
				++index;
			}
			++index;
			if (file)
				res = max(res, s.top() + count);
			else
				s.push(count + s.top() + 1);
		}
		return res;
	}
};