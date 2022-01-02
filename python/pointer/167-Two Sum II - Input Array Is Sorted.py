167. Two Sum II - Input Array Is Sorted

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        start=0
        end=len(numbers)-1
        for i in numbers:
            if numbers[start]+numbers[end]==target:
                return [start+1,end+1]
            elif numbers[start]+numbers[end] > target:
                end-=1
            else:
                start+=1
        '''dic = {}
        for i in range(len(numbers)):
            dic[numbers[i]] = i
        for i in dic:
            if target-i in dic:
                if target-i == i:
                    return [dic[i], dic[i]+1]
                else :
                    return [dic[i]+1, dic[target-i]+1]'''
