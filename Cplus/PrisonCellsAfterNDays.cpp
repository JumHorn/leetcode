#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> prisonAfterNDays(vector<int> &cells, int N)
	{
		unordered_map<int, int> m; //{compressed data,index}
		vector<int> state;
		int index = 0;
		cells = update(cells);
		for (int i = 1; i < N; ++i)
		{
			int data = compress(cells);
			if (m.find(data) != m.end())
			{
				N = N - i;
				int T = state.size() - m[data];
				int finalindex = m[data] + N % T;
				return uncompress(state[finalindex]);
			}
			else
			{
				m[data] = index++;
				state.push_back(data);
			}

			cells = update(cells);
		}
		return cells;
	}

	vector<int> update(vector<int> &cells)
	{
		vector<int> nextcells(8);
		for (int i = 1; i < 7; ++i)
			nextcells[i] = (1 ^ cells[i - 1] ^ cells[i + 1]);
		return nextcells;
	}

	int compress(vector<int> &cells)
	{
		int res = 0;
		for (int i = 0; i < (int)cells.size(); ++i)
		{
			if (cells[i] == 1)
				res |= (1 << i);
		}
		return res;
	}

	vector<int> uncompress(int n)
	{
		vector<int> cells(8);
		for (int i = 0; i < 8; ++i)
			cells[i] = ((n >> i) & 1);
		return cells;
	}
};