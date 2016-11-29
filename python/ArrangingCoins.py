class ArrangingCoins(object):
    def ArrangingCoins(self,n):
        """
        :type n: int
        :rtype: int
        """

        i=int(math.sqrt(2*n))
        while i*(i+1)/2<=n:
            i+=1
        return i-1