#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> divideString(string s, int k, char fill)
	{
		vector<string> res;
		int N = s.length();
		for (int i = 0; i < N; i += k)
			res.push_back(s.substr(i, k));
		while (res.back().size() < k)
			res.back().push_back(fill);
		return res;
	}
};