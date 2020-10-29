#include <algorithm>
#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isRectangleCover(vector<vector<int>> &rectangles)
	{
		int bottom = INT_MAX, left = INT_MAX, top = INT_MIN, right = INT_MIN, area = 0;
		set<pair<int, int>> s;
		for (auto &rect : rectangles)
		{
			bottom = min(rect[0], bottom);
			left = min(rect[1], left);
			top = max(rect[2], top);
			right = max(rect[3], right);
			area += (rect[2] - rect[0]) * (rect[3] - rect[1]);

			if (!s.insert({rect[0], rect[1]}).second)
				s.erase({rect[0], rect[1]});
			if (!s.insert({rect[0], rect[3]}).second)
				s.erase({rect[0], rect[3]});
			if (!s.insert({rect[2], rect[1]}).second)
				s.erase({rect[2], rect[1]});
			if (!s.insert({rect[2], rect[3]}).second)
				s.erase({rect[2], rect[3]});
		}
		if (s.size() != 4 ||
			s.find({bottom, left}) == s.end() ||
			s.find({bottom, right}) == s.end() ||
			s.find({top, left}) == s.end() ||
			s.find({top, right}) == s.end())
			return false;
		return area == (top - bottom) * (right - left);
	}
};