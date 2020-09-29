#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		stack<int> s;
		unordered_map<int, int> m; //{value,next greater}
		for (auto n : nums2)
		{
			while (!s.empty() && n > s.top())
			{
				m[s.top()] = n;
				s.pop();
			}
			s.push(n);
		}
		vector<int> res;
		for (auto n : nums1)
		{
			if (m.find(n) != m.end())
				res.push_back(m[n]);
			else
				res.push_back(-1);
		}
		return res;
	}
};