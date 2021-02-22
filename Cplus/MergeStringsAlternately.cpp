#include <string>
using namespace std;

class Solution
{
public:
	string mergeAlternately(string word1, string word2)
	{
		int N1 = word1.length(), N2 = word2.length();
		string res;
		bool turn = false;
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
			turn = !turn;
			if (turn)
				res += word1[i++];
			else
				res += word2[j++];
		}
		return res;
	}
};