#include<cmath>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int digits[10]={0};
		int res=9;
		int tmp=N;
		while(tmp!=0)
		{
			digits[res--]=tmp%10;
			tmp/=10;
		}
		int i=0;
		while(i<10&&digits[i]==0)
			i++;
		if(i==10)
			return 0;
		if(i==9)
			return digits[i];
		for(;i<9;i++)
			if(digits[i]>digits[i+1])
				break;
		if(i==9)
			return N;
		while(i>=1&&digits[i]==digits[i-1])
            i--;
		return N/(int)pow(10,9-i)*pow(10,9-i)-1;
    }
};
