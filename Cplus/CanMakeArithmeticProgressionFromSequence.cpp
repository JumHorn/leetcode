#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canMakeArithmeticProgression(vector<int> &arr)
	{
		make_heap(arr.begin(), arr.end());

		pop_heap(arr.begin(), arr.end());
		int first = arr.back();
		arr.pop_back();

		pop_heap(arr.begin(), arr.end());
		int second = arr.back();
		arr.pop_back();

		while (!arr.empty())
		{
			pop_heap(arr.begin(), arr.end());
			int third = arr.back();
			arr.pop_back();

			if (first - second != second - third)
				return false;
			first = second;
			second = third;
		}
		return true;
	}
};