#include<vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
		if(x.size()<4)
			return false;		
		int bottom,left,top,right;
		right=0;
		bottom=0;
		top=x[0];
		left=-x[1];
		bool alive=true;
		int coor=top-x[2];
		if(coor>=bottom)
			alive=false;
		bottom=coor;
		for(int i=3;i<(int)x.size();i++)
		{
			switch((i-3)%4)
			{
			case 0:
				//-->
				coor=left+x[i];
				if(!alive&&coor>=right)
					return true;
				if(coor<=right)
					alive=false;
				right=coor;
				break;
			case 1:
				// ^
				coor=bottom+x[i];
				if(!alive&&coor>=top)
					return true;
				if(coor<=top)
					alive=false;
				break;
			case 2:
				//<--
				coor=right-x[i];
				if(!alive&&coor<=left)
					return true;
				if(coor>=left)
					alive=false;
				break;
			case 3:
				// V
				coor=top-x[i];
				if(!alive&&coor<=bottom)
					return true;
				if(coor>=bottom)
					alive=false;
				bottom=coor;
				break;
			default:
				break;
			}
		}
		return false;
    }
};

