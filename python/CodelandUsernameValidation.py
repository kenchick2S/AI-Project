# Coderbyte question

import re

def CodelandUsernameValidation(strParam):

  if len(strParam)>=4 and len(strParam)<=25 and strParam[0].isalpha() and strParam[-1] != '_':
    p = re.compile(r'[a-zA-z1-9_]')
    for s in strParam:
      if not p.match(s):
        return 'false'
    return 'true'
  else:
    return 'false'

  # code goes here
  return strParam

# keep this function call here 
print(CodelandUsernameValidation(input()))



'''
import re


def CodelandUsernameValidation(str):
  pattern = re.compile(r"^[a-zA-Z][\w_]{2,23}[^_]$")
  res = pattern.match(str)
  str = "true" if res else "false"
  return str

# keep this function call here 
print(CodelandUsernameValidation(input()))
'''
