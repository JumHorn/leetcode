#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numRabbits(vector<int> &answers)
	{
		sort(answers.begin(), answers.end());
		int res = 0, colorcount = 0, N = answers.size();
		for (int i = 0; i < N;)
		{
			colorcount = answers[i] + 1;
			int j = i + 1;
			while (j < N && j - i < colorcount && answers[i] == answers[j])
				++j;
			i = j;
			res += colorcount;
		}
		return res;
	}
};