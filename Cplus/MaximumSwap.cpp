#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
		string tmp=to_string(num);
		for(int i=0;i<(int)tmp.length();i++)
		{
			char big='\0';
			int k;
			for(int j=i+1;j<(int)tmp.length();j++)
			{
				if(big<=tmp[j])
				{
					big=tmp[j];
					k=j;
				}
			}
			if(big>tmp[i])
			{
                while(k<(int)tmp.length()-1&&tmp[k]==tmp[k+1])
                    k++;
				swap(tmp[i],tmp[k]);
				return stoul(tmp);
			}
		}
		return stoul(tmp);
    }
};
