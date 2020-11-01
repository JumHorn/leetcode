
/*
XOR性质
1. x^x==0
2. x^0==x
3. 2x^(2x+1)=1
3. 从0到n的异或成周期性变化，取决与后两位bit

start^(start+2)^(start+4)^...^(start+n*2)
先确定最后一位
在计算前面的值
start/2^(start/2+1)^(start/2+2)^...

如果 start/2 是偶数，我们只需要看 n 是否是偶数即可：
如果 n 是偶数，该公式结果就是 n/2 个 1 进行异或。也就是 (n/2)&1
如果 n 是奇数，该公式结果就是 ((n/2)&1)^(start/2+n)

如果 start/2是奇数，那么我们可以在前面补充 (start/2-1)^(start/2-1)就回到n是偶数的情况
*/

int xorOperation(int n, int start)
{
	int last = start + 2 * (n - 1);
	start % 4 < 2 ? start = 0 : --n;
	if (n % 2 == 0)
		return start ^ (n & 2);
	return start ^ last ^ (n & 2);
}
