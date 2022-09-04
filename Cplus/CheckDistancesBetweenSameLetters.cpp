#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkDistances(string s, vector<int> &distance)
	{
		vector<int> pos(26, -1);
		int N = s.size();
		for (int i = 0; i < N; ++i)
		{
			int j = s[i] - 'a';
			if (pos[j] == -1)
				pos[j] = i;
			else
			{
				if (i - pos[j] - 1 != distance[j])
					return false;
			}
		}
		return true;
	}
};