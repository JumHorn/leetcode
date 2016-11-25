#coding=UTF-8
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class GuessNumberHigherOrLower(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        r=n//2
        a=1
        b=n
        while guess(r)!=0:
            if guess(r)==-1:
                r=r-1
                b=r
            else:
                r=r+1
                a=r
            r=(a+b)//2
        return r