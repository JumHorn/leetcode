class AddBinary(object):
    def addBinary(self,a,b):
        l=[]
        carry=0
        
        if len(a)>=len(b):
            i=len(a)-1
            for m in b[::-1]:
                t=int(a[i])+int(m)+carry
                carry=self.add(t,l)
                i=i-1
        else:
            i=len(b)-1
            for n in a[::-1]:
                t=int(n)+int(b[i])+carry
                carry=self.add(t,l)
                i=i-1
        if len(a)>len(b):
            for n in a[-len(b)-1::-1]:
                t=int(n)+carry
                carry=self.add(t,l)
        if len(a)<len(b):
            for m in b[-len(a)-1::-1]:
                t=int(m)+carry
                carry=self.add(t,l)
        if carry==1:
            l.insert(len(l),'1')
            print l
        l.reverse()
        return ''.join(l)
    def add(self,t,l):
        if t==3:
            l.append('1')
            carry=1
        elif t==2:
            l.append('0')
            carry=1
        elif t==1:
            l.append('1')
            carry=0
        else:
            l.append('0')
            carry=0
        return carry


addb=AddBinary()
addb.addBinary("1","1")
