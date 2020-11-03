#include <vector>
using namespace std;

class Solution
{
public:
	int bestRotation(vector<int> &A)
	{
		int n = A.size(), res = 0;
		vector<int> score(n);		//score for every k
		for (int i = 0; i < n; ++i) //for A[i] rotate k to lose point
			--score[(i - A[i] + 1 + n) % n];
		for (int i = 1; i < n; ++i)
			score[i] += score[i - 1] + 1;
		//return distance(score.begin(), max_element(score.begin(), score.end())); //distance much slower
		return max_element(score.begin(), score.end()) - score.begin();
	}
};