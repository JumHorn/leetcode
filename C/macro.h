#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

/*
//cmp function don't consider overflow
int cmp(const void* lhs,const void* rhs)
{
	return *(int*)lhs-*(int*)rhs;
}
*/
