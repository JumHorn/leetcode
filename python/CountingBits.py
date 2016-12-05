#coding=UTF-8
class CountingBits(object):
    def countingBits(self,num):
        """
        :type num: int
        :rtype: List[int]
        """
        binary=[0]
        result=[0]
        i=1
        while i<=num:
            j=0
            c=1
            while j<len(binary):
                if c==1:
                    t=binary[j]+c
                    c=t//2
                    binary[j]=t%2
                    print c,binary[j]
                else:
                    break
                j+=1
            print binary
            if c==1:
                binary.append(1)
            result.append(sum(binary))
            i+=1
        return result

num=2
C=CountingBits()
print C.countingBits(num)
