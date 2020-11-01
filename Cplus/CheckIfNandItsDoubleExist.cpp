#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkIfExist(vector<int> &arr)
	{
		unordered_set<int> s;
		for (auto n : arr)
		{
			if (s.find(n * 2) != s.end())
				return true;
			if (n % 2 == 0 && s.find(n / 2) != s.end())
				return true;
			s.insert(n);
		}
		return false;
	}
};