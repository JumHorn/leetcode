#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
	{
		int N1 = nums1.size(), N2 = nums2.size();
		vector<int> res(k);
		for (int i = 0; i <= k && i <= N1; ++i)
		{
			if (k - i > N2)
				continue;
			vector<int> num1 = maxKNumber(nums1, i);
			vector<int> num2 = maxKNumber(nums2, k - i);
			vector<int> num = merge(num1, num2);
			if (res < num)
				res.swap(num);
		}
		return res;
	}

	bool less(vector<int> &num1, int index1, vector<int> &num2, int index2)
	{
		int N1 = num1.size(), N2 = num2.size();
		for (; index1 < N1 && index2 < N2; ++index1, ++index2)
		{
			if (num1[index1] != num2[index2])
				return num1[index1] < num2[index2];
		}
		return N1 - index1 < N2 - index2;
	}

	vector<int> merge(vector<int> &num1, vector<int> &num2)
	{
		vector<int> res;
		int N1 = num1.size(), N2 = num2.size();
		for (int i = 0, j = 0; i < N1 || j < N2;)
		{
			if (i == N1)
				res.push_back(num2[j++]);
			else if (j == N2)
				res.push_back(num1[i++]);
			else
			{
				if (less(num1, i, num2, j))
					res.push_back(num2[j++]);
				else
					res.push_back(num1[i++]);
			}
		}
		return res;
	}

	//decreasing stack
	vector<int> maxKNumber(vector<int> &num, int k)
	{
		if (k == 0)
			return {};
		vector<int> res;
		int N = num.size();
		for (int i = 0; i < N; ++i)
		{
			while (!res.empty() && res.size() + N - i > k && res.back() < num[i])
				res.pop_back();
			if (res.size() < k)
				res.push_back(num[i]);
		}
		return res;
	}
};