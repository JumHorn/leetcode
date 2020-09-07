#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int distinctEchoSubstrings(string text)
	{
		int N = text.size();
		unordered_set<string> s;
		for (int i = 2; i <= N; i += 2)
		{
			for (int j = 0; j <= N - i; ++j)
			{
				if (text.compare(j, i / 2, text, j + i / 2, i / 2) == 0)
					s.insert(text.substr(j, i / 2));
			}
		}
		return s.size();
	}
};