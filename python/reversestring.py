s=input()
l=list(s)
i=len(s)-1
j=0

while(i>j):
    t=l[i]
    l[i]=l[j]
    l[j]=t
    j=j+1
    i=i-1
t=''.join(l)
print t
