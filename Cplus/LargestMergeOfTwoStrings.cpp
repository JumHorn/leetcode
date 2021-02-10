#include <string>
using namespace std;

class Solution
{
public:
	string largestMerge(string word1, string word2)
	{
		int N1 = word1.length(), N2 = word2.length();
		string res;
		for (int i = 0, j = 0; i < N1 || j < N2;)
		{
			if (i == N1)
			{
				res += word2.substr(j);
				break;
			}
			if (j == N2)
			{
				res += word1.substr(i);
				break;
			}

			int a = word1.compare(i, string::npos, word2, j);
			if (a >= 0)
			{
				res.push_back(word1[i]);
				++i;
			}
			else
			{
				res.push_back(word2[j]);
				++j;
			}
		}
		return res;
	}
};