# Coderbyte question

def FirstFactorial(num):
  tmp = 1
  for i in range(num,1,-1):
    tmp = i*tmp
  # code goes here
  return tmp

# keep this functionan call here 
print(FirstFactorial(input()))

'''
------ recursive method------
def FirstFactorial(num): 
    if num == 1:
      return 1
    else:
      return num * FirstFactorial(num-1)
    # code goes here 
    # return num
    
# keep this function call here  
print(FirstFactorial(input()))
'''
