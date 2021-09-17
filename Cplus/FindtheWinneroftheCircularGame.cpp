
/*
Josephus problem
因为每次数k下，必将消除一个人
当n==1时，res=1
当n==2时，先数一轮k，消除一个人，余下n-1个人,winner从上一轮已知，只需加偏移k，即为本轮winner

如下对应
k k+1 k+2 ... n-2,n-1,0,1,2,... k-2
并且从k开始报0。
我们把他们的编号做一下转换：
k --> 0
k+1 --> 1
k+2 --> 2
...
...
k-2 --> n-2
即
k k+1 k+2 ... n-2,     n-1,    0,    1,     2,   ... k-2(n turn)
0  1   2      n-2-k   n-1-k   n-k  n-k+1  n-k+2      n-2(n-1 turn)

以下代码res从0开始，是为了简化代码
*/

class Solution
{
public:
	int findTheWinner(int n, int k)
	{
		int res = 0;
		for (int i = 1; i <= n; ++i)
			res = (res + k) % i;
		return res + 1;
	}
};