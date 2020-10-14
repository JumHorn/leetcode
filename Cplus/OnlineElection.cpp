#include <map>
#include <vector>
using namespace std;

class TopVotedCandidate
{
public:
	TopVotedCandidate(vector<int> &persons, vector<int> &times)
	{
		int vote = 0, N = persons.size();
		vector<int> count(N + 1);
		for (int i = 0; i < N; ++i)
		{
			if (++count[persons[i]] >= vote)
			{
				vote = count[persons[i]];
				m[times[i]] = persons[i];
			}
		}
	}

	int q(int t)
	{
		return (--m.upper_bound(t))->second;
	}

private:
	map<int, int> m; //{time,top person}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */