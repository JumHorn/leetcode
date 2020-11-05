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

int furthestBuilding(int *heights, int heightsSize, int bricks, int ladders)
{
	int res = 0, heap[heightsSize], heapSize = 0;
	for (int i = 1; i < heightsSize; res = i++)
	{
		if (heights[i - 1] >= heights[i])
			continue;
		int h = heights[i] - heights[i - 1];
		if (bricks >= h)
		{
			bricks -= h;
			heap[heapSize++] = h;
			push_heap(heap, heapSize);
		}
		else
		{
			if (ladders == 0)
				break;
			--ladders;
			if (heapSize != 0 && h < heap[0])
			{
				int b = heap[0];
				pop_heap(heap, heapSize--);
				bricks += b - h;
				heap[heapSize++] = h;
				push_heap(heap, heapSize);
			}
		}
	}
	return res;
}