
//max heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(int *ptr, int size)
{
	if (size <= 0)
		return;
	int val = *ptr, non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1] > ptr[i])
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = ptr[size - 1];
	push_heap(ptr, hole + 1);
	ptr[size - 1] = val;
}

void make_heap(int *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

int lastStoneWeight(int *stones, int stonesSize)
{
	make_heap(stones, stonesSize);
	while (stonesSize > 1)
	{
		pop_heap(stones, stonesSize--);
		pop_heap(stones, stonesSize--);
		if (stones[stonesSize] < stones[stonesSize + 1])
		{
			stones[stonesSize] = stones[stonesSize + 1] - stones[stonesSize];
			push_heap(stones, ++stonesSize);
		}
	}
	return stonesSize > 0 ? stones[0] : 0;
}