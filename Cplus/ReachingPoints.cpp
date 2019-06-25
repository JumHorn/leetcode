class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
 		if(sx==tx&&sy==ty)
	 		return true;		
		if(sx>tx||sy>ty)
			return false;
		return reachingPoints(sx,sx+sy,tx,ty)||reachingPoints(sx+sy,sy,tx,ty);
    }
};
