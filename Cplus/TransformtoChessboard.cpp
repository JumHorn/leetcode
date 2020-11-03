#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int movesToChessboard(vector<vector<int>> &board)
	{
		int m = board.size(), n = board[0].size();
		vector<int> v(m);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; j++)
				v[i] |= board[i][j] << j;
		}
		vector<int> board0 = v, board1 = v;
		int step0 = transfer(board0, 0), step1 = transfer(board1, 1);
		if (step0 == 10000 && step1 == 10000)
			return -1;
		if (step0 != 10000)
		{
			v = transpose(board0);
			if (!checkValid(v))
				step0 = 10000;
			board0 = v;
			int tmp0 = transfer(v, 0), tmp1 = transfer(board0, 1);
			if (tmp0 > tmp1)
				v = board0;
			if (!checkValid(v))
				step0 = 10000;
			step0 += min(tmp0, tmp1);
		}
		if (step1 != 10000)
		{
			v = transpose(board1);
			if (!checkValid(v))
				step1 = 10000;
			board1 = v;
			int tmp0 = transfer(v, 0), tmp1 = transfer(board1, 1);
			if (tmp0 > tmp1)
				v = board1;
			if (!checkValid(v))
				step1 = 10000;
			step1 += min(tmp0, tmp1);
		}
		int res = min(step0, step1);
		return res >= 10000 ? -1 : res;
	}

	vector<int> transpose(vector<int> &v)
	{
		int n = v.size();
		vector<int> res(n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; j++)
				res[i] |= ((v[j] >> i) & 1) << j;
		return res;
	}

	//swap with flag equals to zero or one
	int transfer(vector<int> &board, int flag)
	{
		int m = board.size();
		stack<int> s;
		int res = 0;
		for (int i = 0; i < m; ++i)
		{
			int tmp = (board[i] & 1);
			if (tmp != flag)
			{
				if (s.empty() || (board[s.top()] & 1) == tmp)
					s.push(i);
				else
				{
					swap(board[s.top()], board[i]);
					res++;
					s.pop();
				}
			}
			flag = 1 - flag;
		}
		if (!s.empty())
			return 10000;
		return res;
	}

	bool checkValid(vector<int> &board)
	{
		int mask = (1 << board.size()) - 1;
		for (auto n : board)
		{
			if ((n & 0x55555555 & mask) != n && (n & 0xAAAAAAAA & mask) != n)
				return false;
		}
		return true;
	}
};