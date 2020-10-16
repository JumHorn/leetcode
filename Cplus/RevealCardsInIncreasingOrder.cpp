#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> deckRevealedIncreasing(vector<int> &deck)
	{
		int N = deck.size();
		vector<int> res(N);
		queue<int> q;
		sort(deck.begin(), deck.end());
		for (int i = 0; i < N; ++i)
			q.push(i);
		for (auto n : deck)
		{
			res[q.front()] = n;
			q.pop();
			q.push(q.front());
			q.pop();
		}
		return res;
	}
};