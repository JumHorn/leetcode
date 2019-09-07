#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
		string pattern=first+" "+second+" ";
		int len1=first.length(),len2=second.length(),len3=len1+len2;
		string::size_type i=0,j=0;
		i=text.find(pattern,i);
		while(i!=string::npos)
		{
            if(i>0&&text[i-1]==' '||i==0)
            {
                i+=len3+2;
                if(i>=text.size())
                    break;
                j=text.find(" ",i);
                res.push_back(text.substr(i,j-i));
            }
            else
                i+=len3+2;
            
			i=text.find(pattern,i);
		}
		return res;
    }
};
