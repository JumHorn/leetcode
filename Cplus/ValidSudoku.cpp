#include <bitset>
#include <vector>
using namespace std;

/*
bit operation
we use low 10 bits of a int(at least 4 bit can store 1-9)
type  row/col/sub  val
11    1111         1111
row val encodes 0001 1111 1111
col val encodes 0010 1111 1111
sub val encodes 0000 1111 1111(subboard encodes with fixed prefix 1111 0000 0000)
*/

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		bitset<1 << 10> bits;
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
				{
					int val = board[i][j] - '1';
					int row = (i << 4) | val | (1 << 8);
					int col = (j << 4) | val | (1 << 9);
					int sub = ((i / 3 * 3 + j / 3 % 3) << 4) | val;
					if (bits.test(row) || bits.test(col) || bits.test(sub))
						return false;
					bits.set(row);
					bits.set(col);
					bits.set(sub);
				}
			}
		}
		return true;
	}
};