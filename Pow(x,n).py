"""
Author: Xi Wang
Date: Aug 6, 2013
Update: Aug 6, 2013
Problem: Pow(x, n)
Difficulty: easy
Source: http://leetcode.com/onlinejudge#question_50
Notes:
Implement pow(x, n).
Solution: recursion.
"""


def pow(x,n):
  if x<0:
    if n%2==0:
        return pow(-x,n)
    else:
        return -pow(-x,n)
  elif x==0:
     return x
  elif n<0:
     return 1.0/pow(-x,n)
  elif n==1:
     return x
  elif n==0:
     return 1.0
  else:
     half = pow(x,n/2)
     if n%2==0:
       return half*half
     else:
       return half*half*x

if __name__ =='__main__':
    x = 3
    n = 10
    print pow(x,n) 
