# 605. Can Place Flowers

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0  
        bed_len = len(flowerbed)
        i = 0
        while i < bed_len:

            if (flowerbed[i] == 0 and
                (i == 0 or flowerbed[i-1] == 0) and
                (i == bed_len - 1 or flowerbed[i+1] == 0)):  
                
                count += 1
                if count >= n:
                    return True
                i += 1  

            elif flowerbed[i] == 1:
                i += 1  

            i += 1
        
        return count == n
