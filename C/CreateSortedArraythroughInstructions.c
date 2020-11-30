#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//Fenwick tree(BIT)
int sum(int *tree, int size, int index)
{
	int res = 0;
	for (++index; index > 0; index -= index & -index)
		res += tree[index];
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	for (++index; index < size; index += index & -index)
		tree[index] += delta;
}
/********end of Fenwick tree(BIT)********/

int createSortedArray(int *instructions, int instructionsSize)
{
	static const int MOD = 1e9 + 7;
	int N = instructionsSize, res = 0;
	int bitSize = 1e5 + 2, bit[bitSize];
	memset(bit, 0, sizeof(bit));
	for (int i = 0; i < N; ++i)
	{
		int less = sum(bit, bitSize, instructions[i] - 1);
		int greater = sum(bit, bitSize, instructions[i]);
		res = (res + min(less, i - greater)) % MOD;
		update(bit, bitSize, instructions[i], 1);
	}
	return res;
}