from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        umap = {}
        res = []
        stack = []
        size = len(nums2)
        
        for i in range(size - 1, -1, -1):
            if len(stack) == 0:
                umap[nums2[i]] = -1
            elif len(stack) > 0 and stack[-1] > nums2[i]:
                umap[nums2[i]] = stack[-1]
            elif len(stack) > 0 and stack[-1] <= nums2[i]:
                while len(stack) > 0 and stack[-1] <= nums2[i]:
                    stack.pop()
                if len(stack) == 0:
                    umap[nums2[i]] = -1
                else:
                    umap[nums2[i]] = stack[-1]
            stack.append(nums2[i])
        
        for num in nums1:
            res.append(umap[num])
        
        return res
