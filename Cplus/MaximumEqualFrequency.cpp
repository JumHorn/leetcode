#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxEqualFreq(vector<int> &nums)
	{
		int res = 0;
		unordered_map<int, int> freq, freqfreq;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (freq.find(nums[i]) != freq.end())
			{
				int old = freq[nums[i]];
				if (--freqfreq[old] == 0)
					freqfreq.erase(old);
			}
			++freq[nums[i]];
			++freqfreq[freq[nums[i]]];
			if (freqfreq.size() == 1)
			{
				if (freq.size() == 1 || freq.begin()->second == 1)
					res = i + 1;
			}
			else if (freqfreq.size() == 2)
			{
				int a = freqfreq.begin()->first, b = (++freqfreq.begin())->first;
				if (((a == 1 || a - b == 1) && freqfreq[a] == 1) ||
					((b == 1 || b - a == 1) && freqfreq[b] == 1))
					res = i + 1;
			}
		}
		return res;
	}
};