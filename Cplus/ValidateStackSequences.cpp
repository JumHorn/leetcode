#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
	{
		stack<int> s;
		int poppedIdx = 0;
		for (auto n : pushed)
		{
			s.push(n);
			while (!s.empty() && s.top() == popped[poppedIdx])
			{
				s.pop();
				++poppedIdx;
			}
		}
		return s.empty();
	}
};