#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long interchangeableRectangles(vector<vector<int>> &rectangles)
	{
		int N = rectangles.size();
		long long res = 0;
		map<pair<int, int>, int> m; //{{w,h},count}
		for (int i = 0; i < N; ++i)
		{
			int w = rectangles[i][0], h = rectangles[i][1];
			int g = gcd(w, h);
			w /= g;
			h /= g;
			res += m[{w, h}]++;
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};