#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> splitIntoFibonacci(string S)
	{
		vector<int> res;
		if (!backTracking(S, 0, res))
			return {};
		return res;
	}

	bool backTracking(const string &S, int index, vector<int> &res)
	{
		int N = S.length(), size = res.size();
		long num = 0;
		if (index >= N)
			return size >= 3;
		for (int i = index; i < N; ++i)
		{
			if (S[index] == '0' && i != index)
				break;
			num = num * 10 + S[i] - '0';
			if (num > INT_MAX)
				break;
			if (size >= 2 && num != (long)res[size - 1] + res[size - 2])
				continue;
			res.push_back(num);
			if (backTracking(S, i + 1, res))
				return true;
			res.pop_back();
			if (size >= 2)
				break;
		}
		return false;
	}
};