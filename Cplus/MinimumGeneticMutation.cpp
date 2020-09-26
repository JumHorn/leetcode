#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minMutation(string start, string end, vector<string> &bank)
	{
		unordered_set<string> seen, geneBank(bank.begin(), bank.end());
		queue<string> q;
		int res = 0;
		if (geneBank.find(end) == geneBank.end())
			return -1;
		q.push(start);
		seen.insert(start);
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				auto genestr = q.front();
				q.pop();
				char gene[] = "ACGT";
				for (int i = 0; i < (int)genestr.length(); ++i)
				{
					char old = genestr[i];
					for (int j = 0; j < 4; ++j)
					{
						genestr[i] = gene[j];
						if (genestr == end)
							return res;
						if (seen.find(genestr) == seen.end() && geneBank.find(genestr) != geneBank.end())
						{
							seen.insert(genestr);
							q.push(genestr);
						}
					}
					genestr[i] = old;
				}
			}
		}
		return -1;
	}
};