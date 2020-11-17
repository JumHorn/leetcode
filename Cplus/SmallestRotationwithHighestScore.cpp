#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int bestRotation(vector<int> &A)
	{
		int N = A.size(), res = 0;
		vector<int> score(N);		//score for every k
		for (int i = 0; i < N; ++i) //for A[i] rotate k to lose point
			--score[(i - A[i] + 1 + N) % N];
		for (int i = 1; i < N; ++i)
			score[i] += score[i - 1] + 1;
		//return distance(score.begin(), max_element(score.begin(), score.end())); //distance much slower
		return max_element(score.begin(), score.end()) - score.begin();
	}
};