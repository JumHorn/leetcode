#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPoints(string rings)
	{
		int N = rings.length(), res = 0;
		vector<int> rod(10);
		for (int i = 0; i < N; i += 2)
		{
			if (rings[i] == 'R')
				rod[rings[i + 1] - '0'] |= (1 << 0);
			else if (rings[i] == 'G')
				rod[rings[i + 1] - '0'] |= (1 << 1);
			else //'B'
				rod[rings[i + 1] - '0'] |= (1 << 2);
		}
		for (auto n : rod)
		{
			if (n == 0b111)
				++res;
		}
		return res;
	}
};