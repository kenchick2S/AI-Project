# 455. Assign Cookies

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        count = 0
        g = sorted(g)
        s = sorted(s)
        for i in g:
            while(len(s)>0):
                tmp = s.pop(0)
                if(i <= tmp):
                    count+=1
                    break
        return count

'''
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        c=0
        j=0
        g.sort()
        s.sort()
        for i in s:
            if(j<len(g) and i>=g[j]):
                c+=1
                j+=1
        return c
'''
