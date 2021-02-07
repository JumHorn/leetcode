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

			if (word1[i] > word2[j])
			{
				res.push_back(word1[i]);
				++i;
			}
			else if (word1[i] < word2[j])
			{
				res.push_back(word2[j]);
				++j;
			}
			else
			{
				if (word1.substr(i) + word2.substr(j) > word2.substr(j) + word1.substr(i))
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
		}
		return res;
	}
};