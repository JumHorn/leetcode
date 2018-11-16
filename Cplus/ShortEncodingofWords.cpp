#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
       	int res=words.size();
	    for(int i=res-1;i>=0;i--)
		{
			for(int j=0;j<i;j++)
            {
				if(compare(words,j,i,res))
				{
                    break;
				}
            }
		}
		int sum=0;
		for(int i=0;i<res;i++)
			sum+=words[i].length()+1;
		return sum;
    }

	bool compare(vector<string>& words,int i,int j,int& res)
	{
		int m=words[i].length()-1,n=words[j].length()-1;
		while(m>=0&&n>=0&&words[i][m]==words[j][n])
		{
			m--;
			n--;
		}
		if(m==-1)
		{
			swap(words[i],words[--res]);
			return true;
		}
		if(n==-1)
		{
			swap(words[j],words[--res]);
			return true;
		}
		return false;
	}
};
