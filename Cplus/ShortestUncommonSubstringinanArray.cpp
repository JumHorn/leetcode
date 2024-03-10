#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> shortestSubstrings(vector<string> &arr)
	{
		vector<string> res;
		int M = arr.size();
		for (int k = 0; k < M; ++k)
		{
			string &str = arr[k];
			int N = str.size();
			string s;
			for (int len = 1; len <= N && s.empty(); ++len)
			{
				for (int i = 0, j = len; j <= N; ++i, ++j)
				{
					string sub = str.substr(i, len);
					bool flag = true;
					for (int t = 0; t < M; ++t)
					{
						if (k == t)
							continue;
						string &w = arr[t];
						if (w.find(sub) != string::npos)
						{
							flag = false;
							break;
						}
					}
					if (flag && (s.empty() || sub < s))
						s = sub;
				}
			}
			res.push_back(s);
		}
		return res;
	}
};