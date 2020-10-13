#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> advantageCount(vector<int> &A, vector<int> &B)
	{
		int N = A.size();
		sort(A.begin(), A.end());
		vector<int> res(N);
		vector<pair<int, int>> v; //{B val,B index}
		for (int i = 0; i < N; ++i)
			v.push_back({B[i], i});
		sort(v.begin(), v.end());
		for (int i = N - 1, j = N - 1, k = 0; i >= 0; --i)
		{
			if (A[j] > v[i].first)
				res[v[i].second] = A[j--];
			else
				res[v[i].second] = A[k++];
		}
		return res;
	}
};