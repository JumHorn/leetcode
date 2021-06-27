#include <string>
using namespace std;

class Solution
{
public:
	string removeOccurrences(string s, string part)
	{
		int N = part.size();
		while (true)
		{
			auto iter = s.find(part);
			if (iter == string::npos)
				break;
			string next_s = s.substr(0, iter) + s.substr(iter + N);
			s = next_s;
		}
		return s;
	}
};