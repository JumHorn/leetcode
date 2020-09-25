#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int lastRemaining(int n)
	{
		vector<int> v(n), copy(n);
		for (int i = 0; i < n; ++i)
			v[i] = i + 1;
		int size = n;
		while (size > 1)
		{
			int i = 1, j = size / 2 - 1;
			while (i < size)
			{
				copy[j] = v[i];
				i += 2;
				--j;
			}
			size >>= 1;
			v.swap(copy);
		}
		return v[0];
	}
};