# Coderbyte question

def FirstReverse(strParam):
  tmp = []
  # code goes here
  for i in range(len(strParam)-1,-1,-1):
    tmp.append(strParam[i])
  strParam = "".join(tmp)
  return strParam

# keep this function call here 
print(FirstReverse(input()))

'''
1.
def FirstReverse(str): 

    # code goes here 
    return str[::-1]
    
# keep this function call here  
print(FirstReverse(input()))

2.
def FirstReverse(s): 
  str = ""
  for i in s:
    str = i + str
  return str
    # code goes here
# keep this function call here  
print(FirstReverse(input())) 
'''
