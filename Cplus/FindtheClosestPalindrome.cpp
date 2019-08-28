#include<string>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
		int i=0,j=n.length()-1;
        long nn=stol(n),res0,res1,res2,abs0,abs1,abs2;
		string res(n);
		while(i<j)
			res[j--]=res[i++];
		res0=stol(res);
        abs0=abs(res0-nn);
        if(abs0==0)
            abs0=LONG_MAX;

        i=n.size()/2-1+(n.size()&1),j=n.size()/2;
        string tmp(res);
        if(tmp[i]=='9')
        {
            while (i>=0&&tmp[i]=='9')
            {
                tmp[i]='0';
                tmp[j]=tmp[i];
                i--;
                j++;
            }
            if(i<0)
                res1=pow(10,tmp.length())+1;
            else
            {
                tmp[i]=((tmp[i]-'0')+1)%10;
                res1=stol(tmp);
            }
        }
        else
        {
            if(i==j)
                tmp[i]+=1;
            else
            {
                tmp[i]+=1;
                tmp[j]+=1;
            }
            res1=stol(tmp);
        }
        abs1=abs(res1-nn);
        
        i=n.size()/2-1+(n.size()&1),j=n.size()/2;
        tmp=res;
        if(tmp[i]=='0')
        {
            while (i>=0&&tmp[i]=='0')
            {
                tmp[i]='9';
                tmp[j]=tmp[i];
                i--;
                j++;
            }
            if(i<0)
                res2=pow(10,tmp.length())-1;
            else
            {
                tmp[i]=((tmp[i]-'0')-1)%10;
                res2=stol(tmp);
            }
        }
        else
        {
            if(i==j)
                tmp[i]-=1;
            else
            {
                tmp[i]-=1;
                tmp[j]-=1;
            }
            res2=stol(tmp);
        }
        abs2=abs(res2-nn);

        long diff=min(min(abs0,abs1),abs2);
        if(diff==abs2)
            return to_string(res2);
        if(diff==abs0)
            return to_string(res0);
		return to_string(res1);
    }
};


int main()
{
    Solution sol;
    sol.nearestPalindromic("11");
    return 0;
}