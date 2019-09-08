#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string S) {
        bool flag=true;
        while(flag)
        {
            flag=false;
            int swaposition=canSwap(S,S.length()-1);
            while(swaposition>0)
            {
                int before=beforeSwap(S,swaposition);
                int after=afterSwap(S,swaposition);
                if(canSwap(S,before,swaposition,after))
                {
                    string tmp=S;
                    doSwap(S,before,swaposition,after);
                    if(tmp>=S)
                        S=tmp;
                    else
                        flag=true;
                }
                swaposition=canSwap(S,swaposition-1);
            }
        }
		return S;
    }
	
	bool canSwap(const string& s,int start,int mid,int end)
	{
        int i,j;
		for(i=start,j=mid;i<mid&&j<end;i++,j++)
			if(s[j]>s[i])
				return true;
		return i==mid&&j!=end;
	}

	int canSwap(const string& s,int start)
	{
		for(int i=start;i>0;i--)
			if(s[i]=='1'&&s[i-1]=='0')
				return i;
		return -1;
	}

	int afterSwap(const string& s,int i)
	{
		int tmp=0;
		while(i<(int)s.length())
		{
			if(s[i]=='1')
				tmp++;
			else if(s[i]=='0')
				tmp--;
			if(tmp<0)
				break;
            i++;
		}
		return i;
	}

	int beforeSwap(const string& s,int i)
	{
		int tmp=0;
		while(--i>=0)
		{
			if(s[i]=='0')
				tmp++;
			else if(s[i]=='1')
				tmp--;
			if(tmp==0)
				break;
		}
		return i;
	}
	
	void doSwap(string& s,int start,int mid,int end)
	{
		string tmp=s.substr(start,mid-start);
		copy(s.begin()+mid,s.begin()+end,s.begin()+start);
		copy(tmp.begin(),tmp.end(),s.begin()+start+end-mid);
	}
};