#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string bestHand(vector<int> &ranks, vector<char> &suits)
	{
		if (flush(suits))
			return "Flush";
		if (kind(ranks, 3))
			return "Three of a Kind";
		if (kind(ranks, 2))
			return "Pair";
		return "High Card";
	}

	bool flush(vector<char> &suits)
	{
		char a = suits[0];
		for (auto c : suits)
		{
			if (c != a)
				return false;
		}
		return true;
	}

	bool kind(vector<int> &ranks, int same)
	{
		sort(ranks.begin(), ranks.end());
		int N = ranks.size();
		for (int i = 0; i <= N - same; ++i)
		{
			int j = 0;
			for (; j < same; ++j)
			{
				if (ranks[i] != ranks[j + i])
					break;
			}
			if (j == same)
				return true;
		}
		return false;
	}
};