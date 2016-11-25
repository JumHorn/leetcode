#include<stdio.h>
#include<stdint.h>
int main()
{
	int hammingWeight(uint32_t n);
        printf("%d\n",hammingWeight(16));
}
int hammingWeight(uint32_t n)
{
	n=(n&0x55555555)+((n>>1)&0x55555555);
	n=(n&0x33333333)+((n>>2)&0x33333333);
	n=(n&0x0f0f0f0f)+(n>>4&0x0f0f0f0f);
	n=n+(n>>8);
        n=n+(n>>16);
	return n&0x0000003f;
}
