#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
	{
		auto f = [=](pair<int, int> &lhs, pair<int, int> &rhs) {
			return long(lhs.second - lhs.first) * (rhs.second + 1) * rhs.second < long(rhs.second - rhs.first) * (lhs.second + 1) * lhs.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> q(f);
		int N = classes.size();
		double res = 0.0;
		for (auto &c : classes)
		{
			q.push({c[0], c[1]});
			res += c[0] * 1.0 / c[1];
		}
		for (int i = 0; i < extraStudents; ++i)
		{
			auto top = q.top();
			q.pop();
			res += (top.first + 1) * 1.0 / (top.second + 1) - top.first * 1.0 / top.second;
			q.push({top.first + 1, top.second + 1});
		}
		return res / N;
	}
};