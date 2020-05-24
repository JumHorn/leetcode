#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define abs(x) (((x) < 0) ? (-(x)) : (x))
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define trimax(a, b, c) (max(max(a, b), c)) //the maximum of a,b,c
#define trimin(a, b, c) (min(min(a, b), c)) //the minimum of a,b,c

/*
//frequently used items

//cmp function don't consider overflow
int cmp(const void* lhs,const void* rhs)
{
	return *(int*)lhs-*(int*)rhs;
}

//board dfs direction
int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//monoqueue deque
int deque[k], front = 0, rear = 0;
front = (front + k - 1) % k; //pop front
rear = (rear + 1) % k; // pop rear
front == rear; //is empty
*/

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