#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shiftingLetters(string s, vector<vector<int>> &shifts)
	{
		int N = s.size();
		vector<int> count(N + 1);
		for (auto &v : shifts)
		{
			int l = v[0], r = v[1], d = v[2];
			if (d == 0)
				d += 25;
			count[l] += d;
			count[r + 1] -= d;
		}
		string res;
		for (int i = 0; i < N; ++i)
		{
			if (i > 0)
				count[i] += count[i - 1];
			res.push_back('a' + (s[i] - 'a' + count[i]) % 26);
		}
		return res;
	}
};