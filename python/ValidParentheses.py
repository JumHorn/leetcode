#coding=UTF-8
class ValidParentnesses(object):
    def isValid(self,s):
        '''
        :type s: str
        :rtype : bool
        '''
        right_brackets={'}':1,']':2,')':3}
        left_brackets={'{':1,'[':2,'(':3}
        l=list(s)
        while l:
            i=0
            j=len(l)
            while i<j:
                if right_brackets.has_key(l[i]):
                    if i==0:
                        return False
                    if not left_brackets.has_key(l[i-1]) or right_brackets[l[i]]!=left_brackets[l[i-1]]:
                        return False
                    del l[i]
                    del l[i-1]
                    break
                i+=1
            if i==j:
                return False
        return True

V=ValidParentnesses()
print V.isValid('[{}]()')
