class MinStack(object):
    l=[]
    m=2147483648
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l=[]
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if x<self.m:
            self.m=x
        self.l.append(x)
        

    def pop(self):
        """
        :rtype: void
        """
        if len(self.l)==1:
            self.m=2147483648
        elif self.m==self.l[len(self.l)-1]:
            self.m=min(self.l[0:len(self.l)-1])
        del self.l[len(self.l)-1]
        

    def top(self):
        """
        :rtype: int
        """
        return self.l[len(self.l)-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.m
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()