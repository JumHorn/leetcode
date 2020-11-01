#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> stringMatching(vector<string> &words)
	{
		vector<string> res;
		int N = words.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i != j && words[j].find(words[i]) != string::npos)
				{
					res.push_back(words[i]);
					break;
				}
			}
		}
		return res;
	}
};