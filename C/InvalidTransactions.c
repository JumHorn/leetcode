#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trans
{
	char name[11];
	int time;
	int amount;
	char city[11];
	int index;
} trans;

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	trans *l = (trans *)lhs, *r = (trans *)rhs;
	int res = strcmp(l->name, r->name);
	if (res != 0)
		return res;
	if (l->time != r->time)
		return l->time - r->time;
	if (l->amount != r->amount)
		return l->amount - r->amount;
	return strcmp(l->city, r->city);
}

trans split(char *tran)
{
	trans res;
	sscanf(tran, "%[^,],%d,%d,%s", res.name, &res.time, &res.amount, res.city);
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **invalidTransactions(char **transactions, int transactionsSize, int *returnSize)
{
	*returnSize = 0;
	int N = transactionsSize;
	trans v[N];
	int seen[N]; //{index}
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < N; ++i)
	{
		v[i] = split(transactions[i]);
		v[i].index = i;
		if (v[i].amount >= 1000)
		{
			if (seen[i] == 0)
			{
				seen[i] = 1;
				++*returnSize;
			}
		}
	}
	qsort(v, N, sizeof(trans), cmp);
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (strcmp(v[j].name, v[i].name) != 0)
				break;
			if (v[j].time - v[i].time > 60)
				break;
			if (strcmp(v[j].city, v[i].city) != 0)
			{
				if (seen[v[i].index] == 0)
				{
					seen[v[i].index] = 1;
					++*returnSize;
				}
				if (seen[v[j].index] == 0)
				{
					seen[v[j].index] = 1;
					++*returnSize;
				}
			}
		}
	}
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0, j = 0; i < N; ++i)
	{
		if (seen[i] == 1)
			res[j++] = strdup(transactions[i]);
	}
	return res;
}