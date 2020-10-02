#include <stdbool.h>
/*
greedy algorithm
always add x to previous queue with length equal to 1 or 2
than add to the queue with length >= 3
than start a new queue
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))

bool isPossible(int* nums, int numsSize)
{
	int a = 0, b = 0, c = 0;  //a>=3 b=1 c=2(count of different length of the queue)
	for (int i = 0, j = 0; i < numsSize; i = j)
	{
		j = i + 1;
		while (j < numsSize && nums[i] == nums[j])
			++j;
		if (i - 1 >= 0 && nums[i] != nums[i - 1] + 1)  //not continouse with previouse value
		{
			if (b != 0 || c != 0)  //previous length 1 or 2 queue can not finished
				return false;
			a = b = c = 0;  //all start from the beginning
		}
		int tmp = a, diff = j - i - b - c;  //nums[i] make 1 or 2 queue finished,the left will add to >=3 queue
		if (diff < 0)						//can not finish 1 or 2 queue
			return false;
		a = min(a, diff);  //the increased >=3 queue
		a += c;			   //the newly increased >=3 queue end with nums[i]
		c = b;
		if (diff > tmp)  //start a new queue with length =1
			b = diff - tmp;
		else
			b = 0;
	}
	return b == 0 && c == 0;  //length 1 or 2 queue not exist
}
