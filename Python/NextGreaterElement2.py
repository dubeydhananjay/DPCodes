from typing import List

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        res = []
        st = []
        size = len(nums)

        for i in range(size - 1, -1, -1):
            st.append(nums[i])

        for i in range(size - 1, -1, -1):
            while st and st[-1] <= nums[i]:
                st.pop()
            if not st:
                res.append(-1)
            else:
                res.append(st[-1])
            st.append(nums[i])

        res.reverse()
        return res
