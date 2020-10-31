#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findOcurrences(string text, string first, string second)
	{
		vector<string> res;
		string pattern = first + " " + second + " ";
		int N = pattern.length();
		for (auto pos = text.find(pattern, 0); pos != string::npos; pos = text.find(pattern, pos + N))
		{
			if (pos == 0 || text[pos - 1] == ' ')
			{
				int i = text.find(" ", pos + N);
				res.push_back(text.substr(pos + N, i - pos - N));
			}
		}
		return res;
	}
};