typedef struct pair
{
	int first;
	int second;
} PAIR;

//max heap function series
void push_heap(PAIR *ptr, int size)
{
	if (size > 0)
	{
		PAIR val = ptr[size - 1];
		int hole = size - 1;
		for (int i = (hole - 1) >> 1; hole > 0 && val.first > ptr[i].first; i = (hole - 1) >> 1)
		{
			ptr[hole] = ptr[i];
			hole = i;
		}
		ptr[hole] = val;
	}
}

//for internal usage
void _adjust_heap(PAIR *ptr, int size, int hole, PAIR val)
{
	int non_leaf = (size - 1) >> 1, i = hole;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i].first < ptr[i - 1].first)
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = val;
	push_heap(ptr, hole + 1);
}

void make_heap(PAIR *ptr, int size)
{
	for (int hole = (size - 1) >> 1; hole >= 0; --hole)
		_adjust_heap(ptr, size, hole, ptr[hole]);
}

void pop_heap(PAIR *ptr, int size)
{
	if (size > 0)
	{
		PAIR val = *ptr;
		_adjust_heap(ptr, size, 0, ptr[size - 1]);
		ptr[size - 1] = val;
	}
}

int findMaximizedCapital(int k, int W, int *Profits, int ProfitsSize, int *Capital, int CapitalSize)
{
	//[0] profit [1] capital
	int psize = 0, csize = 0;
	PAIR ipo[ProfitsSize], nonipo[ProfitsSize];
	for (int i = 0; i < ProfitsSize; i++)
	{
		if (Capital[i] <= W)
		{
			ipo[psize].first = Profits[i];
			ipo[psize].second = Capital[i];
			push_heap(ipo, ++psize);
		}
		else
		{
			nonipo[csize].first = -Capital[i];
			nonipo[csize].second = Profits[i];
			push_heap(nonipo, ++csize);
		}
	}
	for (int i = 0; i < k && psize != 0; i++)
	{
		W += ipo[0].first;
		pop_heap(ipo, psize--);
		while (csize != 0 && W >= -nonipo[0].first)
		{
			ipo[psize].first = nonipo[0].second;
			ipo[psize].second = -nonipo[0].first;
			push_heap(ipo, ++psize);
			pop_heap(nonipo, csize--);
		}
	}
	return W;
}