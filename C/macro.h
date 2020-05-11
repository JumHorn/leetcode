#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define trimax(a, b, c) (max(max(a, b), c))	 //the maximum of a,b,c
#define trimin(a, b, c) (min(min(a, b), c))	 //the minimum of a,b,c

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
