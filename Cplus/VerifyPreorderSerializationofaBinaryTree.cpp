#include<string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
		if(preorder.empty())
			return false;
		int index=0;
		if(preorder[index]=='#')
			return index==(int)preorder.size()-1;
    	if(!isValid(preorder,index))
		  	return false;	
		return index==(int)preorder.size()-1;
    }

	bool isValid(string& preorder,int& index)
	{
		while(index<(int)preorder.size()&&preorder[index]!=',')
			++index;
		if(index>=(int)preorder.size()-1)
			return false;
		++index;
		if(preorder[index]!='#')
		{
			if(!isValid(preorder,index))
				return false;
		}
		index+=2;
		if(index>=(int)preorder.size())
			return false;
		if(preorder[index]!='#')
		{
			if(!isValid(preorder,index))
				return false;
		}
		return true;
	}
};
