# Coderbyte question

import re

def LongestWord(sen):
  strlist = re.findall(r'[a-zA-Z1-9]+', sen)
  # code goes here
  tmp = ''
  for s in strlist:
    if len(s) > len(tmp):
      tmp = s
    
  return tmp

# keep this function call here 
print(LongestWord(input()))

'''
Without re
1.
def LongestWord(sen):
    def lk(w):
        return w[0]

    def lw(w):
        return len([l for l in w if l.isalpha() or l.isdigit()])

    wls = sorted([(lw(w), w) for w in sen.split(' ')], key=lk, reverse=True)
    return wls[0][1]
    
    
# keep this function call here  
# to see how to enter arguments in Python scroll down
print LongestWord(raw_input())

2.
def LongestWord(sen): 

    # code goes here 
    return max(sen.translate(None, "~!@#$%^&*()-_+={}[]:;'<>?/,.|`").split(), key=len)
    
# keep this function call here  
print LongestWord(raw_input())
'''
