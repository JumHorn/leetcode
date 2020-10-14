/*
collect type a and b with b after a
count_b means last meet fruitstree[i]ount
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int totalFruit(int* tree, int treeSize)
{
	int res = 0, count_all = 0, count_b = 0, a = 0, b = 0;
	for (int i = 0; i < treeSize; ++i)
	{
		count_all = (tree[i] == a || tree[i] == b ? count_all + 1 : count_b + 1);
		count_b = (tree[i] == b ? count_b + 1 : 1);
		if (b != tree[i])
		{
			a = b;
			b = tree[i];
		}
		res = max(res, count_all);
	}
	return res;
}
