#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int distinctEchoSubstrings(string text)
	{
		unordered_set<string> s;
		for (int i = 2; i < (int)text.size() / 2; i += 2)
		{
			for (int j = 0; j <= (int)text.size() - i; j++)
			{
				if (text.substr(j, i / 2) == text.substr(j + i / 2, i / 2))
					s.insert(text.substr(j, i));
			}
		}
		return s.size();
	}
};
