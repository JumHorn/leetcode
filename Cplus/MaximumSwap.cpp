#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int maximumSwap(int num)
	{
		string val = to_string(num);
		int N = val.length();
		for (int i = 0; i < N; ++i)
		{
			int k = i;
			for (int j = i + 1; j < N; ++j)
			{
				if (val[k] <= val[j])
					k = j;
			}
			if (k != i && val[k] > val[i])
			{
				swap(val[i], val[k]);
				break;
			}
		}
		return stoi(val);
	}
};