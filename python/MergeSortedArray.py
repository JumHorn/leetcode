class MergeSortedArray(object):
    def merge(self,nums1,m,nums2,n):
        '''
        :type nums1:list[int]
        :type m:int
        :type nums2:list[int]
        :type n:int 
        :rtype:void Do not return anything modify nums1 in-place instead
        '''
        if n<=0:
            return 
        if m<=0:
            nums1[:n]=nums2[:n]
            return
        i=0
        for item in nums2:
            while i<m:
                if nums1[i]>item:
                    nums1.insert(i,item)
                    nums1.pop()
                    m=m+1
                    break
                elif i==m-1:
                    nums1.insert(i+1,item)
                    nums1.pop()
                    m=m+1
                    break
                i=i+1



nums1=[1,0]
nums2=[2]
M=MergeSortedArray()
M.merge(nums1,1,nums2,1)
print nums1
