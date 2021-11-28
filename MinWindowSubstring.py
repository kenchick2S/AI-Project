# Coderbyte question

def MinWindowSubstring(strArr):
  
  # New a dictionary
  dic = {}

  for i in strArr[1]:
    if i not in dic.keys() :
      dic[i]=1
    else :
      dic[i]+=1
  '''for i in range(len(strArr[1]),len(strArr[0])):
    print(i)'''
  
  # Sliding window
  for i in range(len(strArr[1]),len(strArr[0])+1):
    for j in range(len(strArr[0])-i+1):
      tmpdic = {}
      tmp = 0
      ##print(strArr[0][j:i+j])
      for k in strArr[0][j:i+j]:
        if k not in tmpdic.keys():
          tmpdic[k]=1
        else:
          tmpdic[k]+=1
      ##print(tmpdic)
      for s in strArr[1]:
        # Compare two dictionary
        try:
          if tmpdic[s] >= dic[s]:
            tmp+=1
            if tmp == len(strArr[1]):
              return strArr[0][j:i+j]
        except KeyError:
          continue 


  # code goes here
  # return strArrr

# keep this function call here 
print(MinWindowSubstring(input()))
