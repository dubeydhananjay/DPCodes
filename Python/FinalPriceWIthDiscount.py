from typing import List

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        v = []
        stack = []
        size = len(prices)
        for i in range(size - 1, -1, -1):
            if len(stack) == 0:
                v.append(prices[i])
            elif len(stack) > 0 and stack[-1] > prices[i]:
                while len(stack) > 0 and stack[-1] > prices[i]:
                    stack.pop()
                if len(stack) == 0:
                    v.append(prices[i])
                else:
                    v.append(prices[i] - stack[-1])
            else:
                v.append(prices[i] - stack[-1])
            stack.append(prices[i])
        
        return v[::-1]
