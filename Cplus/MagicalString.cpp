#include <queue>
using namespace std;

class Solution
{
public:
	int magicalString(int n)
	{
		if (n == 0)
			return 0;
		if (n <= 3)
			return 1;
		n -= 3;
		queue<int> q; //number of count
		q.push(2);
		int elements = 2, res = 1;
		while (--n >= 0)
		{
			int count = q.front();
			q.pop();
			elements = 3 - elements;
			if (count == 2)
			{
				q.push(elements);
				if (elements == 1)
					++res;
				--n;
			}
			q.push(elements);
			if (elements == 1 && n >= 0)
				++res;
		}
		return res;
	}
};