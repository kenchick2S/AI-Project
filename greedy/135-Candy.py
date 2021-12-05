# 135. Candy

class Solution:
    def candy(self, ratings: List[int]) -> int:
        num = [1]*len(ratings)
        
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                num[i] = num[i-1] + 1
        for i in range(len(ratings)-1, 0, -1):
            if ratings[i] < ratings[i-1]:
                num[i-1] = max(num[i-1], num[i]+1)
        print(num)
        return sum(num)
