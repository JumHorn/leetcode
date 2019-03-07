#include<vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if((long long)(rec1[0]-rec2[0])*(rec1[2]-rec2[2])<0&&(long long)(rec1[1]-rec2[1])*(rec1[3]-rec2[3])<0)
			return true;
		if(rec1[0]==rec2[0]||rec1[2]==rec2[2])
			return Overlap(rec1[1],rec1[3],rec2[1],rec2[3]);
		if(rec1[1]==rec2[1]||rec1[3]==rec2[3])
			return Overlap(rec1[0],rec1[2],rec2[0],rec2[2]);
        return Overlap(rec1,rec2[0],rec2[1])||Overlap(rec1,rec2[2],rec2[3])||Overlap(rec1,rec2[0],rec2[3])||Overlap(rec1,rec2[2],rec2[1])||Overlap(rec2,rec1[0],rec1[1])||Overlap(rec2,rec1[2],rec1[3])||Overlap(rec2,rec1[0],rec1[3])||Overlap(rec2,rec1[2],rec1[1]);
    }

	bool Overlap(int y1,int y2,int y3,int y4)
	{
		if(y1>=y3&&y1<y4||y3>=y1&&y3<y2)
			return true;
		return false;
	}

	bool Overlap(vector<int>& rec,int x,int y)
	{
		if(x>rec[0]&&x<rec[2]&&y>rec[1]&&y<rec[3])
			return true;
		return false;
	}
};
