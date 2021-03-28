#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int numDifferentIntegers(string word)
	{
		unordered_set<string> s;
		int N = word.size();
		for (int i = 0; i < N; ++i)
		{
			if (word[i] >= '0' && word[i] <= '9')
			{
				int j = i;
				while (j < N && word[j] >= '0' && word[j] <= '9')
					++j;
				while (i < j && word[i] == '0')
					++i;
				if (i == j)
					s.insert("0");
				else
					s.insert(word.substr(i, j - i));

				i = j;
			}
		}
		return s.size();
	}
};