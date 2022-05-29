#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestWordCount(vector<string> &messages, vector<string> &senders)
	{
		int N = senders.size();
		unordered_map<string, int> m;
		string res;
		for (int i = 0; i < N; ++i)
		{
			int count = wordCount(messages[i]);
			m[senders[i]] += count;
			if (m[res] < m[senders[i]])
				res = senders[i];
			else if (m[res] == m[senders[i]])
			{
				if (res < senders[i])
					res = senders[i];
			}
		}
		return res;
	}

	int wordCount(string &msg)
	{
		int res = 0;
		stringstream ss(msg);
		string word;
		while (ss >> word)
			++res;
		return res;
	}
};