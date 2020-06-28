#include <set>
#include <string>
using namespace std;

class Solution
{
public:
	bool isPathCrossing(string path)
	{
		set<pair<int, int>> s;
		pair<int, int> pos = {0, 0};
		s.insert(pos);
		for (auto c : path)
		{
			if (c == 'N')
				pos.second += 1;
			else if (c == 'S')
				pos.second -= 1;
			else if (c == 'E')
				pos.first += 1;
			else
				pos.first -= 1;
			if (s.find(pos) != s.end())
				return true;
			s.insert(pos);
		}
		return false;
	}
};
