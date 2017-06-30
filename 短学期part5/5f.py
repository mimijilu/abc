import math
t=int(raw_input())
for T in range (t):
        l1,l2,q=map(float,raw_input().split())
        a=l1/2.0
        b=l2/2.0
        c=math.sqrt(a*a+b*b-2*a*b*math.cos(q*math.pi/180.0))
        print math.pi*0.25*(c+a+b)*(c+a+b)