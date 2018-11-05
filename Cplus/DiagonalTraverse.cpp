#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if(matrix.size()==0)
			return vector<int>();
		vector<int> res(matrix.size()*matrix[0].size());
		int i=0,j=0,index=0;
		bool dir=true;
		while(true)
		{
			res[index++]=matrix[i][j];
			if(i==matrix.size()-1&&j==matrix[0].size()-1)
				break;
			if(dir)//up-right
			{
				if(j==matrix[0].size()-1)
				{
					dir=false;
					i++;
				}
				else if(i==0)
				{
					dir=false;
					j++;
				}
				else
				{
					i--;
					j++;
				}
			}	
			else//down-left
			{
				if(i==matrix.size()-1)
				{
					dir=true;
					j++;
				}
				else if(j==0)
				{
					dir=true;
					i++;
				}
				else
				{
					i++;
					j--;
				}
			}
		}
		return res;
    }
};
