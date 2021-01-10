#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
	{
		nth_element(points.begin(), points.begin() + K, points.end(), [](vector<int> &a, vector<int> &b) {
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
		});
		return vector<vector<int>>(points.begin(), points.begin() + K);
	}
};