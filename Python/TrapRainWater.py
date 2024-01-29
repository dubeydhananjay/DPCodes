class Solution:
    def trap(self, height: List[int]) -> int:
        size = len(height)
        maxWater = 0
        maxL = [0] * size
        maxL[0] = height[0]
        for i in range(1, size):
            maxL[i] = max(maxL[i - 1], height[i])
        
        maxR = [0] * size
        maxR[size - 1] = height[size - 1]
        for i in range(size - 2, -1, -1):
            maxR[i] = max(maxR[i + 1], height[i])
        
        for i in range(size):
            maxWater += min(maxL[i], maxR[i]) - height[i]
        
        return maxWater
