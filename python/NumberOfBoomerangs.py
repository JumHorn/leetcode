class NumberofBoomerangs(object):
    def numberofBoomerangs(self,points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        i=0
        n=0
        while i<len(points):
            j=0
            distance={}
            while j<len(points):
                if i!=j:
                    d=(points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1])
                    if d in distance:
                        distance[d]+=1
                    else:
                        distance[d]=1
                j+=1
            for dis in distance.values():
                if dis>=2:
                    n+=dis*(dis-1)
            i+=1
        return n