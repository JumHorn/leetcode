#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int distinctEchoSubstrings(string text)
	{
		unordered_set<string_view> s;
		const char *p = text.c_str();
		for (int i = 2; i <= (int)text.size(); i += 2)
		{
			for (int j = 0; j <= (int)text.size() - i; j++)
			{
				const string_view a(p + j, i / 2);
				const string_view b(p + j + i / 2, i / 2);
				if (a == b)
					s.insert(a);
			}
		}
		return s.size();
	}
};
