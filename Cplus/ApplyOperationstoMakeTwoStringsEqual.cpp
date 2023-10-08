#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(string s1, string s2, int x)
	{
		int N = s1.size();
		vector<int> p; // pos array
		x *= 2;		   // double for division
		for (int i = 0; i < N; ++i)
		{
			if (s1[i] != s2[i])
				p.push_back(i * 2);
		}
		if (p.size() % 2 == 1)
			return -1;
		if (p.size() == 0)
			return 0;
		int f0 = 0, f1 = x / 2;
		for (int i = 1; i < p.size(); ++i)
		{
			int f2 = min(f1 + x / 2, f0 + p[i] - p[i - 1]);
			f0 = f1;
			f1 = f2;
		}
		return f1 / 2;
	}
};