#coding UTF-8
#definition for singly-linked list
class ListNode(object):
    def __init__(self,x):
        self.val=x
        self.next=None

class IntersectionoftwoLinkedLists(object):
    def getIntersectionNode(self,headA,headB):
