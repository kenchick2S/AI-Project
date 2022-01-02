# 452. Minimum Number of Arrows to Burst Balloons

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        
        '''
        [[1,2],[2,3],[3,4],[4,5]]
        
        res = 1 for [1,2] and [1,2] will be extended to [[1,2],[2,3]] at next step
        
        if x_start of [3,4] =  3 > 2 = last_end of [1,2]:
                    there is no intersection
                    res += 1 for [3,4]
                    
        res = 2 for [3,4] and [3,4] will be extended to [[3,4],[4,5]] at next step
        
        '''
        
        points.sort(key=lambda x: x[1])
        res = 1
        last_end = points[0][1]
        
        for x_start, x_end in points[1:]:
            if x_start > last_end:
                res += 1
                last_end = x_end
        
        return res
