
//max heap function series
void push_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = ptr[size - 1], hole = size - 1;
		for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
		{
			ptr[hole] = ptr[i];
			hole = i;
		}
		ptr[hole] = val;
	}
}

//for internal usage
void _adjust_heap(int *ptr, int size, int hole, int val)
{
	int non_leaf = (size - 1) >> 1, i = hole;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i] < ptr[i - 1])
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

void make_heap(int *ptr, int size)
{
	for (int hole = (size - 1) >> 1; hole >= 0; --hole)
		_adjust_heap(ptr, size, hole, ptr[hole]);
}

void pop_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = *ptr;
		_adjust_heap(ptr, size, 0, ptr[size - 1]);
		ptr[size - 1] = val;
	}
}
/********end of max heap********/

int kthSmallest(int **mat, int matSize, int *matColSize, int k)
{
	int v[k], heap[k];
	int vsize = 1, heapsize = 0, m = matSize, n = *matColSize;
	v[0] = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < vsize; ++l)
			{
				int val = mat[i][j] + v[l];
				if (heapsize >= k)
				{
					if (val < heap[0])
					{
						pop_heap(heap, heapsize--);
						heap[heapsize++] = val;
						push_heap(heap, heapsize);
					}
				}
				else
				{
					heap[heapsize++] = val;
					push_heap(heap, heapsize);
				}
			}
		}
		memcpy(v, heap, sizeof(int) * heapsize);
		vsize = heapsize;
		heapsize = 0;
	}
	return heap[0];
}