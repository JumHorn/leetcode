#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> canSeePersonsCount(vector<int> &heights)
	{
		int N = heights.size();
		vector<int> res(N, 1);
		stack<int> s;
		s.push(heights[N - 1]);
		for (int i = N - 2; i >= 0; --i)
		{
			int count = 0;
			while (!s.empty() && heights[i] > s.top())
			{
				s.pop();
				++count;
			}
			res[i] += count;
			if (s.empty())
				--res[i];
			s.push(heights[i]);
		}
		res[N - 1] = 0;
		if (N >= 2)
			res[N - 2] = 1;
		return res;
	}
};