#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool halvesAreAlike(string s)
	{
		unordered_set<char> uset = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		int N = s.length();
		int count = 0;
		for (int i = 0; i < N / 2; ++i)
		{
			if (uset.find(s[i]) != uset.end())
				++count;
		}
		for (int i = N / 2; i < N; ++i)
		{
			if (uset.find(s[i]) != uset.end())
				--count;
		}
		return count == 0;
	}
};