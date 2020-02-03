#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> prisonAfterNDays(vector<int> &cells, int N)
	{
		vector<int> update = cells;
		unordered_map<int, int> m;
		vector<int> v;
		int index = 0;
		for (int i = 1; i < 7; i++)
			update[i] = 1 - (cells[i - 1] ^ cells[i + 1]);
		update[0] = update[7] = 0;
		for (int i = 1; i < N; i++)
		{
			int tmp = compress(update);
			if (m.find(tmp) != m.end())
			{
				N = N - i;
				int c = v.size() - m[tmp];
				int ii = m[tmp] + N % c;
				return uncompress(v[ii]);
			}
			else
			{
				m[tmp] = index++;
				v.push_back(tmp);
			}

			cells = update;
			for (int i = 1; i < 7; i++)
				update[i] = 1 - (cells[i - 1] ^ cells[i + 1]);
		}
		return update;
	}

	int compress(vector<int> &cells)
	{
		int res = 0;
		for (int i = 0; i < (int)cells.size(); i++)
			if (cells[i] == 1)
				res |= (1 << i);
		return res;
	}

	vector<int> uncompress(int n)
	{
		vector<int> cells(8);
		for (int i = 0; i < 8; i++)
			cells[i] = ((n & (1 << i)) >> i);
		return cells;
	}
};