#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth)
	{
		vector<string> res;
		int N = words.size();
		for (int i = 0, k, l; i < N; i += k)
		{
			for (k = l = 0; i + k < N && l + (int)words[i + k].size() <= maxWidth - k; ++k)
				l += words[i + k].size();
			string row = words[i];
			for (int j = 0; j < k - 1; ++j)
			{
				if (i + k >= N) //last row
					row += " ";
				else
					row += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
				row += words[i + j + 1];
			}
			row += string(maxWidth - (int)row.size(), ' ');
			res.push_back(row);
		}
		return res;
	}
};