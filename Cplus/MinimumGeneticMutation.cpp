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
		string gene = "ACGT";
		unordered_set<string> geneBank(bank.begin(), bank.end());
		queue<string> q;
		int res = 0;
		if (geneBank.find(end) == geneBank.end())
			return -1;
		q.push(start);
		geneBank.erase(start);
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				auto mutation = q.front();
				q.pop();
				for (auto &m : mutation)
				{
					char old = m;
					for (auto g : gene)
					{
						m = g;
						if (mutation == end)
							return res;
						if (geneBank.find(mutation) != geneBank.end())
						{
							geneBank.erase(mutation);
							q.push(mutation);
						}
					}
					m = old;
				}
			}
		}
		return -1;
	}
};