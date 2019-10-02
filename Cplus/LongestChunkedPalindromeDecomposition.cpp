#include<string>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text) {
		return recursive(text,0,text.length());		
    }

	int recursive(const string& text,int left,int right)
	{
		if(left>=right)
			return 0;
		int res=1;
		for(int i=right-1;i*2>=left+right;i--)
		{
			if(text[left]==text[i]&&text.substr(left,right-i)==text.substr(i,right-i))
			{
				res=2+recursive(text,left+right-i,i);
				break;
			}
		}
		return res;
	}
};
