# Coderbyte question

def QuestionsMarks(strParam):

  digit = []
  count = 0
  last = False

  for s in strParam:
    if s.isdigit() :
      digit.append(int(s))
      if len(digit)==2:
        #print(digit)
        if sum(digit)==10:
          last = True
          if count != 3:
            return 'false'
      count = 0
      if count<3 and len(digit)>1:
        #print(digit)
        digit.pop(0)
        #print(digit)
        count = 0
    if s == '?':
      count += 1
  return 'true' if last else 'false'
      
  # code goes here

# keep this function call here 
print(QuestionsMarks(input()))


'''
def QuestionsMarks(s): 

    # code goes here 
    count_q = 0
    a = 0
    start_count = False
    true_exist = False
    for i in s:
        if start_count and i == '?':
            count_q += 1
        if i.isdigit():
            a += int(i)
            if a==10 and count_q == 3:
                true_exist = True
            if start_count and a == 10 and count_q != 3:
                return 'false'
            a = int(i)
            count_q = 0
            start_count = True
    return 'true' if true_exist else 'false'

    
# keep this function call here  
print(QuestionsMarks(input()))
'''
