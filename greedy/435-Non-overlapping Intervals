# 435. Non-overlapping Intervals

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        
        intervals = sorted(intervals, key = lambda k : k[1])
        count = 0
        
        prev = intervals[0][1]
        
        for i in range(1, len(intervals)):
            if prev > intervals[i][0]:
                count += 1
            else:
                prev = intervals[i][1]
        return count
