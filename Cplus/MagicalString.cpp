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
		queue<int> q;
		q.push(2);
		int top = 2, res = 1;
		while (--n >= 0)
		{
			int tmp = q.front();
			q.pop();
			top = 3 - top;
			if (tmp == 2)
			{
				q.push(top);
				if (top == 1)
					res++;
				--n;
			}
			q.push(top);
			if (top == 1 && n >= 0)
				res++;
		}
		return res;
	}
};

int main()
{
	Solution sol;
	sol.magicalString(10);
	return 0;
}