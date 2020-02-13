#include <vector>
using namespace std;

class Solution
{
public:
	bool reorderedPowerOf2(int N)
	{
		if (N == 1)
			return true;
		vector<int> num;
		while (N != 0)
		{
			num.push_back(N % 10);
			N /= 10;
		}
		return backTrack(num, 0);
	}

	bool backTrack(vector<int>& num, int index)
	{
		int n = num.size();
		if (index == n)
		{
			if (num.back() == 0)
				return false;
			return checkVector(num);
		}
		for (int i = index; i < n; i++)
		{
			if (i == 0 && num[index] % 2 == 1)
				continue;
			swap(num[index], num[i]);
			if (backTrack(num, index + 1))
				return true;
			swap(num[index], num[i]);
		}
		return false;
	}

	bool checkVector(vector<int>& num)
	{
		int res = 0;
		for (int i = num.size() - 1; i >= 0; i--)
			res = res * 10 + num[i];
		return bitCount(res) == 1;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			n &= n - 1;
			res++;
		}
		return res;
	}
};
