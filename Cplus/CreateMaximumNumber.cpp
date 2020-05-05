#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
	{
		int n1 = nums1.size(), n2 = nums2.size();
		vector<int> res(k);
		for (int i = 0; i <= k && i <= n1; i++)
		{
			if (k - i > n2)
				continue;
			vector<int> left = maxKNumber(nums1, i);
			vector<int> right = maxKNumber(nums2, k - i);
			vector<int> tmp = merge(left, right);
			if (res < tmp)
				res.swap(tmp);
		}
		return res;
	}

	bool less(vector<int> &left, int i, vector<int> &right, int j)
	{
		int n1 = left.size(), n2 = right.size();
		for (; i < n1 && j < n2; i++, j++)
		{
			if (left[i] != right[j])
				return left[i] < right[j];
		}
		return n1 - i < n2 - j;
	}

	vector<int> merge(vector<int> &left, vector<int> &right)
	{
		vector<int> res;
		int i = 0, j = 0, n1 = left.size(), n2 = right.size();
		while (i < n1 && j < n2)
		{
			if (less(left, i, right, j))
				res.push_back(right[j++]);
			else
				res.push_back(left[i++]);
		}
		while (i < n1)
			res.push_back(left[i++]);
		while (j < n2)
			res.push_back(right[j++]);
		return res;
	}

	vector<int> maxKNumber(vector<int> &num, int k)
	{
		if (k == 0)
			return {};
		vector<int> res;
		int n = num.size();
		for (int i = 0; i < n; i++)
		{
			while (!res.empty() && res.size() + n - i > k && res.back() < num[i])
				res.pop_back();
			if (res.size() < k)
				res.push_back(num[i]);
		}
		return res;
	}
};