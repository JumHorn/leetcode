#include <map>
#include <vector>
using namespace std;

class TopVotedCandidate
{
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times)
	{
		vector<int> v(persons.size() + 1);
		int vote = 0;
		for (int i = 0; i < (int)times.size(); i++)
		{
			++v[persons[i]];
			if (v[persons[i]] >= vote)
			{
				vote = v[persons[i]];
				m[times[i]] = persons[i];
			}
		}
	}

	int q(int t)
	{
		auto iter = m.upper_bound(t);
		if (iter == m.end())
			return (--m.end())->second;
		--iter;
		return iter->second;
	}

private:
	map<int, int> m;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
