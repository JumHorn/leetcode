
#define min(a, b) (((a) < (b)) ? (a) : (b))

int memdp(int target, int *dp)
{
	if (target == 0)
		return 0;
	if (dp[target] > 0)
		return dp[target];
	int position = 0, speed = 1, count = 0;
	while (position < target)
	{
		++count;
		position += speed;
		speed *= 2;
	}
	int res = 0;
	if (position == target)
		res = count;
	else
	{
		res = memdp(position - target, dp) + count + 1; //R
		for (int i = 0; i < count - 1; i++)
		{
			int right = memdp(target - (position - speed / 2) + ((1 << i) - 1), dp) + i + count - 1 + 2; //RR
			res = min(res, right);
		}
	}
	return dp[target] = res;
}

int racecar(int target)
{
	int dp[10001] = {0};
	return memdp(target, dp);
}