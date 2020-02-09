#include <vector>
using namespace std;

class Solution
{
public:
	bool checkIfExist(vector<int>& arr)
	{
		vector<int> negative(1001), positive(1001);
		int zero = 0;
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (arr[i] == 0)
				zero++;
			else if (arr[i] > 0)
				++positive[arr[i]];
			else
				++negative[-arr[i]];
		}
		if (zero >= 2)
			return true;
		return checkDouble(positive) || checkDouble(negative);
	}

	bool checkDouble(vector<int>& arr)
	{
		for (int i = 0; i <= (int)arr.size() / 2; i++)
		{
			if (arr[i] != 0 && arr[2 * i] != 0)
				return true;
		}
		return false;
	}
};
