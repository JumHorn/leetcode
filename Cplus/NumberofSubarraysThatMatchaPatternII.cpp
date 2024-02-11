#include <vector>
using namespace std;

class Solution
{
public:
	int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
	{
		vector<int> diff;
		int N = nums.size();
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] == nums[i - 1])
				diff.push_back(0);
			else if (nums[i] > nums[i - 1])
				diff.push_back(1);
			else
				diff.push_back(-1);
		}

		auto kmp = [&](vector<int> &pattern, vector<int> &kmptable)
		{
			for (int i = 1, j = 0; i < (int)pattern.size(); ++i)
			{
				while (j > 0 && pattern[j] != pattern[i])
					j = kmptable[j - 1];
				if (pattern[j] == pattern[i])
					++j;
				kmptable[i] = j;
			}
		};

		int P = pattern.size();
		vector<int> kp(P);
		kmp(pattern, kp);
		return findAll(diff, pattern, kp);
	}

	int findAll(vector<int> &nums, vector<int> &pattern, vector<int> &kmp)
	{
		int M = nums.size(), N = pattern.size(), res = 0;
		for (int i = 0, j = 0; i < M;)
		{
			if (nums[i] == pattern[j])
			{
				++i;
				++j;
			}
			else
				j > 0 ? j = kmp[j - 1] : ++i;

			if (j == N)
			{
				++res;
				j = kmp[j - 1];
			}
		}
		return res;
	}
};