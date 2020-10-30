#include <string>
using namespace std;

class Solution
{
public:
	bool isLongPressedName(string name, string typed)
	{
		int i = 0, M = name.length(), N = typed.length();
		for (int j = 0; j < N; ++j)
		{
			if (i < M && name[i] == typed[j])
				++i;
			else if (j == 0 || typed[j] != typed[j - 1])
				return false;
		}
		return i == M;
	}
};