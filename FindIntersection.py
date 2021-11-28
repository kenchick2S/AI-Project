# Coderbyte question

def FindIntersection(strArr):

  tmp = 'false'
  for s in list(map(int, strArr[1].split(','))):
    if s in list(map(int, strArr[0].split(','))):
      if tmp == 'false':
        tmp = s
      else :
        tmp = f'{tmp},{s}'
  # code goes here
  return tmp

# keep this function call here 
print(FindIntersection(input()))



'''
def FindIntersection(strArr):
  
    setOne = set(strArr[0].split(", "))
    setTwo = set(strArr[1].split(", "))

    result = sorted(list(setOne.intersection(setTwo)), key=lambda str: int(str))
    
    return ','.join(result) if len(result) > 0 else False

# keep this function call here 
print(FindIntersection(input()))
'''
