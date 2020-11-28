
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

int kthSmallest(int **mat, int matSize, int *matColSize, int k)
{
	int v[k], heap[k];
	int vsize = 1, heapsize = 0, M = matSize, N = *matColSize;
	v[0] = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
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