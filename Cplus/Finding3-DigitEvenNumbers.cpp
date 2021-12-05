#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findEvenNumbers(vector<int> &digits)
	{
		set<int> s;
		int N = digits.size();
		for (int i = 0; i < N; ++i)
		{
			if (digits[i] == 0)
				continue;
			for (int j = 0; j < N; ++j)
			{
				if (j == i)
					continue;
				for (int k = 0; k < N; ++k)
				{
					if (i == k || j == k || digits[k] % 2 == 1)
						continue;
					int a = digits[i], b = digits[j], c = digits[k];
					s.insert(a * 100 + b * 10 + c);
				}
			}
		}
		return vector<int>(s.begin(), s.end());
	}
};