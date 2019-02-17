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

/*
Some used stack. Some used the depth of a stack. Here I use a different perspective. In a binary tree, if we consider null as leaves, then

all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree. When the next node comes, we then decrease diff by 1, because the node provides an in degree. If the node is not null, we increase diff by 2, because it provides two out degrees. If a serialization is correct, diff should never be negative and diff will be zero when finished.

public boolean isValidSerialization(String preorder) {
    String[] nodes = preorder.split(",");
    int diff = 1;
    for (String node: nodes) {
        if (--diff < 0) return false;
        if (!node.equals("#")) diff += 2;
    }
    return diff == 0;
}
*/
