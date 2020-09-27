// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

//this table equals the chance of 1-10.when hit * call rand7() again
/*
   1  2  3  4  5  6  7
1  1  2  3  4  5  6  7
2  8  9  10 1  2  3  4
3  5  6  7  8  9  10 1
4  2  3  4  5  6  7  8
5  9  10 1  2  3  4  5
6  6  7  8  9  10 *  *
7  *  *  *  *  *  *  *
*/

int rand10()
{
	static int board[7][7] =
		{
			{1, 2, 3, 4, 5, 6, 7},
			{8, 9, 10, 1, 2, 3, 4},
			{5, 6, 7, 8, 9, 10, 1},
			{2, 3, 4, 5, 6, 7, 8},
			{9, 10, 1, 2, 3, 4, 5},
			{6, 7, 8, 9, 10, 0, 0},
			{0, 0, 0, 0, 0, 0, 0}};
	int res;
	do
	{
		res = board[rand7() - 1][rand7() - 1];
	} while (res == 0);
	return res;
}