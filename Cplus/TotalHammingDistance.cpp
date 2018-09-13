#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
		int res=0;
		for(int i=0;i<32;i++)
		{
			int group=0;
			for(int j=0;j<nums.size();j++)
			{
				if((nums[j]>>i)&1==1)
					group++;
			}
			res+=group*(nums.size()-group);
		}
		return res;
	}
};

//class Solution {
//public:
//    int totalHammingDistance(vector<int>& nums) {
//		int res=0;
//		if(nums.empty())
//		{
//			return 0;
//		}
//		for(int i=0;i<nums.size()-1;i++)//substract 1 cause great problem
//		{
//			for(int j=i+1;j<nums.size();j++)
//			{
//				res+=bitCount(nums[i]^nums[j]);
//			}
//		}
//		return res;
//    }
//
//	int bitCount(int x)
//	{
//		x-=((x>>1)&0x55555555);
//		x=(x&0x33333333)+((x>>2)&0x33333333);
//		x=(x+(x>>4))&0x0F0F0F0F;
//		x+=x>>8;
//		x+=x>>16;
//		return x&0x3F;
//	}

//	int Hamming(int x)
//	{
//		int bit=0;
//		while(x)
//		{
//			bit++;
//			x&=x-1;
//		}
//		return bit;
//	}
//};
