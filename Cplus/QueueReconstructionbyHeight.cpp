#include <algorithm>
#include <vector>
using namespace std;

/*
Pick out tallest group of people and sort them in a subarray (S).
Since there's no other groups of people taller than them,
therefore each guy's index will be just as same as his k value.
For 2nd tallest group (and the rest), insert each one of them into (S) by k value.
So on and so forth.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]
*/

class Solution
{
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
	{
		sort(people.begin(), people.end(), *this);
		for (int i = 0; i < (int)people.size(); ++i)
		{
			if (people[i][1] < i)
			{
				for (int j = i; people[j][1] < j; --j)
					swap(people[j], people[j - 1]);
			}
		}
		return people;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] > rhs[0];
		return lhs[1] < rhs[1];
	}
};