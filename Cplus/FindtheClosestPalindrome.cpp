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
            tmp[i]=((tmp[i]-'0')+1)%10+'0';
            tmp[j]=tmp[i];
            res1=stol(tmp);
        }
        abs1=abs(res1-nn);
        
        i=n.size()/2-1+(n.size()&1),j=n.size()/2;
        tmp=res;
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
            tmp[i]=((tmp[i]-'0')-1)%10+'0';
            if(tmp[i]=='0'&&i==0&&i!=j)
                tmp[j]='9';
            else
                tmp[j]=tmp[i];
            res2=stol(tmp);
        }
        abs2=abs(res2-nn);

        if(abs2<=abs1&&abs2<=abs0)
            return to_string(res2);
        if(abs0<=abs1&&abs0<=abs2)
            return to_string(res0);
		return to_string(res1);
    }
};