#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> res(n);
        int tmp=0;
		lexicalOrder(res,1,n,tmp);
		return res;
    }

	void lexicalOrder(vector<int>& res,int start,int n,int& index)
	{
		if(start>n)
			return;
		for(int i=0;i<=9;i++)
		{
            if(start+i>n||start%10+i==10)
                break;
            res[index++]=start+i;
			lexicalOrder(res,(start+i)*10,n,index);
		}
	}
};
